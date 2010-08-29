/**
 *
 * php_ssdeep
 *
 * http://github.com/treffynnon/php_ssdeep
 *
 * A PHP extension to expose ssdeep functionality for fuzzy
 * hashing and comparing.
 *
 * Version 2.5
 *
 * BSD Licensed.
 *
 * Copyright (c) 2010, Simon Holywell
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php_ssdeep.h"

PHP_FUNCTION(ssdeep_fuzzy_hash) {
    char *hash = (char *) emalloc(FUZZY_MAX_RESULT);
    char *tohash;
    int tohash_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &tohash, &tohash_len) == FAILURE) {
        RETURN_NULL();
    }

    fuzzy_hash_buf((unsigned char *) tohash, tohash_len, hash);

    RETURN_STRING(hash, 0);
}

PHP_FUNCTION(ssdeep_fuzzy_hash_filename) {
    char *hash = (char *) emalloc(FUZZY_MAX_RESULT);
    char *file_name;
    int file_name_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &file_name, &file_name_len) == FAILURE) {
        RETURN_NULL();
    }

    fuzzy_hash_filename(file_name, hash);

    RETURN_STRING(hash, 0);
}

PHP_FUNCTION(ssdeep_fuzzy_compare) {
    char *sig1;
    char *sig2;
    int sig1_len;
    int sig2_len;
    int match;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &sig1, &sig1_len, &sig2, &sig2_len) == FAILURE) {
        RETURN_NULL();
    }

    match = fuzzy_compare(sig1, sig2);

    RETURN_LONG(match);
}

/**
 * PHP info
 */
PHP_MINFO_FUNCTION(ssdeep) {
    php_info_print_table_start();
    php_info_print_table_row(2, PHP_SSDEEP_EXTNAME " Module", "enabled");
    php_info_print_table_row(2, "version", PHP_SSDEEP_EXTVER);
    if (sapi_module.phpinfo_as_text) {
        /* No HTML for you */
        php_info_print_table_row(2, "By",
                "Simon Holywell\nhttp://www.simonholywell.com");
    } else {
        /* HTMLified version */
        php_printf("<tr>"
                "<td class=\"v\">By</td>"
                "<td class=\"v\">"
                "<a href=\"http://www.simonholywell.com\""
                " alt=\"Simon Holywell\">"
                "Simon Holywell"
                "</a></td></tr>");
    }
    php_info_print_table_end();
}

/**
 * PHP extension setup and function mappings
 */
static function_entry ssdeep_functions[] = {
    PHP_FE(ssdeep_fuzzy_hash, NULL)
    PHP_FE(ssdeep_fuzzy_compare, NULL)
    PHP_FE(ssdeep_fuzzy_hash_filename, NULL) {
        NULL, NULL, NULL
    }
};

zend_module_entry ssdeep_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_SSDEEP_EXTNAME,
    ssdeep_functions,
    /* MINIT()/MSHUTDOWN() are called once only when PHP starts up and
     * shutdowns.  They're really called only once and *not* when a new Apache
     * child process is created.
     */
    NULL /* PHP_MINIT(ssdeep) */,
    NULL /* PHP_MSHUTDOWN(ssdeep) */,
    /* RINIT()/RSHUTDOWN() are called once per request
     * We shouldn't really be using them since they are run on every request
     * and can hit performance.
     */
    NULL /* PHP_RINIT(ssdeep) */,
    NULL /* PHP_RSHUTDOWN(ssdeep) */,
    /* NULL */ PHP_MINFO(ssdeep),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_SSDEEP_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SSDEEP
ZEND_GET_MODULE(ssdeep)
#endif