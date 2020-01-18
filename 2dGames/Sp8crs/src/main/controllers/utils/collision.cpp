#include "../../headers/utils/collision.h"
#include <SFML/Graphics.hpp>

bool Collision::checkCollision(sf::FloatRect j, sf::FloatRect k) {
  sf::FloatRect intersection;
  return j.intersects(k, intersection);
}

sf::Vector2f Collision::getSpriteSize(sf::Sprite& Object) {
	sf::IntRect OriginalSize = Object.getTextureRect();
	sf::Vector2f Scale = Object.getScale();
	return sf::Vector2f (OriginalSize.width*Scale.x, OriginalSize.height*Scale.y);
}

/* @TODO make system to move back sprites collided */
/* use classical newtonian physics */
