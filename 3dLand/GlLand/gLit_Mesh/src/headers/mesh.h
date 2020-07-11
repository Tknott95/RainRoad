#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include <shader.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "objLoader.h"
#include "structs/encodedObj.h"

using namespace std;
/*
  struct EncodedObj {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> norms;
  };
*/
class Mesh {
  private:
    EncodedObj encodedObj;
    ObjectLoader objLoader;
    uint objVAO, objVBO, objEBO, objUVBO;

    Mesh() {};

  public:
    void Draw();
};

#endif
