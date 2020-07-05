#include<iostream>
#include<vector>

/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs, 
*/

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

  v3() : x({0,0,0}) {}
  v3(T _x, T _y, T _z) : x{_x, _y, _z} {}

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
  //std::vector<T> x;
  T x[4];

  v4() : x({0,0,0,0}) {}
  v4(T _x, T _y, T _z, T _w) : x{_x, _y, _z, _w} {}

  // v4 operator + (const v4 other) {
  //   return v4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
  // }
  // v4 operator - (const v4 other) {
  //   return v4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
  // }
  // v4 operator * (const v4 other) {
  //   return v4(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
  // }
  // v4 operator / (const v4 other) {
  //   return v4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
  // }
  

  // v4& operator += (const v4& other) {
  //   this->x += other.x; this->y += other.y; this->z += other.z; this->w += other.w; return *this;
  // }
  // v4& operator -= (const v4& other) {
  //   this->x -= other.x; this->y -= other.y; this->z -= other.z; this->w -= other.w; return *this;
  // }
  // v4& operator *= (const v4& other) {
  //   this->x *= other.x; this->y *= other.y; this->z *= other.z; this->w *= other.w; return *this;
  // }
  // v4& operator /= (const v4& other) {
  //   this->x /= other.x; this->y /= other.y; this->z /= other.z; this->w /= other.w; return *this;
  // }
};