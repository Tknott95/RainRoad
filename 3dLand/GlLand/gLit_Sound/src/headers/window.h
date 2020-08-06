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
    dvec2 pos;

    double startTime, deltaTime;

    int FPSRate;
    int fpsEpochs;

    GLFWwindow* _window;
    Mouse mouse;
    Camera* _camera;
    Keys keys;
    Draw* draw;
   

    void mousePolling(dvec2 _pos);
    void FPS();

  public:
    bool isOpen;

    Window(const char*);
    virtual ~Window();

    void render();
    void update();
};
