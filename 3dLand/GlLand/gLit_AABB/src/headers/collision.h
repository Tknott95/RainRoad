
class Collision {
  private:
    vec3 posBeforeCol;

  public:
    vec3 PosAfterCol;
    bool PointInsideAABB(vec3 myPos, vec3 otherPos);
    bool AABBInsideAABB(vec3, vec3);
};
