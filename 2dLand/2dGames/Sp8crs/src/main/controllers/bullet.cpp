#include "../headers/bullet.h"

void Bullet::init(sf::Vector2f startingPos, float halfSprite) {
  this->_bullet.setPosition(startingPos.x + (halfSprite-5), startingPos.y + yOffset);
  if(!this->_playerBulletTexture.loadFromFile("utils/img/player/b1.png")) cout << "ERROR: Could not load utils/img/player/b1.png texture file. \n" << endl;
  if(!this->_enemyBulletTexture.loadFromFile("utils/img/enemy/b2.png")) cout << "ERROR: Could not load utils/img/enemy/b2.png texture file. \n" << endl;
  if(!this->_eShotSound.openFromFile("utils/audio/bullet/l2.ogg")) cout << "ERROR: Could not load utils/audio/bullet/l2.wav audio file." << "\n" << endl;
  if(!this->_eShotDelSound.openFromFile("utils/audio/bullet/d2.ogg")) cout << "ERROR: Could not load utils/audio/bullet/d2.ogg audio file." << "\n" << endl;

  /* @TODO make an audio class - code needs way less lines each file, so, abstraction */
  this->_eShotSound.setVolume(5); /* @TODO each enemy needs own sound */
  /* @TODO need global class for volume setting via. settings screen */
  this->_eShotSound.setPosition(0,0,8);
  this->_eShotDelSound.setVolume(3); /* this is fking dumb, holy earRape */
  this->_eShotDelSound.setPosition(0,0,9);
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
    string yS = to_string(startingPos.y + (yOffset));
    if(!true){
      string myPos = "shotOrigin("+ to_string(startingPos.x)+", "+yS+") \n";
      cout << myPos << endl;
    }
    this->enemyBullets.emplace_back(b);
  }
}

Bullet::Bullet() {
  this->spawnDelay = 0.1f;
  this->clock.restart();
}

Bullet::~Bullet() { }

void Bullet::fire(sf::Vector2f startingPos, float halfSprite, float angleToPlayer, BulletType bType) {
  if(this->DEBUG) cout << " \n  FIRING(" << startingPos.x << ", " << startingPos.y << ")" << endl;
  this->spawn(startingPos, bType, halfSprite, angleToPlayer);
  if(bType == enemy) {
    this->_eShotSound.play();
  }
}

void Bullet::move(const float ySpeed, BulletType bType) {
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
  /* @TODO make impact anim (onDel() | onCol()) */
  if(type == player) {
    this->_eShotDelSound.play();
    this->playerBullets.erase(this->playerBullets.begin() + i);
    if(this->DEBUG) cout << " \n   erasingPlayerBulletID(" << i << ") \n" << endl;
  } else if(type == enemy) {
    this->enemyBullets.erase(this->enemyBullets.begin() + i);
    if(this->DEBUG) cout << " \n   erasingEnemyBulletID(" << i << ") \n" << endl;
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