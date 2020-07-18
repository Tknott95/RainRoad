#include "v.h"
#include "m.h"

template<class T, int dataSize> 
vDyn<T, dataSize*2> merge(vDyn<T, dataSize> _firstArray, vDyn<T, dataSize> _secondArray) {
  // int tempArr[dataSize];  
  int indexVal;
  vDyn<T, dataSize*2> returnArray;

  int c1,c2,counter = 0;
  //for(int j=0;j<dataSize;j++) for(int k=0;k<dataSize;k++) {
    // printf("\n\n 1j(%i): %i    2k(%i): %i   \n", j, _firstArray.val[j], k, _secondArray.val[k]);

  _firstArray.log("_first array");
  _secondArray.log("_second array");
   
  while(c1<dataSize && c2<dataSize) {
    if(_firstArray.val[c1] < _secondArray.val[c2]) returnArray.val[counter++] = _firstArray.val[c1++];
    else returnArray.val[counter++] = _secondArray.val[c2++]; 
  };

  while(c1<dataSize) returnArray.val[counter++] = _firstArray.val[c1++];
  while(c2<dataSize) returnArray.val[counter++] = _secondArray.val[c2++];

  return returnArray;
};

template<class T, const int arraySize>
vDyn<T, arraySize> mergeSort(vDyn<T, arraySize> data) {
  if(arraySize == 1) return data;
  const int halfArraySize = arraySize/2;
  
  vDyn<T, halfArraySize> leftArray;
  vDyn<T, halfArraySize> rightArray;
  vDyn<T, arraySize> returnArray;

  for(int i=0;i<arraySize;i++) {
    if(i<halfArraySize) leftArray.val[i] = data.val[i];
    else if(i>halfArraySize-1) rightArray.val[i-halfArraySize] = data.val[i];
  };

  returnArray = merge<int, halfArraySize>(leftArray, rightArray);


  // if(low < high) {
  //   int mid;
  //   mid = (low + high)/2;
  //   // mergeSort<T, arraySize>(data, low, mid);
  //   // mergeSort<T, arraySize>(data, mid+1, high);
  //   // merge<int, 6>()
  // };

  data.log("\n\n\n\n\nStarting Array");

  leftArray.log("Left Array");
  rightArray.log("Right Array");
  printf("\n");

  returnArray.log("Return Array");
  return returnArray;
};

void mergeSortInit() {
  /* ################################################## SORTING ALGO'S ##################################################*/
  const int mergeSortArraySize = 6;
  int mergeSortVals[] = {1,2,3,4,0,6};

  vDyn<int, mergeSortArraySize> mergeSortVec(mergeSortVals);

  mergeSortVec.log("Before Merge Sort");
  mergeSortVec = mergeSort(mergeSortVec);
};

void dotProdInit() {
    float dotMatInputVals00[1][4] = {{1, 1, 1, 1}};
  mDyn<float, 1, 4> inputsDotMat00(dotMatInputVals00);
  /* - WORKS WITH BOTH MULTI_ROWS OR ONLY ONE
  ** float dotMatInputVals00[2][4] = {{1, 1, 1, 1},{1, 1, 1, 1}};
  **  mDyn<float, 2, 4> inputsDotMat00(dotMatInputVals00);
  */
  float dotMatWeightVals00[2][4] = {{1, 1, 1, 1},{1, 1, 1, 1}};
  mDyn<float, 2, 4> weightsDotMat00(dotMatWeightVals00);
  mDyn<float, 2, 1> dotOutputMat00 = weightsDotMat00.dot<1>(inputsDotMat00);

  
  inputsDotMat00.log("Inputs for DotProd");
  weightsDotMat00.log("Weights for DotProd");
  dotOutputMat00.log("After DotProd");

  /* #### vDyn ##### */
  const int vDynSize00 = 5;
  float vDynVals00[] = {2.0, 2.0, 2.0, 2.0, 2.0};
  vDyn<float, vDynSize00> vDyn00(vDynVals00);

  vDyn<float, 1> vTempDot(vDyn00.dot(vDyn00));
  cout << vTempDot.val[0] << endl;
};

int main() {  
  /* - ################   m3x4 testing   ################# - */
  // m3x4<float> m3x4_01;
  // m3x4<float> inputs3x4 = {
  //    1.8f, 2.1f, -1.2f, -1.77f,
  //    1.75f, -3.33f, 2.13f, -1.37f,
  //   -1.33f, 2.22f, 1.44f, -1.88f
  // };
  // m3x4<float> weights3x4 = {
  //   -0.4, 0.7, 0.2, -0.43,
  //   0.45, -0.82, -0.44, 0.38,
  //   -0.88, -0.75, 0.91, 0.11
  // };
  // v3<float> biasesv3 = {0.2, 0.4, 2};

 /* #### mDyn ##### */
  const int dynRows = 3; 
  const int dynCols = 4;
  mDyn<float, dynRows, dynCols> dynMat();
  float dynVals[dynRows][dynCols] = {
    {-0.4, 0.7, 0.2, -0.43},
    {0.45, -0.82, -0.44, 0.38},
    {-0.88, -0.75, 0.91, 0.11},
  };
  mDyn<float, dynRows, dynCols> dynMat02(dynVals);
  
  const int dynRows03 = 6; 
  const int dynCols03 = 5;
  float dynVals03[dynRows03][dynCols03] = {
    {-0.00, 0.01, 0.02, -0.03, 0.04},
    {0.10, -0.11, -0.12, 0.13, -0.14},
    {-0.20, -0.21, 0.22, 0.23, -0.24},
    {-0.30, 0.31, 0.32, -0.33, 0.34},
    {0.40, -0.41, -0.42, 0.43, -0.44},
    {-0.50, -0.51, 0.52, 0.53, 0.54}
  };

  mDyn<float, dynRows03, dynCols03> dynMat03(dynVals03);
  dynMat03 = dynMat03 += dynMat03 += dynMat03;

  for(int i=0;i<dynRows03; i++) {
    for(int j=0;j<dynCols03;j++) {
      printf("\n dynMat03[%i][%i]: %.2f", i, j, dynMat03.val[i][j]);
    };
  };

  const int i3 = 3;
  float testVals00[i3][i3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  mDyn<float, i3, i3> transMatTest00(testVals00);

  printf("\n\n\n\n");
  transMatTest00.log("Before Transpose");
  transMatTest00 = transMatTest00.transpose();
  transMatTest00.log("After Transpose");
  
  const int testRows01 = 3;
  const int testCols01 = 6;
  float testVals01[testRows01][testCols01] = {
    {1, 2,  3,  4, 5 ,6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18}
  };

  mDyn<float, testRows01, testCols01> testMat01(testVals01);
  
  printf("\n\n\n\n");
  testMat01.log("Before Transpose");
  mDyn<float, testCols01, testRows01> afterTestMat01 = testMat01.transpose();
  afterTestMat01.log("After Transpose");


  float toMultiplyByVals[1][4] = {{0.5, 0.5, 0.5, 0.5}};
  float toTestOperators[1][4] = {{1, 1, 1, 1}};
  mDyn<float, 1, 4> testingOperators00(toTestOperators);
  testingOperators00.log("Before * operator");
  testingOperators00 = testingOperators00 * toMultiplyByVals;
  testingOperators00.log("After * operator");


  dotProdInit();

  mergeSortInit();


  return 0;
}


