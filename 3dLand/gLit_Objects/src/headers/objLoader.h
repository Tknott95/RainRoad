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

// struct ObjIndices {
//   std::vector<uint> vIndices;
// };

class ObjectLoader {
  private:
    vector<uint> vIndices, uvIndices, normIndices;

    /* @NEW prep-work */
    vector<vec3> 
      tempVertices,
      tempUVs/*mightNotUse*/, 
      tempNormals/*mightNotUse*/;
    EncodedObj encodedObj;
  public:
    vector<uint> vertIndices;
    EncodedObj load(const char*, EncodedObj); /* return a vector of <ObjStruct> ? @TODO */
};
