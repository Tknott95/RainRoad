#include<iostream>


template<class T>
struct v2 {
  T x,y;

  v2(T _x, T _y) : x(_x), y(_y) {}

  float mag() { return sqrt(x*x + y*y); }; /* mag() returns float */

  v2 norm() {
    T r = 1 / mag();
    return v2(x*r, y*r); 
  }

  v2 operator + (const v2 other) { /* Do I want this as a const? I am returning a new obj so prob */
    return v2(this->x + other.x, this->y + other.y);
  }
  
  v2 operator - (const v2 other) { /* Do I want this as a const? I am returning a new obj so prob */
    return v2(this->x - other.x, this->y - other.y);
  }

  v2 operator * (const T& other) {
    return v2(this->x * other, this->y * other);
  }

  v2 operator / (const T& other) {
    return v2(this->x / other, this->y / other);
  }
};


/* WILL FINISH THIS ONCE v2 IS FINISHED */
template<class T>
struct v3 {
  T x,y,z;

  v3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
};


int main() {
  // v2 00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("myv2_01(%f, %f)\n", v01.x, v01.y);

  return 0;
}