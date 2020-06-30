#include <iostream>
#include <vector>
#include "shader.h"
#include "camera.h"
#include "texture.h"
#include "objLoader.h"

using namespace glm;

class Draw {
  private:
    uint sbTexID, objTexID;
    uint skyboxVAO, skyboxVBO;
    uint objVAO, objVBO, objEBO, objUVBO;

    ObjStruct objData;
    ObjectLoader objLoader;
    Texture texture;
    Shader skyboxShader;
    Shader objShader;

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
