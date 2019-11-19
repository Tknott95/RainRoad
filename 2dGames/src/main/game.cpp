#include "game.h"

void Game::init() {
 /* Initlialize Variables */
  this->window = nullptr;

 /* Initialize Window */
  this->videoMode.width = 1280;
  this->videoMode.height = 720;

  this->window = new sf::RenderWindow(this->videoMode, "Tks Flatland", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
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
  this->window->display();
}
