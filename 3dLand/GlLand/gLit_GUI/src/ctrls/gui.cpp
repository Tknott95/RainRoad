#include "../headers/gui.h"

GUI::GUI(const char* _fontPath, const int _fontSize) {
  if(FT_Init_FreeType(&ftLib))  printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");
  if(FT_New_Face(ftLib, _fontPath, 0, &ftFace)) printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");

  FT_Set_Pixel_Sizes(ftFace, 0, _fontSize);

  if (FT_Load_Char(face, 'T', FT_LOAD_RENDER) printf("\n\e[0;31;40m GLYPH LOADING ERROR \e[0m");
};
