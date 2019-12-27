#include "../headers/collision.h"
#include <SFML/Graphics.hpp>

bool Collision::checkCollision(sf::FloatRect j, sf::FloatRect k) {
  sf::FloatRect intersection;
  return j.intersects(k, intersection);
}
