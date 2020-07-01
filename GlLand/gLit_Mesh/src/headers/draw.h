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
    vec3 lightPos;
    vec3 lightColor;
    unsigned int diffuseMap, specMap, emissionMap;

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
