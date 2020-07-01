_LOGGER_FILE_PATH="assets/logs/encodedObjLogger.txt"
_S="./src"
_C="$_S/ctrls"
_CPPs=" 
  $_C/window.cpp $_C/keys.cpp $_C/camera.cpp
  $_C/draw.cpp $_C/shader.cpp $_C/texture.cpp $_C/objLoader.cpp"

echo "    - Logger Init() -"
FILE=/etc/resolv.conf
if test -f "$_LOGGER_FILE_PATH"; then
  echo "    - Cleaning logger files at: $_LOGGER_FILE_PATH"
  rm -f assets/logs/encodedObjLogger.txt
fi

echo "    - COMPILING BINARY"
g++ $_S/$1.cpp $_CPPs -o ./runtime/$1 -lglfw -lGLEW -DGLEW_STATIC -lGL # && ./runtime/$1

echo "    - RUNNING BINARY"
./runtime/$1
