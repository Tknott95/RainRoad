#pragma once
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

using namespace std;

class Game {
  private:
    sf::RenderWindow* _window;
    sf::VideoMode _videoMode;
    
    sf::Texture _bgTexture;
    sf::Sprite _bgSprite;

    sf::Event _event;
    sf::Vector2i _mousePos;
    sf::RectangleShape _enemy;

  public:
    Game();
    virtual ~Game();

    void init();
    void initEnemy();
    
    void setBackground();
    void setMousePos();
    const bool isOpen() const;

    void eventPolling();
    void fixedUpdate();
    void update();
    void render();
};
