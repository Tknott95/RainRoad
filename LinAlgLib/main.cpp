#include "v.h"
#include "m.h"

int main() {
  v2<float> v00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("v00(%f, %f)\n", v00.x, v00.y);
  // v00 = v00 + v01 + v01 + v01;
  v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  v01 += v01;
  printf("v00(%f, %f)\n", v00.x, v00.y);
  printf("v01(%f, %f)\n", v01.x, v01.y);

  m2x2<float> m00;
  float f2[2] = {2.f, 2.f};
  float f3[2] = {2.f, 2.f};
  m2x2<float> m01 = {f2, f3};
  printf("\nm00[[%f, %f], [%f, %f])\n", m00.x[0], m00.y[0], m00.x[1], m00.y[1]);
  //  printf("m01[[%f, %f], [%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);

  return 0;
}
