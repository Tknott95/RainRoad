/* THIS IS A SHITBAG SHIT LIBRARY */
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H

class GUI {
  private:
    FT_Library  ftLib;
    FT_Face     ftFace;
  public:
    GUI(const char* fPath, const int _fontSize);
};