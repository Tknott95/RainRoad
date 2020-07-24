#include <iostream>
#include <thread>
#include "keys.h"
#include "draw.h"
#include "gui.h"

class Window {
  private:
    struct Mouse {
      bool initMove = false;
      float lastX;
      float lastY;
    };

    ivec2 screenSize = ivec2(1280, 800);
    dvec2 pos;
    float _deltaTime, _lastFrame = 0.0f;

    GLFWwindow* _window;
    Mouse mouse;
    Camera* _camera;
    Keys keys;
    Draw* draw;
    GUI gui{"assets/fonts/KurriIslandBlack.ttf"};

    void mousePolling(dvec2 _pos);

  public:
    bool isOpen;

    Window(const char*);
    virtual ~Window();

    void render();
    void update();
};
