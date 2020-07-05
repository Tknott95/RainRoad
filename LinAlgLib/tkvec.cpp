#include<iostream>


template<class T>
struct v2 {
  T x,y;

  v2() : x(0), y(0) {}
  v2(T _x, T _y) : x(_x), y(_y) {}

  T mag() { return sqrt(x*x + y*y); };

  v2 norm() {
    T r = 1 / mag();
    return v2(x*r, y*r); 
  }

  v2 operator + (const v2 other) {
    return v2(this->x + other.x, this->y + other.y);
  }
  v2 operator - (const v2 other) {
    return v2(this->x - other.x, this->y - other.y);
  }
  v2 operator * (const T& other) {
    return v2(this->x * other, this->y * other);
  }
  v2 operator / (const T& other) {
    return v2(this->x / other, this->y / other);
  }

  v2& operator += (const v2& other) {
    this->x += other.x; this->y += other.y; return *this;
  }
  v2& operator -= (const v2& other) {
    this->x -= other.x; this->y -= other.y; return *this;
  }
  v2& operator *= (const v2& other) {
    this->x *= other.x; this->y *= other.y; return *this;
  }
  v2& operator /= (const v2& other) {
    this->x /= other.x; this->y /= other.y; return *this;
  }

};


template<class T>
struct v3 {
  T x,y,z;

  v3() : x(0), y(0), z(0) {}
  v3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

  v3 operator + (const v3 other) {
    return v3(this->x + other.x, this->y + other.y, this->z + other.z);
  }
  v3 operator - (const v3 other) {
    return v3(this->x - other.x, this->y - other.y, this->z - other.z);
  }
  v3 operator * (const v3 other) {
    return v3(this->x * other.x, this->y * other.y, this->z * other.z);
  }
  v3 operator / (const v3 other) {
    return v3(this->x / other.x, this->y / other.y, this->z / other.z);
  }
  

  v3& operator += (const v3& other) {
    this->x += other.x; this->y += other.y; this->z += other.z; return *this;
  }
  v3& operator -= (const v3& other) {
    this->x -= other.x; this->y -= other.y; this->z -= other.z; return *this;
  }
  v3& operator *= (const v3& other) {
    this->x *= other.x; this->y *= other.y; this->z *= other.z; return *this;
  }
  v3& operator /= (const v3& other) {
    this->x /= other.x; this->y /= other.y; this->z /= other.z; return *this;
  }
};

template<class T>
struct v4 {
  T x,y,z,w;

  v4() : x(0), y(0), z(0), w(0) {}
  v4(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

  v4 operator + (const v4 other) {
    return v4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
  }
  v4 operator - (const v4 other) {
    return v4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
  }
  v4 operator * (const v4 other) {
    return v4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
  }
  v4 operator / (const v4 other) {
    return v4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
  }
  

  v4& operator += (const v4& other) {
    this->x += other.x; this->y += other.y; this->z += other.z; this->w += other.w; return *this;
  }
};


int main() {
  v2<float> v00;
  v2<float> v01 = {1.0f, 1.0f};

  printf("v00(%f, %f)\n", v00.x, v00.y);
  // v00 = v00 + v01 + v01 + v01;
  v00 += v01 += v01 *= v01 /= {1.0, 1.0};
  v01 += v01;
  printf("v00(%f, %f)\n", v00.x, v00.y);
  printf("v01(%f, %f)\n", v01.x, v01.y);

  return 0;
}