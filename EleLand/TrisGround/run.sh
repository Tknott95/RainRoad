#!/bin/bash
# Clean main or create a .git. I Prefer to clean main here. 
g++ -Wall main.cpp -lglfw -lGL -o runtime/main && ./runtime/main
# g++ -Wall main.cpp -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -lglfw -lGL -lglfw3dll -lopengl32 -o main && ./main.exe
