#include "../headers/collision.h"

bool Collision::PointInsideAABB(vec3 _pos, vec3 _otherPos) {
 const vec3 _otherMag{1.25f}; /* @TODO make this dynamic */
 // this->PosAfterCol = _pos;
 bool returnBool = (_pos.x >= _otherPos.x-_otherMag.x && _pos.x <= _otherPos.x+_otherMag.x) &&
  (_pos.y >= _otherPos.y-_otherMag.y && _pos.y <= _otherPos.y + _otherMag.y) &&
  (_pos.z >= _otherPos.z-_otherMag.z && _pos.z <= _otherPos.z + _otherMag.z);

  /***
  * @TODO track which side hit, as above alrdy does,
  *  and add 0.10f more for better cols
  ****/
  if(returnBool) this->PosAfterCol = this->PosBeforeCol;

  return returnBool;
};

bool Collision::AABBInsideAABB(vec3 _pos, vec3 _otherPos) {
  const float cubeMeshWidth = 1.25f;

  return (_pos.x-cubeMeshWidth >= _otherPos.x-cubeMeshWidth && _pos.x+cubeMeshWidth <= _otherPos.x+cubeMeshWidth) &&
   (_pos.y-cubeMeshWidth >= _otherPos.y-cubeMeshWidth && _pos.y+cubeMeshWidth <= _otherPos.y+cubeMeshWidth) &&
   (_pos.z-cubeMeshWidth >= _otherPos.z-cubeMeshWidth && _pos.z+cubeMeshWidth <= _otherPos.z+cubeMeshWidth);
};
