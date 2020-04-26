#include "../headers/draw.h"
#include "../headers/utils/cube_vertices.h"

void Draw::init() {
  /* @TODO possibly make constructor/destructor for deallocating, is it needed? */
  // shader0.compile("src/shaders/basic/gl.vs", "src/shaders/basic/gl.fs");
  materialShader.compile("src/shaders/material/material.vs", "src/shaders/material/material.fs");
  lampShader.compile("src/shaders/light/light.vs", "src/shaders/light/light.fs");

  // glGenVertexArrays(1, &cubeVAO);
  // glGenBuffers(1, &VBO);

  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
  
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
  // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  // glEnableVertexAttribArray(1);
  
  // glGenVertexArrays(1, &lightVAO);
  // glBindVertexArray(lightVAO);

  // glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  // glEnableVertexAttribArray(0);
}

void Draw::update() {
  // shader0.use();
  // materialShader.use();
  // glBindVertexArray(vao);
  // glDrawArrays(GL_TRIANGLES, 0, 36);
}