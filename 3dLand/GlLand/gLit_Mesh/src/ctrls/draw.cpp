#include "../headers/draw.h"

Draw::Draw()  {  /* onInit() */ };
Draw::~Draw() { /* deallocate anythin needed here */ };

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/
  mesh.draw(camera, screenSize);
 /************* OBJ DRAWING FINISHED **********************/
 
 /************* SKYBOX DRAWING START **********************/
  skyMesh.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
}

void Draw::deallocate() {
  glDeleteVertexArrays(1, &skyboxVAO);
  glDeleteBuffers(1, &skyboxVBO);
}
