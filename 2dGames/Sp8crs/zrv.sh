P1="./src/$1"
P1C="$P1/controllers"
P1CU="$P1C/utils"
g++ $P1/$1.cpp $P1C/player.cpp $P1C/enemy.cpp $P1C/bullet.cpp $P1CU/overlay.cpp -o ./runtime/$1 -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system && ./runtime/$1
