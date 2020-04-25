# file:///home/x4/Downloads/Modern%20OpenGL%20Guide.pdf
_S="./src"
_C="$_S/ctrls"

g++ $_S/$1.cpp $_C/window.cpp $_C/keys.cpp $_C/camera.cpp $_C/shader.cpp -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL && ./runtime/$1
