#!/bin/bash

_S="./src"
_C="$_S/ctrls"
_CPPs=" 
  $_C/window.cpp $_C/keys.cpp $_C/camera.cpp
  $_C/draw.cpp $_C/shader.cpp $_C/texture.cpp $_C/objLoader.cpp
  $_C/mesh.cpp"

function logger_init() {
  _LOGGER_FILE_PATH="assets/logs/encodedObjLogger.txt"
  echo "    - Logger Init() -"
  if test -f "$_LOGGER_FILE_PATH"; then
    echo "    - Cleaning logger files at: $_LOGGER_FILE_PATH"
    rm -f assets/logs/encodedObjLogger.txt
  fi
}

function clean_binary() {
  # So if compiling fails script fails, prior it ran the old binary
  _BINARY_FILE_PATH="runtime/main"
  if test -f "$_BINARY_FILE_PATH"; then
    rm -f $_BINARY_FILE_PATH
  fi
}

logger_init
clean_binary

echo "    - COMPILING BINARY"
g++ $_S/$1.cpp $_CPPs -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL

echo "    - RUNNING BINARY"
./runtime/$1
