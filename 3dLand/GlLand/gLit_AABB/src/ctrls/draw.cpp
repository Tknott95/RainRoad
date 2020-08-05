#include "../headers/draw.h"

bool Draw::isPointInsideAABB(vec3 _pos, vec3 _otherPos) {
 const float cubeMeshWidth = 1.25f;
 bool returnBool = (_pos.x >= _otherPos.x-cubeMeshWidth && _pos.x <= _otherPos.x+cubeMeshWidth) &&
  (_pos.y >= _otherPos.y-cubeMeshWidth && _pos.y <= _otherPos.y+cubeMeshWidth) &&
  (_pos.z >= _otherPos.z-cubeMeshWidth && _pos.z <= _otherPos.z+cubeMeshWidth);

  if(returnBool) this->NewCamPosAfterCol = _pos;

  return returnBool;
};

bool Draw::isAABBInsideAABB(vec3 _pos, vec3 _otherPos) {
  const float cubeMeshWidth = 1.25f;

  return (_pos.x-cubeMeshWidth >= _otherPos.x-cubeMeshWidth && _pos.x+cubeMeshWidth <= _otherPos.x+cubeMeshWidth) &&
   (_pos.y-cubeMeshWidth >= _otherPos.y-cubeMeshWidth && _pos.y+cubeMeshWidth <= _otherPos.y+cubeMeshWidth) &&
   (_pos.z-cubeMeshWidth >= _otherPos.z-cubeMeshWidth && _pos.z+cubeMeshWidth <= _otherPos.z+cubeMeshWidth);
};

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
 /************* OBJ DRAWING START **********************/
  const int meshSize = sizeof(mesh)/sizeof(mesh[0]);
  for(int k=0;k<meshSize;k++) {
    this->mesh[k].draw(camera, screenSize);
  };

  bool hasCollided = isPointInsideAABB(camera->transform.Position, this->mesh[2].pos);
  this->MoveCameraOnCol = hasCollided;

  cout << "\e[0;33;40m hasCollided: " << hasCollided << "\e[0m \n" << endl;
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
