#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Player {
  private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    // sf::Clock clock;
    // sf::Time elapsedTime;

    float movementSpeed = 2.f;
	  float attackWait;

    void init();

  public:
    Player();
	  virtual ~Player();
	  const sf::Vector2f& getPos() const;

    void move(const float x, const float y);
	  const bool canAttack();
  
    void update();
    void render(sf::RenderTarget& target);
};
