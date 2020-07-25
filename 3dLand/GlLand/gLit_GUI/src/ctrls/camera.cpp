#include "../headers/camera.h"

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(transform.Position, transform.Position + transform.Front, transform.Up);
}

float Camera::getZoom() const {
  return this->cam.zoom;
}

void Camera::ProcessKeyboard(CamMovement direction, float deltaTime) {
  float velocity = cam.speed * deltaTime;
  if (direction == FORWARD) transform.Position += transform.Front * velocity;
  if (direction == BACKWARD) transform.Position -= transform.Front * velocity;
  if (direction == LEFT) transform.Position -= transform.Right * velocity;
  if (direction == RIGHT) transform.Position += transform.Right * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true) {
  xoffset *= cam.sensitivity;
  yoffset *= cam.sensitivity;
  cam.yaw += xoffset;
  cam.pitch += yoffset;

  /*When pitch is out of bounds, screen ! get flipped */
  if (constrainPitch) {
    if (cam.pitch > 89.0f) cam.pitch = 89.0f;
    if (cam.pitch < -89.0f) cam.pitch = -89.0f;
  }
  updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset) {
  if (cam.zoom >= 1.0f && cam.zoom <= 45.0f) cam.zoom -= yoffset;
  if (cam.zoom <= 1.0f) cam.zoom = 1.0f;
  if (cam.zoom >= 45.0f) cam.zoom = 45.0f;
}

void Camera::updateCameraVectors() {
  glm::vec3 front;
  front.x = cos(glm::radians(cam.yaw)) * cos(glm::radians(cam.pitch));
  front.y = sin(glm::radians(cam.pitch));
  front.z = sin(glm::radians(cam.yaw)) * cos(glm::radians(cam.pitch));
  transform.Front = glm::normalize(front);
  transform.Right = glm::normalize(glm::cross(transform.Front, transform.WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
  transform.Up    = glm::normalize(glm::cross(transform.Right, transform.Front));
  // printf("\n  \e[0;36;40mcamPos\e[0;39;40m(%.2f, %.2f, %.2f)\e[0m", transform.Position.x, transform.Position.y, transform.Position.z);
}
