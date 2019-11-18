#include <iostream>

int main() {
  const int byteSize = 11;
  int test[byteSize];
  
  test[0] = 4;
  test[1] = 44;
  test[2] = 444;
  test[3] = 33;
  test[4] = 40;
  test[5] = 1101;
  test[6] = 1110;
  test[7] = 0101;  

  for(int i = 0; i < byteSize; i++) {
    std::cout << "\n" << test[i] << std::endl;
  }
  return 0;
}
