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

  void constructEmpty() {
    if(debug)  printf("\n\n\n\n\n\n ############################## \n");
    for(int i=0; i < rowSize; i++) {
      for(int j=0; j < colSize; j++) { 
        if(sizeof(val) != size) this->val[i][j] = i + 1.f; 
        if(debug) printf("\nConstructing [%i][%i] value.", i, j);
      }
    }
  }

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
  /* reversing return on size for transpose */
  /* normally rowxcol */
  mDyn<T, colSize, rowSize, debug> transpose() {
    mDyn<T, colSize, rowSize, debug> transposedMatrix;
    for(int i=0;i<rowSize;i++) { 
      for(int j=0;j<colSize;j++) {
        transposedMatrix.val[j][i] = this->val[i][j];
      }
    }
    return transposedMatrix;
  }

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
