#include "../headers/game.h"


void Game::init() {
  this->_gameMode = running;
}

Game::Game() {
  this->init();
}

Game::~Game() {
  
}