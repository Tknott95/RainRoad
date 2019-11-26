#include <iostream>

using namespace std;

bool asking = false;
bool runFib = false;

void init() {
  asking = true;
}

void fib(int epochs) {
  cout <<"\n Fib() Initialized... Epochs(" << (epochs-1) << ") \n" << endl;
  int j = 0;
  int k = 1;
  int jk;
  for(int i=1; i < epochs; i++) {
    if(i != 1 ) {
      jk = j+k;
      j = k;
      k = jk;
    } else {
        jk = 1;
    }
    cout << "fib()" << "  i-" << i << "    val-" << jk << endl;
  }
}


void ask() {
  int epochs = 44;
  cout << " \n ask() initialized... " << endl;
  while(asking)
  {    
    cout << "Run fib()? (0 or 1)  "; cin >> runFib;
    cout << "# of epochs?  "; cin >> epochs;
    if(runFib)
    {
      fib(epochs+1);
    }
    
    cout << "ask again? (0 or 1)  "; cin >> asking;
  }
}

int main() {
  init();
  ask();
  
  return 0;
}