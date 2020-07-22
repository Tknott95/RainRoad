#include "../headers/draw.h"

Draw::Draw()  {  /* onInit() */
  // this->mesh[0] = this->m00;
  // this->mesh[1] = this->m01;
};

Draw::~Draw() { /* deallocate anythin needed here */ };

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/
  // for(auto obj: this->mesh) {
  //   obj.draw(camera, screenSize);
  // };

  this->mesh[0].draw(camera, screenSize);
  this->mesh[1].draw(camera, screenSize);

 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
