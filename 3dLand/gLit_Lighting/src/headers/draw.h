// #include <string>
// #include <GLFW/glfw3.h>
#include <iostream>
#include <GL/glew.h>
#include "shader.h"

class Draw {
  private:
    // unsigned int cubeVAO, lightVAO;
    GLuint vao, vbo; 
    Shader shader0;

  public:
    void init();
    void update();
};
