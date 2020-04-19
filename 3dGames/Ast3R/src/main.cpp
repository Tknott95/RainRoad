#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>
#include "headers/keys.h"

using namespace std;

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

  float vertices[] = {
    0.0f, 0.5f,
    0.5f, -0.5f,
    -0.5f, -0.5f
  };

  GLuint vBuff;
  glGenBuffers(1, &vBuff);
  printf("%u\n", vBuff);
  glBindBuffer(GL_ARRAY_BUFFER, vBuff);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();

    Keys keys;
    keys.keyPolling(window);
  
  }

  return 0;
}
