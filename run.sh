#!/bin/bash

BUILD_DIR=build
EXECUTABLE=pong

echo "Create \"$BUILD_DIR\" path"
mkdir -p $BUILD_DIR
pushd build > /dev/null

echo "Configuring..."
cmake ..

echo "Building..."
rm -f $EXECUTABLE
make
popd > /dev/null

echo "Running..."
if [[ $BUILD_DIR/$EXECUTABLE ]]
then
    echo "Exit with error."
else
    echo "Done."
fi

