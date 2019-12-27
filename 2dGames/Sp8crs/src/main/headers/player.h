#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Player {
  private:
    sf::Texture _texture;
    
    sf::CircleShape _bullet;
    sf::Clock _clock;
    // sf::Clock clock;
    sf::Time elapsedTime;

    float movementSpeed = 2.f;
	  float attackWait;

    float bulletSpeed = 8.f;

    void init();

  public:
    sf::Sprite _sprite;
    // float globalBounds; /*this->_player->_sprite.getGlobalBounds() */
    Player();
	  virtual ~Player();
	  const sf::Vector2f& getPos() const;

    void move(const float x, const float y);
	  const bool canAttack();

    void shoot();
  
    void update();
    void render(sf::RenderTarget& target);
};
