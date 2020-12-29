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
#include "utils/overlay.h"
// #include "utils/audio.h"
#include "../controllers/utils/collision.cpp"
#include "../controllers/utils/audio.cpp"

using namespace std;

struct GameStruct {
  int currLvl;
  float currScore;
  int currEnemies;
  int maxEnemies;
  bool levelFinished = false;
  /* currAmmo @TODO */
};

enum GameModeEnum {
  running,
  paused
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
    sf::Time _enemyTimeElapsed; /* for enemySpawning */
    sf::Clock _enemyClock; /* for enemySpawning */
    sf::Time _trueElapsedTime;
    GameModeEnum _gameMode;
    GameStruct _gameStruct;
    float _secondsPassed;
    float firingDelay = 0.18f;
    bool _isFirstRun = true;
    const bool DEBUG = false;

    sf::Texture _gameOverTexture;
    sf::Sprite _bgSprite;
    sf::Sprite _bgCloudsSprite;
    sf::Sprite _gameOverSprite;
    sf::Music _bgMusic;
    sf::Music _audio00; /* shooting - space_music.ogg */
    sf::Music _audio01; /* onDead - doomed_music.wav */

    sf::Event _event;
    sf::Vector2i _mousePos;
    sf::Vector2f _mouseCoords; /* rel to screen size */
    Player* _player;
    Enemy* _enemy;
    Bullet* _bullet;
    Overlay* _overlay;

    Collision collision;
    Audio audio;
    float playerSpeed = 3.0;

    bool firing = false;
    bool restartGame = false;
    bool introFinished = false;
    
    void init();
    const int getCurrLvl();
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
    const bool isLevelFinished();
    void render();
};
