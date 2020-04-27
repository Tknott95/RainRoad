#include "third_party/stb_image.h"
#include <glad/glad.h>

#include <iostream>

class Texture {
  public:
    unsigned int load(const char *path);
}