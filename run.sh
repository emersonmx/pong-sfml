#!/bin/bash

set -e

BUILD_DIR=build
EXECUTABLE=pong

echo "Create \"$BUILD_DIR\" path"
mkdir -p $BUILD_DIR
pushd build > /dev/null

echo "Configuring..."
cmake -DCMAKE_BUILD_TYPE=Debug ..

echo "Building..."
make
popd > /dev/null

echo "Running..."
$BUILD_DIR/$EXECUTABLE
echo "Done."
