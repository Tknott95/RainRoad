#include "../headers/enemy.h"

/* @TODO create enemy vector, for rapid abduction anal probe bbbyy, maybe cloning for clone wars like a fkn OG */


void Enemy::init() {
  if(!this->_texture.loadFromFile("utils/img/enemy/e1.png")) {
    std::cout << "ERROR: Could not load enemy texture file." << "\n";
  }

  if (!this->_font00.loadFromFile("utils/fonts/font01.ttf")) {
    std::cout << "ERROR: Could not load enemy font file." << "\n";
  }

  this->_text00.setFont(this->_font00);


  this->_sprite.setTexture(this->_texture);
  this->_sprite.scale(1.4f, 1.4f);
}

void Enemy::spawn(sf::Vector2f pos) {
  if(&pos.x == NULL || &pos.y == NULL) {
    pos. x = 600.f;
    pos.y = 200.f;
  }

  this->_sprite.setPosition(pos.x, pos.y);
  this->_enemies.emplace_back(100.f, this->_sprite); /* replaces push_back due to std::pair usage to track enemy currHealth */
}

Enemy::Enemy() {
  this->init();
  this->spawn(sf::Vector2f(600.f, 200.f));
  this->spawn(sf::Vector2f(1000.f, 200.f));
  this->spawn(sf::Vector2f(000.f, 200.f));
  this->spawn(sf::Vector2f(100.f, 000.f));
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
  // if(this->currHealth <= 0.f) {
  //   return true;
  // }

  return false;
}

 void Enemy::delEnemy(int eId) {
   this->_enemies.erase(this->_enemies.begin() + eId);
 }

void Enemy::takeDmg(int eId, float dmg) {
  this->_enemies[eId].first -= dmg;
}

void Enemy::moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed) {
  const sf::Vector2f enemyPos = this->_enemies[enemyId].second.getPosition();
  sf::Vector2f direction = this->normalize(playerPos - enemyPos);
  this->_enemies[enemyId].second.move(enemySpeed * direction);
} /* @TODO refactor to make dynamic for _enemies vector, pass in position most likely */

void Enemy::update() {
  for(int _j=0;_j < this->_enemies.size();_j++) {
    if(this->_enemies[_j].first <= 0.f) {
      this->delEnemy(_j);
    }
  }
}

const sf::Vector2f & Enemy::getPos() const {
  return this->_sprite.getPosition();
}

void Enemy::render(sf::RenderTarget& target) {
  for(auto &_e : this->_enemies) {
    target.draw(_e.second);

    this->_text00.setString(std::to_string(_e.first));
    this->_text00.setCharacterSize(30);
    this->_text00.setPosition( _e.second.getPosition().x, _e.second.getPosition().y - 30.f);
    this->_text00.setFillColor(sf::Color(140, 40, 40, 210));
    target.draw(this->_text00);
  }
}
