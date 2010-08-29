#include "php.h"
#include <fuzzy.h>
#include "SAPI.h"

// prevent double execution
#ifndef PHP_SSDEEP_H
    #define PHP_SSDEEP_H 1

    #define PHP_SSDEEP_EXTVER "1.0"
    #define PHP_SSDEEP_EXTNAME "ssdeep"

    PHP_FUNCTION(ssdeep_fuzzy_hash);
    PHP_FUNCTION(ssdeep_fuzzy_compare);
    PHP_FUNCTION(ssdeep_fuzzy_hash_filename);

    extern zend_module_entry php_ssdeep_module_entry;
    #define phpext_php_ssdeep_ptr &php_ssdeep_module_entry
#endif