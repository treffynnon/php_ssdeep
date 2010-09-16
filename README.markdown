php_ssdeep is now on PECL
====================

This project is now in the PHP PECL repository.

  - [php_ssdeep PHP/PECL Extension Homepage][1]
  - [ssdeep PECL page][2]
  - [ssdeep PHP documentation][3]
  - [ssdeep PECL source][4]
  - [ohloh Project Page][5] (for project stats)


To install
-------

After you have installed a copy of ssdeep (see below for more information) you simply run the following command:

    sudo pecl install ssdeep


Installing the ssdeep libraries
-------

I would recommend building ssdeep from source using the [instructions][6] from it's [project site][7]. Once done **you need** to copy `.libs/*` to `/usr/lib` so that the php_ssdeep extension can see the ssdeep libraries.

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

Source: [Ubuntu Karmic file list][8]


  [1]: http://treffynnon.github.com/php_ssdeep/ "ssdeep PHP/PECL Extension homepage"
  [2]: http://pecl.php.net/package/ssdeep "ssdeep PECL page"
  [3]: http://docs.php.net/manual/en/book.ssdeep.php "ssdeep PHP Documentation"
  [4]: http://svn.php.net/pecl/ssdeep "SVN repo/source for ssdeep"
  [5]: www.ohloh.net/p/php_ssdeep "ohloh project page for project stats"
  [6]: http://ssdeep.sourceforge.net/usage.html#install "ssdeep Installation Instructions"
  [7]: http://ssdeep.sourceforge.net/ "ssdeep Project Site"
  [8]: http://packages.ubuntu.com/en/karmic/i386/ssdeep/filelist "Ubuntu Karmic file list for ssdeep"