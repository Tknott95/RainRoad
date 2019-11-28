#include <iostream>
#include <cstring>
using namespace std;

class Message {
  private:
    char *_message;
  public:
    Message(const char *);
    ~Message();
    void paint();
};