#include "../headers/draw.h"

// void Draw::addToMesh(Mesh _m) {
//   this->mesh.push_back(_m);
// };

Draw::Draw()  {  /* onInit() */
  this->mesh.push_back(m00);
  // this->addToMesh(m00);
};

Draw::~Draw() { /* deallocate anythin needed here */ };

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/
  // for(auto obj: this->mesh) {
  //   obj.draw(camera, screenSize);
  // };

  this->mesh[0].draw(camera, screenSize);
  
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
