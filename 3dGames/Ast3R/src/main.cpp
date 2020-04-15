#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>

using namespace std;

void keyPolling(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      printf("\n WindowClosing\n");
      glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
      printf("\n  zPressed, bitch");
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
      printf("\n  xPressed, bitch");
    }
}

int main() {
  cout << "\n appInitialized...\n" << endl;
  if(!glfwInit()) {
    printf("\n glfwInit() FAILED\n");
    return -1;
  }

  glfwInit();
  // this_thread::sleep_for(chrono::seconds(1));

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  GLFWwindow* window = glfwCreateWindow(900, 700, "Ast3R", nullptr, nullptr); // Windowed
  // GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
  glewExperimental = GL_TRUE;
  if(!glewInit()) { printf("\nGlewInit FAILED\n"); return -1;}
  glfwMakeContextCurrent(window);
  glewInit();
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  printf("%u\n", vertexBuffer);


  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();

    keyPolling(window);
  
  }

  return 0;
}
