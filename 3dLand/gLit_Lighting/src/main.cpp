#include "headers/window.h"
#include "headers/shader.h"
/*************************
  Reset='\e[0m'
  BlackBG_BoldGreen='\e[1;32;40m'
  BlackBG_Red='\e[0;31;40m'
***************************/

int main() {
  printf("    \n\e[1;32;40m    App Initialized\e[0m\n");

  Window window;

  // Shader shader("src/shaders/material/material.vs", "src/shaders/material/material.fs");

  while(window.isOpen) {
    window.render();
    window.update();
  }
 
  return 0;
}
