#include "game.h"

/* REFACTOR THIS REFACTOR THIS */
void Game::initEnemy() {
  // this->enemy.setPosition();
  this->enemy.setSize(sf::Vector2f(100.f, 100.f));
  this->enemy.setFillColor(sf::Color::Cyan);
  this->enemy.setOutlineColor(sf::Color::Green);
  this->enemy.setOutlineThickness(1.f);
}
/* REFACTOR THIS REFACTOR THIS */

void Game::init() {
 /* Initlialize Variables */
  this->window = nullptr;

 /* Initialize Window */
  this->videoMode.width = 1280;
  this->videoMode.height = 720;

  this->window = new sf::RenderWindow(this->videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
  this->window->setFramerateLimit(88);

  this->initEnemy();
}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->window;
}

const bool Game::isOpen() const {
    return this->window->isOpen();
}

void Game::fixedUpdate() {
  while(this->window->pollEvent(this->event)) {
      switch(this->event.type) {
        case sf::Event::Closed:
          this->window->close();
          break;
        case sf::Event::KeyPressed:
          if(this->event.key.code == sf::Keyboard::Escape){
            cout << "CLOSING WINDOW" << endl;
            this->window->close();
            break;
          }
          if (this->event.key.code == sf::Keyboard::Space){
            cout << "Space PRESSED" << endl;
            break;
          }
          break;
      }
    }
}

void Game::update() {
  this->fixedUpdate();
}

void Game::render() {
  this->window->clear(sf::Color::Blue);
  this->window->draw(this->enemy);
  this->window->display();
}
