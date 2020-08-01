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
    EncodedObj load(const char*); /* return a vector of <ObjStruct> ? @TODO */
};
