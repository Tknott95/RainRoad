#include <iostream>
#include <thread>

#include "keys.h"
#include "draw.h"

class Window {
  /* @TIP will re-implement the proper way once have hotfix time.
    Making this global, which is shit, until ready to reimplement proper via: my own function w/ out callback
  
    struct Mouse {
      bool initMove = false;
      float lastX;
      float lastY;
    };

    void mouseCallback(GLFWwindow* window, double xpos, double ypos);
  */
  struct Mouse {
    bool initMove = false;
    float lastX;
    float lastY;
  };

  private:
    GLFWwindow* _window;
    Mouse mouse;
    Camera* _camera;
    Keys keys;
    Draw* draw;

    ivec2 screenSize = ivec2(1280, 800);
    float _deltaTime, _lastFrame = 0.0f;
    double xpos, ypos;

    void mousePolling(double xpos, double ypos);

  public:
    bool isOpen;

    Window();
    virtual ~Window(); /* @TIP - Using this for dynamic deAllocation of buffers */

    void render();
    void update();
};
