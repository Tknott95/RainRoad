#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"

#include <GL/glew.h>
#include <iostream>

class Texture {
  public:
    unsigned int load(const char *path);
};
