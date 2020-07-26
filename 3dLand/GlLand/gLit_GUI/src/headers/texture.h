#include <iostream>
#include <vector>
#include <string>
#include <map>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"
#include <GL/glew.h>

class Texture {
  public:
    uint load(const char* path, GLenum _textureClamping=GL_CLAMP_TO_BORDER);
    uint loadSkybox(std::vector<std::string>);
};
