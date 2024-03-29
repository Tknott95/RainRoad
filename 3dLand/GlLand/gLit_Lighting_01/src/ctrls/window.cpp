#include "../headers/window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
// void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
//     if (firstMouse)
//     {
//         lastX = xpos;
//         lastY = ypos;
//         firstMouse = false;
//     }

//     float xoffset = xpos - lastX;
//     float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

//     lastX = xpos;
//     lastY = ypos;

//     camera.ProcessMouseMovement(xoffset, yoffset);
// }


Window::Window() {
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  this->_window = glfwCreateWindow(screenSize.x, screenSize.y, "LitLighting", nullptr, nullptr);
  glfwMakeContextCurrent(this->_window);
  glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
  

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

