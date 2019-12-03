#include <vector> /* Look into standard include methodology for c++ */

class Enemy {
  private:
    sf::Texture _texture;
    sf::Sprite _sprite;

    float spawnTimer;
    float spawnDelay;
    int maxEnemies;

  public:
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    void init();
    void spawn();
    void update();
    void run();
};
