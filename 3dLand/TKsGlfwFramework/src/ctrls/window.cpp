#include "../headers/window.h"

Window::Window() { 
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();
  glewInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  this->_window = glfwCreateWindow(_screenWidth, _screenHeight, "LitLighting", nullptr, nullptr);

  glfwMakeContextCurrent(_window);
};

Window::~Window() {
  /* Deallocate here */
  glfwTerminate();
};

void Window::render() {

};

void Window::update() {
  while(!glfwWindowShouldClose(_window)) {
    keys.keyPolling(_window, _camera, _deltaTime);

    float currentFrame = glfwGetTime();
    _deltaTime = currentFrame - _lastFrame;
    _lastFrame = currentFrame;

    glfwSwapBuffers(_window);
    glfwPollEvents();
  }

  isOpen = false;
};