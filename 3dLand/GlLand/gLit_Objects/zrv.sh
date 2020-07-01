# file:///home/x4/Downloads/Modern%20OpenGL%20Guide.pdf
_LOGGER_FILE_PATH="assets/logs/encodedObjLogger.txt"
_S="./src"
_C="$_S/ctrls"
_CPPs=" 
  $_C/window.cpp $_C/keys.cpp $_C/camera.cpp
  $_C/draw.cpp $_C/shader.cpp $_C/texture.cpp $_C/objLoader.cpp"

echo "\n##### - Logger Init() -"
FILE=/etc/resolv.conf
if test -f "$FILE"; then
  echo "Cleaning logger files at: $FILE"
  rm -f assets/logs/encodedObjLogger.txt
fi

echo "\n############### - Compiling the binary \n"
g++ $_S/$1.cpp $_CPPs -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL  # && ./runtime/$1

echo "\n######################## - Running the binary \n"
./runtime/$1
