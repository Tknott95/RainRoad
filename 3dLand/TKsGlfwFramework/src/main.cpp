#include "headers/window.h"

/*************************
  Reset='\e[0m'
  Red='\e[0;31m'
  Green='\e[0;32m'
  Orange='\e[0;33m'
  Blue='\e[0;34m'
  Purple='\e[0;35m'
  Cyan='\e[0;36m'
  LightGrey='\e[0;37m'
  DarkGrey='\e[1;30m'
  LightRed='\e[1;31m'
  LightGreen='\e[1;32m'
  Yellow='\e[1;33m'
  LightBlue='\e[1;34m'
  LightPurple='\e[1;35m'
  LightCyan='\e[1;36m'
  White='\e[1;37m'
  BlackBG_BoldGreen='\e[1;32;40m'
***************************/

int main() {
  printf("    \n\e[1;32;40m    App Initialized\e[0m\n");

  Window window;

  while(window.isOpen) {
    window.render();
    window.update();
  }
 
  return 0;
}
