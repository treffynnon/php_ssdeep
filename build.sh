#!/bin/bash
SRC_DIR="src"
BUILD_DIR="build"
DATE_DIR=`date +%s`
FULL_BUILD_PATH="$BUILD_DIR/$DATE_DIR"
mkdir $FULL_BUILD_PATH
cp $SRC_DIR/* $FULL_BUILD_PATH -r
cd $FULL_BUILD_PATH
phpize
./configure
make
