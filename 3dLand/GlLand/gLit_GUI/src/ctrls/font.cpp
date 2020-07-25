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
      (int)ftFace->glyph->advance.x
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
  glDeleteBuffers(1, &myVBO);

  glDeleteVertexArrays(0, &myVAO);
};

void Font::Draw(string _text, Shader &_shader, vec3 _posAndScale, const vec3 _color) {
  _shader.use();
  glUniform3f(glGetUniformLocation(_shader.ID, "textColor"), _color.x, _color.y, _color.z);
  glActiveTexture(GL_TEXTURE0);
  glBindVertexArray(myVAO);

  string::const_iterator stringChar;
  for(stringChar=_text.begin(); stringChar!=_text.end(); stringChar++) {
    Char myChar = characters[*stringChar];

    float xPos = _posAndScale.x + myChar.Bearing.x * _posAndScale[3];
    float yPos = _posAndScale.y - (myChar.Size.y - myChar.Bearing.y) * _posAndScale[3];
    float width = myChar.Size.x * _posAndScale[3];
    float height = myChar.Size.y * _posAndScale[3];

    float verts[6][4] = {
      {xPos, yPos+height, 0.0f, 0.0f},            
      {xPos, yPos,        0.0f, 1.0f },
      {xPos+width, yPos,  1.0f, 1.0f },
      {xPos, yPos+height,       0.0f, 0.0f },
      {xPos+width, yPos,        1.0f, 1.0f },
      {xPos+width, yPos+height, 1.0f, 0.0f }     
    };

    glBindTexture(GL_TEXTURE_2D, myChar.ID);
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    /***********************
    * adv curs for nxt glyph 
    * adv is # of 1/64 pixels
    * bitshift by 6 to get val in pxls (2^6 = 64)
    *********************/
    _posAndScale.x += (myChar.Advance >> 6) * _posAndScale.z;
  };
  // glBindVertexArray(0);
  // glBindTexture(GL_TEXTURE_2D, 0);
};