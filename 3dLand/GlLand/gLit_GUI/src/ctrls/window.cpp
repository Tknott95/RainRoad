#include "../headers/window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

void Window::mousePolling(dvec2 _pos) {
  if (mouse.initMove) {
    mouse.lastX = _pos.x;
    mouse.lastY = _pos.y;
    mouse.initMove = false;
  }

  float xoffset = _pos.x - mouse.lastX;
  float yoffset = mouse.lastY - _pos.y;

  mouse.lastX = _pos.x;
  mouse.lastY = _pos.y;

  this->_camera->ProcessMouseMovement(xoffset, yoffset, true);
};

void Window::FPS() {
  const float startTime = glfwGetTime();
  deltaTime = startTime-endTime; /* deltaTime gives me loopTime for keysFiring */

  fpsEpochs++;
  if(deltaTime >= 1.f) { /* fix this to reset a clock every time it psses to check for 1ms */
    this->FPSRate = fpsEpochs*1000/deltaTime;

    cout << "\n    \e[0;36;40mFPS:\e[0;39;40m " << FPSRate << "\e[0m" << endl;
  };
  // if(deltaTime >= 1000) FPSRate = fpsEpochs*1000.0/deltaTime;
  /* if(deltaTime >= maxPeriod)*/
  endTime = startTime;
};


Window::Window(const char* _appTitle) {
  if(!glfwInit()) printf("\n\e[0;31;40m glfwInit() FAILED \e[0m\n");
  if(!glewInit()) printf("\n\e[0;31;40m GlewInit FAILED \e[0m\n");

  glfwInit();

  glewExperimental = GL_TRUE;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  this->_window = glfwCreateWindow(
    screenSize.x, screenSize.y,
    _appTitle, nullptr, nullptr);
  glfwMakeContextCurrent(this->_window);
  glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);

  glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  mouse.lastX = screenSize.x /2; mouse.lastY = screenSize.y /2;

  this->_camera = new Camera(screenSize.x, screenSize.y, vec3(0.0f, 0.0f, 2.4f));

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
  uptime = glfwGetTime();

  while(!glfwWindowShouldClose(_window)) {
    this->FPS();    

    keys.keyPolling(_window, _camera, deltaTime);

    glClearColor(0.f, 0.f, 0.14f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->draw->update(_camera, screenSize);

    if(this->_camera->transform.Position.y <= -0.7) {
      this->_camera->transform.Position.y += 0.2f;
    }

    if(this->_camera->transform.Position.y >= 2) {
      this->_camera->transform.Position.y -= 0.3f;
    }
  
    glfwGetCursorPos(_window, &pos.x, &pos.y);
    /* for debugging pos @TODO make a printf();
      std::cout << "\e[0;33;40m  pos.x(" << pos.x << ") pos.y(" << pos.y << ") \e[0m" << std::endl;
    */
    mousePolling(pos);

    glfwSwapBuffers(this->_window);
    glfwPollEvents();
  }

  isOpen = false;
};
