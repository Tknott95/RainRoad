#include "v.h"
#include "m.h"

int main() {
/* - ################   v2 testing   ################# - */
  v2<float> v00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("v00(%f, %f)\n", v00.x, v00.y);
  v00 = v00 + v01 + v01 + v01;
  v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  v01 += v01;
  printf("v00(%f, %f)\n", v00.x, v00.y);
  printf("v01(%f, %f)\n", v01.x, v01.y);

/* - ################   m2x2 testing   ################# - */
  m2x2<float> m00;  /* {x1, y1, x2, y2} */
  m2x2<float> m01 = {5.f, 6.f, 7.f, 8.f};
  m2x2<float> m02 = {1.f, 2.f, 3.f, 4.f};

  printf("\n\n   !! b4 dotProd() \n");
  printf("  m1 2x2 array\n  -> [[%f, %f],[%f, %f])\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);
  printf("  m2 2x2 array\n  -> [[%f, %f],[%f, %f])\n", m02.x[0], m02.y[0], m02.x[1], m02.y[1]);
  m01 = m01 * m02;
  printf("\n   !! after dotProd() \n");
  printf("  m1 2x2 array\n  -> [[%f, %f],[%f, %f])\n\n", m01.x[0], m01.y[0], m01.x[1], m01.y[1]);


/* - ################   AI mock data dotProd() testing   ################# - */
  v4<int> inputs = {1,2,3,4};
  v2<v4<float>> weights = {{-0.4f, 0.7f, 0.2f, 0.4f}, {1.4, -0.8, -0.4, 0.4}};
  v2<float> biases = {0.2, 0.4};

  printf("\n i{%i, %i, %i, %i}\n", inputs.val[0], inputs.val[1],  inputs.val[2], inputs.val[3]);
  v2<float> output = {{inputs.val[0]*weights.val[0].val[0] + inputs.val[1]*weights.val[0].val[1]+ inputs.val[2]*weights.val[0].val[2] + inputs.val[3]*weights.val[0].val[3] + biases.val[0]}, {inputs.val[0]*weights.val[1].val[0] + inputs.val[1]*weights.val[1].val[1] + inputs.val[2]*weights.val[1].val[2] + inputs.val[3]*weights.val[1].val[3] + biases.val[1]}};

  printf("\n\n weights[0][*]: { %.2f, %.2f, %.2f, %.2f}\n weights[1][*]: { %.2f, %.2f, %.2f, %.2f}\n", weights.val[0].val[0],weights.val[0].val[1], weights.val[0].val[2], weights.val[0].val[3], weights.val[1].val[0],weights.val[1].val[1], weights.val[1].val[2], weights.val[1].val[3]);
  printf("\n\n output[0]: %.1f", output.val[0]);
  printf("\n output[1]: %.1f\n", output.val[1]);



  /* - ################   m3x3 testing   ################# - */
  m3x3<float> m3x3_00 = {1.37f, 1.37f, 1.37f, 3.14f, 3.14f, 3.14f, 7.28f, 7.28f, 7.28f};;
  m3x3<float> m3x3_01; // = {1.37f, 1.37f, 1.37f, 3.14f, 3.14f, 3.14f, 7.28f, 7.28f, 7.28f};

  printf("\n\n3x3\n [\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f]\n ]\n", m3x3_00.val[0], m3x3_00.val[1], m3x3_00.val[2], m3x3_00.val[3], m3x3_00.val[4], m3x3_00.val[5], m3x3_00.val[6], m3x3_00.val[7], m3x3_00.val[8], m3x3_00.val[9]);
  printf("\n\n3x3_01\n  [\n    [%.3f, %.3f, %.3f],\n    [%.3f, %.3f, %.3f],\n    [%.3f, %.3f, %.3f]\n  ]\n", m3x3_01.val[0], m3x3_01.val[1], m3x3_01.val[2], m3x3_01.val[3], m3x3_01.val[4], m3x3_01.val[5], m3x3_01.val[6], m3x3_01.val[7], m3x3_01.val[8], m3x3_01.val[9]);

  return 0;
}
