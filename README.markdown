php_ssdeep is now on PECL
====================

This project is now in the PHP PECL repository.

  - [ssdeep PECL page][1]
  - [ssdeep PHP documentation][2]
  - [ssdeep PECL source][3]


To install
-------

After you have installed a copy of ssdeep (see below for more information) you simply run the following command:

    sudo pecl install ssdeep


Installing the ssdeep libraries
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


  [1]: http://pecl.php.net/package/ssdeep "ssdeep PECL page"
  [2]: http://docs.php.net/manual/en/book.ssdeep.php "ssdeep PHP Documentation"
  [3]: http://svn.php.net/pecl/ssdeep "SVN repo/source for ssdeep"
  [4]: http://ssdeep.sourceforge.net/usage.html#install "ssdeep Installation Instructions"
  [5]: http://ssdeep.sourceforge.net/ "ssdeep Project Site"
  [6]: http://packages.ubuntu.com/en/karmic/i386/ssdeep/filelist "Ubuntu Karmic file list for ssdeep"