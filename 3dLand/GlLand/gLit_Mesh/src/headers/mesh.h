#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
using namespace std;

// #include <glad/glad.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "texture.h" /* loads in images as "textures", etc */

#include "objLoader.h"
#include "structs/encodedObj.h"

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;

    Mesh();
    void init();

  public:
    uint VAO;
    Shader shader;
};

#endif
