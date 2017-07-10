#!/bin/bash
set -e

mkdir -p cmake
cd cmake
cmake ..
make -j4
make test

echo
echo "--- Build Successful ---"""
echo
