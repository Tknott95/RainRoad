#include "../headers/draw.h"
#include "../headers/utils/cube_data.h"
#include "../headers/utils/skybox_data.h"

void Draw::init() {
  std::vector<std::string> sbFaces = {
    "assets/skybox/right.jpg",
    "assets/skybox/left.jpg",
    "assets/skybox/top.jpg",
    "assets/skybox/bottom.jpg",
    "assets/skybox/front.jpg",
    "assets/skybox/back.jpg"
  };
  glEnable(GL_DEPTH_TEST);
  skyboxShader.compile("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");

   /******** binding skybox attribs *******/
  glGenVertexArrays(1, &skyboxVAO);
  glGenBuffers(1, &skyboxVBO);
  glBindVertexArray(skyboxVAO);
  glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  sbTexID = texture.loadSkybox(sbFaces);

  skyboxShader.use();
  skyboxShader.setInt("skybox", 0);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
  /* VIEW WHEN DRAWING AN OBJ: mat4 view = camera->GetViewMatrix(); */
  /************* SKYBOX DRAWING START **********************/
  glDepthFunc(GL_LEQUAL);
  skyboxShader.use();

  mat4 view = mat4(mat3(camera->GetViewMatrix()));
  mat4 projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.f);

  skyboxShader.setMat4("view", view);
  skyboxShader.setMat4("projection", projection);

  glBindVertexArray(skyboxVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, sbTexID);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);
  glDepthFunc(GL_LESS);
  /************* SKYBOX DRAWING FINISHED **********************/
}

void Draw::deallocate() {
  glDeleteVertexArrays(1, &skyboxVAO);
  glDeleteBuffers(1, &skyboxVBO);
}
