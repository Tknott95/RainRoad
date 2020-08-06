#include "../headers/collision.h"

bool Collision::PointInsideAABB(vec3 _pos, vec3 _otherPos) {
  const vec3 _otherMag{1.25f}; /* @TODO make this dynamic */

  /* Modularized for tracking "the side collided" */
  bool x0  = _pos.x >= _otherPos.x - _otherMag.x;
  bool x1  = _pos.x <= _otherPos.x + _otherMag.x;
  bool y0  = _pos.y >= _otherPos.y - _otherMag.y;
  bool y1  = _pos.y <= _otherPos.y + _otherMag.y;
  bool z0  = _pos.z >= _otherPos.z - _otherMag.z;
  bool z1  = _pos.z <= _otherPos.z + _otherMag.z;
  bool hasCollided = (x0 && x1) && (y0 && y1) && (z0 && z1);

  /* TRACKING FACE COLLIDED WITH */
  if(x0) printf("\e[2;34;40m x0 HIT \e[0m\n");
  if(x1) printf("\e[2;34;40m x1 HIT \e[0m\n");
  if(y0) printf("\e[2;34;40m y0 HIT \e[0m\n");
  if(y1) printf("\e[2;34;40m y1 HIT \e[0m\n");
  if(z0) printf("\e[2;34;40m z0 HIT \e[0m\n");
  if(z1) printf("\e[2;34;40m z1 HIT \e[0m\n");

  if(hasCollided) /* printf("\e[2;33;40m AABB(%f, %f, %f)\e[0m\n", PosAfterCol.x, PosAfterCol.y, PosAfterCol.z); */
    this->PosAfterCol = this->PosBeforeCol;


  return hasCollided;
};

bool Collision::AABBInsideAABB(vec3 _pos, vec3 _otherPos) {
  const float cubeMeshWidth = 1.25f;

  return (_pos.x-cubeMeshWidth >= _otherPos.x-cubeMeshWidth && _pos.x+cubeMeshWidth <= _otherPos.x+cubeMeshWidth) &&
   (_pos.y-cubeMeshWidth >= _otherPos.y-cubeMeshWidth && _pos.y+cubeMeshWidth <= _otherPos.y+cubeMeshWidth) &&
   (_pos.z-cubeMeshWidth >= _otherPos.z-cubeMeshWidth && _pos.z+cubeMeshWidth <= _otherPos.z+cubeMeshWidth);
};
