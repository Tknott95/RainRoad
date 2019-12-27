#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Enemy {
  private:
    sf::Texture _texture;

    float movementSpeed = 2.f;
	  float attackWait;

    float bulletSpeed = 8.f;

    void init();

  public:
    sf::Sprite _sprite;
    Enemy();
	  virtual ~Enemy();
	  const sf::Vector2f& getPos() const;

    // void move(const float x, const float y);
	  // const bool canAttack();

    // void shoot();
  
    void update();
    void render(sf::RenderTarget& target);
};
