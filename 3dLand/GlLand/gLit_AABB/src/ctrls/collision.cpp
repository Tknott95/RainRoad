#include "../headers/collision.h"

bool Collision::PointInsideAABB(vec3 _pos, vec3 _otherPos) {
  vec3 _otherMag{1.f}; /* @TODO make this dynamic */
  _otherMag += vec3(0.33f);

  bool x0  = _pos.x >= _otherPos.x - _otherMag.x;
  bool x1  = _pos.x <= _otherPos.x + _otherMag.x;
  bool y0  = _pos.y >= _otherPos.y - _otherMag.y;
  bool y1  = _pos.y <= _otherPos.y + _otherMag.y;
  bool z0  = _pos.z >= _otherPos.z - _otherMag.z;
  bool z1  = _pos.z <= _otherPos.z + _otherMag.z;

  bool hasCollided = (x0 && x1) && (y0 && y1) && (z0 && z1);
  /********************
  * x1 -> FRONT
  * x0 -> BACK
  * y1 -> TOP
  * y0 -> BOTTOM
  * z1 -> LEFT
  * z0 -> RIGHT
  *
  * TO DEBUG
  *  1)  if(y1) printf("\e[2;1;40m TOP HIT \e[0m");
  *  2)  printf("\e[2;33;40m AABB(%f, %f, %f)\e[0m\n", PosAfterCol.x, PosAfterCol.y, PosAfterCol.z);
  ********************/
  if(hasCollided) this->PosAfterCol = _pos;

  return hasCollided;
};

bool Collision::AABBInsideAABB(vec3 _pos, vec3 _otherPos) {
  const float cubeMeshWidth = 1.33f;

  bool x00  = (_pos.x-cubeMeshWidth >= _otherPos.x-cubeMeshWidth && _pos.x+cubeMeshWidth <= _otherPos.x+cubeMeshWidth);
  bool y00  = (_pos.y-cubeMeshWidth >= _otherPos.y-cubeMeshWidth && _pos.y+cubeMeshWidth <= _otherPos.y+cubeMeshWidth);
  bool z00  = (_pos.z-cubeMeshWidth >= _otherPos.z-cubeMeshWidth && _pos.z+cubeMeshWidth <= _otherPos.z+cubeMeshWidth);

  bool hasCollided = x00 && y00 && z00;

  return hasCollided;
};
