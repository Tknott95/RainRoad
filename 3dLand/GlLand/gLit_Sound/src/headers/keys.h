#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "camera.h"

class Keys {
  public:
    void keyPolling(GLFWwindow*, Camera*, float);
};