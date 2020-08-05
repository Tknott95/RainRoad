#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>


#include "structs/encodedObj.h"
#include "utils/skybox_data.h"

#include "shader.h"
#include "texture.h"
#include "objLoader.h"
#include "camera.h"

using namespace std;
using namespace glm;

enum class TypeOfMesh {
  IsObject,
  IsCollision,
  IsSkybox
};

struct ShaderParams { 
  mat4 model;
  mat4 transform;
  mat4 projection;
  mat4 view;
};

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    TypeOfMesh meshType;

    vec3 pos{0.0f, 0.0f, 0.0f};
    vec3 uShaderColorChange{1.f, 1.f, 1.f};

    ShaderParams sP;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;
    const char* _objPath = "assets/objects/plane.obj";
    const char*  texturePath;

    bool isSkybox(TypeOfMesh);
    bool isObject(TypeOfMesh);
    bool isCollision(TypeOfMesh);

  public:
    uint VAO;
    Shader shader;

    Mesh(TypeOfMesh _meshtype, // = isObject
      vec3 pos=vec3{0.0f},
      const char* _objPath = "assets/objects/plane.obj",
      const char* _texturePath = "assets/textures/box_weave.png"
    );

    virtual ~Mesh();
    void draw(Camera* camera, ivec2 screenSize);
};

#endif
