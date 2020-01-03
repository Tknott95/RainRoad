#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>

class Bullet {
  private:
    const float bulletSpeed = 5.f;
    sf::CircleShape _bullet;
    sf::Clock clock;
    sf::Time elapsedTime;

    float spawnTimer;
    float spawnDelay;

  public:
    std::vector <sf::CircleShape> _bullets;
    void init(sf::Vector2f, float);
    Bullet();
	  virtual ~Bullet();
    void fire(sf::Vector2f, float);
    void move(float);
    void erase(int);
    void render(sf::RenderTarget& target);


};
