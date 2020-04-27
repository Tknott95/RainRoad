#include "../headers/window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
/* @TIP HATE_CALLBACKS, REMOVE THIS SHIT Hack together my own way w/ out callbacks, this is shit */
/* Using SFML next time because callback are dogshit */
// void Window::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
//   if (mouse.initMove) {
//     mouse.lastX = xpos;
//     mouse.lastY = ypos;
//     mouse.initMove = false;
//   }

//   float xoffset = xpos - mouse.lastX;
//   float yoffset = mouse.lastY - ypos; // reversed since y-coordinates go from bottom to top

//   mouse.lastX = xpos;
//   mouse.lastY = ypos;

//   this->_camera->ProcessMouseMovement(xoffset, yoffset, true);
// }
/* GETTING RID OF CALLBACKS OTHER THEN framebufferCallback
   WILL USE glfwGetCursorPos(window, &xpos, &ypos); for mouse fps cam 
   || WILL DO THIS IN MY FRAMEWORK PROJECT b4 Implementation here ||
*/

Window::Window() {
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  this->_window = glfwCreateWindow(screenSize.x, screenSize.y, "LitLighting02", nullptr, nullptr);
  glfwMakeContextCurrent(this->_window);
  glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

  mouse.lastX = screenSize.x /2;
  mouse.lastY = screenSize.y /2;  

  this->_camera = new Camera(screenSize.x, screenSize.y, glm::vec3(0.0f, 0.0f, 3.0f));

  glewInit();

  glEnable(GL_DEPTH_TEST);

  this->draw = new Draw();
  this->draw->init();
};

Window::~Window() {
  /* Deallocate here */
  glfwTerminate();
};

void Window::render() {

};

void Window::update() {
  while(!glfwWindowShouldClose(_window)) {
    float currentFrame = glfwGetTime();
    _deltaTime = currentFrame - _lastFrame;
    _lastFrame = currentFrame;
    keys.keyPolling(_window, _camera, _deltaTime);

    glClearColor(0.f, 0.f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->draw->update(_camera, screenSize);

    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }

  isOpen = false;
};

