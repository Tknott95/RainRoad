#include "../headers/enemy.h"

void Enemy::init() {
  this->spawnDelay = 0.01f;
  this->maxEnemies = 2;

  if (!_texture.loadFromFile("./utils/sprite.png")) {
    cout << "\n ERROR LOADING ENEMY TEXTURE \n" << endl;
  }
}

void Enemy::spawn() {
  // printf("\n SPAWNING ENEMY \n");
  // this->enemy.setPosition(50.f, 50.f);
  this->enemy.setRotation(rand() % 180);
  this->enemy.setSize(sf::Vector2f(33, rand() % 133));
  this->enemy.setFillColor(sf::Color(rand() % 144, rand() % 144, rand() % 255, rand() % 255));
  this->enemy.setOutlineColor(sf::Color::White);
  this->enemy.setOutlineThickness(1.8f);

  this->enemy.setPosition(
    /* @REFACTOR grab screen size instead once the dynamic screen size is setup */
    static_cast<float>(rand() % static_cast<int>(1280, 1280)),
    static_cast<float>(rand() % static_cast<int>(720/2, 720/2))
  );
  this->enemies.push_back(this->enemy);
  this->clock.restart();
}

void Enemy::update() {
  this->elapsedTime = clock.getElapsedTime();
  
  // int cur = 0;
  // for(auto &e : this->enemies) { /* change to old school loop */
  //   cur++;
  //   e.move(0.14f, .48f + rand() % 3);
  //   //sf::Vector2f pos = e.getPosition();
  //   cout << "x pos:" << e.getPosition().x << "  y pos:" << e.getPosition().y << endl;
  //   e.setRotation(e.getRotation() + 0.1);

  //   if(e.getPosition().y > 333) {
  //     printf("\n  DELETE OBJ \n");
  //     // this->enemies.erase(e); /* best way I know with vector looping via. auto to grab index as of meow */    
  //   }
  //  // cout << e.getGlobalBounds() << endl;
  //   // e.setSize(sf::Vector2f(13, rand() % 33));
  //   /* if enemy leaves screen area DEL IT */
  // }


  if(this->enemies.size() < this->maxEnemies && this->elapsedTime.asSeconds() > this->spawnDelay) {
    this->spawn();   
  }

  for (size_t i = 0; i < this->enemies.size(); i++) {
     this->enemies[i].move(0.14f, .48f + rand() % 4);
     this->enemies[i].setRotation(this->enemies[i].getRotation() + 0.1);

     if(this->enemies[i].getPosition().y >= 720) {
       this->enemies.erase(this->enemies.begin() + i);
       cout << this->enemies.size() << endl;
     }
  }




}

void Enemy::run() {
  this->update();
}
