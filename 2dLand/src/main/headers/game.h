#pragma once
#include <iostream>
#include <ctime>



#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include "enemy.h"

using namespace std;

class Game {
  private:
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;

    sf::Sprite _bgSprite;

    sf::Event _event;
    sf::Vector2i _mousePos;
    sf::Vector2f _mouseCoords; /* rel to screen size in float foramat */
    // float score;
    Enemy enemy;

  public:
    Game();
    virtual ~Game();

    void init();
    
    void setBackground();
    void setMousePos();
    const bool isOpen() const;

    void eventPolling();
    void fixedUpdate();
    void update();
    void render();
};
