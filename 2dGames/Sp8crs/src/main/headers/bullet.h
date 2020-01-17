#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>
#include<math.h>
/* @TODO move bullet sound into bullet class */

using namespace std;

enum BulletType {
  player,
  enemy
};

struct BulletStruct {
  BulletType type;
  sf::Sprite bullet;
  float angle;
};

class Bullet {
  private:
    const float bulletSpeed = 5.f;
    const bool DEBUG = false;
    sf::CircleShape _bullet;
    sf::Music _eShotSound;
    sf::Clock clock;
    sf::Time elapsedTime;
    sf::Texture _enemyBulletTexture;
    sf::Texture _playerBulletTexture;
    float spawnTimer;
    float spawnDelay;
    float _pi = 3.14159;
    float yOffset = 10.f;

  public:
    std::vector <sf::CircleShape> _bullets;
    std::vector <BulletStruct> playerBullets;
    std::vector <BulletStruct> enemyBullets;
    void init(sf::Vector2f, float);
    void spawn(sf::Vector2f startingPos, BulletType bType, float xOffset, float angleToPlayer);
    Bullet();
	  virtual ~Bullet();
    void fire(sf::Vector2f, float halfSprite, float angleToPlayer, BulletType bType);
    void move(float, BulletType);
    void erase(int, BulletType);

    void render(sf::RenderTarget& target);
};
