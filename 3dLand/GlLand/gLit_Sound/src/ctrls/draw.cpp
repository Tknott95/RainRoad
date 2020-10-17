#include "../headers/draw.h"

void Draw::renderGUI(Camera* camera, ivec2 screenSize, int fps) {
  const string fpsText = "FPS: " + to_string(fps);
  font.Draw(
    fpsText,                     // TextToRender
    fontShader,                  // Shader
    vec3(5.f, 5.f, 1.f),         // (Pos(x,y), and Scale)
    vec3(0.05f, 0.35f, 0.55f)    // Color  0.f->1.f
  );
 
  string camPos[3] = {
    to_string(camera->transform.Position.x).substr(0,4),
    to_string(camera->transform.Position.y).substr(0,4),
    to_string(camera->transform.Position.z).substr(0,4)
  };
  const string camString = camPos[0]+", " +camPos[1]+", " +camPos[2];

  camLoc.Draw(
    camString,
    fontShader,
    vec3(screenSize.x*0.40, screenSize.y*0.9, 0.5f),
    vec3(0.7f, 0.9f, 0.91f)
  );
};


Draw::Draw() { fontShader.compile("assets/shaders/font/font.vs","assets/shaders/font/font.fs"); };
Draw::~Draw() {};

void Draw::update(Camera* camera, ivec2 screenSize, int fps) {
  glClearColor(0.f, 0.f, 0.14f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  this->renderGUI(camera, screenSize, fps);
  this->audio.Update();

 /************* OBJ DRAWING START **********************/
  const int meshSize = sizeof(mesh)/sizeof(mesh[0]);
  for(int k=0;k<meshSize;k++) {
    this->mesh[k].draw(camera, screenSize);
  };

  /***** COLLISION CHECKING *****/
  PosAndMag myPosAndMag;
  myPosAndMag.Mag = vec3(1.f);
  myPosAndMag.Pos = this->mesh[1].pos;
  this->CameraCollided = collision.PointInsideAABB(camera->transform.Position, myPosAndMag);
  if(!this->CameraCollided) collision.PosBeforeCol = camera->transform.Position;
  /***** COLLISION CHECKING FINISHED *****/

 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
