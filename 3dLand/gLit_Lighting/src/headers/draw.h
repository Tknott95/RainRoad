#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"

class Draw {
  private:
    unsigned int vbo, cubeVAO, lightVAO;
    glm::vec3 lightPos;
    // Shader materialShader("src/shaders/material/material.vs", "src/shaders/material/material.fs");
    // Shader lightShader("src/shaders/light/light.vs", "src/shaders/light/light.fs");

  public:
    Draw();

    void update();
};
