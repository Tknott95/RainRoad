#include "Message.h"

/* Basic Script For Constructor/Destructor Visualization */
Message::Message(const char *val) {
  cout << "\n Making: " << _message << endl;
  _message = new char[strlen(val) + 1];
  strcpy(_message, val);
}

Message::~Message() {
  cout << "\n Del: " << _message << endl;
  delete [] _message;
}

void Message::paint() {
  cout << "\n Msg: " << _message << endl;
}