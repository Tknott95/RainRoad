#include "../headers/enemy.h"

/* ctime messes up sfml, needinternal library which sfml does indeed HAVE */
// void delay(int number_of_seconds) {
//   int milli_seconds = 1000 * number_of_seconds; 
//   clock_t start_time = clock(); 
//   while (clock() < start_time + milli_seconds) ; 
// }


// clock.restart();

void Enemy::init() {
  this->spawnDelay = 1.f;
  // this->spawnTimer = 111; //this->spawnDelay; WE NEED AN ACTUAL TIMER HERE
  this->maxEnemies = 3;

  if (!_texture.loadFromFile("./utils/sprite.png")) {
    cout << "\n ERROR LOADING ENEMY TEXTURE \n" << endl;
  }
}

void Enemy::spawn() {
  printf("\n SPAWNING ENEMY \n");
  // this->enemy.setPosition(50.f, 50.f);
  this->enemy.setSize(sf::Vector2f(133, 133));
  this->enemy.setFillColor(sf::Color(40, 40, 104, 200));
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.8f);

  this->enemy.setPosition(
    /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
    static_cast<float>(rand() % static_cast<int>(1280/3, 1280/3)),
    static_cast<float>(rand() % static_cast<int>(720/2, 720/2))
  );
  this->enemies.push_back(this->enemy);
}

void Enemy::update() {
  // cout << this->enemies.size() << endl;
  this->elapsedTime = clock.getElapsedTime();
  if(this->enemies.size() < this->maxEnemies) {
    if(this->elapsedTime.asSeconds() >= this->spawnDelay) {
      this->spawn();
      //delay(1000);
      //this->spawnTimer = 0.f;
      this->clock.restart();
    } 
  }

  for(auto &e : this->enemies) {
    e.move(1.4f, .8f);
  }
}

void Enemy::run() {
  this->init();
  this->update();
}
