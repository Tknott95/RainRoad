# file:///home/x4/Downloads/Modern%20OpenGL%20Guide.pdf
P1="./src/"
P1C="$P1/ctrls"
P1CU="$P1C/utils"

g++ $P1/$1.cpp $P1C/keys.cpp -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL && ./runtime/$1
