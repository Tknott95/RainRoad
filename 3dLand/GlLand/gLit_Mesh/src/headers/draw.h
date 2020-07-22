#include <iostream>
#include <vector>

#include "mesh.h"
#include "camera.h"

using namespace glm;

class Draw {
  private:
    Mesh m00;
    Mesh m01{false, "assets/objects/col.obj"};
    Mesh skybox{true};
    std::vector<Mesh> mesh;

  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize);
};
