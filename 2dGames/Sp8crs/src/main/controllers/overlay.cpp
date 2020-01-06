#include "./headers/overlay.h"

void Overlay::init(float screenWidth, float screenHeight) {
  if (!this->_font00.loadFromFile("utils/fonts/font00.ttf")) {
    cout << "ERROR: Could not load game - font00.ttf file." << "\n";
  }

  this->_text02.setFont(this->_font00);
  this->_text02.setString("LEVEL " + to_string(this->_gameStruct.currLvl)); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text02.setCharacterSize(180);
  this->_text02.setPosition((screenWidth/2)*0.40, screenHeight/2 - 200);
  this->_text02.setFillColor(sf::Color(178,250,245,100));
  this->_text02.setOutlineColor(sf::Color::Black);
  this->_text02.setOutlineThickness(2.f);

  this->_text03.setFont(this->_font00);
  this->_text03.setString("LEVEL FINISHED"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text03.setCharacterSize(90);
  this->_text03.setPosition((screenWidth/2)*0.40, screenHeight/2 - 100);
  this->_text03.setFillColor(sf::Color(178,250,245,130));
  this->_text03.setOutlineColor(sf::Color(0, 0, 0, 100));
  this->_text03.setOutlineThickness(10.2f);

  this->_text04.setFont(this->_font00);
  this->_text04.setString("CONTINUE?"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text04.setCharacterSize(70);
  this->_text04.setPosition((screenWidth/2)*0.50, screenHeight/2 + 50);
  this->_text04.setFillColor(sf::Color(178, 200, 245, 120));
  this->_text04.setOutlineThickness(10.2f);

  this->_text00.setFont(this->_font00);
  this->_text00.setString("GAME OVER");
  this->_text00.setCharacterSize(130);
  this->_text00.setPosition((screenWidth/2)*0.25, screenHeight/2 - 200);
  this->_text00.setFillColor(sf::Color(140, 40, 40, 210));

  this->_text01.setFont(this->_font00);
  this->_text01.setString("PLAY AGAIN?");
  this->_text01.setCharacterSize(100);
  this->_text01.setPosition((screenWidth/2)*0.40, screenHeight/2);
  this->_text01.setFillColor(sf::Color(100, 40, 40, 210));
}

Overlay::Overlay() {

}

Overlay::~Overlay() {

}

void Overlay::Update() {

}

void Overlay::Render(sf::RenderTarget& target) {

}