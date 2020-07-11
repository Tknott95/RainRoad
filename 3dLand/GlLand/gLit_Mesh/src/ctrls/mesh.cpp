#include "../headers/mesh.h"

Mesh::Mesh() {
    /* Pass path down prob via: param to call ub draw class dynamically down the stack */
    encodedObj = objLoader.load("assets/objects/plane.obj");

    shader.compile("assets/shaders/obj.vs", "assets/shaders/obj.fs");

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

  this->textureID = texture.load("assets/objects/plane.obj");

  shader.use();
  shader.setInt("myTexture", 0);
};

void Mesh::Draw(Shader &shader) {

};