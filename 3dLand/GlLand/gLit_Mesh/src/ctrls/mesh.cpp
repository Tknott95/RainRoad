#include "../headers/mesh.h"

Mesh::Mesh() {
    /* Pass path down prob via: param to call ub draw class dynamically down the stack */
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
};

void Mesh::loadObjects() {

};

void Mesh::Draw() {

};