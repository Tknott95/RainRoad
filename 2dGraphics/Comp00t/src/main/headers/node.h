#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Node {
  private:
    const int totalNodes = 1444; /* @TODO | MAKE DYNAMIC w/ vertices[<#>] VARIABLE */
    const float spawnDelay = 0.1f;
    sf::CircleShape _node;
    vector<sf::CircleShape> _nodes;
    sf::Vertex vertices[2000]; /* @TODO | MAKE DYNAMIC w/ TOTALNODES VARIABLE */
    sf::Font _font;
    sf::Text _text;
    // sf::VertexArray lines(sf::PrimitiveType); // THIS IS REPLACED BY DYNAMIC sf::Vertex for meow meow
    // LineStrip // vertexCount Initial number of vertices in the array

    void init();
    void spawn(float, float);

  public:
    Node();
    virtual ~Node();
    void update();
    void render(sf::RenderTarget& target);
};