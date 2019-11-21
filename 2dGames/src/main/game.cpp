#include "game.h"

/* REFACTOR THIS REFACTOR THIS */
void Game::initEnemy() {
  this->enemy.setPosition(50.f, 50.f);
  this->enemy.setSize(sf::Vector2f(133, 133));
  this->enemy.setFillColor(sf::Color(40, 40, 104, 100));
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.f);
}
/* REFACTOR THIS REFACTOR THIS */

void Game::init() {
/* Initalize Vars */
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

void Game::setMousePos() {
  this->mousePos = sf::Mouse::getPosition(*this->window);
  /* call *this->window inside getPosition() for relative pos to window */
  cout << "MOUSE POS: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
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

  this->setMousePos();
}

void Game::update() {
  this->fixedUpdate();
}

void Game::render() {
  this->window->clear(sf::Color::Black);
  this->window->draw(this->enemy);
  this->window->display();
}
