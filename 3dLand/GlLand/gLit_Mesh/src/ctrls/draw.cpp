#include "../headers/draw.h"

Draw::Draw()  {  /* onInit() */
  this->mesh.push_back(m00);
  // this->mesh.push_back(m01);
};

Draw::~Draw() { /* deallocate anythin needed here */ };

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/
  // for(auto obj: this->mesh) {
  //   obj.draw(camera, screenSize);
  // };

  this->mesh[0].draw(camera, screenSize);
  this->mesh[1].draw(camera, screenSize);
  this->m01.draw(camera, screenSize);

 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
