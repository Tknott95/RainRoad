#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;

class Overlay {
  private:
    sf::Font _font00;
    sf::Font _font01;
    /* @TODO maybe use vector/array logic 4 readability */
    sf::Text _text00; /* GAME OVER */
    sf::Text _text01; /* PLAY AGAIN */
    sf::Text _text02; /* LEVEL <#> - BEGIN IN <3... 2... 1...> @TODO */
    sf::Text _text03; /* LEVEL 1 COMPLETE */
    sf::Text _text04; /* GO TO NEXT LEVEL? */
    sf::Text _text05; /* CURRENT LVL */
    sf::Texture _gameOverTexture;
    sf::Sprite _gameOverSprite;
    bool levelFinished;
    bool isGameOver;
    int currLvl;
    

  public:
    Overlay();
    virtual ~Overlay();

    void Init(float screenWidth, float screenHeight, int currLevel);
    bool isMousePressedAndContains(sf::Vector2f mousePos,int type);
    void Update(bool isGameOver, sf::Vector2f mousePos, bool levelFinished, int currLevel);
    void Render(sf::RenderTarget& target,bool introFinished, bool levelFinished, bool isGameOver);
};
