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

  bool returnBool = (x0 && x1) && (y0 && y1) && (z0 && z1);

  if(returnBool) {
    this->PosAfterCol = this->PosBeforeCol;
    printf("\e[0;33;40m PointInsideAABB @(%f, %f, %f) \e[0m \n", PosAfterCol.x, PosAfterCol.y, PosAfterCol.z);
  };

  return returnBool;
};

bool Collision::AABBInsideAABB(vec3 _pos, vec3 _otherPos) {
  const float cubeMeshWidth = 1.25f;

  return (_pos.x-cubeMeshWidth >= _otherPos.x-cubeMeshWidth && _pos.x+cubeMeshWidth <= _otherPos.x+cubeMeshWidth) &&
   (_pos.y-cubeMeshWidth >= _otherPos.y-cubeMeshWidth && _pos.y+cubeMeshWidth <= _otherPos.y+cubeMeshWidth) &&
   (_pos.z-cubeMeshWidth >= _otherPos.z-cubeMeshWidth && _pos.z+cubeMeshWidth <= _otherPos.z+cubeMeshWidth);
};
