#include <iostream>
// #define GLEW_STATIC replaced w/ cli:  -DGLEW_STATIC
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <thread>
#include "headers/keys.h"
#define STB_IMAGE_IMPLEMENTATION
#include "headers/third_party/stb_image.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
/* @TODO bring this into keys class */
// void processInput(GLFWwindow *window);
/* @TODO bring this into keys class */

/* @TODO make game.cpp & game.h to get rid of this global shit */
GLFWwindow* window;
Camera* camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 576;
/*
 16:10 1280×800, 1440×900, 1680×1050, 1920×1200, 2560×1600.
 16:9 1024×576, 1152×648,  1280×720, 1366×768, 1600×900,
      1920×1080, 2560×1440 and 3840×2160
 */
int shaderProgram;
int fragmentShader;
GLuint vertexShader;
unsigned int vao, vbo, ebo;
unsigned int texture0;
/* @TODO make game.cpp & game.h to get rid of this global shit */


float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;
/* @TODO refactor this */
float lastX = WIDTH / 2.0f;
float lastY = HEIGHT / 2.0f;
bool firstMouse = true;
/* @TODO refactor this */

float vertices[] = {
  -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f,
  0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,     1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
  0.5f,  0.5f, -0.5f,     1.0f, 0.8f, 1.0f,    1.0f, 1.0f,
  -0.5f,  0.5f, -0.5f,    0.2f, 0.3f, 0.4f,    0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,

  -0.5f, -0.5f,  0.5f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f,
  0.5f, -0.5f,  0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,     1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,     1.0f, 0.8f, 1.0f,    1.0f, 1.0f,
  -0.5f,  0.5f,  0.5f,    0.2f, 0.3f, 0.4f,    0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,     0.0f, 0.0f,

  -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
  -0.5f,  0.5f, -0.5f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,    1.0f, 0.8f, 1.0f,    0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,    0.2f, 0.3f, 0.4f,    0.0f, 0.0f,
  -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,

  0.5f,  0.5f,  0.5f,     0.0f, 0.0f, 1.0f,    1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
  0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,    0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,     1.0f, 0.8f, 1.0f,    0.0f, 1.0f,
  0.5f, -0.5f,  0.5f,     0.2f, 0.3f, 0.4f,    0.0f, 0.0f,
  0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 1.0f,    1.0f, 0.0f,

  -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
  0.5f, -0.5f,  0.5f,     1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
  0.5f, -0.5f,  0.5f,     1.0f, 0.8f, 1.0f,    1.0f, 0.0f,
  -0.5f, -0.5f,  0.5f,    0.2f, 0.3f, 0.4f,    0.0f, 0.0f,
  -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,

  -0.5f,  0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    0.0f, 1.0f,
  0.5f,  0.5f, -0.5f,     0.0f, 1.0f, 0.0f,    1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,     1.0f, 0.0f, 0.0f,    1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,     1.0f, 0.8f, 1.0f,    1.0f, 0.0f,
  -0.5f,  0.5f,  0.5f,    0.2f, 0.3f, 0.4f,    0.0f, 0.0f,
  -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f
};

glm::vec3 cubePos[] = {
  glm::vec3( 0.0f,  0.0f,  0.0f),
  glm::vec3( 2.0f,  5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f),
  glm::vec3(-3.8f, -2.0f, -12.3f),
  glm::vec3( 2.4f, -0.4f, -3.5f),
  glm::vec3(-1.7f,  3.0f, -7.5f),
  glm::vec3( 1.3f, -2.0f, -2.5f),
  glm::vec3( 1.5f,  2.0f, -2.5f),
  glm::vec3( 1.5f,  0.2f, -1.5f),
  glm::vec3(-1.3f,  1.0f, -1.5f)
};

void initWindow() {
  cout << "\n appInitialized...\n" << endl;
  if(!glfwInit()) {
    printf("\n glfwInit() FAILED\n");
    /* return -1; - @TODO: replace w/ panicCall */
  }

  glfwInit();
  // this_thread::sleep_for(chrono::seconds(1));
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  window = glfwCreateWindow(WIDTH, HEIGHT, "Ast3R", nullptr, nullptr);
  // GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
  // glewExperimental = GL_TRUE;
  if(!glewInit()) { printf("\nGlewInit FAILED\n"); /* return -1 */;}
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); /* is this + theFunc really needed? */
  glfwSetCursorPosCallback(window, mouse_callback);
  glfwSetScrollCallback(window, scroll_callback);

  glewInit();
};

const char *vertexSource =
    "#version 440 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"

    "uniform mat4 transform;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"

    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * transform * vec4(aPos, 1.0);\n"
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
    "    FragColor = texture(texture0, TexCoord)* vec4(ourColor, 1.0);\n"
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
  
  glEnable(GL_DEPTH_TEST);

  // unsigned int vao, vbo, ebo; // vertexArrayObject
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  // glGenBuffers(1, &ebo);
  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load("resources/textures/marble.jpg", &width, &height, &nrChannels, 0);
  glGenTextures(1, &texture0);
  glBindTexture(GL_TEXTURE_2D, texture0); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    cout << "Failed to load texture" << endl;
  }
  stbi_image_free(data); /* endTextureInit */

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
  // glDeleteBuffers(1, &ebo);
  glfwTerminate();
  cout << "\n DeAllocation \n" << endl;
}

int main() {
  initWindow();
  glInit();

  // glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  // trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
  // vec = trans * vec;
  // cout << " (" << vec.x << ", " << vec.y <<  ", " << vec.z << ") \n" << endl;
  // trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5)); 

  float timeRot;
  glm::mat4 trans0 = glm::mat4(1.0f);
  // glm::mat4 proj0 = glm::mat4(1.0f);
  // glm::mat4 view0 = glm::mat4(1.0f);


  /* camera Init() */
  glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
  glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
  glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f); 
  glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
  glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
  glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); 
  glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
  // glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
  // glm::mat4 view;
  // view = glm::lookAt(
  //   glm::vec3(0.0f, 0.0f, 3.0f), 
  //   glm::vec3(0.0f, 0.0f, 0.0f), 
  // 	glm::vec3(0.0f, 1.0f, 0.0f));


  // glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);

  // glm::mat4 projection;
  // projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  // glUseProgram(shaderProgram);

  while(!glfwWindowShouldClose(window)) {
    Keys keys;
    keys.keyPolling(window, camera, deltaTime);

    glm::mat4 proj0= glm::perspective(glm::radians(camera->Zoom), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
    glm::mat4 view0 = camera->GetViewMatrix();

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    
    proj0 = glm::perspective(glm::radians(45.0f), (float)WIDTH/(float)HEIGHT, 0.1f, 100.0f);
    // view0 = glm::translate(view0, glm::vec3(0.0f, 0.0f, -0.002f));
    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    // rotates cam view0 = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
    // view0 = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
  
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture0"), 0); // grabs uniform from shader, bby
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);

    // if(timeRot > 2) glfwSetTime(0);  oscillate speed
    // timeRot = (float)glfwGetTime() * .00085;
    float rotSpeed = 0.005f;


    unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view0));
    unsigned int projLoc = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj0));
   
    trans0 = glm::rotate(trans0, rotSpeed, glm::vec3(1.0, 1.0, 1.0));
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans0));

    glBindVertexArray(vao);
    for(unsigned int i=0; i < 10; i++) {
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, glm::vec3(1.7f, 1.0f, 1.0f) * cubePos[i]);
      model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.3f, 0.3f));
      unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
      glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); @REMOVED_ebo or elementBufferObject
    // @TODO Make vertices check dynamic, the 36

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  deAllocate();

  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
  lastX = xpos;
  lastY = ypos;
  camera->ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera->ProcessMouseScroll(yoffset);
}
