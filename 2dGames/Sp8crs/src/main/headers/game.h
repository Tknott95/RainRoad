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

using namespace std;

class Game {
  const int screenWidth = 1280;
  const int screenHeight = 720;
  private:
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    sf::Clock _clock;
    sf::Time _timeElapsed;
    float _secondsPassed;

    sf::Sprite _bgSprite;

    sf::Event _event;
    sf::Vector2i _mousePos;
    sf::Vector2f _mouseCoords; /* rel to screen size in float foramat */
    // float score;
    Player* _player;
    Enemy* _enemy;
    float playerSpeed = 3.0;

    bool firing = false;
    
    void init();

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
