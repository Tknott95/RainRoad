#include <iostream>
#include <math.h>

using namespace std;

int main() {
  cout << "\n Prime # Machine Init... \n" << endl;
  const int byteSize = 100;

  for(int i = 1; i < byteSize; i++) {
    const double powerTwo = pow(2, (i - 1));
    if(fmod(powerTwo, i) == 1) {
      cout << "Prime: " << i << endl;
    }
  }

  return 0;
}
