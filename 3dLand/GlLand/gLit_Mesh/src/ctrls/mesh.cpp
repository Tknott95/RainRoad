#include "../headers/mesh.h"

Mesh::Mesh() {
    /* Pass path down prob via: param to call ub draw class dynamically down the stack */
    shader.compile("assets/shaders/obj.vs", "assets/shaders/obj.fs");
    encodedObj = objLoader.load("assets/objects/plane.obj"); 

    this->init();
};

void Mesh::init() {
  glGenVertexArrays(1, &VAO);

  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  glGenBuffers(1, &UVBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, encodedObj.vertices.size() * sizeof(vec3), &encodedObj.vertices[0], GL_STATIC_DRAW);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(
    0, /* matches layout in header */
    3, /* size */
    GL_FLOAT, /* type */
    GL_FALSE, /* isNormalized? */
    sizeof(vec3), /*  or 3 * sizeof(float) | stride, matches my data xyz|vec3*/
    (void*)0 /* array buffer offset */
  );
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, UVBO);
  glBufferData(GL_ARRAY_BUFFER, encodedObj.uvs.size() * sizeof(vec2), &encodedObj.uvs[0], GL_STATIC_DRAW);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vec2), (void*)0);
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, objLoader.vertIndices.size() * sizeof(uint), &objLoader.vertIndices[0], GL_STATIC_DRAW);

  glBindVertexArray(0); /* may not need */

  this->textureID = texture.load("assets/textures/box_weave.png");

  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shader.use();
  shader.setInt("myTexture", 0);
};

void Mesh::draw(Camera* camera, ivec2 screenSize) {
  shader.use();

  sP.model = mat4(1.0f);
  sP.transform = mat4(1.0f);
  sP.projection = perspective(radians(camera->Zoom), (float)screenSize.x / (float)screenSize.y, 0.1f, 100.f);
  sP.view = camera->GetViewMatrix();
  sP.transform = translate(sP.transform, glm::vec3(1.0f, -1.0f, 0.0f));

  shader.setMat4("model", sP.model);
  shader.setMat4("view", sP.view);
  shader.setMat4("projection", sP.projection);
  shader.setMat4("transform", sP.transform);

  glBindVertexArray(VAO);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glDrawElements(GL_TRIANGLES, sizeof(objLoader.vertIndices), GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
};
