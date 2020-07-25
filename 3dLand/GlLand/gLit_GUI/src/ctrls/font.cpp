#include "../headers/font.h"

Font::Font(const char* _fontPath, const int _fontSize) {
  if(FT_Init_FreeType(&ftLib))  printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");
  if(FT_New_Face(ftLib, _fontPath, 0, &ftFace)) printf("\n\e[0;31;40m FREETYPE LIBRARY INIT() ERROR \e[0m");

  FT_Set_Pixel_Sizes(ftFace, 0, _fontSize);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  if (FT_Load_Char(ftFace, 'T', FT_LOAD_RENDER)) printf("\n\e[0;31;40m GLYPH LOADING ERROR \e[0m");

  
  for(unsigned char k=0;k<128;k++) {
    if(FT_Load_Char(ftFace, k, FT_LOAD_RENDER)) printf("\n\e[0;31;40m GLYPH LOADING ERROR IN LOOP \e[0m");

    uint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    /* alpha hack */
    GLint swizzleMask[] = {GL_ZERO, GL_ZERO, GL_ZERO, GL_RED};
    glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
  
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
      ivec2(ftFace->glyph->bitmap.width, ftFace->glyph->bitmap.rows),
      ivec2(ftFace->glyph->bitmap_left, ftFace->glyph->bitmap_top),
      ftFace->glyph->advance.x
    };


    characters.insert(std::pair<char, Char>(k, thisChar));
  };

  glBindTexture(GL_TEXTURE_2D, 0);

  FT_Done_Face(ftFace);
  FT_Done_FreeType(ftLib);

  glGenVertexArrays(1, &myVAO);
  glGenBuffers(1, &myVBO);
  glBindVertexArray(myVAO);
  glBindBuffer(GL_ARRAY_BUFFER, myVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

  glBindVertexArray(myVAO);
};

Font::~Font() {
  glDeleteBuffers(1, &myVBO);
  glDeleteVertexArrays(0, &myVAO);
};

void Font::Draw(string _text, Shader &_shader, vec3 _posAndScale, const vec3 _color) {
  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
  // glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

  mat4 projection = ortho(0.0f, static_cast<float>(1280.f), 0.0f, static_cast<float>(800.f));
  _shader.use();
  glUniformMatrix4fv(glGetUniformLocation(_shader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));


  glUniform3f(glGetUniformLocation(_shader.ID, "textColor"), _color.x, _color.y, _color.z);
  glActiveTexture(GL_TEXTURE0);
  glBindVertexArray(myVAO);

  string::const_iterator stringChar;
  for(stringChar = _text.begin(); stringChar != _text.end(); stringChar++) {
    Char myChar = characters[*stringChar];

    float xPos = _posAndScale.x + myChar.Bearing.x * _posAndScale.z;
    float yPos = _posAndScale.y - (myChar.Size.y - myChar.Bearing.y) * _posAndScale.z;
    float width = myChar.Size.x * _posAndScale.z;
    float height = myChar.Size.y * _posAndScale.z;

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
  glBindVertexArray(0);
  glBindTexture(GL_TEXTURE_2D, 0);
};