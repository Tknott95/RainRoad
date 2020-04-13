#include "headers/game.h"


/* forLINUX: -lsfml-graphics -lsfml-window -lsfml-system -lGL */
int main() {
  cout << "\n App Initialized... \n" << endl;

  Game game;
  while(game.IsOpen()) {
    game.Update();
    game.Render();
  }

  return 0;
}