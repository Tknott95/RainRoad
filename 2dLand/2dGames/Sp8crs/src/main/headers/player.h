#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

using namespace std;

class Player {
  private:
    sf::Texture _texture;
    
    sf::CircleShape _bullet;
    sf::Clock _clock;
    sf::Time elapsedTime;

    float movementSpeed = 4.f;
	  float attackWait;
    float bulletSpeed = 8.f;

    void init();

  public:
    sf::Sprite _sprite;
    sf::Font font00;
    sf::Text text00; /* playerHealth text */
    sf::Text text01; /* timeElapsed text */
    float curHealth = 100.f; /* @TODO REFACTOR TO PRIVATE W/ PUB CLASS  @TODO */
    float score = 0.f;
    Player();
	  virtual ~Player();
    void update();
	  const sf::Vector2f& getPos() const;
    const float getRot() const;

    void move(const float x, const float y);
    void takeDmg(const float amount);
    void displayHealth();
	  const bool canAttack();

    void shoot();
  
    void render(sf::RenderTarget& target);
};
