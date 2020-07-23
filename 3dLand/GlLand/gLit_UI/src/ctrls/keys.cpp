#include "../headers/keys.h"

void Keys::keyPolling(GLFWwindow* window, Camera* camera, float deltaTime) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    printf("    \n\e[1;32;40m    WindowClosing\e[0m\n");
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    printf("\n  1, 1Pressed    |    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);");
  }
  if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    printf("\n  2, 2Pressed    |    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);");
  }

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) camera->ProcessKeyboard(FORWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) camera->ProcessKeyboard(BACKWARD, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) camera->ProcessKeyboard(LEFT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) camera->ProcessKeyboard(RIGHT, deltaTime);
  if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
  if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
  if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS);
  if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
    if(camera->transform.Position.y <= 0) camera->transform.Position.y += 0.2f;
  }
}