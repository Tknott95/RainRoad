#include "v.h"
#include "m.h"

int main() {
  v2<float> v00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("v00(%f, %f)\n", v00.x, v00.y);
  v00 = v00 + v01 + v01 + v01;
  v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  v01 += v01;
  printf("v00(%f, %f)\n", v00.x, v00.y);
  printf("v01(%f, %f)\n", v01.x, v01.y);

  m2x2<float> m00;  /* {x1, y1, x2, y2} */
  m2x2<float> m01 = {5.f, 7.f, 6.f, 8.f};
  m2x2<float> m02 = {1.f, 2.f, 3.f, 4.f};

  // printf("\n\n - b4 dotProd() \n");
  // printf("m01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);
  // printf("\nm02[\n[%f, %f],\n[%f, %f])\n", m02.x[0], m02.y[0], m02.x[1], m02.y[1]);
  // m01 = m01 * m02; /* dotProd() order does matter */
  // printf("\n  - after dotProd()");
  // printf("\nm01[\n[%f, %f],\n[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);




 /* - ##################################### - */
  v4<int> inputs = {1,2,3,4};
  v2<v4<float>> weights = {{-0.4f, 0.7f, 0.2f, 0.4f}, {1.4, -0.8, -0.4, 0.4}};
  v2<float> biases = {0.2, 0.4};

  printf("\n i[0]: %i \n i[1]: %i \n i[2]: %i\n i[3]: %i", inputs.val[0], inputs.val[1],  inputs.val[2], inputs.val[3]);
  v2<float> output = {{inputs.val[0]*weights.val[0].val[0] + inputs.val[1]*weights.val[0].val[1]+ inputs.val[2]*weights.val[0].val[2] + inputs.val[3]*weights.val[0].val[3] + biases.val[0]}, {inputs.val[0]*weights.val[1].val[0] + inputs.val[1]*weights.val[1].val[1] + inputs.val[2]*weights.val[1].val[2] + inputs.val[3]*weights.val[1].val[3] + biases.val[1]}};

  printf("\n\n weights[0][0]: %.2f", weights.val[0].val[0]);
  printf("\n\n output[0]: %.1f", output.val[0]);
  printf("\n output[1]: %.1f", output.val[1]);

  return 0;
}
