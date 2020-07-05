#include<iostream>

/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs
*/

template<class T>
struct m2x2 {
  T val[4], x[2], y[2];

  m2x2() : val{0.f, 0.f, 1.f, 1.f} {}
  m2x2(T _x1, T _y1, T _x2, T _y2) : val{_x1, _y1, _x2, _y2} {
    /* makes things easier, will rmv if need extra memory */
    x[0] = val[0];
    y[0] = val[1];
    x[1] = val[2];
    y[1] = val[3];
  }

  m2x2 operator + (const m2x2 other) {
    return m2x2(this->x[0] + other.x[0], this->y[0] + other.y[0], this->x[1] + other.x[1], this->y[1] + other.y[1]);
  }
  m2x2 operator - (const m2x2 other) {
    return m2x2(this->x[0] - other.x[0], this->y[0] - other.y[0], this->x[1] - other.x[1], this->y[1] - other.y[1]);
  }
  m2x2 operator * (const m2x2 other) { /* grabs dotProd() */
    return m2x2(this->x[0] * other.x[0] + this->y[0] * other.x[1], this->x[0] * other.y[0] + this->y[0] * other.y[1],  this->x[1] * other.x[0] + this->y[1] * other.x[1] , this->x[1] * other.y[0] + this->y[1] * other.y[1]);
  }
  m2x2& operator += (const m2x2& other) { /* maybe loop? */
    this->x[0] += other.x[0]; this->y[0] += other.y[0]; this->x[1] += other.x[1]; this->y[1] += other.y[1]; return *this;
  }
  m2x2& operator -= (const m2x2& other) { /* maybe loop? */
    this->x[0] -= other.x[0]; this->y[0] -= other.y[0]; this->x[1] -= other.x[1]; this->y[1] -= other.y[1]; return *this;
  }
};
