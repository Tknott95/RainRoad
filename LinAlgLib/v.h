#include<iostream>
#include<vector>

/*
** @AUTHOR     - Trevor Knott
** @EMAIL      - tk@trevorknott.io
** @ABSTRACT   - Linear Algebra Library to rid third party libs, 
*/

template<class T, int size>
struct vDyn {
  T val[size];

  vDyn() : val{} { this->constructEmpty(); }
  vDyn(T _val[size]) : val{_val[size]} {
    for(int i=0;i<size;i++) this->val[i] = _val[i];
  }

  void constructEmpty() {
    for(int j=0;j<size;j++) { 
      this->val[j] = 0; 
    }
  }

  vDyn<T, 1> dot(vDyn<T, size> other) {
    vDyn<T, 1> tempV;
    for(int i=0;i<size;i++) tempV.val[0] += (this->val[i] * other.val[i]);
    return tempV;
  }

  vDyn<T, size> operator + (const vDyn<T, size> other) {
    vDyn<T, size> tempV;
    for(int i=0;i<size;i++) tempV.val[i] = this->val[i] + other.val[i];
    return tempV;
  }
  vDyn<T, size> operator - (const vDyn<T, size> other) {
    vDyn<T, size> tempV;
    for(int i=0;i<size;i++) tempV.val[i] = this->val[i] - other.val[i];
    return tempV;
  }
  vDyn<T, size> operator * (const vDyn<T, size> other) {
    vDyn<T, size> tempV;
    for(int i=0;i<size;i++) tempV.val[i] = this->val[i] * other.val[i];
    return tempV;
  }
  vDyn<T, size> operator / (const vDyn<T, size> other) {
    vDyn<T, size> tempV;
    for(int i=0;i<size;i++) tempV.val[i] = this->val[i] / other.val[i];
    return tempV;
  }
  vDyn<T, size> operator += (const vDyn<T, size> other) {
    for(int i=0;i<size;i++) this->val[i] += other.val[i];
    return *this;
  }
  vDyn<T, size> operator -= (const vDyn<T, size> other) {
    for(int i=0;i<size;i++) this->val[i] -= other.val[i];
    return *this;
  }
};
