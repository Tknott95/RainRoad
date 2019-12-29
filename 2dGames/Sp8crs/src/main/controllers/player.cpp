#include "../headers/player.h"


void Player::init() {

  if(!this->_texture.loadFromFile("utils/img/player/medfighter.png")) {
    std::cout << "ERROR: Could not load player texture file." << "\n";
  }
  if (!this->font.loadFromFile("utils/fonts/Orbitron-Bold.ttf"))
  {
    std::cout << "ERROR: Could not load player font file." << "\n";
  }

  this->text.setFont(font);
  this->text.setString(std::to_string(this->curHealth));
  this->text.setCharacterSize(24);
  this->text.setFillColor(sf::Color::White); /* switch to rgba .4 opacity @TODO */

  

  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(1.4f, 1.4f);
  this->_sprite.setPosition(674.f, 600.f);
  this->_sprite.setRotation(359);


  this->movementSpeed = 2.f;
  this->attackWait = 1.f;
}

Player::Player() {
  this->init();
}

Player::~Player() {

}

void Player::update() {
  if(this->curHealth <= 0.0) {
    this->curHealth = 0.0;
  }
  this->text.setString(std::to_string(this->curHealth));
}

const sf::Vector2f & Player::getPos() const {
  return this->_sprite.getPosition();
}

void Player::move(const float x, const float y) {
  this->_sprite.move(this->movementSpeed * x, this->movementSpeed * y);
}

void Player::takeDmg(const float amount) {
  this->curHealth -= amount;
}

void Player::displayHealth() {
  // this->curHealth;
} 

void Player::shoot() {
  this->_bullet.setPosition(this->_sprite.getPosition().x + ((this->_sprite.getGlobalBounds().width/2) -5), this->_sprite.getPosition().y /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
  this->_bullet.setRadius(5.f);
  this->_bullet.setFillColor(sf::Color::Yellow);
  this->_bullet.move(0.f, 0.1f + 2.f);
}

void Player::render(sf::RenderTarget& target) {
  target.draw(this->text);
  target.draw(this->_bullet);
	target.draw(this->_sprite);
}
