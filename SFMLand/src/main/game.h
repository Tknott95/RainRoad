#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class Game {
  private:

  public:
    Game();
    virtual ~Game();

    void fixedUpdate();
    void update();
    void render();
};

