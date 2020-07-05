#include<iostream>


template<class T>
struct v2 {
  T x,y;

  v2(T _x, T_y) : x(_x), y(_y) {}

  float mag() { return sqrt(x*x + y*y); }; /* mag() returns float */

  v2 norm() {
    T r = 1 / mag();
    return v2(x*r, y*r); 
  }

  /* other should be rightHandSide param in arithmetics */
  v2 operator + (const v2 other) { /* Do I want this as a const? I am returning a new obj so prob */
    return v2(this->x + other.x, this->y + other.y);
  }
  
  v2 operator - (const v2 other) { /* Do I want this as a const? I am returning a new obj so prob */
    return v2(this->x - other.x, this->y - other.y);
  }

  v2 operator * (const T& other)
};


/* WILL FINISH THIS ONCE v2 IS FINISHED */
template<class T>
struct v3 {
  T x,y,z;

  v3(T _x, T_y, T _z) : x(_x), y(_y), z(_z) {}
};