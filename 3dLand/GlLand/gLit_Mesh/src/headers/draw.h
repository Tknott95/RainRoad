#include <iostream>
#include <vector>

#include "mesh.h"
#include "camera.h"

using namespace glm;

class Draw {
  private:
    Mesh m00{false, vec3(0.0f,-1.0f, 0.0f)};
    Mesh m01{false, vec3(2.0f,0.0f,1.0f), "assets/objects/sqr.obj"};
    Mesh m02{false, vec3(2.0f,1.0f,4.0f), "assets/objects/col_lg.obj"};
    Mesh m03{false, vec3(2.0f,1.0f,-4.0f), "assets/objects/col_lg.obj"};
    Mesh skybox{true};
    Mesh mesh[4] = { /* @TODO make sizing dynamic */
      m00,m01,m02,m03
    };

  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize);
};
