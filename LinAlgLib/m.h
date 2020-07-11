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

  mDyn() : val{} { this->constructEmpty(); }
  mDyn(T _vals[][colSize]) : val{_vals[rowSize][colSize]} { this->set(_vals); }

  void constructEmpty() {
    for(int i=0; i < rowSize; i++) {
      for(int j=0; j < colSize; j++) { 
        if(sizeof(val) != (rowSize*colSize)) this->val[i][j] = 0; 
      };
    };
  };

  void set(T other[][colSize]){
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] = other[i][j];
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

  mDyn<T, colSize, rowSize> transpose() {
    mDyn<T, colSize, rowSize> transposedMatrix;
    for(int i=0;i<rowSize;i++) { 
      for(int j=0;j<colSize;j++) {
        transposedMatrix.val[j][i] = this->val[i][j];
      };
    };
    return transposedMatrix;
  };

  template<int otherRowSize>
  mDyn<T, rowSize, 1> dot(mDyn<T, otherRowSize, colSize> other) {
    mDyn<T, rowSize, 1> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        printf("\n %i", j);
        if(otherRowSize == 1) {
          returnMat.val[i][0] += (this->val[i][j] * other.val[0][j]);
        } else {
          returnMat.val[i][0] += (this->val[i][j] * other.val[i][j]);
        }
      }
    }
    return returnMat;
  };

  mDyn<T, rowSize, colSize> operator + (const mDyn<T, rowSize, colSize> other) {
    mDyn<T, rowSize, colSize> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        returnMat.val[i][j] = this->val[i][j] + other.val[i][j];
      };
    };
    return returnMat;
  }
  mDyn<T, rowSize, colSize> operator - (const mDyn<T, rowSize, colSize> other) {
    mDyn<T, rowSize, colSize> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        returnMat.val[i][j] = this->val[i][j] - other.val[i][j];
      };
    };
    return returnMat;
  }
  mDyn<T, rowSize, colSize> operator / (const mDyn<T, rowSize, colSize> other) {
    mDyn<T, rowSize, colSize> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        returnMat.val[i][j] = this->val[i][j] / other.val[i][j];
      };
    };
    return returnMat;
  }
  mDyn<T, rowSize, colSize> operator * (const mDyn<T, rowSize, colSize> other) {
    mDyn<T, rowSize, colSize> returnMat;
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        returnMat.val[i][j] = this->val[i][j] * other.val[i][j];
      };
    };
    return returnMat;
  }
  mDyn<T, rowSize, colSize> operator += (const mDyn<T, rowSize, colSize> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] += other.val[i][j];
      };
    };
    return *this;
  }
  mDyn<T, rowSize, colSize> operator -= (const mDyn<T, rowSize, colSize> other) {
    for(int i=0;i < rowSize; i++) {
      for(int j=0;j < colSize; j++) {
        this->val[i][j] -= other.val[i][j];
      };
    };
    return *this;
  }
};
