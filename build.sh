#!/bin/bash
SRC_DIR="ssdeep"
BUILD_DIR="build"
DATE_DIR=`date +%s`
FULL_BUILD_PATH="$BUILD_DIR/$DATE_DIR"
mkdir $FULL_BUILD_PATH
cp $SRC_DIR/* $FULL_BUILD_PATH -r
cd $FULL_BUILD_PATH
phpize
./configure --with-ssdeep
make
make test
cd ../../
cp $FULL_BUILD_PATH/modules/ssdeep.so ./ssdeep.so