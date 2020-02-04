#include "../headers/game.h"


void Game::init() {
  this->_gameMode = running;

  this->_window = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight, 64), "Cub3Z");

}

Game::Game() {
  this->init();
}

Game::~Game() {
  
}