#include "../headers/obj_loader.h"

std::vector<ObjData> ObjectLoader::load(const char* objPath) {
  std::FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m"); /* change this to be under the return of the if(data) as it is da waay */

  while(data) {
    char header[128];
    int j = fscanf(data, "%s", header);
    if(j == EOF) break;
    std::cout << j << std::endl;
  }
};
