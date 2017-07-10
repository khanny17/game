#!/bin/bash
set -e

mkdir -p cmake
cd cmake
cmake ..
make
make test

echo
echo "--- Build Successful ---"""
echo
