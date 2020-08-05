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


// return (point.x >= box.minX && point.x <= box.maxX) &&
//        (point.y >= box.minY && point.y <= box.maxY) &&
//        (point.z >= box.minZ && point.z <= box.maxZ);
bool Draw::isPointInsideAABB(vec3 _pos, vec3 _otherPos/*float other[6]*/) {
 const float cubeMeshWidth = 1.0f;
 return (_pos.x >= _otherPos.x-cubeMeshWidth && _pos.x <= _otherPos.x+cubeMeshWidth) &&
  (_pos.y >= _otherPos.y-cubeMeshWidth && _pos.y <= _otherPos.y+cubeMeshWidth) &&
  (_pos.z >= _otherPos.z-cubeMeshWidth && _pos.z <= _otherPos.z+cubeMeshWidth);
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
  // printf("\e[0;33;40m meshPos(%f, %f, %f)\e[0m \n", this->mesh[2].pos.x, this->mesh[2].pos.y, this->mesh[2].pos.z);
  std::cout << "\e[0;33;40m hasCollided: " << hasCollided << "\e[0m \n" << std::endl;
 /************* OBJ DRAWING FINISHED **********************/
 /************* SKYBOX DRAWING START **********************/
  this->skybox.draw(camera, screenSize);
 /************* SKYBOX DRAWING FINISHED **********************/
};
