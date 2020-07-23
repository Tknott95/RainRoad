#include "../headers/window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

void Window::mousePolling(double xpos, double ypos) {
  if (mouse.initMove) {
    mouse.lastX = xpos;
    mouse.lastY = ypos;
    mouse.initMove = false;
  }

  float xoffset = xpos - mouse.lastX;
  float yoffset = mouse.lastY - ypos;

  mouse.lastX = xpos;
  mouse.lastY = ypos;

  this->_camera->ProcessMouseMovement(xoffset, yoffset, true);
}

Window::Window() {
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  /* @TODO make var for window name, maybe inside the custom screen struct */
  this->_window = glfwCreateWindow(
    screenSize.x, screenSize.y,
    appTitle,
    nullptr, nullptr);
  glfwMakeContextCurrent(this->_window);
  glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

  glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  mouse.lastX = screenSize.x /2; mouse.lastY = screenSize.y /2;  

  this->_camera = new Camera(screenSize.x, screenSize.y, glm::vec3(0.0f, 0.0f, 2.4f));

  glewInit();

  glEnable(GL_DEPTH_TEST);

  this->draw = new Draw();
};

Window::~Window() {
  glfwTerminate();
  delete(this->_camera);
  delete(this->draw);
};

void Window::render() {

};

void Window::update() {
  while(!glfwWindowShouldClose(_window)) {
    float currentFrame = glfwGetTime();
    _deltaTime = currentFrame - _lastFrame;
    _lastFrame = currentFrame;
    keys.keyPolling(_window, _camera, _deltaTime);

    glClearColor(0.f, 0.f, 0.14f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->draw->update(_camera, screenSize);

    if(this->_camera->Position.y <= -0.7) {
      this->_camera->Position.y += 0.2f;
    }

    if(this->_camera->Position.y >= 2) {
      this->_camera->Position.y -= 0.3f;
    }
  
    glfwGetCursorPos(_window, &xpos, &ypos);
    /* for debugging pos @TODO make a printf();
      std::cout << "\e[0;33;40m  xPos(" << xpos << ") yPos(" << ypos << ") \e[0m" << std::endl;
    */
    mousePolling(xpos, ypos);

    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }

  isOpen = false;
};
