#include "../headers/enemy.h"

/* @TODO create enemy vector, for rapid abduction anal probe bbbyy, maybe cloning for clone wars like a fkn OG */


void Enemy::init() {
  if(!this->_texture.loadFromFile("utils/img/enemy/e1.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }
  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(1.4f, 1.4f);
  this->_sprite.setPosition(600.f, 200.f);

  this->_enemies.push_back(this->_sprite);
}

Enemy::Enemy() {
  this->init();
} /* @TODO MAKE GET POS() FUNCTION */

Enemy::~Enemy() {
}

sf::Vector2f Enemy::normalize(const sf::Vector2f& j) {
  float mag = sqrt((j.x * j.x) + (j.y * j.y));
  std::cout << "\n MAGNITUDE(" << mag << ") \n" << std::endl;
  if(mag != 0) {
    return sf::Vector2f(j.x / mag, j.y / mag);
  } else {
    return j;
  }
}

const bool Enemy::isDead() {
  if(this->currHealth <= 0.f) {
    return true;
  }

  return false;
}

void Enemy::moveToPlayer(sf::Vector2f playerPos, float enemySpeed, sf::Vector2f enemyPos) {
  sf::Vector2f direction = this->normalize(playerPos - enemyPos);
  this->_sprite.move(enemySpeed * direction);
} /* @TODO refactor to make dynamic for _enemies vector, pass in position most likely */

void Enemy::update() {

}

const sf::Vector2f & Enemy::getPos() const {
  return this->_sprite.getPosition();
}

void Enemy::render(sf::RenderTarget& target) {
  target.draw(this->_sprite);
}
