#include "../headers/draw.h"
#include "../headers/utils/cube_vertices.h"

void Draw::init() {
  this->matShader.compile("src/shaders/material/material.vs", "src/shaders/material/material.fs");
  this->lightShader.compile("src/shaders/light/light.vs", "src/shaders/light/light.fs");

  // glGenVertexArrays(1, &cubeVAO);
  // glGenBuffers(1, &vbo);
  // glBindBuffer(GL_ARRAY_BUFFER, vbo);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
  // glBindVertexArray(cubeVAO);

  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
  // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  // glEnableVertexAttribArray(1);

  // glGenVertexArrays(1, &lightVAO);
  // glBindVertexArray(lightVAO);

  // glBindBuffer(GL_ARRAY_BUFFER, vbo);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);

  // lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
}

void Draw::update() {
  // materialShader.use();
  // materialShader.setVec3("light.position", lightPos);
  // //materialShader.setVec3("viewPos", camera.Position);

  // glm::vec3 lightColor;
  // lightColor.x = sin(glfwGetTime() * 2.0f);
  // lightColor.y = sin(glfwGetTime() * 0.7f);
  // lightColor.z = sin(glfwGetTime() * 1.3f);
  // glm::vec3 diffuseColor = lightColor   * glm::vec3(0.5f);
  // glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
  // materialShader.setVec3("light.ambient", ambientColor);
  // materialShader.setVec3("light.diffuse", diffuseColor);
  // materialShader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

  // materialShader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
  // materialShader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
  // materialShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
  // materialShader.setFloat("material.shininess", 32.0f);

  // glm::mat4 projection = glm::mat4(1.0f); //= glm::perspective(glm::radians(camera.Zoom), (float)_screenWidth / (float)_screenHeight, 0.1f, 100.0f);
  // glm::mat4 view = glm::mat4(1.0f); //camera.GetViewMatrix();
  // materialShader.setMat4("projection", projection);
  // materialShader.setMat4("view", view);

  // glm::mat4 model = glm::mat4(1.0f);
  // materialShader.setMat4("model", model);

  // glBindVertexArray(cubeVAO);
  // glDrawArrays(GL_TRIANGLES, 0, 36);

  // lightShader.use();
  // lightShader.setMat4("projection", projection);
  // lightShader.setMat4("view", view);
  // model = glm::mat4(1.0f);
  // model = glm::translate(model, lightPos);
  // model = glm::scale(model, glm::vec3(0.2f));
  // lightShader.setMat4("model", model);

  // glBindVertexArray(lightVAO);
  // glDrawArrays(GL_TRIANGLES, 0, 36);
}