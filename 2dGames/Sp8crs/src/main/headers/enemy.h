#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<math.h>

using namespace std;

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
    sf::Texture _texture00;
    sf::Texture _texture01;
    sf::Text _text00;
    sf::Font _font00;
    float movementSpeed = 2.f;
    float bulletSpeed = 8.f;
    float enemySpeedAmplifier = 1.f;
    int currLvl = 1;

    void init();
    void spawn(sf::Vector2f pos, EnemyType eType);

    sf::Vector2f normalize(const sf::Vector2f&);

  public:
    std::vector<EnemyStruct> _enemies; /* health, _enemySprite */
    sf::Sprite _sprite;
    void spawner(int currLvl);
    Enemy();
	  virtual ~Enemy();
	  const sf::Vector2f& getPos() const; /* @TODO why a const after the call again? Return value becoming one? Just more control? */

    void takeDmg(int eId, float dmg);
    void delEnemy(int eId);
    const EnemyType getType(int eId);
    void lookAtPlayer(int enemyId, sf::Vector2f playerPos);
    const float getAngleToPlayer(int enemyId, sf::Vector2f playerPos);
    const sf::Vector2f getPosById(int eId);
    void moveToPlayer(int enemyId, sf::Vector2f playerPos, float enemySpeed);
    void update(int currLvl);
    void render(sf::RenderTarget& target);
};
