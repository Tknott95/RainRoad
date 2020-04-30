#include "../headers/obj_loader.h"

ObjStruct ObjectLoader::load(const char* objPath) {
  std::FILE *data = fopen(objPath, "r");
  if(!data) printf("\n\e[0;31;40m OBJECT NOT LOADING\e[0m"); /* change this to be under the return of the if(data) as it is da waay */

  if(data) {
    char header[256];
    int j = fscanf(data, "%s", header);

    printf("\n  \e[1;33;40m    %d \e[0m", j);
  }

  printf("\n  \e[1;33;40m  Object Loaded\e[0m\n");

  return objData;
};
