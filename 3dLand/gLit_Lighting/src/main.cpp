#include "headers/window.h"

/*************************
  Reset='\e[0m'
  Red='\033[0;31m'
  Green='\033[0;32m'
  Orange='\033[0;33m'
  Blue='\033[0;34m'
  Purple='\033[0;35m'
  Cyan='\033[0;36m'
  LightGrey='\033[0;37m'
  DarkGrey='\033[1;30m'
  LightRed='\033[1;31m'
  LightGreen='\033[1;32m'
  Yellow='\033[1;33m'
  LightBlue='\033[1;34m'
  LightPurple='\033[1;35m'
  LightCyan='\033[1;36m'
  White='\033[1;37m'
  BlackBG_BoldGreen='\033[1;32;40m'
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
