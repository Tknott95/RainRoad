#include "../headers/draw.h"

Draw::Draw()  {};
Draw::~Draw() {};

void Draw::update(Camera* camera, ivec2 screenSize) {
 /************* OBJ DRAWING START **********************/

  fontShader.compile("assets/shaders/font/font.vs","assets/shaders/font/font.fs");
  font.Draw(
    "das one lit gui homie",
    fontShader,
    vec3(25.f, 25.f, 1.f),
    vec3(0.2, 0.2f, 0.6f)
  );
  const int meshSize = sizeof(mesh)/sizeof(mesh[0]);
  for(int k=0;k<meshSize;k++) {
    this->mesh[k].draw(camera, screenSize);
  };
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
