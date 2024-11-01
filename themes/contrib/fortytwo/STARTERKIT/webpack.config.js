const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const path = require("path");
const BrowserSyncPlugin = require("browser-sync-webpack-plugin");
const StylelintPlugin = require('stylelint-webpack-plugin');

// Use below if you use Valet Secure url and want a safe page.
// const homedir = require('os').homedir();

module.exports = (env, argv) => {
  const isDevMode = argv.mode === "development";
  const domain = 'STARTERKIT.ddev.site';
  const themefolder = '/themes/custom/STARTERKIT/dist/'

  return {
    mode: isDevMode ? "development" : "production",
    devtool: isDevMode ? "source-map" : false,
    entry: {
      main: ["./static/js/main.js", "./static/scss/main.scss"]
    },
    module: {
      rules: [
        {
          test: /\.scss$/,
          exclude: [path.resolve(__dirname, 'fortytwo')],
          use: [
            {
              loader: MiniCssExtractPlugin.loader
            },
            {
              loader: "css-loader",
              options: {
                sourceMap: true,
                modules: false
              }
            },
            {
              loader: "postcss-loader",
              options: {
                sourceMap: true
              }
            },
            {
              loader: "sass-loader",
              options: {
                sourceMap: true,
              }
            }
          ]
        },
        {
          test: /\.js$/,
          exclude: /(node_modules|bower_components)/,
          use: {
            loader: "babel-loader",
            options: {
              presets: [["@babel/preset-env", { modules: false }]],
              plugins: ['@babel/plugin-transform-runtime']
            }
          }
        }
      ]
    },
    output: {
      path: path.resolve(__dirname, "dist"),
      filename: "[name].min.js",
      publicPath: themefolder
    },
    plugins: [
      new StylelintPlugin({
        configFile: './.stylelintrc.json',
        exclude: ['static/**/*.css', 'dist/*.css', 'static/js/lib/*.js']
      }),
      new MiniCssExtractPlugin(),
      new BrowserSyncPlugin({
        proxy: "https://" + domain,
        host: domain,
        open: false,
      })
    ]
  };

};
