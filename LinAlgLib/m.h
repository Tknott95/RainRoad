#include<iostream>

/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs, 
*/

template<class T>
struct m2x2 {
  // T x1,y1, x2, y2;
  T x[2],y[2];

  m2x2() : x{0.f, 1.f}, y{0.f, 1.f} {}
  m2x2(T _x[2], T _y[2]) : x{_x[0], _x[1]}, y{_y[0], _y[1]} {}

  m2x2 operator + (const m2x2 other) {
    return m2x2(this->x[0] + other.x[0], this->y[0] + other.y[0], this->x[1] + other.x[1], this->y[1] + other.y[1]);
  }
  m2x2 operator - (const m2x2 other) {
    return m2x2(this->x[0] - other.x[0], this->y[0] - other.y[0], this->x[1] - other.x[1], this->y[1] - other.y[1]);
  }
  m2x2 operator * (const m2x2 other) {
    return m2x2(this->x[0] * other.x[0], this->y[0] * other.y[0], this->x[1] * other.x[1], this->y[1] * other.y[1]);
  }
 m2x2 operator / (const m2x2 other) {
    return m2x2(this->x[0] / other.x[0], this->y[0] / other.y[0], this->x[1] / other.x[1], this->y[1] / other.y[1]);
  }

  m2x2& operator += (const m2x2& other) { /* maybe loop? */
    this->x[0] += other.x[0]; this->y[0] += other.y[0]; this->x[1] += other.x[1]; this->y[1] += other.y[1]; return *this;
  }
  // v2& operator -= (const v2& other) {
  //   this->x -= other.x; this->y -= other.y; return *this;
  // }
  // v2& operator *= (const v2& other) {
  //   this->x *= other.x; this->y *= other.y; return *this;
  // }
  // v2& operator /= (const v2& other) {
  //   this->x /= other.x; this->y /= other.y; return *this;
  // }

};
