#include "../headers/objLoader.h"

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

/*ObjStruct*/bool ObjectLoader::load(const char* objPath, EncodedObj outObj) {
  FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m"); /* change this to be under the return of the if(data) as it is da waay */

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
      tempVertices.push_back(vertex);
      objData.vertices.push_back(vertex);
    }
    else if(strcmp(header, "vt") == 0) {
      vec2 uvs;
      fscanf(data, "%f %f \n", &uvs.x, &uvs.y);
      objData.uvs.push_back(uvs);
      encodedObj.uvs.push_back(uvs);
    }
    else if(strcmp(header, "vn") == 0) {
      vec3 vertexNormal;
      fscanf(data, "%f %f %f \n", &vertexNormal.x, &vertexNormal.y, &vertexNormal.z);
      objData.normals.push_back(vertexNormal);
      encodedObj.norms.push_back(vertexNormal);
    }
    else if(strcmp(header, "f") == 0) {
      uint vIndex[3], uvIndex[3], normIndex[3];
      int dataAmt = fscanf(data, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vIndex[0], &uvIndex[0], &normIndex[0], &vIndex[1], &uvIndex[1], &normIndex[1], &vIndex[2], &uvIndex[2], &normIndex[2]);
      if(dataAmt != 9) printf("\n\e[0;31;40m OBJ(face) DATA TOO LARGE(!9)\e[0m");

      // @OLD objData.vertIndices.push_back(vec3(vIndex[0], vIndex[1], vIndex[2])); Can't pass a vec3 must be uint
      vertIndices.push_back(vIndex[0]);
      vertIndices.push_back(vIndex[1]);
      vertIndices.push_back(vIndex[2]);
      uvIndices.push_back(uvIndex[0]);
      uvIndices.push_back(uvIndex[1]);
      uvIndices.push_back(uvIndex[2]);
      normIndices.push_back(normIndex[0]);
      normIndices.push_back(normIndex[1]);
      normIndices.push_back(normIndex[2]);
      /* *********** Faces Debuggine  **************
      ** printf("\n\e[0;39;49m  faces(%d)  \e[0m", dataAmt);
      */
    }
  }

  /* @TODO compare for(uint) to for(size_t) in book */
  for(size_t i=0; i<vertIndices.size(); i++) {
    uint currVertexIndex = vertIndices[i]-1;
    // glm::vec3 newVertex = tempVertices[currVertexIndex-1];
    printf("Indice[%i](%f, %f, %f)\n", i, tempVertices[currVertexIndex].x, tempVertices[currVertexIndex].y, tempVertices[currVertexIndex].z);
    encodedObj.vertices.push_back(tempVertices[currVertexIndex]);
  }

  /* @TODO build objData here possibly instead for indexing? */

  printf("\n  \e[0;94;40m  Object Loaded: \e[0;33;40m %s \n    v(%d) vIndices(%d) \e[0m\n",
    objPath, objData.vertices.size(), vertIndices.size());

  return true; //objData;
};
