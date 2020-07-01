#include "../headers/objLoader.h"
#include <fstream>
/******************************
  USING
    v - vertices - x y z
    vt - uvs - x y
    vn
    f - vIndices, uvIndices, texIndices - x/y/z x/y/z x/y/z
  @TODO -> read below for indexing
  @TODO -> NEEDS INDEXING FOR VERTICES - starting at 1 not 0 as obj files start at 1 unlike matematicuhh bruhh
  @INTERESTING || so the position is temp_vertices[ vertexIndex-1 ] (there is a -1 because C++ indexing starts at 0 and OBJ indexing starts at 1, remember ?) :
*******************************/

EncodedObj ObjectLoader::load(const char* objPath) {
  FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m"); /* change this to be under the return of the if(data) as it is da waay */

  ofstream objFileForLogger;
  objFileForLogger.open ("assets/logs/encodedObjLogger.txt");
  while(data) { /* while so it reads every lang rather then an if */
    char header[256];
    int reader = fscanf(data, "%s", header);
    // printf("\n  \e[1;33;40m    %d \e[0m", reader);
    if(reader == EOF) break;

    if(strcmp(header, "#") == 0 || strcmp(header, "mtllib") == 0) {
      // IGNORE
    }
    else if(strcmp(header, "o") == 0) {
      /* ObjName from file for prefab type creation */
    }
    else if(strcmp(header, "v") == 0) {
      vec3 vertex;
      fscanf(data, "%f %f %f \n", &vertex.x, &vertex.y, &vertex.z);
      objFileForLogger << "v " << vertex.x << ", " << vertex.y << ", " << vertex.z <<"\n";
      encodedObj.vertices.push_back(vertex);
    }
    else if(strcmp(header, "vt") == 0) {
      vec2 uvs;
      fscanf(data, "%f %f \n", &uvs.x, &uvs.y);
      encodedObj.uvs.push_back(uvs);
    }
    else if(strcmp(header, "vn") == 0) {
      vec3 vertexNormal;
      fscanf(data, "%f %f %f \n", &vertexNormal.x, &vertexNormal.y, &vertexNormal.z);
      encodedObj.norms.push_back(vertexNormal);
    }
    else if(strcmp(header, "f") == 0) {
      uint vIndex[3], uvIndex[3], normIndex[3];
      int dataAmt = fscanf(data, "%i/%i/%i %i/%i/%i %i/%i/%i\n", &vIndex[0], &uvIndex[0], &normIndex[0], &vIndex[1], &uvIndex[1], &normIndex[1], &vIndex[2], &uvIndex[2], &normIndex[2]);
      if(dataAmt != 9) printf("\n\e[0;31;40m OBJ(face) DATA TOO LARGE(!9)\e[0m");

      objFileForLogger << "i-ces 1(" << vIndex[0] << ") 2(" << vIndex[1] << ") 3(" << vIndex[2] <<") \n";

      vertIndices.push_back(vIndex[0]);
      vertIndices.push_back(vIndex[1]);
      vertIndices.push_back(vIndex[2]);
      // uvIndices.push_back(uvIndex[0]);
      // uvIndices.push_back(uvIndex[1]);
      // uvIndices.push_back(uvIndex[2]);
      // normIndices.push_back(normIndex[0]);
      // normIndices.push_back(normIndex[1]);
      // normIndices.push_back(normIndex[2]);
      /* *********** Faces Debuggine  **************
      ** printf("\n\e[0;39;49m  faces(%d)  \e[0m", dataAmt);
      */
    }
  }

  // /* @TODO compare for(uint) to for(size_t) in book */
  // for(size_t i=0; i<vertIndices.size(); i++) {
  //   uint currVertexIndex = vertIndices[i];
  //   // glm::vec3 newVertex = tempVertices[currVertexIndex-1];
  //   printf("Vertex[%i](%f, %f, %f)\n", i, tempVertices[currVertexIndex-1].x, tempVertices[currVertexIndex-1].y, tempVertices[currVertexIndex-1].z);
  //   encodedObj.vertices.push_back(tempVertices[currVertexIndex-1]);
  // }

  printf("\n  \e[0;94;40m  Object Loaded: \e[0;33;40m %s \n    v(%d) vIndices(%d) \e[0m\n",
    objPath, encodedObj.vertices.size(), vertIndices.size());
  
  objFileForLogger.close();

  return encodedObj;
};
