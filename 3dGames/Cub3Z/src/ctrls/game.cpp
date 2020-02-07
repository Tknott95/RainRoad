#include "../headers/game.h"


void Game::init() {
  this->_gameMode = running;

  this->_contextSettings.depthBits = 24;
  this->_contextSettings.stencilBits = 8;
  this->_contextSettings.antialiasingLevel = 4;
  this->_contextSettings.majorVersion = 3;
  this->_contextSettings.minorVersion = 0;
  this->_window = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight), "Cub3Z", sf::Style::Default, this->_contextSettings);

  this->_window->setVerticalSyncEnabled(true);
  this->_window->setActive(true);
  // this->_window = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight, 64), "Cub3Z");

  this->_overlay = new Overlay();
}

Game::Game() {
  this->init();
}

Game::~Game() {
  delete this->_window;
  delete this->_overlay;
}

const bool Game::IsOpen() const {
  return this->_window->isOpen();
}

void Game::EventPolling() {
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
        break;
    }
  }
}

void Game::Update() {
  this->EventPolling();
}

void Game::Render() {
  this->_window->display();

  this->_overlay->Init(this->screenWidth, this->screenHeight);
  this->_overlay->Render(*this->_window);
}
