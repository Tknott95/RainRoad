#ifndef CAMERA_H
#define CAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <GLFW/glfw3.h>

enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera {
public:
  glm::vec3 Position;
  glm::vec3 Front;
  glm::vec3 Up;
  glm::vec3 Right;
  glm::vec3 WorldUp;
  float Yaw;
  float Pitch;
  float MovementSpeed;
  float MouseSensitivity;
  float Zoom;
  float lastX; //= screenWidth / 2.0f;
  float lastY; // = screenHeight / 2.0f;

//   Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {};
//   Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {};
  Camera(float screenWidth, float screenHeight, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    float lastX = screenWidth / 2.0f; // prob don't need this yety coding safe for mvp then will pull out
    float lastY = screenHeight / 2.0f; // prob don't need this yety coding safe for mvp then will pull out

    updateCameraVectors();
  };
  Camera(float screenWidth,  float screenHeight, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
     float lastX = screenWidth / 2.0f; // prob don't need this yety coding safe for mvp then will pull out
    float lastY = screenHeight / 2.0f; // prob don't need this yety coding safe for mvp then will pull out
    updateCameraVectors();
  };

  glm::mat4 GetViewMatrix();
  void ProcessKeyboard(Camera_Movement direction, float deltaTime);
  void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch);
  void ProcessMouseScroll(float yoffset);
  //   void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
  //   void MouseCallback(GLFWwindow* window, double xpos, double ypos, bool firstMouse);

private:
  void updateCameraVectors();
};
#endif