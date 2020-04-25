// #include <string>
#include "shader.h"
#include <GLFW/glfw3.h>

/* @TODO hand make shaders for lighting then create iwn shader class w/ own methodology */
class Draw {
  private:
    unsigned int vbo, cubeVAO, lightVAO;
    glm::vec3 lightPos;
    Shader matShader;
    Shader lightShader;

  public:
    void init();
    void update();
};
