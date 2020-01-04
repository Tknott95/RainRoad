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
  EnemyStruct e00;
  e00.enemy = this->_sprite;
  e00.health = 100.f;
  e00.text00 = this->_text00;
  this->_enemies.emplace_back(e00); /* replaces push_back due to std::pair usage to track enemy currHealth */
}

Enemy::Enemy() {
  this->init();
  this->spawn(sf::Vector2f(600.f, 200.f));
  this->spawn(sf::Vector2f(1000.f, 200.f));
  this->spawn(sf::Vector2f(333.f, 100.f));
  this->spawn(sf::Vector2f(100.f, 000.f));
  this->spawn(sf::Vector2f(555.f, 300.f));
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
  this->_enemies[eId].health -= dmg;
}

void Enemy::moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed) {
  const sf::Vector2f enemyPos = this->_enemies[enemyId].enemy.getPosition();
  sf::Vector2f direction = this->normalize(playerPos - enemyPos);
  this->_enemies[enemyId].enemy.move(enemySpeed * direction);
} /* @TODO refactor to make dynamic for _enemies vector, pass in position most likely */

void Enemy::update() {
  for(int _j=0;_j < this->_enemies.size();_j++) {
    // if(this->_enemies[_j].health <= 0.f) {
    //   this->delEnemy(_j);
    // }

    /* @TODO refactor this as the text for enemy may need to be inside the vector for external calls on update */
    if(this->_enemies[_j].health < 67.f) {
      this->_enemies[_j].text00.setFillColor(sf::Color(60, 140, 40, 130));
    } else if(this->_enemies[_j].health < 33.f) {
      this->_enemies[_j].text00.setFillColor(sf::Color(140, 60, 40, 120));
      this->_enemies[_j].text00.setString("BIRD IS THE WORD");

    } else if(this->_enemies[_j].health < 10.f) {
      this->_enemies[_j].text00.setFillColor(sf::Color(240, 40, 40, 110));
      /* @TODO why won't this work? Dynamic fill color? I have a struct? it should? or should it baha bja habjabkj */ 
    }
  }
}

const sf::Vector2f & Enemy::getPos() const {
  return this->_sprite.getPosition();
}

void Enemy::render(sf::RenderTarget& target) {
  for(auto &_e : this->_enemies) {
    target.draw(_e.enemy);

    _e.text00.setString(std::to_string(_e.health).substr(0, 5));
    _e.text00.setCharacterSize(22);
    _e.text00.setPosition(_e.enemy.getPosition().x, _e.enemy.getPosition().y - 30.f);
    _e.text00.setFillColor(sf::Color(240, 240, 240, 180));

    target.draw(_e.text00);
  }
}
