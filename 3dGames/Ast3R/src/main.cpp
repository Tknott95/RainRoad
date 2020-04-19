#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>
#include "headers/keys.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GLFWwindow* window;
const unsigned int WIDTH = 900;
const unsigned int HEIGHT = 700;
int shaderProgram;
int fragmentShader;
GLuint vertexShader;
unsigned int vao, vbo, ebo;


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
  window = glfwCreateWindow(WIDTH, HEIGHT, "Ast3R", nullptr, nullptr); // Windowed
  // GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
  glewExperimental = GL_TRUE;
  if(!glewInit()) { printf("\nGlewInit FAILED\n"); /* return -1 */;}
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); /* is this + theFunc really needed? */
  glewInit();
};

const char *vertexSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";

const char *fragmentSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor, 1.0f);\n"
    "}\n\0";

void glInit() {
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  GLint status;
  char buffer[512];
  glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

  // fragmentShader
  // @TODO double check glsl for frag shader
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  // glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);
  
  float vertices[] = {
    0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom left
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f  // top left 
  };
  unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
  }; 

  // unsigned int vao, vbo, ebo; // vertexArrayObject
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


  // position attribute
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
    // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glUseProgram(shaderProgram);


  // if(glfwWindowShouldClose(window)) {
  //   glDeleteProgram(shaderProgram);
  //   glDeleteShader(fragmentShader);
  //   glDeleteShader(vertexShader);
  //   glDeleteBuffers(1, &vbo);
  //   glDeleteVertexArrays(1, &vao);
  //   glDeleteBuffers(1, &ebo);
  //   glfwTerminate();
  //   printf("\n DeAllocation \n");
  // }
}

int main() {
  initWindow();
  glInit();
  
  while(!glfwWindowShouldClose(window)) {
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    Keys keys;
    keys.keyPolling(window);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); /*  GL_LINE if wanting wireframe view */
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(shaderProgram);
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &ebo);
  glfwTerminate();
  printf("\n DeAllocation \n");

  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
