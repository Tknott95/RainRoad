#include "../headers/bullet.h"

const float yOffset = 10.f;
 /* @TODO better naming as it is used in two classes and an exyternal var */
/* @TODO create bullet vector, for rapid semi-auto fire bbbyy, maybe auto like a fkn OG */
void Bullet::init(sf::Vector2f startingPos, float halfSprite) {
  this->_bullet.setPosition(startingPos.x + (halfSprite-5) /*+((this->_sprite.getGlobalBounds().width/2)-5)*/, startingPos.y + yOffset /* this->_sprite.getPosition().x, this->_sprite.getPosition().y - 50 */);
   if(!this->_playerBulletTexture.loadFromFile("utils/img/player/b1.png")) {
      std::cout << "ERROR: Could not load utils/img/player/b1.png texture file. \n" << std::endl;
   }
   if(!this->_enemyBulletTexture.loadFromFile("utils/img/enemy/b2.png")) {
      std::cout << "ERROR: Could not load utils/img/enemy/b2.png texture file. \n" << std::endl;
   }
}

void Bullet::spawn(sf::Vector2f startingPos, BulletType bType, float xOffset, float angleToPlayer) {
  if(bType == player) {
    BulletStruct b;
    b.bullet.setTexture(this->_playerBulletTexture);
    b.type = player;
    b.bullet.setPosition(startingPos.x + (xOffset-10) , startingPos.y + yOffset);
    b.bullet.scale(1.4f, 1.2f);
    b.angle = angleToPlayer;
    this->playerBullets.emplace_back(b);
  } else if (bType == enemy) {
    BulletStruct b;
    b.bullet.setTexture(this->_enemyBulletTexture);
    b.bullet.setRotation(angleToPlayer + 90);
    b.type = enemy;
    b.bullet.setPosition(startingPos.x+2.5 , startingPos.y + (yOffset));
    b.bullet.scale(1.7f, 1.7f);
    b.angle = angleToPlayer - 9; /* -9 toCenter onPlayer */ 
    std::string yS = std::to_string(startingPos.y + (yOffset));
    if(!true){
      std::string myPos = "shotOrigin("+ std::to_string(startingPos.x)+", "+yS+") \n";
      std::cout << myPos << std::endl;
    }
    this->enemyBullets.emplace_back(b);
  }
}

Bullet::Bullet() {
  /* @TODO look into constructors for bullets, is it stupid? */
  this->spawnDelay = 0.1f;
  this->clock.restart();
}

Bullet::~Bullet() {
  /* @TODO look into destructors for bullets, is it stupid? */
}

void Bullet::fire(sf::Vector2f startingPos, float halfSprite, float angleToPlayer, BulletType bType) {
  this->elapsedTime = this->clock.getElapsedTime();
  std::cout << " \n  FIRING(" << startingPos.x << ", " << startingPos.y << ")" << std::endl;
  this->spawn(startingPos, bType, halfSprite, angleToPlayer);
}

void Bullet::move(float ySpeed, BulletType bType) {
  if(bType == player) {
    for(auto &b : this->playerBullets) {
      b.bullet.move(0, 1.f * -ySpeed);
    }
  } else if(bType == enemy) {
    for(auto &b : this->enemyBullets) {
      b.bullet.move(cos(b.angle*_pi/180) * ySpeed, sin(b.angle*_pi/180) * ySpeed);
    }
  }
}

void Bullet::erase(int i, BulletType type) {
  if(type == player) {
    this->playerBullets.erase(this->playerBullets.begin() + i);
    std::cout << " \n   erasingPlayerBulletID(" << i << ") \n" << std::endl;
  } else if(type == enemy) {
    this->enemyBullets.erase(this->enemyBullets.begin() + i);
    std::cout << " \n   erasingEnemyBulletID(" << i << ") \n" << std::endl;
  }
}

void Bullet::render(sf::RenderTarget& target) {
  for(auto &b : this->_bullets) {
    target.draw(b);
  }

  for(auto &pB : this->playerBullets) {
    target.draw(pB.bullet);
  }

  for(auto &eB : this->enemyBullets) {
    target.draw(eB.bullet);
  }

}