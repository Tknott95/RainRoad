#include <iostream>

int main() {
  const int byteSize = 100;
  int fermatArray[byteSize];
  
  for(int i = 0; i < byteSize; i++) {
    fermatArray[i] = i;
    if(i % 3 == 0 && i % 5 ==0) {
      std::cout << fermatArray[i] << std::endl;
    }
  }

  return 0;
}

