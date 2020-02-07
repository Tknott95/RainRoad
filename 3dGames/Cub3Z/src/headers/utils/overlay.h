#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Overlay {
  private:
    sf::Font _font00;
    sf::Font _font01;
    /* @TODO maybe use vector/array logic 4 readability */
    // vector<sf::Text> myText;//  ??? */
    sf::Text _text00; /* GAME OVER */
    sf::Text _text01; /* PLAY AGAIN */
    // sf::Texture _gameOverTexture;
    // sf::Sprite _gameOverSprite; 

  public:
    Overlay();
    virtual ~Overlay();

    void Init(float screenWidth, float screenHeight);
    void Update();
    void Render(sf::RenderTarget& target);
};