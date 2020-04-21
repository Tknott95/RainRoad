#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <thread>
#include "headers/keys.h"
#define STB_IMAGE_IMPLEMENTATION
#include "headers/third_party/stb_image.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


GLFWwindow* window;
const unsigned int WIDTH = 900;
const unsigned int HEIGHT = 700;
int shaderProgram;
int fragmentShader;
GLuint vertexShader;
unsigned int vao, vbo, ebo;
unsigned int texture0;


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

const char *vertexSource =
    "#version 440 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "   TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}\0";

const char *fragmentSource =
    "#version 440 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "in vec2 TexCoord;\n"

    // texture sampler
    "uniform sampler2D texture0;\n"

    "void main()\n"
    "{\n"
    "    FragColor = texture(texture0, TexCoord) * vec4(ourColor, 1.0);\n"
    //FragColor = vec4(ourColor, TexCoord);\n"
    // vec4(texture0, TexCoord) * vec4(ourColor, 1.0);\n"

    "}\n\0";

void glInit() {
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexSource, NULL);
  glCompileShader(vertexShader);

  GLint status;
  char buffer[512];
  glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
  glCompileShader(fragmentShader);

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  // glBindFragDataLocation(shaderProgram, 0, "outColor");
  glLinkProgram(shaderProgram);

  /* FIGURE OUT WHERE TO DYNMAN CHANGE THIS SHADER @TODO */
  // float timeVal = glfwGetTime();
  // float greenVal = sin(timeVal) / 2.0f + 0.5f;
  // int vertexColorLoc = glGetUniformLocation(shaderProgram, "fragColor");
  // glUniform4f(vertexColorLoc, 0.0f, greenVal, 0.0f, 1.0f);
  /* FIGURE OUT WHERE TO DYNMAN CHANGE THIS SHADER @TODO */
  
  float vertices[] = {
    0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.75f,  0.0f,  // top right
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.75f, 0.75f, // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.75f,   // bottom left
    -0.5f,  0.5f, 0.0f,  1.0f, 0.8f, 1.0f,   0.0f, 0.0f // top left 
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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  // color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  // texture attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  /* TEXTURE INIT HERE */



  glBindVertexArray(0);
  int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    // resources/textures/container.jpg
    unsigned char *data = stbi_load("resources/textures/pepe.png", &width, &height, &nrChannels, 0);
    // unsigned int texture; MADE GLOBAL
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

  /* endTextureInit */

  glUseProgram(shaderProgram);
  // glActiveTexture(GL_TEXTURE0);
  // glBindTexture(GL_TEXTURE_2D, texture);

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

void deAllocate() {
  glDeleteProgram(shaderProgram);
  glDeleteShader(fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);
  glDeleteBuffers(1, &ebo);
  glfwTerminate();
  cout << "\n DeAllocation \n" << endl;
}

int main() {
  initWindow();
  glInit();
  
  while(!glfwWindowShouldClose(window)) {
    Keys keys;
    keys.keyPolling(window);
  
    glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glBindTexture(GL_TEXTURE_2D, texture);
    // glBindVertexArray(vao);
    glUseProgram(shaderProgram);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glBindVertexArray(vao);


    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); /*  GL_LINE if wanting wireframe view */
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  deAllocate();

  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
