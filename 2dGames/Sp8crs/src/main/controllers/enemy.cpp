#include "../headers/enemy.h"

void Enemy::init() {
  if(!this->_texture.loadFromFile("utils/img/enemy/e1.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }
  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(1.4f, 1.4f);
  this->_sprite.setPosition(600.f, 200.f);
}

Enemy::Enemy() {
  this->init();
}

Enemy::~Enemy() {
}

void Enemy::update() {

}

void Enemy::render(sf::RenderTarget& target) {
  target.draw(this->_sprite);
}
