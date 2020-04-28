#include <iostream>
#include <vector>
#include "shader.h"
#include "camera.h"
#include "texture.h"

using namespace glm;

class Draw {
  private:
    uint sbTexID;
    uint skyboxVAO, skyboxVBO, cubeVAO, cubeVBO;
    Shader skyboxShader;

    uint loadSkybox(std::vector<std::string> _sbFaces);

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
