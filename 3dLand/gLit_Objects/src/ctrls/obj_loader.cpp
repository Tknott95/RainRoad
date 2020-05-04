#include "../headers/obj_loader.h"

/******************************
  USING
    v
    vt
    vn
    f
*******************************/

ObjStruct ObjectLoader::load(const char* objPath) {
  std::FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m"); /* change this to be under the return of the if(data) as it is da waay */

  while(data) { /* while so it reads every lang rather then an if */
    char header[256];
    int reader = fscanf(data, "%s", header);
    // printf("\n  \e[1;33;40m    %d \e[0m", reader);
    if(reader == EOF) break;

    if(strcmp(header, "v") == 0) {
      glm::vec3 vertex;
      fscanf(data, "%f %f %f \n", &vertex.x, &vertex.y, &vertex.z);
      objData.vertices.push_back(vertex);
    }
    if(strcmp(header, "vt") == 0) {
      glm::vec2 uvs;
      fscanf(data, "%f %f \n", &uvs.x, &uvs.y);
      objData.uvs.push_back(uvs);
    }
    if(strcmp(header, "f") == 0) {
      uint vIndex[3], uvIndex[3], normIndex[3];
      int dataAmt = fscanf(data, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vIndex[0], &uvIndex[0], &normIndex[0], &vIndex[1], &uvIndex[1], &normIndex[1], &vIndex[2], &uvIndex[2], &normIndex[2]);
      if(dataAmt != 9) printf("\n\e[0;31;40m OBJ(face) DATA TOO LARGE(!9)\e[0m");
      // vIndices.push_back(vIndex[0]);
      // vIndices.push_back(vIndex[1]);
      // vIndices.push_back(vIndex[2]);
      // uvIndices.push_back(uvIndex[0]);
      // uvIndices.push_back(uvIndex[1]);
      // uvIndices.push_back(uvIndex[2]);
      // normIndices.push_back(normIndex[0]);
      // normIndices.push_back(normIndex[1]);
      // normIndices.push_back(normIndex[2]);
      // objData.vertIndices.push_back(glm::vec3(vIndex[0], vIndex[1], vIndex[2])); Can't pass a vec3 must be uint
      objData.vertIndices.push_back(vIndex[0]);
      objData.vertIndices.push_back(vIndex[1]);
      objData.vertIndices.push_back(vIndex[2]);
      /* EACH of the vertexIndices needs to be an x,y,x coord */

       /* Faces Debuggine  ************************************
        * printf("\n\e[0;39;49m  faces(%d)  \e[0m", dataAmt); */
      // std::cout << vIndex[0] << std::endl;
    }
  }

  //std::cout << objData.vertices.size() << std::endl;
  //std::cout << objData.vertIndices.size() << std::endl;

  printf("\n  \e[0;94;40m  Object Loaded: \e[0;33;40m %s \n    v(%d) vIndices(%d) \e[0m\n",
    objPath, objData.vertices.size(), objData.vertIndices.size());

  return objData;
};
