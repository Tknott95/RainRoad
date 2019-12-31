#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Node {
  private:
    const int totalNodes = 100;
    const float spawnDelay = 0.1f;
    sf::CircleShape _node;
    vector<sf::CircleShape> _nodes;
    sf::Font _font;
    sf::Text _text;

    void init();
    void spawn(float, float);
    void update();

  public:
    Node();
    virtual ~Node();
    void render(sf::RenderTarget& target);
};