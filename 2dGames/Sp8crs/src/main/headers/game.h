#pragma once
#include <iostream>
#include <ctime>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "../controllers/collision.cpp"

using namespace std;

struct GameStruct {
  int currLvl;
  float currScore;
  int currEnemies;
  int maxEnemies;
  /* currAmmo @TODO */
};

enum GameModeEnum {
  running,
  paused,
  guiOverlay
};


class Game {
  const int screenWidth = 1280;
  const int screenHeight = 720;
  private:
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Clock _clock;
    sf::Time _timeElapsed;
    sf::Clock _trueClock;
    sf::Time _trueElapsedTime;
    GameModeEnum _gameMode;
    GameStruct _gameStruct;
    float _secondsPassed;
    float firingDelay = 0.2f;
    bool _isFirstRun = true;

    sf::Sprite _bgSprite;
    sf::Sprite _bgCloudsSprite;
    sf::Music _bgMusic;
    sf::Music _audio00; /* shooting - space_music.ogg */
    sf::Music _audio01; /* onDead - doomed_music.wav */
    sf::Font _font00;
    /* @TODO maybe use vector/array logic 4 readability */
    sf::Text _text00; /* GAME OVER */
    sf::Text _text01; /* PLAY AGAIN */
    sf::Text _text02; /* LEVEL <#> - BEGIN IN <3... 2... 1...> @TODO */
    sf::Text _text03; /* LEVEL 1 COMPLETE */
    sf::Text _text04; /* GO TO NEXT LEVEL? */

    sf::Event _event;
    sf::Vector2i _mousePos;
    sf::Vector2f _mouseCoords; /* rel to screen size in float foramat */
    // float score;
    Player* _player;
    Enemy* _enemy;
    Bullet* _bullet;

    Collision collision;
    float playerSpeed = 3.0;

    bool firing = false;
    bool restartGame = false;
    bool introFinished = false;
    const bool DEBUG = false;
    
    void init();
    const bool isGameOver();  

  public:
    Game();
    virtual ~Game();

    
    
    void setBackground();
    void setMousePos();
    const bool isOpen() const;

    void eventPolling();
    void fixedUpdate();
    void update();
    void render();
};
