#!/bin/bash
WIN_BINARY=main.exe
LINUX_BINARY=main

echo "   Cleaning old Binaries"
if test -f "main.exe"; then
  rm -f ./main.exe
elif test -f "main"; then
  rm -f ./main
fi

echo "   Compiling and running binary"
g++ main.cpp -o main && ./main
