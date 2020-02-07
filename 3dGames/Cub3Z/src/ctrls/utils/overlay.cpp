#include "../../headers/utils/overlay.h"

void Overlay::Init(float screenWidth, float screenHeight) {
  if (!this->_font00.loadFromFile("utils/fonts/alien.ttf"))  std::cout << "ERROR: Could not load game - font00.ttf file. \n" << std::endl;
  if (!this->_font01.loadFromFile("utils/fonts/alien.ttf"))  std::cout << "ERROR: Could not load player font file. \n" << std::endl;

  this->_text00.setFont(this->_font00);
  this->_text00.setString("GAME OVER");
  this->_text00.setCharacterSize(40);
  this->_text00.setOutlineColor(sf::Color::Black);
  this->_text00.setOutlineThickness(2.f);
  this->_text00.setPosition(10, 10);
  // this->_text00.setPosition((screenWidth/2)*0.35, screenHeight/2 - 200);
  this->_text00.setFillColor(sf::Color(40, 40, 240, 210));

  this->_text01.setFont(this->_font00);
  this->_text01.setString("TimeElapsed:    "); // +std::to_string(0.0));
  this->_text01.setCharacterSize(30);
  this->_text00.setPosition(10, 40);
  // this->_text01.setPosition((screenWidth/2)*0.45, screenHeight/2);
  this->_text01.setFillColor(sf::Color(40, 40, 240, 230));
}

Overlay::Overlay() {

}

Overlay::~Overlay() {

}

void Overlay::Update() {
  this->_text01.setString("TimeElapsed:    "+std::to_string(0.0));
}

void Overlay::Render(sf::RenderTarget& target) {
  target.clear(sf::Color::Cyan);
  target.draw(this->_text00);
  target.draw(this->_text01);
}