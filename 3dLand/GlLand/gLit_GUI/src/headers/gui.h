/* THIS IS A SHITBAG SHIT LIBRARY */
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H

struct Char {
  uint ID;            // TextureID
  glm::ivec2 Size;    // GlyphSize
  glm::ivec2 Bearing; // Offset from baseline from L to R 
  uint Advance;       // Offset to advance to next glyph
};

class GUI {
  private:
    FT_Library  ftLib;
    FT_Face     ftFace;
  public:
    GUI(const char*, const int _fontSize=12);
};