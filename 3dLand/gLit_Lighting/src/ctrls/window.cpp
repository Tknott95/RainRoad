#include "../headers/window.h"

Window::Window() {
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  this->_window = glfwCreateWindow(screenSize.x, screenSize.y, "LitLighting", nullptr, nullptr);
  glfwMakeContextCurrent(this->_window);

  this->_camera = new Camera(screenSize.x, screenSize.y, glm::vec3(0.0f, 0.0f, 3.0f));

  glewInit();

  this->draw = new Draw();
  this->draw->init();
};

Window::~Window() {
  /* Deallocate here */
  glfwTerminate();
};

void Window::render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
};

void Window::update() {
  while(!glfwWindowShouldClose(_window)) {
    keys.keyPolling(_window, _camera, _deltaTime);
    float currentFrame = glfwGetTime();
    _lastFrame = currentFrame;
    _deltaTime = currentFrame - _lastFrame;

    glClearColor(0.f, 0.f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    this->draw->update(_camera, screenSize);

    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }

  isOpen = false;
};