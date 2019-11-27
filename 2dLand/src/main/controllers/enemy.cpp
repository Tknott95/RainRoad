#include "../headers/enemy.h"

void Enemy::init() {
  this->_enemy.setPosition(50.f, 50.f);
  this->_enemy.setSize(sf::Vector2f(133, 133));
  this->_enemy.setFillColor(sf::Color(40, 40, 104, 200));
  this->_enemy.setOutlineColor(sf::Color::White);
  this->_enemy.setOutlineThickness(1.8f);
}

// Enemy::Enemy() {
//   this->init();
// }

// Enemy::~Enemy() {
//   delete this->_enemy;
// }