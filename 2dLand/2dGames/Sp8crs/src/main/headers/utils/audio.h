#include<iostream>
#include <SFML/Audio.hpp>

using namespace std;

class Audio {
  private:
    sf::Music _bgMusic;
    sf::Music _audio00; /* shooting - space_music.ogg */
    sf::Music _audio01; /* onDead - doomed_music.wav */
  public:
    void init();
    void playerMoving();
    void playerShooting();
    void shipDestroyed();
    void enemyShooting(); /* might make this and playerShooting one shooting class with type param */
    void gameOver();
};
