#pragma once
#include <SFML/Graphics.hpp>

#include <vector> /* Look into standard include methodology for c++ */
#include <iostream>

using namespace std;
class Node {
  private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Clock clock;
    sf::Time elapsedTime;

    float spawnTimer;
    float spawnDelay;
    int maxNodes;

  public:
    std::vector<sf::RectangleShape> nodes;
    sf::RectangleShape _node;

    void init();
    void spawn();
    void update();
    void run();
};
