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

sf::Vector2f Enemy::normalize(const sf::Vector2f& j) {
  float mag = sqrt((j.x * j.x) + (j.y * j.y));
  if(mag != 0) {
    return sf::Vector2f(j.x / mag, j.y / mag);
  } else {
    return j;
  }
}

void Enemy::moveToPlayer(sf::Vector2f playerPos, float enemySpeed) {
  sf::Vector2f direction = this->normalize(playerPos - this->_sprite.getPosition());
  this->_sprite.move(enemySpeed * direction);
}

void Enemy::update() {

}

void Enemy::render(sf::RenderTarget& target) {
  target.draw(this->_sprite);
}
