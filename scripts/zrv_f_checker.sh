RUNTIME="./runtime/$1"
if test -f $RUNTIME; then
  g++ ./src/$1/$1.cpp -o ./runtime/$1 && ./runtime/$1
else
  g++ ./src/$1/$1.cpp -o ./runtime/$1
fi
