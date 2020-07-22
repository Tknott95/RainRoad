#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>

using namespace std;

#include "structs/encodedObj.h"
// #include "utils/skybox_data.h"

#include "shader.h"
#include "texture.h"
#include "objLoader.h"
#include "camera.h"

using namespace glm;

struct ShaderParams { 
  mat4 model;
  mat4 transform;
  mat4 projection;
  mat4 view;
};

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    bool isSkybox;
    vec3 pos{0.0f, 0.0f, 0.0f};

    ShaderParams sP;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;

  public:
    uint VAO;
    Shader shader;

    Mesh(bool _isSkybox=false, vec3 pos=vec3{0.0f}, const char* _objPath = "assets/objects/plane.obj");
    virtual ~Mesh();
    void init();
    void draw(Camera* camera, ivec2 screenSize);
};

#endif
