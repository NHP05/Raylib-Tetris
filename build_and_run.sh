#!/bin/bash

# Raylib Tetris Build and Run Script

echo "Building Raylib Tetris..."

# Check if raylib is installed
if ! pkg-config --exists raylib; then
    echo "Raylib not found. Installing raylib..."
    sudo apt update
    sudo apt install -y libraylib-dev
fi

# Create build directory if it doesn't exist
mkdir -p build

# Compile the game
g++ -std=c++17 -Wall -Wno-missing-braces \
    -Isrc/raylib/src -Isrc \
    src/main.cpp \
    src/game.cpp \
    src/grid.cpp \
    src/blocks.cpp \
    src/block.cpp \
    src/position.cpp \
    src/colors.cpp \
    -o game \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

if [ $? -eq 0 ]; then
    echo "Build successful! Running game..."
    ./game
else
    echo "Build failed!"
    exit 1
fi