#include "../headers/gui.h"

GUI::GUI(const char* _fontPath, const int _fontSize) {
  if(FT_Init_FreeType(&ftLib))  printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");
  if(FT_New_Face(ftLib, _fontPath, 0, &ftFace)) printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");

  FT_Set_Pixel_Sizes(ftFace, 0, _fontSize);

  if (FT_Load_Char(ftFace, 'T', FT_LOAD_RENDER)) printf("\n\e[0;31;40m GLYPH LOADING ERROR \e[0m");

  for(unsigned char k=0;k<128;k++) {
    if(FT_Load_Char(ftFace, k, FT_LOAD_RENDER)) printf("\n\e[0;31;40m GLYPH LOADING ERROR IN LOOP \e[0m");

    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(
      GL_TEXTURE_2D,                // target
      0,                            // level
      GL_RED,                       // internalFormat
      ftFace->glyph->bitmap.width,  // width
      ftFace->glyph->bitmap.rows,   // height
      0,                            // border
      GL_RED,                       // format
      GL_UNSIGNED_BYTE,             // type
      ftFace->glyph->bitmap.buffer  // data
    );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    Char thisChar = {
      texture,
      glm::ivec2(),
      glm::ivec2(),
      ftFace->glyph->advance.x
    };

    characters.insert(std::pair<char, Char>(k, thisChar));
  }
};
