#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "glm/glm.hpp"

struct ObjStruct { /* this will have to be an external header OR created twice */
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  std::vedtor<glm::vec2> texCoords;
  std::vector<glm::vec3> normals;
  std::vector<uint> vertIndices;
};

class ObjectLoader {
  private:
    ObjStruct objData;
    std::vector<uint> vIndices, uvIndices, normIndices;
  public:
    ObjStruct load(const char*);
};
