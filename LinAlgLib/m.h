#include<iostream>
/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs
** @TYPES      - m2x2. m3x3
*/
using namespace std;

template<class T, int rowSize, int colSize, bool debug=false>
struct mDyn {
  T val[rowSize][colSize];
  int size = rowSize*colSize;

  mDyn() : val{} { this->constructEmpty(); }
  mDyn(T _vals[][colSize]) : val{_vals[rowSize][colSize]} { this->set(_vals); }

  /* #### HELPER FUNCS #### */
  void constructEmpty() {
    if(debug)  printf("\n\n\n\n\n\n ############################## \n");
    for(int i=0; i < rowSize; i++) {
      for(int j=0; j < colSize; j++) { 
        if(sizeof(val) != size) this->val[i][j] = 0; 
        if(debug) printf("\nConstructing [%i][%i] value.", i, j);
      };
    };
  };

  void set(T other[][colSize]){
    if(debug)  printf("\n\n\n");
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] = other[i][j];
        if(debug) {
          printf("\n other        [%i][%i]: %.2f", i, j, other[i][j]);
          printf("\n target   .val[%i][%i]: %.2f\n", i, j,  this->val[i][j]);
        }
      };
    };
  };

  void log(string name = "Anonymous Matrix") {
    printf("\n\n\n\n  - %s - \n[", name.c_str());
    for(int i=0; i<rowSize;i++) {
      printf("\n  [");
      for(int j=0;j<colSize;j++) {
        printf("%.2f ",this->val[i][j]);
      };
      printf("] ");
    };
    printf("\n]");
  };

  /* reversing return on size for transpose */
  /* normally rowxcol */
  mDyn<T, colSize, rowSize, debug> transpose() {
    mDyn<T, colSize, rowSize, debug> transposedMatrix;
    for(int i=0;i<rowSize;i++) { 
      for(int j=0;j<colSize;j++) {
        transposedMatrix.val[j][i] = this->val[i][j];
      };
    };
    return transposedMatrix;
  };

  mDyn<T, rowSize, 1, debug> dot(mDyn<T, rowSize, colSize, debug> other) {
    mDyn<T, rowSize, 1, debug> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        printf("\n %i", i);
        returnMat.val[i][0] += (this->val[i][j] * other.val[i][j]);
      }
    }
    return returnMat;
  };


  /* #### OPERATOR FUNCS #### */
  /* wasn't returning pointer below prior */
  mDyn<T, rowSize, colSize, debug> operator += (const mDyn<T, rowSize, colSize, debug> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] += other.val[i][j];
      };
    };
    return *this;
  }
  mDyn<T, rowSize, colSize, debug> operator -= (const mDyn<T, rowSize, colSize, debug> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] -= other.val[i][j];
      };
    };
    return *this;
  }
};
