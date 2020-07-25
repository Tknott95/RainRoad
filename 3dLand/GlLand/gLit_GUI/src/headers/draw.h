#include <iostream>
#include <vector>

#include "font.h"
#include "mesh.h"
#include "camera.h"
#include <string>

// using namespace glm;
// using namespace std;

class Draw {
  private:
    Font font{"assets/fonts/KurriIslandBlack.ttf"};
    Font camLoc;
    Shader fontShader;

    Mesh plane{false,
      vec3(0.0f,-1.0f,0.0f),
      "assets/objects/plane_for_walls.obj"};
    Mesh mCube00{false,
      vec3(4.0f, 0.0f, 1.0f),
      "assets/objects/sqr.obj"};
    Mesh mCube01{false,
      vec3(-4.0f, 0.0f, 1.0f),
      "assets/objects/sqr.obj"};
    Mesh skybox{true};
    Mesh mesh[3] = {
      plane,
      mCube00, mCube01
    };

    void renderGUI(Camera* camera, ivec2 screenSize);

  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize);
};
