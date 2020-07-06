#include "v.h"
#include "m.h"

int main() {
/* - ################   v2 testing   ################# - */
  v2<float> v00;
  v2<float> v01 = {1.f, 1.f};

  printf("v00(%.2f, %.2f)\n", v00.x, v00.y);

  v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  v01 += v01;
  printf("v00(%f, %f)\n", v00.x, v00.y);
  printf("v01(%f, %f)\n", v01.x, v01.y);

/* - ################   m2x2 testing   ################# - */
  m2x2<float> m00;  /* {x1, y1, x2, y2} */
  m2x2<float> m01 = {5.f, 6.f, 7.f, 8.f};
  m2x2<float> m02 = {1.f, 2.f, 3.f, 4.f};

  printf("\n\n   !! b4 dotProd() \n");
  printf("  m1 2x2 array\n  -> [[%f, %f],[%f, %f])\n", m01.getVal.at("x0"), m01.getVal.at("y0"), m01.getVal.at("x1"), m01.getVal.at("y1"));
  printf("  m2 2x2 array\n  -> [[%f, %f],[%f, %f])\n", m02.getVal.at("x0"), m02.getVal.at("y0"), m02.getVal.at("x1"), m02.getVal.at("y1"));
  m01 = m01 * m02;
  printf("\n   !! after dotProd() \n");
  printf("  m1 2x2 array\n  -> [[%f, %f],[%f, %f])\n\n", m01.getVal.at("x0"), m01.getVal.at("y0"), m01.getVal.at("x1"), m01.getVal.at("y1"));


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
  m3x3<float> m3x3_01;
  m3x3<float> m3x3_00 = {1.37f, 1.37f, 1.37f, 3.14f, 3.14f, 3.14f, 7.28f, 7.28f, 7.28f};

  

  printf("\n\n3x3\n [\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f]\n ]\n", m3x3_00.val[0], m3x3_00.val[1], m3x3_00.val[2], m3x3_00.val[3], m3x3_00.val[4], m3x3_00.val[5], m3x3_00.val[6], m3x3_00.val[7], m3x3_00.val[8]);
  printf("\n\n3x3_01\n  [\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f]\n  ]\n", m3x3_01.val[0], m3x3_01.val[1], m3x3_01.val[2], m3x3_01.val[3], m3x3_01.val[4], m3x3_01.val[5], m3x3_01.val[6], m3x3_01.val[7], m3x3_01.val[8]);
 
  printf(" \n   !! Adding both 3x3's");
  m3x3<float> m3x3_02;
  m3x3_02 += m3x3_00;
  printf("\n3x3_01\n  [\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f]\n  ]\n",m3x3_02.val[0], m3x3_02.val[1], m3x3_02.val[2],m3x3_02.val[3],m3x3_02.val[4],m3x3_02.val[5],m3x3_02.val[6],m3x3_02.val[7],m3x3_02.val[8]);
 
  printf("\nm3x3_00.getVal.at('x0'): %.2f\n",  m3x3_00.getVal.at("x0"));
  printf("\n\n\nm3x3_00\n  [\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f]\n  ]\n", m3x3_00.getVal.at("x0"), m3x3_00.getVal.at("y0"), m3x3_00.getVal.at("z0"), m3x3_00.getVal.at("x1"), m3x3_00.getVal.at("y1"), m3x3_00.getVal.at("z1"), m3x3_00.getVal.at("x2"), m3x3_00.getVal.at("y2"), m3x3_00.getVal.at("z2"));
  
  
  /* - ################   m3x4 testing   ################# - */
  m3x4<float> m3x4_01;
  m3x4<float> inputs3x4 = {
     1.8f, 2.1f, -1.2f, -1.77f,
     1.75f, -3.33f, 2.13f, -1.37f,
    -1.33f, 2.22f, 1.44f, -1.88f
  };

  m3x4<float> weights3x4 = {
    -0.4, 0.7, 0.2, -0.43,
    0.45, -0.82, -0.44, 0.38,
    -0.88, -0.75, 0.91, 0.11
  };

  v3<float> biasesv3 = {0.2, 0.4, 2};

  printf("\nm3x4_01\n  [\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f]\n  ]\n",
    m3x4_01.val[0][0], m3x4_01.val[0][1], m3x4_01.val[0][2], m3x4_01.val[0][3],
    m3x4_01.val[1][0], m3x4_01.val[1][1], m3x4_01.val[1][2], m3x4_01.val[1][3],
    m3x4_01.val[2][0], m3x4_01.val[2][1], m3x4_01.val[2][2], m3x4_01.val[2][3]
  );
  
  printf("\ninputs3x4\n  [\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f]\n  ]\n",
    inputs3x4.val[0][0], inputs3x4.val[0][1], inputs3x4.val[0][2], inputs3x4.val[0][3],
    inputs3x4.val[1][0], inputs3x4.val[1][1], inputs3x4.val[1][2], inputs3x4.val[1][3],
    inputs3x4.val[2][0], inputs3x4.val[2][1], inputs3x4.val[2][2], inputs3x4.val[2][3]
  );

  printf("\nweights3x4\n  [\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f],\n    [%.2f, %.2f, %.2f, %.2f]\n  ]\n",
    weights3x4.val[0][0], weights3x4.val[0][1], weights3x4.val[0][2], weights3x4.val[0][3],
    weights3x4.val[1][0], weights3x4.val[1][1], weights3x4.val[1][2], weights3x4.val[1][3],
    weights3x4.val[2][0], weights3x4.val[2][1], weights3x4.val[2][2], weights3x4.val[2][3]
  );

 
  const int dynRows = 3; 
  const int dynCols = 3;
  mDyn<int, dynRows, dynCols> dynMat;
  printf("\n\n\nmDyn<int, 2, 2>\n  -> [[%f, %f],[%f, %f])\n\n",
     m01.val[0][0], m01.val[0][1], m01.val[1][0], m01.val[1][1]
  );

  return 0;
}
