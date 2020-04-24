#include <iostream>
#include <thread>
#include <glm/gtc/type_ptr.hpp>
#include "headers/keys.h"
#include "headers/shader.h"
#include "headers/utils/cube_vertices.h"
#define STB_IMAGE_IMPLEMENTATION
#include "headers/third_party/stb_image.h"
using namespace std;

/* @TODO refactor into Game class -  main is not to hold all code - this is shit */
/* @TODO refactor <  > into a Window class */
const unsigned int WIDTH = 1280;
const unsigned int HEIGHT = 800;
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
/* @TODO bring this into keys class */
// void processInput(GLFWwindow *window);
/* @TODO bring this into keys class */

/* @TODO make game.cpp & game.h to get rid of this global shit */
GLFWwindow* window;
Camera* camera = new Camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 3.0f));
/*
 16:10 1280×800, 1440×900, 1680×1050, 1920×1200, 2560×1600.
 16:9 1024×576, 1152×648,  1280×720, 1366×768, 1600×900,
      1920×1080, 2560×1440 and 3840×2160
 */
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

int totalCubes = 10; // sizeOf(cubePos) causes an extra cube render bug
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
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback); /* is this + theFunc really needed? */
  glfwSetCursorPosCallback(window, mouseCallback);
  glfwSetScrollCallback(window, scrollCallback);
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  if (glfwRawMouseMotionSupported()) glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

  glewInit();
};

void deAllocate() {
  glDeleteBuffers(1, &vbo); /* @TIP - may not need to do */
  glDeleteVertexArrays(1, &vao); /* @TIP - may not need to do */
  // glDeleteBuffers(1, &ebo);
  glfwTerminate();
  cout << "\n DeAllocation \n" << endl;
}

int main() {
  initWindow();
  Shader shader("resources/shaders/gl.vs", "resources/shaders/gl.frag");
  // glInit(); @TODO reuse once modularized/refactored for a header file - was a custom function
  glEnable(GL_DEPTH_TEST);
  // glEnable(GL_STENCIL_TEST); maybe will use for fun little effects such as edge detection

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

  shader.use();
  shader.setInt("texture0", 0);

  while(!glfwWindowShouldClose(window)) {
    Keys keys;
    keys.keyPolling(window, camera, deltaTime);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);

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

    // if(timeRot > 2) glfwSetTime(0);  oscillate speed
    // timeRot = (float)glfwGetTime() * .00085;
    float rotSpeed = 0.005f;

    glm::mat4 viewLoc = glm::mat4(1.0f);
    glm::mat4 projLoc = glm::mat4(1.0f);
    glm::mat4 transformLoc = glm::mat4(1.0f);

    shader.use();

    /* REPLACED BY SHADER CLASS */
    // unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
    // glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view0));
    // unsigned int projLoc = glGetUniformLocation(shaderProgram, "projection");
    // glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj0));
   
    trans0 = glm::rotate(trans0, rotSpeed, glm::vec3(1.0, 1.0, 1.0));
    // unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    // glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans0));

    shader.setMat4("view", view0);
    shader.setMat4("projection", proj0);
    shader.setMat4("transform", trans0);

    glBindVertexArray(vao);

    // for(int j=0; j < 50; j++) {
    //   if(j % 2 == 0) {
    //     cubePos[j] = glm::vec3(j, 2, 1);
    //   } else if(j % 3 == 0) {
    //     cubePos[j] = glm::vec3(j, 1, 1);
    //   } else {
    //     cubePos[j] = glm::vec3(j, 3, 1);
    //   }
    // }
    
    for(unsigned int i=0; i < totalCubes; i++) { /* sizeOf(cubePos); */
      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, glm::vec3(1.0f, 1.0f, 1.0f) * cubePos[i]);
      model = glm::rotate(model, glm::radians(20.0f), glm::vec3(1.0f, 0.3f, 0.3f));
      // unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
      // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
      shader.setMat4("model", model);

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

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// /* @TODO pull into keys class */
void mouseCallback(GLFWwindow* window, double xpos, double ypos){
  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }
  float xoffset = xpos - lastX;
  float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
  lastX = xpos;
  lastY = ypos;
  camera->ProcessMouseMovement(xoffset, yoffset, firstMouse);
}

/* @TODO pull into keys class? */
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
    camera->ProcessMouseScroll(yoffset);
}
