#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "glm/glm.hpp"

/*****************************************
* make vec5 for verticesData then uv's
* x y z u v
*
* @TODO
* - make objStruct w/ out indices
* - make indices struct
* - use obj struct as my data pass in instead of objStruct.vertices
*   ^ this  will dynam load other data ^
*****************************************/

struct ObjStruct { /* this will have to be an external header OR created twice */
  std::vector<glm::vec3> vertices;
  std::vector<glm::vec2> uvs;
  // std::vector<glm::vec3> normals;
  std::vector<uint> vertIndices; /* pull out of objStruct so i can call sizeof(objStruct)? */
};

class ObjectLoader {
  private:
    ObjStruct objData;
    std::vector<uint> vIndices, uvIndices, normIndices;
  public:
    ObjStruct load(const char*);
};
