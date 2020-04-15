P1="./src/"
P1C="$P1/ctrls"
P1CU="$P1C/utils"

g++ $P1/$1.cpp  -o ./runtime/$1  -lGL && ./runtime/$1
