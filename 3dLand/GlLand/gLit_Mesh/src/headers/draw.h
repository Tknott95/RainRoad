#include <iostream>
#include <vector>

#include "mesh.h"
#include "camera.h"

using namespace glm;

class Draw {
  private:
    uint sbTexID, objTexID;
    uint skyboxVAO, skyboxVBO;
    uint objVAO, objVBO, objEBO, objUVBO;

    ObjectLoader objLoader;
    EncodedObj encodedObj;
    Texture texture;
    Shader skyboxShader;
    Shader objShader;
    Mesh mesh; /* make a class to make vecs of mesh(es) in order to make algo's for proper clipping/chunking */ 

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
