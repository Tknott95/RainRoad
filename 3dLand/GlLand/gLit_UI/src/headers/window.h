#include <iostream>
#include <thread>

#include "keys.h"
#include "draw.h"

class Window {
  private:
    struct Mouse {
      bool initMove = false;
      float lastX;
      float lastY;
    };

    ivec2 screenSize = ivec2(1280, 800);
    float _deltaTime, _lastFrame = 0.0f;
    double xpos, ypos;

    GLFWwindow* _window;
    Mouse mouse;
    Camera* _camera;
    Keys keys;
    Draw* draw;

    void mousePolling(double xpos, double ypos);

  public:
    bool isOpen;

    Window(const char*);
    virtual ~Window();

    void render();
    void update();
};
