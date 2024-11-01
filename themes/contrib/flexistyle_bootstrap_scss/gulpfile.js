let gulp = require('gulp'),
  sass = require('gulp-sass')(require('sass')),
  sourcemaps = require('gulp-sourcemaps'),
  $ = require('gulp-load-plugins')(),
  cleanCss = require('gulp-clean-css'),
  rename = require('gulp-rename'),
  postcss = require('gulp-postcss'),
  autoprefixer = require('autoprefixer'),
  postcssInlineSvg = require('postcss-inline-svg'),
  browserSync = require('browser-sync').create(),
  pxtorem = require('postcss-pxtorem'),
	postcssProcessors = [
		postcssInlineSvg({
      removeFill: true,
      paths: ['./node_modules/bootstrap-icons/icons']
    }),
		pxtorem({
			propList: ['font', 'font-size', 'line-height', 'letter-spacing', '*margin*', '*padding*'],
			mediaQuery: true
		})
  ];

const paths = {
  scss: {
    src: './scss/theme/*.scss',
    dest: './css',
    watch: './scss/**/*.scss',
  },
  js: {
    global: './js/global.js',
    dest: './js'
  }
}

/*
  This function compiles SCSS files into CSS, writes sourcemaps, applies PostCSS processors, minifies the CSS,
  and outputs both the regular and minified versions of the CSS.
*/
function styles () {
  return gulp.src([paths.scss.src])
    .pipe(sourcemaps.init())
    .pipe(sass({
      includePaths: [
        './node_modules/bootstrap/scss',
      ]
    }).on('error', sass.logError))
    .pipe($.postcss(postcssProcessors))
    .pipe(sourcemaps.write())
    .pipe(gulp.dest(paths.scss.dest))
    .pipe(cleanCss())
    .pipe(rename({ suffix: '.min' }))
    .pipe(gulp.dest(paths.scss.dest))
    .pipe(browserSync.stream())
}

// This function moves JavaScript files to the destination directory and triggers a live reload with browser-sync.
function js () {
  return gulp.src([paths.js.global])
    .pipe(gulp.dest(paths.js.dest))
    .pipe(browserSync.stream())
}

// Static server and watches for changes in SCSS files to recompile them and reload the browser.
function serve () {
  gulp.watch([paths.scss.watch], styles).on('change', browserSync.reload)
}

const build = gulp.series(styles, gulp.parallel(js, serve))

exports.styles = styles
exports.js = js
exports.serve = serve

exports.default = build
