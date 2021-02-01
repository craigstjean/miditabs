#!/usr/bin/env bash
set -e

make antlr
mkdir -p build
cd build
cmake -GNinja ..
ninja

