// #include <string>
// #include <GLFW/glfw3.h>
#include <iostream>
#include <GL/glew.h>
#include "shader.h"

/* @TODO hand make shaders for lighting then create iwn shader class w/ own methodology */
class Draw {
  private:
    // unsigned int cubeVAO, lightVAO;
    GLuint vao, vbo; 
    Shader shader0;

  public:
    void init();
    void update();
};
