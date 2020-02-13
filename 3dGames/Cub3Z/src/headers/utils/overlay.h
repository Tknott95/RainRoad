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
    sf::Text _text00; /* GAME OVER */
    sf::Text _text01; /* PLAY AGAIN */
    sf::Clock _clock00;
    sf::Time _timeElapsed00;
  public:
    Overlay();
    virtual ~Overlay();

    void Init(float screenWidth, float screenHeight);
    void Update();
    void Render(sf::RenderTarget& target);
};