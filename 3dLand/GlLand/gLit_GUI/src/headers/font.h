#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H

#include "shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <map>

struct Char {
  uint ID;            // TextureID
  glm::ivec2 Size;    // GlyphSize
  glm::ivec2 Bearing; // Offset from baseline from L to R 
  long Advance;       // Offset to advance to next glyph
};

class Font {
  private:
    FT_Library  ftLib;
    FT_Face     ftFace;
  
    std::map<char, Char> characters;
  public:
    unsigned int myVAO, myVBO;
    Font(const char*, const int _fontSize=12);
    virtual ~Font();
    void Draw();
};