#!/bin/bash
set -e

mkdir -p cmake
cd cmake
cmake ..
make -j2
cd ..
./cmake/unit_tests

echo
echo "--- Build Successful ---"""
echo
