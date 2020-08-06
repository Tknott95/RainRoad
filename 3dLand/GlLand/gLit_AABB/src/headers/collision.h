#include <glm/glm.hpp>
using namespace glm;

class Collision {
  private:
    
  public:
    vec3 PosBeforeCol;
    vec3 PosAfterCol;
    bool PointInsideAABB(vec3, vec3);
    bool AABBInsideAABB(vec3, vec3);
};
