#include <vector>
#include <cstdio>
#include <iostream>
#include "glm/glm.hpp"

struct ObjStruct { /* this will have to be an external header OR created twice */
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vector<glm::vec3> normals; 
};

class ObjectLoader {
  private:
    ObjStruct objData;
  public:
    ObjStruct load(const char*);
};
