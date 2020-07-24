#!/bin/bash

_S="./src"
_C="$_S/ctrls"
_CPPs=" 
  $_C/window.cpp $_C/keys.cpp $_C/camera.cpp
  $_C/draw.cpp $_C/shader.cpp $_C/texture.cpp $_C/objLoader.cpp
  $_C/mesh.cpp $_C/gui.cpp"
# Pulled w/: pkg-config --cflags freetype2
_FREETYPE="
  -I/usr/include/freetype2
  -I/usr/include/libpng16
  -I/usr/include/harfbuzz
  -I/usr/include/glib-2.0
  -I/usr/lib/glib-2.0/include"

source ../utils.sh

echo "    - COMPILING BINARY"
g++ $_S/$1.cpp $_CPPs $_FREETYPE -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL -lfreetype

echo "    - RUNNING BINARY"
./runtime/$1
