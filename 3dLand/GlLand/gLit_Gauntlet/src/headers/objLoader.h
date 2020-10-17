#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>

#include "structs/encodedObj.h"
#include "glm/glm.hpp"

using namespace std;
using namespace glm;

class ObjectLoader {
  private:
    vector<uint> vIndices, uvIndices, normIndices;

    vector<vec3> 
      tempVertices,
      tempUVs, 
      tempNormals;
    EncodedObj encodedObj;
  public:
    vector<uint> vertIndices;
    /* store location of 6 floating points IF this is a meshForCollision */
    /* Collision check internal? or make it external for MVP first */
    EncodedObj load(const char*); /* return a vector of <ObjStruct> ? @TODO */
};
