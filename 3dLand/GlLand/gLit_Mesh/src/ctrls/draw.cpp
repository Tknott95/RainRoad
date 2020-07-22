#include "../headers/draw.h"

Draw::Draw()  {  /* onInit() */
  this->mesh.emplace_back(this->skybox);
  this->mesh.emplace_back(this->m00);
};

Draw::~Draw() { /* deallocate anythin needed here */ };

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/
 // mesh[1].draw(camera, screenSize);
 // mesh.draw(camera, screenSize);
 /************* OBJ DRAWING FINISHED **********************/
 
 /************* SKYBOX DRAWING START **********************/
  // mesh[0].draw(camera, screenSize);
  // mesh[0].draw(camera, screenSize);
  // this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
  // if(int k = mesh.size()-1; k>=0; k--) {
  //   this->mesh[k].draw(camera, screenSize);
  //   printf("\n  k(%i)", k);
  // };

  this->mesh[1].draw(camera, screenSize);
  this->mesh[0].draw(camera, screenSize);
};
