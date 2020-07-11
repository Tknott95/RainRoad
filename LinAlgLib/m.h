#include<iostream>
/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs
** @TYPES      - m2x2. m3x3
*/
using namespace std;

template<class T, int rowSize, int colSize>
struct mDyn {
  T val[rowSize][colSize];
  int size = rowSize*colSize;

  mDyn() : val{} { this->constructEmpty(); }
  mDyn(T _vals[rowSize*colSize]) : val{_vals[rowSize][colSize]} {}
  
  void constructEmpty(bool debug=false) {
    if(debug) printf("\n\n\n\n\n\n ############################## \n");
    for(int i=0; i <= rowSize; i++) {
      for(int j=0; j <= colSize; j++) { 
        if(! val[0][0]) val[i][j] = i + j; 
        if(debug) printf("\nConstructing [%i][%i] value.", i, j);
      }
    }
  }

  template<class T2, int _rows, int _cols>
  void set(T2 other[][_cols], bool debug=false){
    if(debug)  printf("\n\n\n");
    for(int i=0;i < _rows; i++) {
      for(int j=0;j < _cols; j++) {
        this->val[i][j] = other[i][j];
        if(debug) {
          printf("\n other        [%i][%i]: %.2f", i, j, other[i][j]);
          printf("\n target   .val[%i][%i]: %.2f\n", i, j,  this->val[i][j]);
        }
      };
    };
  };


  /* wasn't returning pointer below prior */
  mDyn<T, rowSize, colSize> operator += (const mDyn<T, rowSize, colSize> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] += other.val[i][j];
      };
    };
    return *this;
  }
  mDyn<T, rowSize, colSize> operator -=(const mDyn<T, rowSize, colSize> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] -= other.val[i][j];
      };
    };
    return *this;
  }
};
