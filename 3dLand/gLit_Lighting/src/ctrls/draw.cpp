#include "../headers/draw.h"
#include "../headers/utils/cube_vertices.h"

/*************************************
 * 
 *   glDeleteVertexArrays(1, &cubeVAO);
 *   glDeleteVertexArrays(1, &lightVAO);
 *   glDeleteBuffers(1, &VBO);
 * 
 *    @TODO create a con/de(structor)
 * ***********************************/

void Draw::init() {
  lightPos = vec3(1.2f, 1.0f, 2.0f);
  // lightColor = glm::vec3(0.9f, 0.8f, 0.1f);
  lightColor.x = sin(glfwGetTime() * 2.0f);
  lightColor.y = sin(glfwGetTime() * 0.7f);
  lightColor.z = sin(glfwGetTime() * 1.3f);
  /* @TODO possibly make constructor/destructor for deallocating, is it needed? */
  // shader0.compile("src/shaders/basic/gl.vs", "src/shaders/basic/gl.fs");
  materialShader.compile("src/shaders/material/material.vs", "src/shaders/material/material.fs");
  lampShader.compile("src/shaders/light/light.vs", "src/shaders/light/light.fs");

  glGenVertexArrays(1, &cubeVAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  
  glGenVertexArrays(1, &lightVAO);
  glBindVertexArray(lightVAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Draw::update(Camera* camera, ivec2 screenSize) {
  // shader0.use();
  materialShader.use();
  materialShader.setVec3("light.position", lightPos);
  materialShader.setVec3("viewPos", camera->Position);

  vec3 diffuseColor = lightColor * vec3(0.5f);
  vec3 ambientColor = diffuseColor * vec3(0.2f);
  materialShader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
  materialShader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
  materialShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
  materialShader.setFloat("material.shininess", 32.0f);

  mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.0f);
  mat4 view = camera->GetViewMatrix();
  materialShader.setMat4("projection", projection);
  materialShader.setMat4("view", view);

  mat4 model = glm::mat4(1.0f);
  materialShader.setMat4("model", model);
  
  glBindVertexArray(cubeVAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);

         // also draw the lamp object
  lampShader.use();
  lampShader.setMat4("projection", projection);
  lampShader.setMat4("view", view);
  model = glm::mat4(1.0f);
  model = glm::translate(model, lightPos);
  model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
  lampShader.setMat4("model", model);

  glBindVertexArray(lightVAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);
}