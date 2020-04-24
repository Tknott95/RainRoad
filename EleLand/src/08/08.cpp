#include <fstream>
#include <iostream>
#include<sstream>
using namespace std;



int main() { 
  string text;
  float v[] = {};
  string vData;

  ifstream ifs("src/08/cube_vertices.txt", ios::in);
  if(!ifs.is_open()) {
    printf("Shit broke on ifstream bruhva");
    return -1;
  }

  int i=0;
  while(getline(ifs, text)) {
    stringstream ss(text);
    getline(ss, vData, '\n');
    cout << vData << endl;
  }

  ifs.close();

  return 0; 
}