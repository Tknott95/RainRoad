#include "../headers/enemy.h"

void Enemy::init() {
  if(!this->_texture.loadFromFile("utils/img/enemy/e1.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }
  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(0.4f, 0.4f);
  this->_sprite.setPosition(200.f, 200.f);
}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::update() {

}

void Enemy::render(sf::RenderTarget& target) {

}
