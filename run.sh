#!/bin/bash

BUILD_DIR=build
EXECUTABLE=pong

echo "Create \"$BUILD_DIR\" path"
mkdir -p $BUILD_DIR
pushd build > /dev/null

echo "Configuring..."
cmake ..

echo "Building..."
make
popd > /dev/null

echo "Running..."
$BUILD_DIR/$EXECUTABLE
echo "Done."
