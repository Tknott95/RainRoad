#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Bullet {
  private:
    const float bulletSpeed = 5.f;
    sf::CircleShape _bullet;

  public:
    Bullet();
	  virtual ~Bullet();
    void fire(sf::Vector2f);

};
