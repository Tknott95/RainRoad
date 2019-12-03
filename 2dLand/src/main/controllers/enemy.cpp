#include "../headers/enemy.h"

void Enemy::init() {
  this->spawnTimer = 0.0f;
  this->spawnDelay = 1000.0f;
  this->maxEnemies = 3;

  if (!_texture.loadFromFile("./utils/sprite.png")) {
    cout << "\n ERROR LOADING ENEMY TEXTURE \n" << endl;
  }
}

void Enemy::spawn() {
  this->enemy.setPosition(50.f, 50.f);
  this->enemy.setSize(sf::Vector2f(133, 133));
  this->enemy.setFillColor(sf::Color(40, 40, 104, 200));
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.8f);

  this->enemy.setPosition(
    /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
    static_cast<float>(rand() % static_cast<int>(1280/2, 1280/2)),
    static_cast<float>(rand() % static_cast<int>(720/2, 720/2))
  );
  this->enemies.push_back(this->enemy);
}

void Enemy::update() {
  this->spawn();
  if(this->enemies.size() < this->maxEnemies) {
    if(this->spawnTimer >= this->spawnDelay) {
      this->spawn();
      this->spawnTimer = 0.0f;
    } else {
      this->spawnTimer += 1.0f;
    }
  }
}

void Enemy::run() {
  this->init();
  this->update();
}
