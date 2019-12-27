g++ ./src/$1/$1.cpp ./src/$1/controllers/enemy.cpp -o ./runtime/$1 -lsfml-graphics -lsfml-window -lsfml-system && ./runtime/$1
