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
  float m01_x[2] = {5.f, 7.f};
  float m01_y[2] = {6.f, 8.f};
  m2x2<float> m01 = {m01_x, m01_y};

  float m02_x[2] = {1.f, 3.f};
  float m02_y[2] = {2.f, 4.f};
  m2x2<float> m02 = {m02_x, m02_y};


  // printf("\nm00[[%f, %f], [%f, %f])\n", m00.x[0], m00.y[0], m00.x[1], m00.y[1]);
  // printf("m01[[%f, %f], [%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);

  printf("\n\nBEFORE MULTIPLY\n");
  printf("m01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);
  printf("\nm02[\n[%f, %f],\n[%f, %f])\n", m02.x[0], m02.y[0], m02.x[1], m02.y[1]);

  m01 = m01 * m02;

  printf("\n AFTER MULTIPLY");
  printf("\nm01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);
  printf("\nm02[\n[%f, %f],\n[%f, %f])\n", m02.x[0], m02.y[0], m02.x[1], m02.y[1]);


  return 0;
}
