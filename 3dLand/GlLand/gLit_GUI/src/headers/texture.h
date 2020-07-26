#include <iostream>
#include <vector>
#include <string>
#include <map>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"
#include <GL/glew.h>

class Texture {
  public:
    /* _textureClamping { GL_REPEAT GL_CLAMP_TO_EDGE GL_CLAMP_TO_BORDER } */
    uint load(const char* path, GLenum _textureClamping=GL_CLAMP_TO_EDGE);
    uint loadSkybox(std::vector<std::string>);
};
