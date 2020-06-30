#pragma once

#include <vector>
#include <glm/glm.hpp>

struct EncodedObj {
  std::vector<glm::vec3> VertPos;
  std::vector<glm::vec2> UVs;
  std::vector<glm::vec3> Norms;
};
