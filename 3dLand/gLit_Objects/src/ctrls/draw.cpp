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

  objData = objLoader.load("assets/objects/oddShape.obj"); /* star.obj | oddShape.obj */

  skyboxShader.compile("assets/shaders/skybox.vs", "assets/shaders/skybox.fs");
  objShader.compile("assets/shaders/obj.vs", "assets/shaders/obj.fs");

  glGenVertexArrays(1, &objVAO);
  glGenBuffers(1, &objVBO);
  glGenBuffers(1, &objEBO);
  glBindVertexArray(objVAO);
  glBindBuffer(GL_ARRAY_BUFFER, objVBO); //  * sizeof(glm::vec3)
  glBufferData(GL_ARRAY_BUFFER, objData.vertices.size(), &objData.vertices[0], GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, objEBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, objData.vertIndices.size() * sizeof(uint), &objData.vertIndices[0], GL_STATIC_DRAW);

  glGenVertexArrays(1, &skyboxVAO);
  glGenBuffers(1, &skyboxVBO);
  glBindVertexArray(skyboxVAO);
  /* @TODO need texture coordinates imported in */
  glActiveTexture(GL_TEXTURE1);
  glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

  sbTexID = texture.loadSkybox(sbFaces);
  objTexID = texture.load("assets/textures/box_weave.png");

  glDepthMask(GL_FALSE);
  skyboxShader.use();
  skyboxShader.setInt("skybox", 0);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
  glDepthFunc(GL_LEQUAL);
  skyboxShader.use();

  mat4 view = mat4(mat3(camera->GetViewMatrix()));
  mat4 projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.f);
  // view = mat4(mat3(camera->GetViewMatrix()));
  skyboxShader.setMat4("view", view);
  skyboxShader.setMat4("projection", projection);

  glBindVertexArray(skyboxVAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_CUBE_MAP, sbTexID);
  glDrawArrays(GL_TRIANGLES, 0, 36);
  glBindVertexArray(0);


  objShader.use();
  mat4 model = mat4(1.0f);
  mat4 transform = mat4(1.0f);
  transform = translate(transform, glm::vec3(0.0f, 5.0f, 5.0f));
  objShader.setMat4("model", model);
  objShader.setMat4("view", view);
  objShader.setMat4("projection", projection);
  objShader.setMat4("transform", transform);
  // mat4 objColor = mat4(1.0f, 1.0f, 1.0f, 1.0f);
  // objShader.setMat4("ourColor", objColor);
  glBindVertexArray(objVAO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, objEBO);

  // glBindBuffer(objEBO);
  /* @TODO need texture coordinates imported in */
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE1, objTexID);

  // glDrawArrays(GL_TRIANGLES, 0 , objData.vertices.size());
  glDrawElements(GL_TRIANGLES, objData.vertIndices.size(), GL_UNSIGNED_INT, 0);

  glBindVertexArray(0);
  glDepthFunc(GL_LESS);
}

void Draw::deallocate() {
  glDeleteVertexArrays(1, &skyboxVAO);
  glDeleteBuffers(1, &skyboxVBO);
}
