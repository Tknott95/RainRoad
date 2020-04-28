#include "../headers/draw.h"
#include "../headers/utils/cube_data.h"
#include "../headers/utils/skybox_data.h"

uint Draw::loadSkybox(std::vector<std::string> _sbFaces) {
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
  }

  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

  return texID;
}

void Draw::init() {

  std::vector<std::string> sbFaces = {
    "assets/skybox/right.jpg",
    "assets/skybox/left.jpg",
    "assets/skybox/top.jpg",
    "assets/skybox/bottom.jpg",
    "assets/skybox/front.jpg",
    "assets/skybox/back.jpg"
  };

  skyboxShader.compile("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");

  glGenVertexArrays(1, &skyboxVAO);
  glGenBuffers(1, &skyboxVBO);
  glBindVertexArray(skyboxVAO);
  glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  sbTexID = loadSkybox(sbFaces);

  glDepthMask(GL_FALSE);
  skyboxShader.use();
  skyboxShader.setInt("skybox", 0);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
  // glDepthFunc(GL_LEQUAL);
  glDepthMask(GL_FALSE);
  skyboxShader.use();

  mat4 view = mat4(1.0f);
  mat4 projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.f);
  view = mat4(mat3(camera->GetViewMatrix()));
  skyboxShader.setMat4("view", view);
  skyboxShader.setMat4("projection", projection);

  glBindVertexArray(skyboxVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, sbTexID);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);
  // glDepthFunc(GL_LESS);
  glDepthMask(GL_TRUE);
}

void Draw::deallocate() {
  glDeleteVertexArrays(1, &skyboxVAO);
  glDeleteBuffers(1, &skyboxVBO);
}
