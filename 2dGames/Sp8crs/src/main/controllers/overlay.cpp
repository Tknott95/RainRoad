#include "../headers/overlay.h"

void Overlay::Init(float screenWidth, float screenHeight, int currLevel) {
  if (!_font00.loadFromFile("utils/fonts/font02.ttf")) {
    cout << "ERROR: Could not load game - font00.ttf file." << "\n";
  }
  if (!_font01.loadFromFile("utils/fonts/font01.ttf")) {
    std::cout << "ERROR: Could not load player font file." << "\n";
  }
  currLvl = currLevel;

  _text02.setFont(_font00);
  _text02.setString("Sp8Crs"/*"LEVEL " + to_string(currLvl)*/); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  _text02.setCharacterSize(280);
  _text02.setPosition((screenWidth/2)*0.30, screenHeight/2 - 50);
  _text02.setFillColor(sf::Color(178,250,245,100));
  _text02.setOutlineColor(sf::Color::Black);
  _text02.setOutlineThickness(10.f);

  _text03.setFont(_font00);
  _text03.setString("LEVEL FINISHED"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  _text03.setCharacterSize(140);
  _text03.setPosition((screenWidth/2)*0.40, screenHeight/2 - 100);
  _text03.setFillColor(sf::Color(178,250,245,130));
  _text03.setOutlineColor(sf::Color(0, 0, 0, 100));
  _text03.setOutlineThickness(10.2f);

  _text04.setFont(_font00);
  _text04.setString("CONTINUE?"); /* @TODO make this dynamic w/ beginning timer from 3 -> 0 */
  _text04.setCharacterSize(130);
  _text04.setPosition((screenWidth/2)*0.50, screenHeight/2 + 50);
  _text04.setFillColor(sf::Color(178, 200, 245, 120));
  _text04.setOutlineThickness(10.2f);

  _text00.setFont(_font00);
  _text00.setString("GAME OVER");
  _text00.setCharacterSize(130);
  _text00.setOutlineColor(sf::Color::Black);
  _text00.setOutlineThickness(2.f);
  _text00.setPosition((screenWidth/2)*0.25, screenHeight/2 - 200);
  _text00.setFillColor(sf::Color(140, 40, 40, 210));

  _text01.setFont(_font00);
  _text01.setString("PLAY AGAIN?");
  _text01.setCharacterSize(100);
  _text01.setPosition((screenWidth/2)*0.40, screenHeight/2);
  _text01.setFillColor(sf::Color(100, 40, 40, 210));

  _text05.setFont(_font01);
  _text05.setString("Current Lvl:    "+std::to_string(currLvl));
  _text05.setCharacterSize(18);
  _text05.setFillColor(sf::Color(255, 255, 255, 175)); /* switch to rgba .4 opacity @TODO */
  _text05.setOutlineColor(sf::Color::Black);
  _text05.setPosition(50.f, 150.f);
}

Overlay::Overlay() {

}

Overlay::~Overlay() {

}

bool Overlay::isMousePressedAndContains(sf::Vector2i mousePos, int type) {
  if(type = 04 && _text04.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    return true;
  } else {
    return false;
  }
  if(type = 01 && _text01.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    return true;
  } else {
    return  false;
  }
}


void Overlay::Update(bool isGameOver, sf::Vector2i mousePos, bool levelFinished, int currLevel) {
  levelFinished = levelFinished;
  isGameOver = isGameOver;
  currLvl = currLevel;
  _text05.setString("Current Lvl:    "+std::to_string(currLvl));
  /* AFTER GAME TEXT onHOVER() */
  /* @TODO refactor this hack of onHOVER() */
  if(isGameOver && _text01.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    _text01.setFillColor(sf::Color(40, 40, 140, 180));
    // @TODO figure this out .. _audio01.play();
  } else {
    _text01.setFillColor(sf::Color(100, 40, 40, 210));
  }
  /* END AFTER GAME TEXT onHOVER() END */

  /* onHover() 2 needs refactor */
  if(_text04.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
    _text04.setFillColor(sf::Color(178, 200, 255, 80));
  } else {
    _text04.setFillColor(sf::Color(178, 200, 245, 120));
  }
  /* end of onHOver() 2*/
}

void Overlay::Render(sf::RenderTarget& target,bool introFinished, bool levelFinished, bool isGameOver) {
  levelFinished = levelFinished; /* prob rmv lvlFinished in params, right meow to much todo */
  isGameOver = isGameOver;
  if(introFinished) { 
  } else {
    target.draw(_text02);
  }

  if(levelFinished) {
    target.draw(_text03);
    target.draw(_text04);
  }

  if(introFinished && !levelFinished && !isGameOver) {
    target.draw(_text05);
  }

  if(isGameOver) {
    target.clear(sf::Color::White);
    _gameOverTexture.loadFromFile("./utils/img/bg/game_over.png");
    _gameOverSprite.setTexture(_gameOverTexture);
    target.draw(_gameOverSprite);
    target.draw(_text00);
    target.draw(_text01);
  }
}