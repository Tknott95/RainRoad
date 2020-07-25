#include "../headers/draw.h"

void Draw::renderGUI() {
  font.Draw(
    "FPS: ++", // TextToRender
    fontShader,              // Shader
    vec3(5.f, 5.f, 1.f),   // (Pos(x,y), and Scale)
    vec3(0.05f, 0.35f, 0.55f)    // Color  (0->255 == 0.f->1.f)
  );

};

Draw::Draw()  {
  fontShader.compile("assets/shaders/font/font.vs","assets/shaders/font/font.fs");
};
Draw::~Draw() {};

void Draw::update(Camera* camera, ivec2 screenSize) {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  this->renderGUI();
 /************* OBJ DRAWING START **********************/
  const int meshSize = sizeof(mesh)/sizeof(mesh[0]);
  for(int k=0;k<meshSize;k++) {
    this->mesh[k].draw(camera, screenSize);
  };
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
