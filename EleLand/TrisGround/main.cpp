#include<iostream>
#include<vector>

#include <GLFW/glfw3.h>

using namespace std;

class RefactorMe {
  // @TODO Refactor code into headers/ctrls
  private:
    struct v3 { float x,y,z; };
    struct triangle { v3 coord[3]; };
    struct mesh { vector<triangle> tris; };

  public:
    mesh cubeMesh;

    void onInit() { 
      // Not USing constuctors here for visualization purposes
      // South side towards ME on Zedd Axis
      cubeMesh.tris = { 
        /*
           - Coords in order, w/ 2 tris each a face, of (x,y,z) in clockwise tri order -
          South
          East
          North
          West
          Top
          Bottom
        */
       {0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f},
       {0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f},

       {1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f},
       {1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f},

       {1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f},
       {1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f},

       {0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f},
       {0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f},

       {0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f},
       {0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f},

       {1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f},
       {1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f},
      };
    }
};

int main() {
  printf("\n  App Initialized() ... \n");

  RefactorMe refactorMe;
  refactorMe.onInit();

  printf("\n - cubeMesh tri coords  - \n");
  for (auto tri : refactorMe.cubeMesh.tris) {
    // Here we would draw each triangle coord, (x,y,z), via: clockwise motion as the coords are orientated that way.
    printf("{(%.2f, %.2f, %.2f),  (%.2f, %.2f, %.2f),  (%.2f, %.2f, %.2f)} \n", tri.coord[0].x, tri.coord[0].y, tri.coord[0].z, tri.coord[1].x, tri.coord[1].y, tri.coord[1].z, tri.coord[2].x, tri.coord[2].y, tri.coord[2].z);
  }
  printf("\n");

  return 0;
}
