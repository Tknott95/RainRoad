#include<iostream>
#include<vector>

/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs, 
*/

template<class T>
struct v2 {
  T val[2], x, y;

  v2() : val{0, 0} {}
  v2(T _x, T _y) : val{_x, _y} {
    x = val[0];
    y = val[1];
  }

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
  T val[3], x,y,z;

  v3() : val{0,0,0} {}
  v3(T _x, T _y, T _z) : val{_x, _y, _z} {
    x = val[0];
    y = val[1];
    z = val[2];
  }

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
  T val[4], x,y,z,w;

  v4() : val{0,0,0,0} {}
  v4(T _x, T _y, T _z, T _w) : val{_x, _y, _z, _w} {
    x = val[0];
    y = val[1];
    z = val[2];
    w = val[3];
  }

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
  v4& operator -= (const v4& other) {
    this->x -= other.x; this->y -= other.y; this->z -= other.z; this->w -= other.w; return *this;
  }
  v4& operator *= (const v4& other) {
    this->x *= other.x; this->y *= other.y; this->z *= other.z; this->w *= other.w; return *this;
  }
  v4& operator /= (const v4& other) {
    this->x /= other.x; this->y /= other.y; this->z /= other.z; this->w /= other.w; return *this;
  }
};