php_ssdeep (A PHP extension to utilise ssdeep's API)
====================

Introduction
-------

ssdeep is a utility for creating and comparing fuzzy hashes, which allows you to determine how similar the data is. For a better explanation see the [ssdeep project page][1]. This a PHP extension that exposes the [ssdeep API][2] to PHP.

Released under a [BSD license][3].

File Layout
-------

  - **ssdeep** (extension source files)
    - **docs** (generated HTML documentation)
    - **examples** (PHP example files demonstrating usage)
    - **tests** (PHP test files)
  - **phpdoc_src** (phpdoc source files for the extension)
    - **en** (English documentation)

Usage
-------

See `ssdeep/docs/*` for more information.

Installation
-------

See `ssdeep/docs/*` for more information.

Requirements
-------

  - Linux (tested on Ubuntu)
  - ssdeep (tested with 2.5 built from source)
  - PHP (tested on 5.3)


PECL Packaging
-------

Package for PECL using Pyrus:

  1. Got to the `ssdeep` directory
  2. `php /path/to/pyrus.phar pickle ssdeep --donotpackage`
  3. `php /path/to/pyrus.phar package package.xml`

For some reason that I am as yet unable to fathom running the straight `php /path/to/pyrus.phar pickle ssdeep` does not work and produces a broken .tgz release archive.


Install ssdeep package
-------

I would recommend building ssdeep from source using the [instructions][4] from it's [project site][5]. Once done **you need** to copy `.libs/*` to `/usr/lib` so that the php_ssdeep extension can see the ssdeep libraries.

    sudo cp .libs/* /usr/lib

You can use the packages supplied with Ubuntu or Debian, but they are not yet updated to the latest version of ssdeep.

If you are having trouble building or running the php_ssdeep extension it expects to see the following directory structure:

> /usr/bin/ssdeep
>
> /usr/include/fuzzy.h
>
> /usr/lib/libfuzzy.a
>
> /usr/lib/libfuzzy.la
>
> /usr/lib/libfuzzy.so
>
> /usr/lib/libfuzzy.so.2
>
> /usr/lib/libfuzzy.so.2.0.0

Source: [Ubuntu Karmic file list][6]

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


PECL ssdeep PHP Extension Licence
-------
This extension is under the BSD Licence:

Copyright (c) 2010, Simon Holywell
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


ssdeep Licensing Exemption
-------

Although ssdeep and the fuzzy hashing API are usually licensed under GNU GPLv2 Jesse Kornblum has licenced them to PECL under the terms of the Perl Artistic Licence with the following declaration:
"I hereby license ssdeep, the current version and all subsequent versions, under the terms of the Perl Artistic License, for inclusion into the PECL."
See http://news.php.net/php.pecl.dev/7625 for the verbatim email.


  [1]: http://ssdeep.sourceforge.net/ "ssdeep project page"
  [2]: http://ssdeep.sourceforge.net/api/html/ "ssdeep API documentation"
  [3]: http://en.wikipedia.org/wiki/BSD_licenses "BSD licence"
  [4]: http://ssdeep.sourceforge.net/usage.html#install "ssdeep Installation Instructions"
  [5]: http://ssdeep.sourceforge.net/ "ssdeep Project Site"
  [6]: http://packages.ubuntu.com/en/karmic/i386/ssdeep/filelist "Ubuntu Karmic file list for ssdeep"