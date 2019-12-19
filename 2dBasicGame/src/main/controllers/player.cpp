#include "../headers/player.h"


void Player::init() {

  if(!this->_texture.loadFromFile("utils/sprite.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }

  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(0.1f, 0.1f);

  this->movementSpeed = 1.f;
  this->attackWait = 1.f;
}

Player::Player() {
  this->init();
}

Player::~Player() {

}

const sf::Vector2f & Player::getPos() const {
  return this->_sprite.getPosition();
}

void Player::move(const float dirX, const float dirY) {
  this->_sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->_sprite);
}