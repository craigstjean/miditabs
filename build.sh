#!/usr/bin/env bash
set -e

if [ ! -f deps/antlr-4.9.1-complete.jar ]; then
    curl https://www.antlr.org/download/antlr-4.9.1-complete.jar -o deps/antlr-4.9.1-complete.jar
fi

make antlr
mkdir -p build
cd build
cmake -GNinja ..
ninja

