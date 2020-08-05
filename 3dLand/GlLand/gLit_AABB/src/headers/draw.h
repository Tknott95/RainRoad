#include <iostream>
#include <vector>

#include "font.h"
#include "mesh.h"
#include "camera.h"
#include <string>
#include <iostream>

/* @TODO refactor this into a file, maybe utilities? mesh-utilities, etc. */
// enum TypeOfMesh {
//   Object,
//   Collision,
//   Skybox
// };

class Draw {
  private:
    Font font{"assets/fonts/KurriIslandBlack.ttf"};
    Font camLoc;
    Shader fontShader;

    Mesh plane{TypeOfMesh::IsObject,
      vec3(0.0f,-1.0f,0.0f),
      "assets/objects/plane_for_walls.obj",
      "assets/textures/plane.png"};
    Mesh mCube00{TypeOfMesh::IsObject,
      vec3(4.0f, 0.0f, 1.0f),
      "assets/objects/meshCube.obj"};
    Mesh mCube01{TypeOfMesh::IsCollision,
      vec3(-4.0f, 0.0f, 1.0f),
      "assets/objects/meshCube.obj"};
    Mesh skybox{TypeOfMesh::IsSkybox};
    Mesh mesh[3] = {
      plane,
      mCube00, mCube01
    };

    void renderGUI(Camera* camera, ivec2 screenSize, int fps);

    bool isPointInsideAABB(vec3 myPos, vec3 otherPos/*float otherCube[6]*/);
    bool isAABBInsideAABB(vec3, vec3);
  public:
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize, int fps);
};