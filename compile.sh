#!/bin/bash

RAYLIB_PATH="C:/raylib/raylib"
CC=gcc
CFLAGS="-O2 -std=c99 -Wall"
INCLUDE="-I$RAYLIB_PATH/src -I./header"
LIBS="-L$RAYLIB_PATH/src -lraylib -lopengl32 -lgdi32 -lwinmm"

echo "Compiling main.c..."
$CC $CFLAGS $INCLUDE -o main main.c utils.c $LIBS

if [ -f main.exe ]; then
    echo "Compilation successful!"
    echo "Running main.exe..."
    ./main.exe
else
    echo "Compilation failed!"
    exit 1
fi
