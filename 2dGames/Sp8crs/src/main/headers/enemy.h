#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<math.h>

enum EnemyType {
  kamikaze,
  sheriff,
  jester
};

struct EnemyStruct {
  float health;
  sf::Sprite enemy;
  sf::Text text00;
  EnemyType type;
};


class Enemy {
  private:
    sf::Texture _texture;
    sf::Text _text00;
    sf::Font _font00;
    // float currHealth = 100.f; /* will add to vec
    // float maxHealth = 100.f;
    float movementSpeed = 2.f;
    float bulletSpeed = 8.f;
    int currLvl = 1;

    void init();
    void spawn(sf::Vector2f pos, EnemyType eType);

    sf::Vector2f normalize(const sf::Vector2f&);
    const bool isDead();

  public:
    std::vector<EnemyStruct> _enemies; /* health, _enemySprite */
    sf::Sprite _sprite;
    void spawner(int currLvl);
    Enemy();
	  virtual ~Enemy();
	  const sf::Vector2f& getPos() const; /* @TODO why a const after the call again? Return value becoming one? Just more control? */

    // void move(const float x, const float y);
	  // const bool canAttack();

    // void shoot();
    void takeDmg(int eId, float dmg);
    void delEnemy(int eId);
    const EnemyType getType(int eId);
    void lookAtPlayer(int enemyId, sf::Vector2f playerPos, int PlayerRot);
    void moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed);
    void update(int currLvl);
    void render(sf::RenderTarget& target);
};
