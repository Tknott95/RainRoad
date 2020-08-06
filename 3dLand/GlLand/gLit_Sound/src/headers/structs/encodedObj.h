#pragma once

#include <vector>
#include <glm/glm.hpp>

struct EncodedObj {
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> norms;
};
