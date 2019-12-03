#include "controllers/game.cpp"

int main() {
  cout << "\n App Initialized... \n" << endl;
  
  std::srand(static_cast<unsigned>(time(NULL)));
  Game game;

  while(game.isOpen()) {
    game.fixedUpdate();
    game.update();
    game.render();
  }
 
  return 0;
}
