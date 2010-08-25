PHP_ARG_ENABLE(ssdeep, whether to enable ssdeep support,
[ --enable-ssdeep   Enable ssdeep support])

if test "$PHP_SSDEEP" = "yes"; then
  AC_DEFINE(HAVE_SSDEEP, 1, [Whether you have SSDEEP])
  PHP_NEW_EXTENSION(ssdeep, php_ssdeep.c, $ext_shared)
fi