#include "headers/window.h"
/*************************
  Reset='\e[0m'
  BlackBG_BoldGreen='\e[1;32;40m'
  BlackBG_Red='\e[0;31;40m'
  BlackBG_Yellow='\e[0;33;40m'
***************************/

int main() {
  const char* APP_TITLE = "gLit_UI";

  printf("    \n\e[1;32;40m    App Initialized\e[0m\n");
  Window window{APP_TITLE};

  while(window.isOpen) {
    window.render();
    window.update();
  }
 
  return 0;
}
