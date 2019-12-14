#include "../headers/game.h"

void Game::init() {
  this->_videoMode.width = 1280;
  this->_videoMode.height = 720;

  this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->_window->setFramerateLimit(88);

  this->enemy.init();

}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;
}

const bool Game::isOpen() const {
  return this->_window->isOpen();
}

void Game::setBackground() {
  sf::Texture bgTexture;
  bgTexture.loadFromFile("./utils/background.jpg");
  sf::Vector2u size = bgTexture.getSize();
  this->_bgSprite.setTexture(bgTexture);
  this->_window->draw(this->_bgSprite);
}

void Game::setMousePos() {
  this->_mousePos = sf::Mouse::getPosition(*this->_window);
  this->_mouseCoords = this->_window->mapPixelToCoords(this->_mousePos);
  /* call *this->_window inside getPosition() for relative pos to _window */
  cout << "COORDS MOUSE POS: " << this->_mouseCoords.x << " " << this->_mouseCoords.y << "\n";
  cout << "MOUSE POS: " << this->_mousePos.x << " " << this->_mousePos.y << "\n";
}

void Game::eventPolling() {
  while(this->_window->pollEvent(this->_event)) {
      switch(this->_event.type) {
        case sf::Event::Closed:
          this->_window->close();
          break;
        case sf::Event::KeyPressed:
          if(this->_event.key.code == sf::Keyboard::Escape){
            cout << "\n CLOSING WINDOW \n" << endl;
            this->_window->close();
            break;
          }
          if (this->_event.key.code == sf::Keyboard::Space){
            cout << "Space PRESSED" << endl;
            break;
          }
          break;
      }
    }
}

void Game::fixedUpdate() {
  this->eventPolling();
  this->setMousePos();
   this->enemy.run();
}

void Game::update() {
 
}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->setBackground();
  for(auto &e : enemy.enemies) {
    this->_window->draw(e);
  }
  this->_window->display();
}
