Building Documentation
====================

Setup
-------

You need a copy of the PHP manual and its build tools, which can be obtained from GitHub. However we need to setup the directory structure first:

 - phpdoc
   - doc-base
   - en

 1. [PHP documentation build tools][1] (clone to doc-base)
 2. [English manual source][2] (clone to en)

We also need to install the PhD DocBook build tool for PHP Documentation, which is best done through PEAR by following these installation instructions: [PhD Installation via PEAR][3].


Merge in ssdeep Documentation
-------

In `phpdoc/doc-base/manual.xml.in` add the following line to the section marked `<set xml:id="refs.basic.other">`:

    &reference.ssdeep.book;

Then in `phpdoc/doc-base/entities/global.ent` add the following lines:

    <!ENTITY url.ssdeep.libssdeep "http://ssdeep.sourceforge.net">
    <!ENTITY url.ssdeep.ctph "http://dfrws.org/2006/proceedings/12-Kornblum.pdf">

Now copy the `en` folder from `phpdoc_src` in the ssdeep repository to your `phpdoc/` directory.


Run configure.php
-------

Configure.php has a few useful options when setting up the build. Generally I run the following command from `phpdoc/`:

    php doc-base/configure.php --with-partial=ssdeep --disable-segfault-error --enable-xml-details

`--disable-segfault-error` is very important if you are running on Windows otherwise the PHP process will just mysteriously crash with no helpful output.


Now to Build the Docs
-------

Again there are a [few nice options][4] that can be run with PhD but I usually run this command in `phpdoc/`:

    phd -d doc-base/.manual.book.ssdeep.xml -o output_dir

The built docs will now be in `phpdoc/output_dir`.


  [1]: http://github.com/php/phpdoc-doc-base "PHP Manual Build Tools"
  [2]: http://github.com/php/phpdoc-en "English PHP Manual git Source"
  [3]: http://doc.php.net/phd/docs/#installation "PhD PEAR Installation"
  [4]: http://doc.php.net/phd/docs/#render-phpdoc "PhD options"