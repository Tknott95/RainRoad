#include "game.h"

/* REFACTOR THIS REFACTOR THIS */
void Game::initEnemy() {
  this->_enemy.setPosition(50.f, 50.f);
  this->_enemy.setSize(sf::Vector2f(133, 133));
  this->_enemy.setFillColor(sf::Color(40, 40, 104, 100));
  this->_enemy.setOutlineColor(sf::Color::White);
  this->_enemy.setOutlineThickness(1.f);
}
/* REFACTOR THIS REFACTOR THIS */

void Game::init() {
/* Initalize Vars */
  this->_window = nullptr;

 /* Initialize _window */
  this->_videoMode.width = 1280;
  this->_videoMode.height = 720;

  this->_window = new sf::RenderWindow(this->_videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->_window->setFramerateLimit(88);

 /* refactor full enemy methodology
  for better abstraction */
  this->initEnemy();
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

void Game::setMousePos() {
  this->_mousePos = sf::Mouse::getPosition(*this->_window);
  /* call *this->_window inside getPosition() for relative pos to _window */
  cout << "MOUSE POS: " << sf::Mouse::getPosition(*this->_window).x << " " << sf::Mouse::getPosition(*this->_window).y << "\n";
}

void Game::eventPolling() {
  while(this->_window->pollEvent(this->_event)) {
      switch(this->_event.type) {
        case sf::Event::Closed:
          this->_window->close();
          break;
        case sf::Event::KeyPressed:
          if(this->_event.key.code == sf::Keyboard::Escape){
            cout << "CLOSING _window" << endl;
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
}

void Game::update() {

}

void Game::render() {
  this->_window->clear(sf::Color::Black);
  this->_window->draw(this->_enemy);
  this->_window->display();
}
