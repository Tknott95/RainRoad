#include "../headers/texture.h"

uint Texture::load(const char *path) {
  uint texID;
  glGenTextures(1, &texID);

  int width, height, nrComponents;
  unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
  if (data) {
    GLenum format;
    if (nrComponents == 1) format = GL_RED;
    else if (nrComponents == 3) format = GL_RGB;
    else if (nrComponents == 4) format = GL_RGBA;

    glBindTexture(GL_TEXTURE_2D, texID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(data);
  } else {
    std::cout << "\n\e[0;31;40m Texture failed to load at path: " << path << " \e[0m" << std::endl;
    stbi_image_free(data);
  }

  printf("\n  \e[1;95;40m  Texture(%d) Loaded:\e[0;33;40m %s \e[0m\n", texID, path);

  return texID;
}

uint Texture::loadSkybox(std::vector<std::string> _sbFaces) {
  /* @TODO move into my texture class */
  uint texID;
  glGenTextures(1, &texID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, texID);

  int width, height, numChannels;
  for(uint i = 0; i < _sbFaces.size(); i++) {
    u_char *data = stbi_load(_sbFaces[i].c_str(), &width, &height, &numChannels, 0);

    if(data) {
      glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      stbi_image_free(data);
    } else {
      std::cout << "\e[0;31;40m Skybox texture failed to load: " << _sbFaces[i] << "\e[0m" <<std::endl;
      stbi_image_free(data);
    }
    
    printf("\n  \e[1;95;40m  Texture(%d) Loaded:\e[0;33;40m %s \e[0m\n", texID, _sbFaces[i].c_str());
  }

  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return texID;
}
