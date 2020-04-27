#include <iostream>
#include "shader.h"
#include "camera.h"
#include "texture.h"

using namespace glm;

class Draw {
  private:
    Shader lampShader;
    Shader materialShader;
    Texture texture;
    GLuint VBO, cubeVAO, lightVAO;
    glm::vec3 lightPos;
    glm::vec3 lightColor;
    unsigned int diffuseMap, specMap, emissionMap;

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
};
