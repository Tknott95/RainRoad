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

struct ShaderParams { /* will tweak this just better if ctrl have "knobs" */
 glm::mat4 model;
 glm::mat4 transform;
 glm::mat4 projection;
 glm::mat4 view;
};

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    bool isSkybox;

    ShaderParams sP;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;

  public:
    uint VAO;
    Shader shader;

    Mesh(bool _isSkybox=false);
    virtual ~Mesh();
    void init();
    void draw(Camera* camera, ivec2 screenSize);
};

#endif
