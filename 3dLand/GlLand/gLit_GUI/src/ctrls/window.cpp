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
  /* FPS capped at 60 due to double buffering and v-sync w/ glfw */
  double nowTime = glfwGetTime();
  fpsEpochs++;

  deltaTime = nowTime-startTime;

  if(deltaTime >= 1.f) {
    FPSRate = fpsEpochs;
    fpsEpochs = 0;
    /* time not resetting and getting huge and arith to costly,
    * set timer back to 0 before the subtraction reaction for no costly faction
    * inside realities pac-10 controlled masonic lobbied congolomerate. 
    */
    // ms/frame = 1000.0/FPSRate;
    startTime = glfwGetTime();
    printf("\n    \e[3;36;40mdeltaTime:\e[0;39;40m %f\e[0m", deltaTime);
    printf("\n    \e[1;36;40mFPS:\e[0;39;40m %i\e[0m", FPSRate);
    printf("\n    \e[0;36;40mstartTime:\e[0;39;40m %f\e[0m", startTime);
    printf("\n    \e[2;36;40mnowTime:\e[0;39;40m %f\e[0m", nowTime);
  };
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

  startTime = glfwGetTime();
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
    this->FPS();    
 
    keys.keyPolling(_window, _camera, deltaTime); /* inverting delta time here */

    glClearColor(0.f, 0.f, 0.14f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->draw->update(_camera, screenSize, FPSRate);

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
