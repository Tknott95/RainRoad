#include "../../headers/utils/overlay.h"

void Overlay::Init(float screenWidth, float screenHeight) {
  if (!this->_font00.loadFromFile("utils/fonts/font01.ttf"))  std::cout << "ERROR: Could not load game - font00.ttf file. \n" << std::endl;
  if (!this->_font01.loadFromFile("utils/fonts/font01.ttf"))  std::cout << "ERROR: Could not load player font file. \n" << std::endl;

  
  this->_text00.setFont(this->_font00);
  this->_text00.setString("Cub3Z");
  this->_text00.setCharacterSize(12);
  this->_text00.setOutlineColor(sf::Color::Black);
  this->_text00.setOutlineThickness(2.f);
  this->_text00.setPosition(20, 10);
  // this->_text00.setPosition((screenWidth/2)*0.35, screenHeight/2 - 200);
  this->_text00.setFillColor(sf::Color(40, 140, 240, 110));

  this->_text01.setFont(this->_font00);
  this->_text01.setCharacterSize(12);
  this->_text01.setPosition(20, screenHeight-50);
  // this->_text01.setPosition((screenWidth/2)*0.45, screenHeight/2);
  this->_text01.setFillColor(sf::Color(40, 140, 240, 10));
  
}

Overlay::Overlay() {
  this->_clock00.restart();
  // this->_timeElapsed00 = this->_clock00.getElapsedTime();
}

Overlay::~Overlay() {

}

void Overlay::Update() {
  this->_timeElapsed00 = this->_clock00.getElapsedTime();
  std::cout << "\n FRAME HIT(" << this->_timeElapsed00.asSeconds() << ")\n" << std::endl;
  this->_text01.setString(/*"TimeElapsed: "+ std::to_string(this->_timeElapsed00.asSeconds())*/ "nil, bitch");

}

void Overlay::Render(sf::RenderTarget& target) {
  target.draw(this->_text00);
  target.draw(this->_text01);
}