#include "../headers/collision.h"
#include <SFML/Graphics.hpp>

bool Collision::checkCollision(sf::FloatRect r1, sf::FloatRect r2) {
  
  sf::FloatRect intersection;
  return r1.intersects(r2, intersection);
}
