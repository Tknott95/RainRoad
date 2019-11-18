#pragma once

class Game {
  private:

  public:
    Game();
    virtual ~Game();

    void fixedUpdate();
    void update();
    void render();
}
