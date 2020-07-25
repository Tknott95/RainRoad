#include "headers/window.h"
/*************************
@AUTHOR: Trevor Knott
@DATE:   07-22-20
  Reset='\e[0m'
  BlackBG_BoldGreen='\e[1;32;40m'
  BlackBG_Red='\e[0;31;40m'
  BlackBG_Yellow='\e[0;33;40m'
  BlackBG_Blue=\e[0;36;40m
  BlackBG_BoldWhite=\e[0;39;40m
  BlackBG_BlueWhiteCombo=\e[0;36;40m ...  \e[0;39;40m... \e[0m
***************************/

int main(int argc, char *argv[]) {
  const char* APP_TITLE = "gLit_UI";
  const bool DEBUG_MODE = (argc) ? true : false;

  printf("    \n\e[1;32;40m    App Initialized\e[0m\n");

  Window window{APP_TITLE};

  while(window.isOpen) {
    window.render();
    window.update();
  }
 
  return 0;
}
