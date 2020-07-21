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
    Mesh skyMesh{true}; /* temp hack then using vec, jus testing and one git push on MVP b4 refactor */

  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
