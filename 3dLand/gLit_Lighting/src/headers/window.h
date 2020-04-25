#include <iostream>
#include <thread>
#include <thread>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

#include "keys.h"
#include "shader.h"

class Window {
  private:
    GLFWwindow* _window;
    Camera* _camera; /* @TIP -  Will need to instantiate via: new in constructor */
    Keys keys;

    int _screenWidth = 1280;
    int _screenHeight = 800;

    float _deltaTime = 0.0f;
    float _lastFrame = 0.0f;

  public:
    bool isOpen;

    Window();
    virtual ~Window(); /* @TIP - Using this for dynamic deAllocation of buffers */

    void render();
    void update();
};
