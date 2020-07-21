#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
using namespace std;

#include "shader.h"
#include "texture.h"
#include "objLoader.h"
#include "structs/encodedObj.h"

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;

  public:
    uint VAO;
    Shader shader;

    Mesh();
    void init();
    void draw();
};

#endif
