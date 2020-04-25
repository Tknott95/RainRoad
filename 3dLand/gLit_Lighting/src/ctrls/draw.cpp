#include "../headers/draw.h"
#include "../headers/utils/cube_vertices.h"

void Draw::init() {
  shader0.compile("src/shaders/basic/gl.vs", "src/shaders/basic/gl.fs");

  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
  
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void Draw::update() {
  shader0.use();
  glBindVertexArray(vao);
  glDrawArrays(GL_TRIANGLES, 0, 36);
}