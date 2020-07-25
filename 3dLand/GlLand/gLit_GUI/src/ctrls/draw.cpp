#include "../headers/draw.h"

Draw::Draw()  {};
Draw::~Draw() {};

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/

 font.Draw("das one lit gui homie");
  const int meshSize = sizeof(mesh)/sizeof(mesh[0]);
  for(int k=0;k<meshSize;k++) {
    this->mesh[k].draw(camera, screenSize);
  };
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
