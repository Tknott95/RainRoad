#!/bin/bash

_IGNORE="
-Wno-unused-function 
-Wno-unused-variable"
_O="./runtime/main"

function clean_binary() {
  # So if compiling fails script fails, prior it ran the old binary
  _BINARY_FILE_PATH="runtime/main"
  if test -f "$_BINARY_FILE_PATH"; then
    rm -f $_BINARY_FILE_PATH
  fi
}

function logger_init() {
  _LOGGER_FILE_PATH="assets/logs/encodedObjLogger.txt"
  echo "    - Logger Init() -"
  if test -f "$_LOGGER_FILE_PATH"; then
    echo "    - Cleaning logger files at: $_LOGGER_FILE_PATH"
    rm -f assets/logs/encodedObjLogger.txt
  fi
}

function clean_o() {
  if test -f "main.o"; then
    rm -rf *.o
  fi
}

clean_binary
logger_init
