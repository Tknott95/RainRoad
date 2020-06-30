#!/bin/bash

g++ -Wall main.cpp -lglfw -lGL -o bin/main && ./bin/main
# g++ -Wall main.cpp -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lglfw -lGL -lglfw3dll -lopengl32 -o main && ./main.exe
