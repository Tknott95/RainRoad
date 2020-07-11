#include<iostream>
#include<map>
/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs
** @TYPES      - m2x2. m3x3
*/
using namespace std;

// template<class T>
// struct m2x2 {
//   T val[2][2];
//   map<string, T> getVal;

//   m2x2() : val{0.f, 0.f, 1.f, 1.f} {}
//   m2x2(T _x1, T _y1, T _x2, T _y2) : val{_x1, _y1, _x2, _y2} {
//    getVal = { 
//       {"x0", val[0][0]},
//       {"y0", val[0][1]},
//       {"x1", val[1][0]},
//       {"y1", val[1][1]}
//     };
//   }

//   m2x2 operator + (const m2x2 other) {
//     return m2x2(
//       this->x[0] + other.x[0], this->y[0] + other.y[0],
//       this->x[1] + other.x[1], this->y[1] + other.y[1]
//     );
//   }
//   m2x2 operator - (const m2x2 other) {
//     return m2x2(
//       this->x[0] - other.x[0], this->y[0] - other.y[0],
//       this->x[1] - other.x[1], this->y[1] - other.y[1]
//     );
//   }
//   m2x2 operator * (const m2x2 other) { /* grabs dotProd() */
//     return m2x2(
//       this->val[0][0] * other.val[0][0] + this->val[0][0] * other.val[1][0], this->val[0][0] * other.val[0][0] + this->val[0][0] * other.val[1][1],
//       this->val[1][0] * other.val[0][0] + this->val[1][1] * other.val[1][0] , this->val[1][0] * other.val[0][0] + this->val[1][1] * other.val[1][1]
//     );
//   }
//   m2x2& operator += (const m2x2& other) { /* maybe loop? */
//     this->val[0][0] += other.val[0][0]; this->val[0][1] += other.val[0][1];
//     this->val[1][0] += other.val[1][0]; this->val[1][1] += other.val[1][1];
//     return *this;
//   }
//   m2x2& operator -= (const m2x2& other) { /* maybe loop? */
//     this->val[0][0] -= other.val[0][0]; this->val[0][1] -= other.val[0][1];
//     this->val[1][0] -= other.val[1][0]; this->val[1][1] -= other.val[1][1];
//     return *this;
//   }
// };

// template<class T>
// struct m3x3 {
//   T val[3][3];
//   map<string, T> getVal;

//   m3x3() : val{0, 0, 0, 1, 1, 1, 2, 2, 2} {}
//   m3x3(T _x1, T _y1, T _z1, T _x2, T _y2, T _z2, T _x3, T _y3, T _z3) : val{_x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3} {
//     getVal = { 
//       {"x0", val[0][0]},
//       {"y0", val[0][1]},
//       {"z0", val[0][2]},
//       {"x1", val[1][0]},
//       {"y1", val[1][1]},
//       {"z1", val[1][2]},
//       {"x2", val[2][0]},
//       {"y2", val[2][1]},
//       {"z2", val[2][2]}
//     };
//   }

//   m3x3 operator + (const m3x3 other) {
//     return m3x3(
//       this->getVal.at("x0") + other.getVal.at("x0"), this->getVal.at("y0") + other.getVal.at("y0"), this->getVal.at("z0") + other.getVal.at("z0"),
//       this->getVal.at("x1") + other.getVal.at("x1"), this->val[1][1] + other.val[1][1], this->val[1][2] + other.val[1][2],
//       this->val[2][0] + other.val[2][0], this->val[2][1] + other.val[2][1], this->val[2][2] + other.val[2][2]
//     );
//   }
//   m3x3 operator - (const m3x3 other) {
//     return m3x3(
//       this->val[0][0] - other.val[0][0], this->val[0][1] - other.val[0][1], this->val[0][2] - other.val[0][2],
//       this->val[1][0] - other.val[1][0], this->val[1][1] - other.val[1][1], this->val[1][2] - other.val[1][2],
//       this->val[2][0] - other.val[2][0], this->val[2][1] - other.val[2][1], this->val[2][2] - other.val[2][2]
//     );
//   }
//   m3x3& operator += (const m3x3& other) { /* loop? */
//     this->val[0][0] += other.val[0][0]; this->val[0][1] += other.val[0][1]; this->val[0][2] += other.val[0][2];
//     this->val[1][0] += other.val[1][0]; this->val[1][1] += other.val[1][1]; this->val[1][2] += other.val[1][2];
//     this->val[2][0] += other.val[2][0]; this->val[2][1] += other.val[2][1]; this->val[2][2] += other.val[2][2];  
//     return *this;
//   }
//   m3x3& operator -= (const m3x3& other) {
//     this->val[0][0] -= other.val[0][0]; this->val[0][1] -= other.val[0][1]; this->val[0][2] -= other.val[0][2];
//     this->val[1][0] -= other.val[1][0]; this->val[1][1] -= other.val[1][1]; this->val[1][2] -= other.val[1][2];
//     this->val[2][0] -= other.val[2][0]; this->val[2][1] -= other.val[2][1]; this->val[2][2] -= other.val[2][2];
//     return *this;
//   }
// };

// template<class T>
// struct m3x4 {
//   T val[3][4];
//   map<string, T> getVal;

//   m3x4() : val{0, 0, 0, 0,  1, 1, 1, 1,  2, 2, 2, 2} {}
//   m3x4(T _x1, T _y1, T _z1, T _w1, T _x2, T _y2, T _z2, T _w2, T _x3, T _y3, T _z3, T _w3) : val{{_x1, _y1, _z1, _w1}, {_x2, _y2, _z2, _w2}, {_x3, _y3, _z3, _w3}} {
//     getVal = { 
//       {"x0", val[0][0]},
//       {"y0", val[0][1]},
//       {"z0", val[0][2]},
//       {"w0", val[0][3]},
//       {"x1", val[1][0]},
//       {"y1", val[1][1]},
//       {"z1", val[1][2]},
//       {"w1", val[1][3]},
//       {"x2", val[2][0]},
//       {"y2", val[2][1]},
//       {"z2", val[2][2]},
//       {"w2", val[2][3]}
//     };
//   }

//   m3x4 operator + (const m3x4 other) {
//     return m3x4(
//       this->val[0][0] + other.val[0][0], this->val[0][1] + other.val[0][1], this->val[0][2] + other.val[0][2], this->val[0][3] + other.val[0][3],
//       this->val[1][0] + other.val[1][0], this->val[1][1] + other.val[1][1], this->val[1][2] + other.val[1][2], this->val[1][3] + other.val[1][3],
//       this->val[2][0] + other.val[2][0], this->val[2][1] + other.val[2][1], this->val[2][2] + other.val[2][2], this->val[2][3] + other.val[2][3]
//     );
//   }
//   m3x4 operator - (const m3x4 other) {
//     return m3x4(
//       this->val[0][0] - other.val[0][0], this->val[0][1] - other.val[0][1], this->val[0][2] - other.val[0][2], this->val[0][3] - other.val[0][3],
//       this->val[1][0] - other.val[1][0], this->val[1][1] - other.val[1][1], this->val[1][2] - other.val[1][2], this->val[1][3] - other.val[1][3],
//       this->val[2][0] - other.val[2][0], this->val[2][1] - other.val[2][1], this->val[2][2] - other.val[2][2], this->val[2][3] - other.val[2][3]
//     );
//   }

//   m3x4& operator += (const m3x4& other) {
//     this->val[0][0] += other.val[0][0]; this->val[0][1] += other.val[0][1]; this->val[0][2] += other.val[0][2];
//     this->val[1][0] += other.val[1][0]; this->val[1][1] += other.val[1][1]; this->val[1][2] += other.val[1][2];
//     this->val[2][0] += other.val[2][0]; this->val[2][1] += other.val[2][1]; this->val[2][2] += other.val[2][2];
//     return *this;
//   }
//   m3x4& operator -= (const m3x4& other) {
//     this->val[0][0] -= other.val[0][0]; this->val[0][1] -= other.val[0][1]; this->val[0][2] -= other.val[0][2];
//     this->val[1][0] -= other.val[1][0]; this->val[1][1] -= other.val[1][1]; this->val[1][2] -= other.val[1][2];
//     this->val[2][0] -= other.val[2][0]; this->val[2][1] -= other.val[2][1]; this->val[2][2] -= other.val[2][2];
//     return *this;
//   }
// };

#include<vector>
template<class T, int rowSize, int colSize>
struct mDyn {
  T val[rowSize][colSize];
  int size = rowSize*colSize;

  mDyn() : val{} { this->constructEmpty(); }
  mDyn(T _vals[rowSize*colSize]) : val{_vals[rowSize][colSize]} {}
  
  void constructEmpty(bool debug=false) {
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


  mDyn<T, rowSize, colSize> operator + (const mDyn<T, rowSize, colSize> other) {
    // return mDyn<T, rowSize, colSize>(
      for(int i=0;i < rowSize; i++) {
        for(int j=0;j < colSize; j++) {
          this->val[i][j] + other.val[i][j];
        };
      };
    return *this; /* pointer retrun dumb? not the way prior */
  }
};
