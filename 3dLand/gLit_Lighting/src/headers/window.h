#include <iostream>
#include <thread>

#include "keys.h"
#include "draw.h"

class Window {
  private:
    GLFWwindow* _window;
    Camera* _camera;
    Keys keys;

    int _screenWidth = 800/*1280*/;
    int _screenHeight = 600/*800*/;

    float _deltaTime, _lastFrame = 0.0f;

  public:
    bool isOpen;

    Window();
    virtual ~Window(); /* @TIP - Using this for dynamic deAllocation of buffers */

    void render();
    void update();
};
