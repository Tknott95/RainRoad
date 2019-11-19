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
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    sf::RectangleShape enemy;

  public:
    Game();
    virtual ~Game();

    void init();
    void initEnemy();

    const bool isOpen() const;

    void fixedUpdate();
    void update();
    void render();
};

