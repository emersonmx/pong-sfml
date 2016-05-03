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
make -j3
popd > /dev/null

echo "Running..."
$BUILD_DIR/$EXECUTABLE
echo "Done."

echo "Generating tags"
ctags --c++-kinds=+p --c-kinds=+p --fields=+liaS --extra=+fq /usr/include/SFML /usr/include/Box2D ./Pong/ ./MXG/
echo "Done."
