#include <iostream>
#include <vector>

#include "font.h"
#include "mesh.h"
#include "camera.h"
#include "collision.h"

#include <string>
#include <iostream>

class Draw {
  private:
    Font font{"assets/fonts/KurriIslandBlack.ttf"};
    Font camLoc;
    Shader fontShader;

    Mesh plane{TypeOfMesh::IsObject,
      vec3(0.0f,-1.0f,0.0f),
      "assets/objects/plane_for_walls.obj",
      "assets/textures/plane.png"};
    Mesh sqr00{TypeOfMesh::IsCollision,
      vec3(-4.0f, 0.0f, 1.0f),
      "assets/objects/meshCube.obj"};
    Mesh skybox{TypeOfMesh::IsSkybox};
    Mesh mesh[2] = {
      plane,
      sqr00
    };

    void renderGUI(Camera* camera, ivec2 screenSize, int fps);

  public:
    Collision collision;
    bool CameraCollided = false;

    Draw();
    virtual ~Draw();
    void update(Camera* camera, ivec2 screenSize, int fps);
};