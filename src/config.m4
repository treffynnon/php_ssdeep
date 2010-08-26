PHP_ARG_ENABLE(ssdeep, whether to enable ssdeep support,
[ --enable-ssdeep   Enable ssdeep support])

if test "$PHP_SSDEEP" = "yes"; then
  PHP_SUBST(SSDEEP_SHARED_LIBADD)
  AC_DEFINE(HAVE_SSDEEP, 1, [Whether you have SSDEEP])
  PHP_NEW_EXTENSION(ssdeep, php_ssdeep.c, $ext_shared)
  PHP_ADD_LIBRARY_WITH_PATH(fuzzy, "/usr/lib/.libs/", SSDEEP_SHARED_LIBADD)
fi