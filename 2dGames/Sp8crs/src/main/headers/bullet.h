#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>

class Bullet {
  private:
    const float bulletSpeed = 5.f;
    std::vector <sf::CircleShape> _bullets;
    sf::CircleShape _bullet;
    sf::Clock clock;
    sf::Time elapsedTime;

    float spawnTimer;
    float spawnDelay;

  public:
    void init(sf::Vector2f, float);
    Bullet();
	  virtual ~Bullet();
    void fire(sf::Vector2f, float);
    void move(float);
    void render(sf::RenderTarget& target);


};
