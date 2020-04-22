#include "../headers/keys.h"

void Keys::keyPolling(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    printf("\n WindowClosing\n");
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
    printf("\n  z, zPressed");
  }
  if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
    printf("\n  x, xPressed");
  }

  bool enableDepth = false;
  if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    enableDepth = !enableDepth;
    printf("\n  d, dPressed    |    glEnable(GL_DEPTH_TEST);");
    std::cout << "\n  bool enableDepth(" << enableDepth << ")" << std::endl;
    if(enableDepth) glEnable(GL_DEPTH_TEST);
  }

  if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    printf("\n  1, 1Pressed    |    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);");
  }
  if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    printf("\n  2, 2Pressed    |    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);");
  }
}