P1="./src/"
P1C="$P1/ctrls"
P1CU="$P1C/utils"
# @TODO  make list and loop through
g++ $P1/$1.cpp $P1C/game.cpp $P1CU/overlay.cpp -o ./runtime/$1 -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lGL && ./runtime/$1