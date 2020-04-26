#include <iostream>
#include <thread>

#include "keys.h"
#include "draw.h"

class Window {
  private:
    GLFWwindow* _window;
    Camera* _camera;
    Keys keys;
    Draw* draw;

    ivec2 screenSize = ivec2(500, 400);

    // int _screenWidth = 500/*1280*/;
    // int _screenHeight = 400/*800*/;

    float _deltaTime, _lastFrame = 0.0f;

    // void framebufferSizeCallback(GLFWwindow* window, int width, int height);

  public:
    bool isOpen;

    Window();
    virtual ~Window(); /* @TIP - Using this for dynamic deAllocation of buffers */

    void render();
    void update();
};
