// #include <string>
// #include <GLFW/glfw3.h>
#include <iostream>
#include <GL/glew.h>
#include "shader.h"
#include "camera.h"

using namespace glm;

class Draw {
  private:
    Shader lampShader;
    Shader materialShader;
    // unsigned int cubeVAO, lightVAO;
    GLuint VBO, cubeVAO, lightVAO;
    glm::vec3 lightPos;
    glm::vec3 lightColor;
    // Shader shader0;
    // Shader lightShader;

  public:
    void init();
    void update(Camera* camera);
};
