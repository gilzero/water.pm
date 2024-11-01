/**
 * @file
 * Gulpfile for fortytwo.
 */

var gulp = require('gulp');
var $ = require('gulp-load-plugins')();
var del = require('del');

function sassLint() {
  return gulp.src('static/sass/**/*.s+(a|c)ss')
      .pipe($.sassLint({configFile: '.sass-lint.yml'}))
      .pipe($.sassLint.format())
      .pipe($.sassLint.failOnError());
}

function sassCompile() {
  var pcPlug = {
    autoprefixer: require('autoprefixer'),
    mqpacker: require('css-mqpacker'),
    flexbugs: require('postcss-flexbugs-fixes')
  };
  var pcProcess = [
    pcPlug.autoprefixer(),
    pcPlug.mqpacker(),
    pcPlug.flexbugs()
  ];

  return gulp
      .src('static/sass/**/*.s+(a|c)ss')
      .pipe($.plumber())
      .pipe($.sourcemaps.init())
      .pipe($.sass({outputStyle: "expanded"}))
      .pipe($.postcss(pcProcess))
      .pipe($.sourcemaps.write())
      .pipe(gulp.dest("static/css"));
}

// Clean assets
function clean() {
  return del(['static/css/*']);
}

function watchFiles() {
  gulp.watch('static/sass/**/*.+(scss|sass)', gulp.series(sassLint, sassCompile));
}

const watch = gulp.series(clean, gulp.series(sassLint, sassCompile), watchFiles);

// Export tasks.
exports.watch = watch;
exports.default = watch;