#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>

enum BulletType {
  player,
  enemy
};

struct BulletStruct {
  BulletType type;
  sf::Sprite bullet;
};

class Bullet {
  private:
    const float bulletSpeed = 5.f;
    sf::CircleShape _bullet;
    sf::Clock clock;
    sf::Time elapsedTime;
    sf::Texture _enemyBulletTexture;
    sf::Texture _playerBulletTexture;
    float spawnTimer;
    float spawnDelay;

  public:
    std::vector <sf::CircleShape> _bullets;
    std::vector <BulletStruct> playerBullets;
    std::vector <BulletStruct> enemyBullets;
    void init(sf::Vector2f, float);
    void spawn(sf::Vector2f startingPos, BulletType bType, float xOffset);
    Bullet();
	  virtual ~Bullet();
    void fire(sf::Vector2f, float);
    void move(float, BulletType);
    void erase(int);
    void render(sf::RenderTarget& target);


};
