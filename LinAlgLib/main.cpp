#include "v.h"
#include "m.h"

int main() {
  v2<float> v00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("v00(%f, %f)\n", v00.x, v00.y);
  // // v00 = v00 + v01 + v01 + v01;
  // v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  // v01 += v01;
  // printf("v00(%f, %f)\n", v00.x, v00.y);
  // printf("v01(%f, %f)\n", v01.x, v01.y);

  m2x2<float> m00;
  float m01_x[2] = {5.f, 7.f};
  float m01_y[2] = {6.f, 8.f};
  m2x2<float> m01 = {m01_x, m01_y};

  float m02_x[2] = {1.f, 3.f};
  float m02_y[2] = {2.f, 4.f};
  m2x2<float> m02 = {m02_x, m02_y};


  // printf("\nm00[[%f, %f], [%f, %f])\n", m00.x[0], m00.y[0], m00.x[1], m00.y[1]);
  // printf("m01[[%f, %f], [%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);

  printf("\n\n - b4 dotProd() \n");
  printf("m01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);
  printf("\nm02[\n[%f, %f],\n[%f, %f])\n", m02.x[0], m02.y[0], m02.x[1], m02.y[1]);

  m01 = m01 * m02; /* dotProd() order does matter */

  printf("\n  - after dotProd()");
  printf("\nm01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);




 /* - ##################################### - */
  v4<int> inputs = {1,2,3,4};
  v4<float> weights[2] = {{-0.4f, 0.7f, 0.2f, 0.4f}, {1.4, -0.8, -0.4, 0.4}};
  float biases[] = {0.2, 0.4};

  printf("\n i[0]: %i \n i[1]: %i \n i[2]: %i\n i[3]: %i", inputs.val[0], inputs.val[1],  inputs.val[2], inputs.val[3]);
  // v2<float> output = {{i[0]*w[0][0] + i[1]*w[0][1] + i[2]*w[0][2] + i[3]*w[0][3] + b[0]}, {i[0]*w[1][0] + i[1]*w[1][1] + i[2]*w[1][2] + i[3]*w[1][3] + b[1]}};

//  float output[2][1] = {
//     {i[0]*w[0][0] + i[1]*w[0][1] + i[2]*w[0][2] + i[3]*w[0][3] + b[0]},
//     {i[0]*w[1][0] + i[1]*w[1][1] + i[2]*w[1][2] + i[3]*w[1][3] + b[1]}
//   };

  // i = i * w[0];
  // printf("\n\n output[0][0]: %f", output[0][0]);
  // printf("\n output[1][0]: %f", output[1][0]);

  return 0;
}
