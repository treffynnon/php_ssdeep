php_ssdeep (A PHP extension to utilise ssdeep's API)
====================

Introduction
-------

ssdeep is a utility for creating and comparing fuzzy hashes, which allows you to look determine how similar the data is. For a better explanation see the [ssdeep project page][1]. This a PHP extension that exposes the [ssdeep API][2] to PHP.

Usage
-------

Three functions are exposed:

  - ssdeep_fuzzy_hash_filename()
  - ssdeep_fuzzy_hash()
  - ssdeep_fuzzy_compare()

ssdeep_fuzzy_hash_filename() allows you to supply a path to a file you would like to get a hash of:

    $hash1 = ssdeep_fuzzy_hash_filename('/home/simon/text.text');


ssdeep_fuzzy_hash() will return a hash when it is supplied a string:

    $hash2 = ssdeep_fuzzy_hash('A piece of text would go here!');

ssdeep_fuzzy_compare() compares two hashes and returns their match percentage:

    $match = ssdeep_fuzzy_compare($hash1, $hash2);

Also see the test.php file for more examples of how this can be used.

Installation
-------

There are two options for installing this extension:

 1. Use the pre-compiled .so download.
 2. Build the extension yourself using the instructions below.

Either way you will need to copy the resultant .so file to your PHP modules directory and add a new line to your php.ini to tell PHP where to find php_ssdeep.

    extension=/path/to/ssdeep.so

If you have not got a working copy of ssdeep already installed then please follow the instructions available below before continuing here.

Now we have everything setup we can run the test code; in a console run:

    php -f /path/to/test.php

And you should see three hashes on your screen followed by the results of two matches/comparisons:

> Hash 1:
> 24:FPlUMKVsgNfgmjFadP6WboWjb8tsH4RSXqMbLFpjwPDt4tFF:9lUajiiPbbnr4RSXqMbppMZ4t3
> Hash 2:
> 48:9lUajiiPbbnr4RSXqMbLbmo03Rcq0K/cvhQ+3/M8M5BEaB6:9HFHsGqabmoMR18hQ+308sBdk
> Hash 3:
> 6144:pxgjtzD/W2dKdRWyguoglXjafNeS1l6bIjeQEa9TLnSptVkRwNI:pxgt7WFRWy9l21sbiLEa9T0t2RwNI
> 1 & 2 Match:57
> 2 & 3 Match:0

If it comes back with message about a shared library not being available then please review the ssdeep installation instructions (below) again. Paying particular attention to the file list/directory structure. It is most likely that libs are not where they are expected to be (`/usr/lib`).

Install ssdeep package
-------

I would recommend building ssdeep from source using the [instructions][3] from it's [project site][4]. Once done **you need** to copy `.libs/*` to `/usr/lib` so that the php_ssdeep extension can see the ssdeep libraries.

    sudo cp .libs/* /usr/lib

You can use the packages supplied with Ubuntu or Debian, but they are not yet updated to the latest version of ssdeep.

If you are having trouble building or running the php_ssdeep extension it expects to see the following directory structure:

> /usr/bin/ssdeep
> /usr/include/fuzzy.h
> /usr/lib/libfuzzy.a
> /usr/lib/libfuzzy.la
> /usr/lib/libfuzzy.so
> /usr/lib/libfuzzy.so.2
> /usr/lib/libfuzzy.so.2.0.0

Source: [Ubuntu Karmic file list][5]

Requirements
-------

  - Linux (tested on Ubuntu)
  - ssdeep (tested with 2.5 built from source)
  - PHP (tested on 5.3)

Building the extension yourself
-------

You will need:

  - A working installation of PHP
  - A working installation of ssdeep (see above)
  - A complete copy of the repository associated with this extension

Move into the directory containing the php_ssdeep source code and create a new directory called build:

    mkdir build

And then you can simple run the build.sh bash script:

    ./build.sh

If you now run `ls` on the directory then you will see that ssdeep.so has been created. This is the file you need to copy to your PHP module directory.

Obviously you do not need to use the ./build.sh script if you want to manually specify the build commands yourself. It essentially handles configuring, phpizing, making and then copy out the resultant ssdeep.so file to the base directory.


  [1]: http://ssdeep.sourceforge.net/ "ssdeep project page"
  [2]: http://ssdeep.sourceforge.net/api/html/ "ssdeep API documentation"
  [3]: http://ssdeep.sourceforge.net/usage.html#install "ssdeep Installation Instructions"
  [4]: http://ssdeep.sourceforge.net/ "ssdeep Project Site"
  [5]: http://packages.ubuntu.com/en/karmic/i386/ssdeep/filelist "Ubuntu Karmic file list for ssdeep"