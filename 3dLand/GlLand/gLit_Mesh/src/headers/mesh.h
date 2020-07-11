#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
using namespace std;

// #include <glad/glad.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "objLoader.h"
#include "structs/encodedObj.h"



class Mesh {
  private:
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    uint VBO, EBO, UVBO;

    Mesh() {};
    void init();
    void loadObjects();

  public:
    uint VAO;

    void Draw();
};

#endif
