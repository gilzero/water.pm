import gulp from 'gulp';
import dartSass from 'sass';
import gulpSass from 'gulp-sass';
import sourcemaps from 'gulp-sourcemaps';
import postcss from 'gulp-postcss';
import autoprefixer from 'autoprefixer';
import uglify from 'gulp-uglify';
import pump from 'pump';
import sassGlob from 'gulp-sass-glob';

const sass = gulpSass(dartSass);

const paths = {
  app: '',
  src: 'src',
  dist: 'dist',
  css: 'dist/css',
  js: 'dist/js'
};


export const jsDev = (cb) => {
  pump([
    gulp.src(`${paths.src}/**/*.js`),
    gulp.dest(paths.dist)
  ], cb);
};

export const sassDev = gulp.series(jsDev, async () => {
  const processors = [autoprefixer()];
  return gulp.src(`${paths.src}/global/styles.scss`)
    .pipe(sourcemaps.init())
    .pipe(sassGlob())
    .pipe(sass({
      includePaths: [
        './../../../',
        './../../../../',
        './../../../../../',
      ]
    }).on('error', sass.logError))
    .pipe(postcss(processors))
    .pipe(sourcemaps.write('../map'))
    .pipe(gulp.dest(`${paths.css}/global`));
});

export const jsProd = (cb) => {
  pump([
    gulp.src(`${paths.src}/**/*.js`),
    uglify(),
    gulp.dest(paths.dist)
  ], cb);
};

export const sassProd = gulp.series(jsProd, async () => {
  const processors = [autoprefixer()];
  return gulp.src(`${paths.src}/global/styles.scss`)
    .pipe(sassGlob())
    .pipe(sass({
      includePaths: [
        './../../../',
        './../../../../',
        './../../../../../',
      ],
      outputStyle: 'compressed'
    }).on('error', sass.logError))
    .pipe(postcss(processors))
    .pipe(gulp.dest(`${paths.css}/global`));
});

export const watch = gulp.series(sassDev, () => {
  gulp.watch(`${paths.src}/**/*.scss`, gulp.series(sassDev));
});

export default gulp.series(watch);
