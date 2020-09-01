#include <cstdio>
#include <glm/glm.hpp>

using namespace glm;

struct PosAndMag {
  vec3 Pos;
  vec3 Mag;

  PosAndMag(): Mag(vec3(1.f)) {};
};

class Collision {
  private:
    
  public:
    vec3 PosBeforeCol;
    vec3 PosAfterCol;
    bool PointInsideAABB(vec3, PosAndMag);
    bool AABBInsideAABB(vec3, vec3);
};
