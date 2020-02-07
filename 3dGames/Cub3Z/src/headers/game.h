#pragma once
#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include "utils/overlay.h"

using namespace std;

struct GameStruct {
  int currLvl;
  float currScore;
  int currEnemies;
  int maxEnemies;
  bool levelFinished = false;
};

enum GameModeEnum {
  running,
  paused
};

class Game {
  private:
    const int screenWidth = 1280;
    const int screenHeight = 720;
    GameModeEnum _gameMode;
    GameStruct _gameStruct;

    sf::RenderWindow *_window;
    sf::ContextSettings _contextSettings;
    Overlay* _overlay;

    void init();

  public:
    Game();
    virtual ~Game();
    void Update();
    void Render();
};
