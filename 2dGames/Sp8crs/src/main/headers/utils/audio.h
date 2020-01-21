#include<iostream>

using namespace std;

class Audio {
  private:
  public:
    void init();
    void playerMoving();
    void playerShooting();
    void shipDestroyed();
    void enemyShooting(); /* might make this and playerShooting one shooting class with type param */
};
