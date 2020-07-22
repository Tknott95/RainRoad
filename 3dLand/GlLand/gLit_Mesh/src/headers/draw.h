#include <iostream>
#include <vector>

#include "mesh.h"
#include "camera.h"

using namespace glm;

class Draw {
  private:
    std::vector<Mesh> mesh;
    Mesh skybox{true};
    Mesh m00;

  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize);
};
