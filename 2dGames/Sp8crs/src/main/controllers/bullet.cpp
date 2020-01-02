#include "../headers/bullet.h"

Bullet::Bullet() {

}

Bullet::~Bullet() {

}

void Bullet::fire(sf::Vector2f startingPos) {
  this->_bullet.setPosition(startingPos.x /*+((this->_sprite.getGlobalBounds().width/2)-5)*/, startingPos.y /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
  this->_bullet.setRadius(5.f);
  this->_bullet.setFillColor(sf::Color::Yellow);
  for(int j=0;j>20;j++) { /* @TODO ADD AN OR W/ A TIME BOOLEAN LOGIC TO CREATE A LERPING STYLE MOVEMENT ON OWN TERMS, NOT FPS */
    this->_bullet.move(0.f, 0.1f + 2.f);
  }
}