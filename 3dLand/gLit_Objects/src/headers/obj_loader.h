#include <vector>
#include <cstdio>
#include <iostream>
#include "glm/glm.hpp"

struct ObjData {
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals; 
};

class ObjectLoader {
  private:
    ObjData objData;
  public:
    std::vector<ObjData> load(const char*);
};
