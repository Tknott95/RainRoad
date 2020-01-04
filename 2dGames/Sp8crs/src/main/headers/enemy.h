#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<math.h>

class Enemy {
  private:
    sf::Texture _texture;
    float currHealth = 100.f;
    float maxHealth = 100.f;
    float movementSpeed = 2.f;
    float bulletSpeed = 8.f;

    void init();
    void spawn(sf::Vector2f pos);

    sf::Vector2f normalize(const sf::Vector2f&);
    const bool isDead();

  public:
    std::vector<sf::Sprite> _enemies;
    sf::Sprite _sprite;
    Enemy();
	  virtual ~Enemy();
	  const sf::Vector2f& getPos() const; /* @TODO why a const after the call again? Return value becoming one? Just more control? */
    

    // void move(const float x, const float y);
	  // const bool canAttack();

    // void shoot();
    void takeDmg(float dmg);
    void moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed);
    void update();
    void render(sf::RenderTarget& target);
};
