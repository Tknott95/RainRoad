#include "Message.h"

/* Basic Script For Constructor/Destructor Visualization */
Message::Message(const char *val) {
  cout << "\n Making: " << this->_message << endl;
  _message = new char[strlen(val) + 1];
  strcpy(_message, val);
}

Message::~Message() {
  cout << "\n Del: " << this->_message << endl;
  delete [] this->_message;
}

void Message::paint() {
  cout << "\n Msg: " << this->_message << endl;
}