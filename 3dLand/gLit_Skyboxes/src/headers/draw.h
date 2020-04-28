#include <iostream>
#include <vector>
#include "shader.h"
#include "camera.h"
#include "texture.h"

using namespace glm;

class Draw {
  private:
    Texture texture;
    uint sbTexID;

  public:
    void init();
    void update(Camera* camera, ivec2 screenSize);
    void deallocate();
};
