#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<math.h>

class Enemy {
  private:
    sf::Texture _texture;

    float movementSpeed = 2.f;
	  float attackWait;

    float bulletSpeed = 8.f;

    void init();

    sf::Vector2f normalize(const sf::Vector2f&);

  public:
    sf::Sprite _sprite;
    Enemy();
	  virtual ~Enemy();
	  const sf::Vector2f& getPos() const;
    

    // void move(const float x, const float y);
	  // const bool canAttack();

    // void shoot();
    void moveToPlayer(sf::Vector2f, float);
    void update();
    void render(sf::RenderTarget& target);
};
