#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include <stdint.h>
#include <string.h>
#include <fuzzy.h>

#include "php_ssdeep.h"

static function_entry ssdeep_functions[] = {
    PHP_FE(ssdeep_fuzzy_hash, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry ssdeep_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_SSDEEP_EXTNAME,
    ssdeep_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_SSDEEP_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SSDEEP
ZEND_GET_MODULE(ssdeep)
#endif

PHP_FUNCTION(ssdeep_fuzzy_hash)
{
    char *hash = (char *) emalloc(FUZZY_MAX_RESULT);
    char *tohash;
    int tohash_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &tohash, &tohash_len) == FAILURE) {
        RETURN_NULL();
    }

    php_printf("String = %s ", tohash);
    php_printf("Length = %c ", tohash_len);

    fuzzy_hash_buf((unsigned char *) tohash, tohash_len, hash);

    //RETURN_STRING(hash, 1);
}