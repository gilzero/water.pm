<?php

namespace Drupal\ai_seo\Form;

use Drupal\Core\Ajax\AjaxResponse;
use Drupal\Core\Ajax\RedirectCommand;
use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Datetime\DateFormatterInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Language\LanguageManagerInterface;
use Drupal\Core\Link;
use Drupal\Core\Messenger\MessengerInterface;
use Drupal\Core\Messenger\MessengerTrait;
use Drupal\Core\Routing\CurrentRouteMatch;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Url;
use Drupal\node\NodeInterface;
use Drupal\ai_seo\AiSeoAnalyzer;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Analyze Url form.
 */
class AnalyzeNodeForm extends FormBase {
  use MessengerTrait;

  /**
   * The entity type manager.
   *
   * @var \Drupal\Core\Entity\EntityTypeManagerInterface
   */
  protected $entityTypeManager;

  /**
   * Current route match.
   *
   * @var \Drupal\Core\Routing\CurrentRouteMatch
   */
  protected $currentRouteMatch;

  /**
   * The language manager.
   *
   * @var \Drupal\Core\Language\LanguageManagerInterface
   */
  protected $languageManager;

  /**
   * AI analyzer.
   *
   * @var \Drupal\ai_seo\AiSeoAnalyzer
   */
  protected $analyzer;

  /**
   * The date formatter service.
   *
   * @var \Drupal\Core\Datetime\DateFormatterInterface
   */
  protected $dateFormatter;

  /**
   * The messenger service.
   *
   * @var \Drupal\Core\Messenger\MessengerInterface
   */
  protected $messenger;

  /**
   * The current user.
   *
   * @var \Drupal\Core\Session\AccountInterface
   */
  protected $currentUser;

  /**
   * The config.
   *
   * @var \Drupal\Core\Config\ImmutableConfig
   */
  protected $config;

  /**
   * Constructs a new Weight table form object.
   *
   * @param \Drupal\Core\Entity\EntityTypeManagerInterface $entity_type_manager
   *   The entity type manager.
   * @param \Drupal\Core\Routing\CurrentRouteMatch $current_route_match
   *   The language manager.
   * @param \Drupal\Core\Language\LanguageManagerInterface $language_manager
   *   The language manager.
   * @param \Drupal\ai_seo\AiSeoAnalyzer $analyzer
   *   AI analyzer.
   * @param \Drupal\Core\Datetime\DateFormatterInterface $date_formatter
   *   The date formatter service.
   * @param \Drupal\Core\Messenger\MessengerInterface $messenger
   *   The messenger service.
   * @param \Drupal\Core\Session\AccountInterface $current_user
   *   Current user.
   * @param \Drupal\Core\Config\ConfigFactoryInterface $config_factory
   *   The config factory service.
   */
  public function __construct(
      EntityTypeManagerInterface $entity_type_manager,
      CurrentRouteMatch $current_route_match,
      LanguageManagerInterface $language_manager,
      AiSeoAnalyzer $analyzer,
      DateFormatterInterface $date_formatter,
      MessengerInterface $messenger,
      AccountInterface $current_user,
      ConfigFactoryInterface $config_factory,
    ) {
    $this->entityTypeManager = $entity_type_manager;
    $this->currentRouteMatch = $current_route_match;
    $this->languageManager = $language_manager;
    $this->analyzer = $analyzer;
    $this->dateFormatter = $date_formatter;
    $this->messenger = $messenger;
    $this->currentUser = $current_user;
    $this->config = $config_factory->get('ai_seo.configuration');
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static(
      $container->get('entity_type.manager'),
      $container->get('current_route_match'),
      $container->get('language_manager'),
      $container->get('ai_seo.service'),
      $container->get('date.formatter'),
      $container->get('messenger'),
      $container->get('current_user'),
      $container->get('config.factory'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'analyze_url_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state, $hash = NULL) {
    $form['container'] = [
      '#type' => 'container',
      '#open' => TRUE,
      '#collapsible' => FALSE,
      '#attributes' => [
        'class' => [
          'analyze-url-form__container',
        ],
      ],
    ];

    // First make sure that the AI config is set up.
    $model_and_provider_string = $this->config->get('provider_and_model') ?? '';
    $model_and_provider = explode('__', $model_and_provider_string);

    if (count($model_and_provider) !== 2) {
      $form['container']['header'] = [
        '#type' => 'markup',
        '#markup' => $this->t('<p>Missing provider, select on at %settings.</p>', [
          '%settings' => Link::createFromRoute('AI SEO module settings', 'ai_seo.settings')->toString(),
        ]),
        '#attributes' => [
          'class' => [
            'form--header',
          ],
        ],
      ];
      return $form;
    }

    $entity_type_id = 'node';
    $entity = $this->currentRouteMatch->getParameter($entity_type_id);
    if (!($entity instanceof NodeInterface)) {
      $form['container']['header'] = [
        '#type' => 'markup',
        '#markup' => '
          <p>Node not found.</p>
        ',
        '#attributes' => [
          'class' => [
            'form--header',
          ],
        ],
      ];
      return $form;
    }

    $form['container']['header'] = [
      '#type' => 'markup',
      '#markup' => '
        <p>This form facilitates the generation of SEO reports by allowing you to specify criteria for content analysis.
        Modify the prompt in the options below. The report generation can take some time so stay on the page while it is happening.</p>
      ',
      '#attributes' => [
        'class' => [
          'form--header',
        ],
      ],
    ];

    // Show the previous reports if there are any.
    $previous_reports = $this->analyzer->getReports($entity->id());
    if (count($previous_reports) > 0) {
      // Create a details for the latest report.
      $form['container']['reports'] = [
        '#type' => 'details',
        '#title' => $this->t('Latest report'),
        '#open' => TRUE,
        '#collapsible' => FALSE,
        '#attributes' => [
          'class' => [
            'reports__container',
          ],
        ],
      ];

      // Show the created on datetime.
      $time_ago = $this->dateFormatter->formatTimeDiffSince($previous_reports[0]['timestamp']) . ' ' . $this->t('ago');

      // Get the revision if it's been stored.
      $revision_row = '';
      if (!empty($previous_reports[0]['revision_id'])) {
        $revision_row = $this->t('<div class="report--revision-id"><label><strong>Created for revision</strong> <a href="/node/:nid/revisions/:revision_id/view">#:revision_id</a></label></div>', [
          ':nid' => $entity->id(),
          ':revision_id' => $previous_reports[0]['revision_id'],
        ]);
      }

      $form['container']['reports']['latest'] = [
        '#type' => 'markup',
        '#children' => '
        <div class="report--timestamp"><label><strong>Report created:</strong> ' . $time_ago . '</label></div>' .
        $revision_row .
        $previous_reports[0]['report'],
      ];

      $form['container']['reports']['prompt'] = [
        '#type' => 'textarea',
        '#title' => 'Prompt used',
        '#disabled' => TRUE,
        '#readonly' => TRUE,
        '#value' => $previous_reports[0]['prompt'],
      ];
    }

    $report_count = count($previous_reports);
    if ($report_count > 1) {
      // Create a details for the latest report.
      $form['container']['older_reports'] = [
        '#type' => 'details',
        '#title' => $this->t('Older reports'),
        '#open' => FALSE,
        '#collapsible' => FALSE,
        '#attributes' => [
          'class' => [
            'older-reports__container',
          ],
        ],
      ];

      for ($i = 1; $i < $report_count; $i++) {
        $report_number = $report_count - $i;
        $form['container']['older_reports']['report_' . $i] = [
          '#type' => 'details',
          '#title' => $this->t('Report #:report_number', [
            ':report_number' => $report_number,
          ]),
          '#open' => FALSE,
          '#collapsible' => FALSE,
          '#attributes' => [
            'class' => [
              'reports__container',
            ],
          ],
        ];

        // Show the created on datetime.
        $time_ago = $this->dateFormatter->formatTimeDiffSince($previous_reports[$i]['timestamp']) . ' ' . $this->t('ago');

        // Get the revision if it's been stored.
        $revision_row = '';
        if (!empty($previous_reports[$i]['revision_id'])) {
          $revision_row = $this->t('<div class="report--revision-id"><label><strong>Created for revision</strong> <a href="/node/:nid/revisions/:revision_id/view">#:revision_id</a></label></div>', [
            ':nid' => $entity->id(),
            ':revision_id' => $previous_reports[$i]['revision_id'],
          ]);
        }

        $form['container']['older_reports']['report_' . $i]['report'] = [
          '#type' => 'markup',
          '#children' => '
          <div class="report--timestamp"><label><strong>Report created:</strong> ' . $time_ago . '</label></div>' .
          $revision_row .
          $previous_reports[$i]['report'],
        ];
        $form['container']['older_reports']['report_' . $i]['prompt'] = [
          '#type' => 'textarea',
          '#title' => 'Prompt used',
          '#disabled' => TRUE,
          '#readonly' => TRUE,
          '#value' => $previous_reports[$i]['prompt'],
        ];
      }
    }

    // Check permissions for report generation.
    if ($this->currentUser->hasPermission('create seo reports')) {
      // Start the report generation section.
      $form['container']['new_report'] = [
        '#type' => 'markup',
        '#markup' => '
          <h3>Create a New SEO Report</h3>',
      ];

      // Prompt.
      // Get the default / custom prompt.
      $form['container']['prompt'] = [
        '#type' => 'details',
        '#title' => $this->t('Customize Your Analysis Prompt'),
        '#open' => FALSE,
        '#collapsible' => TRUE,
        '#attributes' => [
          'class' => [
            'analyze-url-prompt__container',
          ],
        ],
      ];

      $form['container']['prompt']['prompt_to_use'] = [
        '#type' => 'textarea',
        '#title' => 'Your Analysis Prompt',
        '#default_value' => $this->analyzer->getPromptText(),
        '#rows' => 20,
        '#description' => $this->t('Modify the analysis prompt as needed or use the default settings in the %settings.', [
          '%settings' => Link::createFromRoute('module settings', 'ai_seo.settings')->toString(),
        ]),
        '#required' => TRUE,
      ];

      // Settings.
      // $form['container']['settings'] = [
      //   '#type' => 'details',
      //   '#title' => $this->t('Report Settings'),
      //   '#open' => FALSE,
      //   '#collapsible' => TRUE,
      //   '#attributes' => [
      //     'class' => [
      //       'analyze-url-settings__container',
      //     ],
      //   ],
      // ];

      // If the entity is moderated, show some extra controls.
      if (!empty($entity->moderation_state->value)) {
        /** @var \Drupal\content_moderation\ModerationInformation $moderation_information_service */
        $moderationInformationService = \Drupal::service('content_moderation.moderation_information');
        $workflow = $moderationInformationService->getWorkflowForEntity($entity);
        $storage = $this->entityTypeManager->getStorage($entity_type_id);

        // Find the revisions and build the options.
        $revisions = $storage->revisionIds($entity);
        $published_revision_id = NULL;
        $revisions = array_reverse($revisions);
        $options = [];
        foreach ($revisions as $revision_id) {
          $revision = $storage->loadRevision($revision_id);
          if ($revision->isPublished() && empty($published_revision_id)) {
            $published_revision_id = $revision_id;
          }
          $created_at = $this->dateFormatter->format($revision->getChangedTime(), 'short');

          $options[$revision_id] = $this->t('#:revision_id - :revision_created - :revision_label:current_label', [
            ':revision_id' => $revision_id,
            ':revision_created' => $created_at,
            ':revision_label' => $workflow->getTypePlugin()->getState($revision->moderation_state->value)->label(),
            ':current_label' => ($revision_id === $published_revision_id) ? ' (current revision)' : '',
          ]);
        }

        $form['container']['moderation_state'] = [
          '#type' => 'details',
          '#title' => $this->t('Select Content Revision'),
          '#open' => TRUE,
          '#collapsible' => FALSE,
          '#attributes' => [
            'class' => [
              'analyze-url-settings__container',
            ],
          ],
        ];
        $form['container']['moderation_state']['revision_id'] = [
          '#type' => 'select',
          '#title' => 'Revision to analyze',
          '#required' => TRUE,
          '#default_value' => $published_revision_id,
          '#options' => $options,
        ];
      }

      // Footer.
      $form['container']['footer'] = [
        '#type' => 'markup',
        '#markup' => '
          <p>Generating the report takes some time, don\'t navigate away from this page during it.</p>
        ',
        '#attributes' => [
          'class' => [
            'form--footer',
          ],
        ],
      ];

      // Fields to store entity info to submit.
      $form['container']['entity_id'] = [
        '#type' => 'hidden',
        '#title' => 'Entity ID',
        '#required' => TRUE,
        '#value' => $entity->id(),
      ];
      $form['container']['langcode'] = [
        '#type' => 'hidden',
        '#title' => 'Entity langcode',
        '#required' => TRUE,
        '#value' => $entity->language()->getId(),
      ];

      // Form actions.
      $form['container']['actions'] = ['#type' => 'actions'];
      $form['container']['actions']['submit'] = [
        '#type' => 'submit',
        '#value' => $this->t('Analyze'),
        '#attributes' => [
          'class' => [
            'btn--analyze',
          ],
        ],
        '#ajax' => [
          'callback' => [$this, 'ajaxSubmit'],
          'wrapper' => 'seo-analyze-results',
        ],
      ];
    }

    // The wrapper for search results.
    $form['analyze_results'] = [
      '#prefix' => '<div id="seo-analyze-results">',
      '#suffix' => '</div>',
      '#markup' => '',
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {

  }

  /**
   * Fetch and parse results.
   */
  public function ajaxSubmit(array &$form, FormStateInterface $form_state) {
    $entity_id = $form_state->getValue('entity_id');
    $langcode = !empty($form_state->getValue('langcode')) ? $form_state->getValue('langcode') : NULL;
    $revision_id = !empty($form_state->getValue('revision_id')) ? $form_state->getValue('revision_id') : NULL;
    $prompt = $form_state->getValue('prompt_to_use') ?? $this->analyzer->getDefaultPrompt();

    // Analyze node URL using our custom analyzer service.
    $this->analyzer->analyzeEntity($prompt, 'node', $entity_id, $revision_id, 'full', $langcode, []);

    // Create an AjaxResponse object to hold the commands.
    $response = new AjaxResponse();

    // Add the command to reload the current page.
    $current_url = Url::fromRoute('<current>');
    $response->addCommand(new RedirectCommand($current_url->toString()));

    return $response;
  }

}
