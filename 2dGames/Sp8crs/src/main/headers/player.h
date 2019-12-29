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
    sf::Font font;
    sf::Text text;
    float curHealth = 100.f; /* REFACTOR TO PRIVATE W/ PUB CLASS  @TODO */
    // float globalBounds; /*this->_player->_sprite.getGlobalBounds() */
    Player();
	  virtual ~Player();
    void update();
	  const sf::Vector2f& getPos() const;

    void move(const float x, const float y);
    void takeDmg(const float amount);
    void displayHealth();
	  const bool canAttack();

    void shoot();
  
    void render(sf::RenderTarget& target);
};
