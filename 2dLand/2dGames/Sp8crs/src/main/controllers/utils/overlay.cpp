#include "../../headers/utils/overlay.h"

void Overlay::Init(float screenWidth, float screenHeight, int currLevel) {
  if (!this->_font00.loadFromFile("utils/fonts/font02.ttf"))  std::cout << "ERROR: Could not load game - font00.ttf file. \n" << std::endl;
  if (!this->_font01.loadFromFile("utils/fonts/font01.ttf"))  std::cout << "ERROR: Could not load player font file. \n" << std::endl;
  this->currLvl = currLevel;

  this->_text02.setFont(this->_font00);
  this->_text02.setString("Sp8Crs"/*"LEVEL " + to_string(this->currLvl)*/); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text02.setCharacterSize(280);
  this->_text02.setPosition((screenWidth/2)*0.30, screenHeight/2 - 50);
  this->_text02.setFillColor(sf::Color(178,250,245,100));
  this->_text02.setOutlineColor(sf::Color::Black);
  this->_text02.setOutlineThickness(10.f);

  this->_text03.setFont(this->_font00);
  this->_text03.setString("LEVEL FINISHED"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text03.setCharacterSize(140);
  this->_text03.setPosition((screenWidth/2)*0.40, screenHeight/2 - 100);
  this->_text03.setFillColor(sf::Color(178,250,245,130));
  this->_text03.setOutlineColor(sf::Color(0, 0, 0, 100));
  this->_text03.setOutlineThickness(10.2f);

  this->_text04.setFont(this->_font00);
  this->_text04.setString("CONTINUE?"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  this->_text04.setCharacterSize(130);
  this->_text04.setPosition((screenWidth/2)*0.50, screenHeight/2 + 50);
  this->_text04.setFillColor(sf::Color(178, 200, 245, 120));
  this->_text04.setOutlineThickness(10.2f);

  this->_text00.setFont(this->_font00);
  this->_text00.setString("GAME OVER");
  this->_text00.setCharacterSize(130);
  this->_text00.setOutlineColor(sf::Color::Black);
  this->_text00.setOutlineThickness(2.f);
  this->_text00.setPosition((screenWidth/2)*0.35, screenHeight/2 - 200);
  this->_text00.setFillColor(sf::Color(140, 40, 40, 210));

  this->_text01.setFont(this->_font00);
  this->_text01.setString("PLAY AGAIN?");
  this->_text01.setCharacterSize(100);
  this->_text01.setPosition((screenWidth/2)*0.45, screenHeight/2);
  this->_text01.setFillColor(sf::Color(100, 40, 40, 230));

  this->_text05.setFont(this->_font01);
  this->_text05.setString("Current Lvl:    "+std::to_string(this->currLvl));
  this->_text05.setCharacterSize(18);
  this->_text05.setFillColor(sf::Color(255, 255, 255, 175));
  this->_text05.setOutlineColor(sf::Color::Black);
  this->_text05.setPosition(50.f, 150.f);
}

Overlay::Overlay() {

}

Overlay::~Overlay() {

}

bool Overlay::isMousePressedAndContains(sf::Vector2f mousePos, int type) {
  if(type = 4 && this->_text04.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    return true;
  } else {
    return false;
  }
  if(type = 1 && this->_text01.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    return true;
  } else {
    return  false;
  }
}


void Overlay::Update(bool isGameOver, sf::Vector2f mousePos, bool levelFinished, int currLevel) {
  this->levelFinished = levelFinished;
  this->isGameOver = isGameOver;
  this->currLvl = currLevel;
  this->_text05.setString("Current Lvl:    "+std::to_string(this->currLvl));
  /* @TODO FIX_THIS */
  
  if(this->isGameOver &&  this->_text01.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    this->_text01.setFillColor(sf::Color(40, 40, 140, 180));
  } else {
    this->_text01.setFillColor(sf::Color(100, 40, 40, 210));
  }

  if(this->_text04.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    this->_text04.setFillColor(sf::Color(178, 200, 255, 80));
    this->_text04.setOutlineColor(sf::Color(0,0,10,230));
    this->_text04.setOutlineThickness(10.2f);

  } else {
    this->_text04.setFillColor(sf::Color(178, 200, 245, 120));
    this->_text04.setOutlineColor(sf::Color::Black);
    this->_text04.setOutlineThickness(10.2f);
  }
}

void Overlay::Render(sf::RenderTarget& target,bool introFinished, bool levelFinished, bool isGameOver) {
  this->levelFinished = levelFinished;
  this->isGameOver = isGameOver;
  if(introFinished) { 
  } else {
    target.draw(this->_text02);
  }

  if(this->levelFinished) {
    target.draw(this->_text03);
    target.draw(_text04);
  }

  if(introFinished && !this->levelFinished && !isGameOver) {
    target.draw(this->_text05);
  }

  if(isGameOver) {
    target.clear(sf::Color::White);
    if(!this->_gameOverTexture.loadFromFile("./utils/img/bg/game_over.png")) std::cout << "ERROR: Could not load game - /utils/img/bg/game_over.png \n" << std::endl;
    this->_gameOverSprite.setTexture(_gameOverTexture);
    target.draw(_gameOverSprite);
    target.draw(this->_text00);
    target.draw(this->_text01);
  }
}