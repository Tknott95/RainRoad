#include "../headers/gui.h"

GUI::GUI(const char* _fontPath, const int _fontSize) {
  if(FT_Init_FreeType(&ftLib))  printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");
  if(FT_New_Face(ftLib, _fontPath, 0, &ftFace)) printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");

  FT_Set_Pixel_Sizes(ftFace, 0, _fontSize);
};

// void GUI::DrawText(const char* _fPath, const int _fontSize) {
//   if(FT_New_Face(ftLib, _fPath, 0, &ftFace)) printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");

//   FT_Set_Pixel_Sizes(ftFace, 0, _fontSize);
// };