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
vec3 cubePos[] = {
  vec3(0.0f,  0.0f,  0.0f),
  vec3(1.0f,  1.0f, -2.0f),
  vec3(-1.4f, 0.6f, -0.5f),
};

void Draw::init() {
  lightPos = vec3(0.5f, 0.6f, 2.0f);

  /* @TODO possibly make constructor/destructor for deallocating, is it needed? */
  materialShader.compile("src/shaders/material/material.vs", "src/shaders/material/material.fs");
  lampShader.compile("src/shaders/light/light.vs", "src/shaders/light/light.fs");
  
  glGenVertexArrays(1, &cubeVAO);
  glGenBuffers(1, &VBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

  glBindVertexArray(cubeVAO);
  
  /* Material Shader */
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  
  /* Lamp Shader */
  glGenVertexArrays(1, &lightVAO);
  glBindVertexArray(lightVAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  diffuseMap = texture.load("assets/textures/box_cloud.png");
  specMap = texture.load("assets/textures/box_specular.png");
  emissionMap = texture.load("assets/textures/matrix.jpg");

  materialShader.use();
  materialShader.setInt("material.diffuse", 0);
  materialShader.setInt("material.specular", 1);
  // materialShader.setInt("material.specular", 2);/* makes matrix come from light if 2 instead of emission */
  materialShader.setInt("material.emission", 2);

}

void Draw::update(Camera* camera, ivec2 screenSize) {

  materialShader.use();
  materialShader.setVec3("light.position", lightPos);
  materialShader.setVec3("viewPos", camera->Position);
  materialShader.setFloat("time", glfwGetTime());

  // lightColor.x = sin(glfwGetTime() * 2.0f);
  // lightColor.y = sin(glfwGetTime() * 0.7f);
  // lightColor.z = sin(glfwGetTime() * 1.3f);

  materialShader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
  materialShader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
  materialShader.setVec3("light.specular", 1.50f, 1.5f, 1.5f);

  materialShader.setVec3("material.ambient", 1.0f, 0.5f, 0.31f);
  materialShader.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
  materialShader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
  materialShader.setFloat("material.shininess", 64.0f);

  mat4 projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.0f);
  mat4 view = camera->GetViewMatrix();
  mat4 transform = mat4(1.0f);
  materialShader.setMat4("projection", projection);
  materialShader.setMat4("view", view);
  materialShader.setMat4("tranform", transform);


 
  // model0 = scale(model0, vec3(1.0f));

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, diffuseMap);
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, specMap);
  glActiveTexture(GL_TEXTURE2);
  glBindTexture(GL_TEXTURE_2D, emissionMap);

  glBindVertexArray(cubeVAO);
  
  float rotTime = sin(glfwGetTime() * 1.3f);
  

  for(size_t i=0; i < 3; i++) {
    mat4 model0 = mat4(1.0f);
    model0 = translate(model0, cubePos[i] * vec3(1.10f));
    model0 = rotate(model0, rotTime, vec3(1.0f, 0.3f, 0.3f));
    materialShader.setMat4("model", model0);
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }


  lampShader.use();
  lampShader.setMat4("projection", projection);
  lampShader.setMat4("view", view);
  mat4 model1 = mat4(1.0f);
  model1 = translate(model1, lightPos);
  model1 = scale(model1, vec3(0.2f));
  lampShader.setMat4("model", model1);

  glBindVertexArray(lightVAO);
  glDrawArrays(GL_TRIANGLES, 0, 36);
}