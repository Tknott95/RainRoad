#include "../headers/player.h"


void Player::init() {

  if(!this->_texture.loadFromFile("utils/sprite.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }

  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(0.4f, 0.4f);
  this->_sprite.setPosition(674.f, 600.f);

  this->movementSpeed = 2.f;
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

void Player::move(const float x, const float y) {
  this->_sprite.move(this->movementSpeed * x, this->movementSpeed * y);
}

void Player::shoot() {

  this->_bullet.setPosition( 50.f, 50.f /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
  this->_bullet.setRadius(5.f);
  this->_bullet.setFillColor(sf::Color::Yellow);
  this->_bullet.move(0.f,  10.f);
}

void Player::render(sf::RenderTarget& target) {
	target.draw(this->_sprite);
}