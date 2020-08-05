#include <iostream>
#include <vector>

#include "font.h"
#include "mesh.h"
#include "camera.h"
#include <string>
#include <iostream>

class Draw {
  private:
    Font font{"assets/fonts/KurriIslandBlack.ttf"};
    Font camLoc;
    Shader fontShader;
    vec3 posBeforeCol;

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

    /* @TODO REFACTOR THESE */
    bool isPointInsideAABB(vec3 myPos, vec3 otherPos);
    bool isAABBInsideAABB(vec3, vec3);

    void renderGUI(Camera* camera, ivec2 screenSize, int fps);

  public:
    bool MoveCameraOnCol = false;
    vec3 NewCamPosAfterCol;
    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize, int fps);
};