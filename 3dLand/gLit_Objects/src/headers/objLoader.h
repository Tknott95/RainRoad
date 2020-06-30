#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>

#include "structs/encodedObj.h"
#include "glm/glm.hpp"

using namespace std;
using namespace glm;

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
  vector<vec3> vertices;
  vector<vec2> uvs;
  vector<vec3> normals;
  // std::vector<uint> vertIndices; /* pull out of objStruct so i can call sizeof(objStruct)? */
};

// struct ObjIndices {
//   std::vector<uint> vIndices;
// };

class ObjectLoader {
  private:
    ObjStruct objData;
    vector<uint> vIndices, uvIndices, normIndices;
  public:
    vector<uint> vertIndices;
    ObjStruct load(const char*); /* return a vector of <ObjStruct> ? @TODO */
};
