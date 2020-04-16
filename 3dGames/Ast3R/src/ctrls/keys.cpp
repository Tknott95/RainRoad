#include "../headers/keys.h"

void Keys::keyPolling(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      printf("\n WindowClosing\n");
      glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
      printf("\n  zPressed, bitch");
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
      printf("\n  xPressed, bitch");
    }
}