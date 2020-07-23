#include <iostream>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"
#include <GL/glew.h>

class Texture {
  public:
    uint load(const char* path);
    uint loadSkybox(std::vector<std::string>);
};
