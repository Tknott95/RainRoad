#include "../headers/enemy.h"

void Enemy::init() {
  this->spawnDelay = 0.0001f;
  this->maxEnemies = 333333;

  if (!_texture.loadFromFile("./utils/sprite.png")) {
    cout << "\n ERROR LOADING ENEMY TEXTURE \n" << endl;
  }
}

void Enemy::spawn() {
  printf("\n SPAWNING ENEMY \n");
  // this->enemy.setPosition(50.f, 50.f);
  this->enemy.setSize(sf::Vector2f(33, rand() % 133));
  this->enemy.setFillColor(sf::Color(rand() % 144, rand() % 144, rand() % 255, rand() % 200));
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
  this->elapsedTime = clock.getElapsedTime();
  if(this->enemies.size() < this->maxEnemies) {
    if(this->elapsedTime.asSeconds() >= this->spawnDelay) {
      this->spawn();
      this->clock.restart();
    } 
  }

  for(auto &e : this->enemies) {
    e.move(0.14f, .48f);
    // e.setSize(sf::Vector2f(13, rand() % 33));
    /* if enemy leaves screen area DEL IT */
  }
}

void Enemy::run() {
  this->init();
  this->update();
}
