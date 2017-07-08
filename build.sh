#!/bin/bash
set -e -x

mkdir -p cmake
cd cmake
cmake ..
../util/run-clang-tidy.py #Our own version because it fails if clang fails
make
