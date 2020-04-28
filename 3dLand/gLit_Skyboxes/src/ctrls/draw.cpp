#include "../headers/draw.h"
#include "../headers/utils/cube_data.h"


void Draw::init() {

  std::vector<std::string> sbFaces = {
    "assets/skybox/right.jpg",
    "assets/skybox/left.jpg",
    "assets/skybox/top.jpg",
    "assets/skybox/bottom.jpg",
    "assets/skybox/front.jpg",
    "assets/skybox/back.jpg"
  };


  glGenTextures(1, &sbTexID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, sbTexID);

  int width, height, numChannels;
  for(uint i = 0; i < sbFaces.size(); i++) {
    u_char *data = stbi_load(sbFaces[i].c_str(), &width, &height, &numChannels, 0);

    if(data) {
      glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      stbi_image_free(data);
    } else {
      std::cout << "\e[0;31;40m Skybox texture failed to load: " << sbFaces[i] << "\e[0m" <<std::endl;
      stbi_image_free(data);
    }
  }

  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
}

void Draw::deallocate() {
}