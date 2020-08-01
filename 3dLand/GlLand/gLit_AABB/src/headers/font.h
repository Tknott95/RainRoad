#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H

#include "shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <map>

using namespace glm;
using namespace std;

struct Char {
  uint ID;            // TextureID
  ivec2 Size;         // GlyphSize
  ivec2 Bearing;      // Offset from baseline from L to R 
  long int Advance;       // Offset to advance to next glyph
};

class Font {
  private:
    FT_Library  ftLib;
    FT_Face     ftFace;
  
    map<char, Char> characters;
  public:
    unsigned int myVAO, myVBO;
    Font(const char* _fontPath="assets/fonts/KurriIslandBlack.ttf", const int _fontSize=128);
    virtual ~Font();
    void Draw(
      string _text, Shader &_shader,
      vec3 _posAndScale,
      const vec3 _color);
};