#ifndef MESH_H
#define MESH_H

#include <string>
#include <vector>
#include <shader.h>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


using namespace std;
using namespace glm;

struct Vertex {
  glm::vec3 Position;
  glm::vec3 Normal;
  glm::vec3 Tangent;
  glm::vec3 BitTangent;
};
