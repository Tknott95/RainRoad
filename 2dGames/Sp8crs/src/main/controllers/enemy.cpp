#include "../headers/enemy.h"

/* @TODO create enemy vector, for rapid abduction anal probe bbbyy, maybe cloning for clone wars like a fkn OG */


void Enemy::init() {

  if (!this->_font00.loadFromFile("utils/fonts/font01.ttf")) {
    cout << "ERROR: Could not load enemy font file." << "\n";
  }

  this->_text00.setFont(this->_font00);
}

void Enemy::spawn(sf::Vector2f pos, EnemyType eType) {
  EnemyStruct e00;
  if(&pos.x == NULL || &pos.y == NULL) {
    pos. x = 600.f;
    pos.y = 200.f;
  }

  if(eType == kamikaze) {
    if(!this->_texture00.loadFromFile("utils/img/enemy/e1.png")) {
      cout << "ERROR: Could not load enemy texture file." << "\n";
    }
    e00.enemy.setTexture(this->_texture00);
    e00.enemy.scale(1.3f, 1.28f);
  } else if(eType == sheriff) {
    if(!this->_texture01.loadFromFile("utils/img/enemy/e2.png")) {
        cout << "ERROR: Could not load enemy texture file." << "\n";
    }
    e00.enemy.scale(0.58f, 0.74f);
    e00.enemy.setTexture(this->_texture01);     
    const sf::Vector2f _orgn = {50, 0};
    e00.enemy.setOrigin(_orgn);
  }

  e00.enemy.setPosition(pos.x, pos.y);

  e00.health = 100.f;
  e00.text00 = this->_text00;
  e00.type = eType;
  this->_enemies.emplace_back(e00); /* replaces push_back due to std::pair usage to track enemy currHealth */
}

void Enemy::spawner(int currLvl) {
  if(currLvl == 1) {
    // this->spawn(sf::Vector2f(600.f, 200.f), kamikaze);
    // this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(100.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(555.f, 300.f), sheriff); 
    /* @TODO create lookAtPlayer() then a case/if statement to choose which to run regarding type */
  } else if (currLvl == 2) {
    this->spawn(sf::Vector2f(80.f, 200.f), sheriff);
    this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(100.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(755.f, 170.f), sheriff);
    this->spawn(sf::Vector2f(220.f, 150.f), kamikaze);
  } else if (currLvl == 3) { /* @TODO create new types of enemies w/ the enum made a few days prior */
    this->spawn(sf::Vector2f(600.f, 200.f), sheriff);
    this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(100.f, 000.f), sheriff);
    this->spawn(sf::Vector2f(555.f, 170.f), kamikaze);
    this->spawn(sf::Vector2f(220.f, 150.f), sheriff);
    this->spawn(sf::Vector2f(1100.f, 130.f), kamikaze);
    this->spawn(sf::Vector2f(1333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(340.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(755.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(600.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    // this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    // this->spawn(sf::Vector2f(100.f, 000.f), kamikaze);
    // this->spawn(sf::Vector2f(555.f, 300.f), kamikaze);
  } else if (currLvl == 3) {
    this->spawn(sf::Vector2f(600.f, 200.f), sheriff);
    this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(100.f, 000.f), sheriff);
    this->spawn(sf::Vector2f(555.f, 170.f), kamikaze);
    this->spawn(sf::Vector2f(220.f, 150.f), sheriff);
    this->spawn(sf::Vector2f(1100.f, 130.f), kamikaze);
    this->spawn(sf::Vector2f(1333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(340.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(755.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(600.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(1000.f, 200.f), sheriff);
    this->spawn(sf::Vector2f(333.f, 100.f), sheriff);
    this->spawn(sf::Vector2f(100.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(555.f, 300.f), sheriff);
    this->spawn(sf::Vector2f(1000.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(100.f, 000.f), sheriff);
    this->spawn(sf::Vector2f(555.f, 170.f), kamikaze);
    this->spawn(sf::Vector2f(220.f, 150.f), sheriff);
    this->spawn(sf::Vector2f(1100.f, 130.f), kamikaze);
    this->spawn(sf::Vector2f(1333.f, 100.f), kamikaze);
    this->spawn(sf::Vector2f(340.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(755.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(600.f, 200.f), kamikaze);
    this->spawn(sf::Vector2f(1000.f, 200.f), sheriff);
    this->spawn(sf::Vector2f(333.f, 100.f), sheriff);
    this->spawn(sf::Vector2f(100.f, 000.f), kamikaze);
    this->spawn(sf::Vector2f(555.f, 300.f), sheriff);
  }
}

Enemy::Enemy() {
  this->init();
}

Enemy::~Enemy() {
}

sf::Vector2f Enemy::normalize(const sf::Vector2f& j) {
  float mag = sqrt((j.x * j.x) + (j.y * j.y));
  if(!true) cout << "\n MAGNITUDE(" << mag << ") \n" << endl;
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
  /* @TODO make destruction sound onDel() */
  this->_enemies.erase(this->_enemies.begin() + eId);
}

void Enemy::takeDmg(int eId, float dmg) {
  this->_enemies[eId].health -= dmg;
}

const EnemyType Enemy::getType(int eId) {
  return this->_enemies[eId].type;
}

void Enemy::lookAtPlayer(int enemyId, sf::Vector2f playerPos) {
  sf::Vector2f enemyPos = this->_enemies[enemyId].enemy.getPosition();
  float halfX = this->_enemies[enemyId].enemy.getGlobalBounds().width/2;
  float halfY = this->_enemies[enemyId].enemy.getGlobalBounds().height/2;
  const float angleForwardOffset = 90; /* @TODO if adding another function call make this a param for dynamic sets */

  /* @TODO rotateFromOrigin() currently not twerking /()()\ */
  // sf::Vector2f origin = this->_enemies[enemyId].enemy.getOrigin(); 
  // cout << "\n   Origin(" << origin.x << ", " << origin.y << ")  \n" << endl;
  // this->_enemies[enemyId].enemy.setOrigin(origin.x, origin.y);

  /* @TODO dblCheck halfX, halfY logic */
  float myAngle = atan2(playerPos.y - (enemyPos.y - halfY), playerPos.x - (enemyPos.x - halfX)) * 180 / 3.145;
  this->_enemies[enemyId].enemy.setRotation(myAngle + angleForwardOffset);
  if(!true) cout << "\n   myAngle(" << myAngle << ")  \n" << endl;
}

const float Enemy::getAngleToPlayer(int enemyId, sf::Vector2f playerPos) {
  sf::Vector2f enemyPos = this->_enemies[enemyId].enemy.getPosition();
  float halfX = this->_enemies[enemyId].enemy.getGlobalBounds().width/2;
  float halfY = this->_enemies[enemyId].enemy.getGlobalBounds().height/2;

  // sf::Vector2f origin = this->_enemies[enemyId].enemy.getOrigin(); 
  // cout << "\n   Origin(" << origin.x << ", " << origin.y << ")  \n" << endl;
  // this->_enemies[enemyId].enemy.setOrigin(origin.x, origin.y);

  /* @TODO dblCheck halfX, halfY logic */
  float myAngle = atan2(playerPos.y - enemyPos.y, playerPos.x - enemyPos.x) * 180 / 3.145;
  return myAngle;
}

const sf::Vector2f Enemy::getPosById(int eId) {
  return this->_enemies[eId].enemy.getPosition();
}

void Enemy::moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed) {
  const sf::Vector2f enemyPos = this->_enemies[enemyId].enemy.getPosition();
  sf::Vector2f direction = this->normalize(playerPos - enemyPos);
  this->_enemies[enemyId].enemy.move(enemySpeed * direction * this->enemySpeedAmplifier);
} /* @TODO refactor to make dynamic for _enemies vector, pass in position most likely */

void Enemy::update(int currLvl) {
  this->currLvl = currLvl;
  if(this->currLvl == 2) {
    this->enemySpeedAmplifier = 0.3;
  } else if (this->currLvl == 3) {
    this->enemySpeedAmplifier = 0.8;
  }
  
  const int newRand = (rand() % 20);
  for(int _j=0;_j < this->_enemies.size();_j++) {
    if(this->_enemies[_j].type == sheriff) {
      if(newRand % 4 == 0 && this->_enemies[_j].enemy.getPosition().y < 100) { /* @TODO bring in screen size as sf::vector2f, possibly make one a var instead of 2 floats in game class */
        this->_enemies[_j].enemy.move(-0.1f, -0.4f);
      } else if(newRand % 3 == 0) {
        this->_enemies[_j].enemy.move(0.001f, 0.2f);
      }
    }
    /* @TODO refactor this as the text for enemy may need to be inside the vector for external calls on update */
    // if(this->_enemies[_j].health < 67.f) {
    //   this->_enemies[_j].text00.setFillColor(sf::Color(60, 140, 40, 130));
    // } else if(this->_enemies[_j].health < 33.f) {
    //   this->_enemies[_j].text00.setFillColor(sf::Color(140, 60, 40, 120));
    // } else if(this->_enemies[_j].health < 10.f) {
    //   this->_enemies[_j].text00.setFillColor(sf::Color(240, 40, 40, 110));
    //   /* @TODO why won't this work? Dynamic fill color? I have a struct? it should? or should it baha bja habjabkj */ 
    // }
  }
}

const sf::Vector2f & Enemy::getPos() const {
  return this->_sprite.getPosition();
}

void Enemy::render(sf::RenderTarget& target) {
  for(auto &_e : this->_enemies) {
    _e.text00.setString(to_string(_e.health).substr(0, 5));
    _e.text00.setCharacterSize(18);
    _e.text00.setFillColor(sf::Color(255, 255, 255, 140));
    _e.text00.setOutlineColor(sf::Color::Black);
    _e.text00.setOutlineThickness(2.f);
    if(_e.type == sheriff) {
      _e.text00.setPosition(_e.enemy.getPosition().x, _e.enemy.getPosition().y - 100.f);
      target.draw(_e.text00);
    } else {
      _e.text00.setPosition(_e.enemy.getPosition().x, _e.enemy.getPosition().y - 20.f);
      target.draw(_e.text00);
    }

    target.draw(_e.enemy);
  }
}
