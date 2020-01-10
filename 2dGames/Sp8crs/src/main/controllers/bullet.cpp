#include "../headers/bullet.h"

float yOffset = 10.f; /* @TODO better naming as it is used in two classes and an exyternal var */
/* @TODO create bullet vector, for rapid semi-auto fire bbbyy, maybe auto like a fkn OG */
void Bullet::init(sf::Vector2f startingPos, float halfSprite) {
  this->_bullet.setPosition(startingPos.x + (halfSprite-5) /*+((this->_sprite.getGlobalBounds().width/2)-5)*/, startingPos.y + yOffset /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
}

Bullet::Bullet() {
  /* @TODO look into constructors for bullets, is it stupid? */
  this->spawnDelay = 0.1f;
  this->clock.restart();
}

Bullet::~Bullet() {
  /* @TODO look into destructors for bullets, is it stupid? */
}

void Bullet::fire(sf::Vector2f startingPos, float halfSprite) {
  this->elapsedTime = this->clock.getElapsedTime();
  this->_bullet.setPosition(startingPos.x + (halfSprite-5) /*+((this->_sprite.getGlobalBounds().width/2)-5)*/, startingPos.y + yOffset /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
  std::cout << " \n  FIRING(" << startingPos.x << ", " << startingPos.y << ")" << std::endl;
  this->_bullet.setRadius(5.f);
  this->_bullet.setOutlineColor(sf::Color(0,0,0,150));
  this->_bullet.setOutlineThickness(2.3f);
  this->_bullet.setFillColor(sf::Color(230, 230, 190, 140));

  this->_bullets.push_back(this->_bullet);
  // for(int j=0;j<2000;j++  && this->elapsedTime.asSeconds() > this->spawnDelay) { /* @TODO ADD AN OR W/ A TIME BOOLEAN LOGIC TO CREATE A LERPING STYLE MOVEMENT ON OWN TERMS, NOT FPS */
  //   this->_bullet.move(0.f, -.03f);
  //   std::cout << "\n   SECS ELAPSED (" << this->elapsedTime.asSeconds() << ") \n" << std::endl;
  //   std::cout << "\n   (" << this->_bullet.getPosition().x << ", " << this->_bullet.getPosition().y << ") \n" << std::endl;
  //   this->clock.restart();
  // }

  /* @TODO EXTRACT MOVEMENT TO ANOTHER FUNCTION AS IT SEEMS TO NOT WORK INTERNALLY WITH THE SAME FUNCTION INSTANTIATING THE SPRITE, MAY BE ME BEING A FUCKING STUPID FCUKI IDIOTLNDSKJKBVBVBBV */  
}

void Bullet::move(float ySpeed) {
  for(auto &b : this->_bullets) {
    b.move(0, 1.f * -ySpeed);
  }
}

void Bullet::erase(int i) {
  this->_bullets.erase(this->_bullets.begin() + i);
  std::cout << " \n   erasingBulletID(" << i << ") \n" << std::endl;
}

void Bullet::render(sf::RenderTarget& target) {
  for(auto &b : this->_bullets) {
    target.draw(b);
  }
}