#include "../headers/objLoader.h"

EncodedObj ObjectLoader::load(const char* objPath) {
  FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m");

  ofstream objFileForLogger;
  objFileForLogger.open("assets/logs/encodedObjLogger.txt");
  while(data) {
    char header[256];
    int reader = fscanf(data, "%s", header);
    if(reader == EOF) break;

    if(strcmp(header, "o") == 0) {
    }
    else if(strcmp(header, "v") == 0) {
      vec3 vertex;
      fscanf(data, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
      objFileForLogger << "v " << vertex.x << ", " << vertex.y << ", " << vertex.z <<"\n";
      encodedObj.vertices.push_back(vertex);
    }
    else if(strcmp(header, "vt") == 0) {
      vec2 uvs;
      fscanf(data, "%f %f\n", &uvs.x, &uvs.y);
      encodedObj.uvs.push_back(uvs);
    }
    else if(strcmp(header, "vn") == 0) {
      vec3 vertexNormal;
      fscanf(data, "%f %f %f\n", &vertexNormal.x, &vertexNormal.y, &vertexNormal.z);
      encodedObj.norms.push_back(vertexNormal);
    }
    else if(strcmp(header, "f") == 0) {
      uint vIndex[3], uvIndex[3], normIndex[3];
      int dataAmt = fscanf(data, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vIndex[0], &uvIndex[0], &normIndex[0], &vIndex[1], &uvIndex[1], &normIndex[1], &vIndex[2], &uvIndex[2], &normIndex[2]);
      if(dataAmt != 9) printf("\n\e[0;31;40m OBJ(face) DATA TOO LARGE(!9)\e[0m");

      objFileForLogger << "i-ces 1(" << vIndex[0]-1 << ") 2(" << vIndex[1]-1 << ") 3(" << vIndex[2]-1 <<") \n";

      vertIndices.push_back(vIndex[0]-1);
      vertIndices.push_back(vIndex[1]-1);
      vertIndices.push_back(vIndex[2]-1);
      uvIndices.push_back(uvIndex[0]-1);
      uvIndices.push_back(uvIndex[1]-1);
      uvIndices.push_back(uvIndex[2]-1);
      normIndices.push_back(normIndex[0]-1);
      normIndices.push_back(normIndex[1]-1);
      normIndices.push_back(normIndex[2]-1);
    }
  }

  printf("\n  \e[0;94;40m  Object Loaded: \e[0;33;40m %s \n    v(%d) vIndices(%d) \e[0m\n",
    objPath, encodedObj.vertices.size(), vertIndices.size());
  
  objFileForLogger.close();

  return encodedObj;
};
