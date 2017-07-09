#!/bin/bash
set -e

mkdir -p cmake
cd cmake
cmake ..
make

../util/run-clang-tidy.py #Our own version because the official was annoying

echo
echo "--- Build Successful ---"""
echo
