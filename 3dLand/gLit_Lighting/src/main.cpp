#include "headers/window.h"
/*************************
  Reset='\e[0m'
  BlackBG_BoldGreen='\e[1;32;40m'
  BlackBG_Red='\e[0;31;40m'
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
