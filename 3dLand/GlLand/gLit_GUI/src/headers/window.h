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

    const double maxFPS = 244.0, maxPeriod = 1.0/maxFPS;
    float deltaTime=0.f,endTime=0.f;
    double FPSRate;
    int fpsEpochs=0;

    float uptime;

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
