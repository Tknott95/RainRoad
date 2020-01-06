#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Overlay {
  private:
    sf::Font _font00;
    /* @TODO maybe use vector/array logic 4 readability */
    sf::Text _text00; /* GAME OVER */
    sf::Text _text01; /* PLAY AGAIN */
    sf::Text _text02; /* LEVEL <#> - BEGIN IN <3... 2... 1...> @TODO */
    sf::Text _text03; /* LEVEL 1 COMPLETE */
    sf::Text _text04; /* GO TO NEXT LEVEL? */
    void init(float, float);

  public:
    Overlay();
    virtual ~Overlay();

    void Update();
    void Render(sf::RenderTarget& target);
};
