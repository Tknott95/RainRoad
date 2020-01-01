#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Node {
  private:
    const int totalNodes = 30;
    const float spawnDelay = 0.1f;
    sf::CircleShape _node;
    vector<sf::CircleShape> _nodes;
    sf::Font _font;
    sf::Text _text;
    // sf::VertexArray lines(sf::PrimitiveType);
    // LineStrip // vertexCount Initial number of vertices in the array

    void init();
    void spawn(float, float);
    void update();

  public:
    Node();
    virtual ~Node();
    void render(sf::RenderTarget& target);
};