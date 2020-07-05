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
  m2x2(T _x[2], T _y[2]) : x(_x), y(_y) {}

  // T mag() { return sqrt(x*x + y*y); };

  // v2 norm() {
  //   T r = 1 / mag();
  //   return v2(x*r, y*r); 
  // }

  // v2 operator + (const v2 other) {
  //   return v2(this->x + other.x, this->y + other.y);
  // }
  // v2 operator - (const v2 other) {
  //   return v2(this->x - other.x, this->y - other.y);
  // }
  // v2 operator * (const T& other) {
  //   return v2(this->x * other, this->y * other);
  // }
  // v2 operator / (const T& other) {
  //   return v2(this->x / other, this->y / other);
  // }

  // v2& operator += (const v2& other) {
  //   this->x += other.x; this->y += other.y; return *this;
  // }
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
