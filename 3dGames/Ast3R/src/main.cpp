#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>
#include "headers/keys.h"

using namespace std;

GLFWwindow* window;

void initWindow() {
  cout << "\n appInitialized...\n" << endl;
  if(!glfwInit()) {
    printf("\n glfwInit() FAILED\n");
    /* return -1; - @TODO: replace w/ panicCall */
  }

  glfwInit();
  // this_thread::sleep_for(chrono::seconds(1));
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window = glfwCreateWindow(900, 700, "Ast3R", nullptr, nullptr); // Windowed
  // GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
  glewExperimental = GL_TRUE;
  if(!glewInit()) { printf("\nGlewInit FAILED\n"); /* return -1 */;}
  glfwMakeContextCurrent(window);
  glewInit();
};

const char* vertexSource = R"glsl(
  #version 330 core
  in vec2 position;
  void main() {
    gl_Position = vec4(position, 0.0, 1.0);
  }
  )glsl";

  const char* fragmentSource = R"glsl(
  #version 330 core
  out vec4 outColor;
  void main() {
    outColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);    }
  )glsl";

void glInit() {
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  GLint status;
  // glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
  // char buffer[512];
  // glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  // fragmentShader
  // @TODO double check glsl for frag shader
  int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);
  glUseProgram(shaderProgram);

  float vertices[] = {
    0.5f,  0.5f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
  };
  unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  }; 

  unsigned int vao, vbo, ebo; // vertexArrayObject
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


  GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
  glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(posAttrib);

  if(glfwWindowShouldClose(window)) {
    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &ebo);
    glfwTerminate();
  }
}

int main() {
  initWindow();
  glInit();
  
  while(!glfwWindowShouldClose(window)) {
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
    glfwPollEvents();

    Keys keys;
    keys.keyPolling(window);  
  }

  return 0;
}
