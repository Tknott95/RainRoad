#include "../headers/font.h"

Font::Font(const char* _fontPath, const int _fontSize) {
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
  };

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  FT_Done_Face(ftFace);
  FT_Done_FreeType(ftLib);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

  glGenVertexArrays(0, &myVAO);
  glGenBuffers(1, &myVBO);
  glBindVertexArray(myVAO);
  glBindBuffer(GL_ARRAY_BUFFER, myVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
};

Font::~Font() {

};

void Font::DrawText() {

};