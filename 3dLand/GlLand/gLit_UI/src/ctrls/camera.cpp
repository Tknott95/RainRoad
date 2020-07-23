#include "../headers/camera.h"

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(CamMovement direction, float deltaTime) {
  float velocity = MovementSpeed * deltaTime;
  if (direction == FORWARD) Position += Front * velocity;
  if (direction == BACKWARD) Position -= Front * velocity;
  if (direction == LEFT) Position -= Right * velocity;
  if (direction == RIGHT) Position += Right * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true) {
  xoffset *= MouseSensitivity;
  yoffset *= MouseSensitivity;
  Yaw += xoffset;
  Pitch += yoffset;

  // Make sure that when pitch is out of bounds, screen doesn't get flipped
  if (constrainPitch) {
    if (Pitch > 89.0f) Pitch = 89.0f;
    if (Pitch < -89.0f) Pitch = -89.0f;
  }
  updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
  if (Zoom >= 1.0f && Zoom <= 45.0f) Zoom -= yoffset;
  if (Zoom <= 1.0f) Zoom = 1.0f;
  if (Zoom >= 45.0f) Zoom = 45.0f;
}

void Camera::updateCameraVectors() {
  glm::vec3 front;
  front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
  front.y = sin(glm::radians(Pitch));
  front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
  Front = glm::normalize(front);
  Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
  Up    = glm::normalize(glm::cross(Right, Front));

  printf("\n  \e[0;36;40mcamPos\e[0;39;40m(%.2f, %.2f, %.2f)\e[0m", Position.x, Position.y, Position.z);
}
