#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
using namespace std;

// #include <glad/glad.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

#include "texture.h" /* loads in images as "textures", etc */
#include "shader.h"
#include "objLoader.h"
#include "structs/encodedObj.h"


/* Temp hack struct @TODO remove this w/ proper conventions */
// struct ITexture {
//     unsigned int id;
//     string type;
//     string path;
// };

class Mesh {
  private:
    uint VBO, EBO, UVBO, textureID;
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    Texture texture;
    Shader shader;

    Mesh() {};
    void init();
    void loadObjects();

  public:
    uint VAO;

    void Draw();
};

#endif
