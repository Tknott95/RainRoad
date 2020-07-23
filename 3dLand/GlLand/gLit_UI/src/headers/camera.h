#ifndef CAMERA_H
#define CAMERA_H
#include <stdio.h> /* for printf */
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <GLFW/glfw3.h>

enum CamMovement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

  // const float YAW=-90.f,
  //   Pitch=0.f,
  //   Speed=2.5f,
  //   Sensitivity=0.1f,
  //   Zoom=45.f;


// struct CamTrans {
//   glm::vec3 Position;
//   glm::vec3 Front;
//   glm::vec3 Up;
//   glm::vec3 Right;
//   glm::vec3 WorldUp;
// };

// const float YAW = -90.0f;
// const float PITCH = 0.0f;
// const float SPEED = 2.5f;
// const float SENSITIVITY = 0.1f;
// const float ZOOM = 45.0f;

class Camera {
struct CamData {
  float yaw=-90.f,
    pitch=0.f,
    speed=2.5f,
    sensitivity=0.1f,
    zoom=45.f;
  // CamData(float _pitch, _speed, _sensitivity, _zoom): Pitch(_pitch), Speed(_speed), Sensitivity(_sensitivity), Zoom(_zoom)  {};
};
public:
  CamData cam;
  glm::vec3 Position;
  glm::vec3 Front;
  glm::vec3 Up;
  glm::vec3 Right;
  glm::vec3 WorldUp;


  Camera(float screenWidth, float screenHeight, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.f, float pitch = 0.f) : Front(glm::vec3(0.0f, 0.0f, -1.0f)) {
    Position = position;
    WorldUp = up;
    cam.yaw = yaw;
    cam.pitch = pitch;

    updateCameraVectors();
  };
  Camera(float screenWidth,  float screenHeight, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)) {
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    cam.yaw = yaw;
    cam.pitch = pitch;

    updateCameraVectors();
  };

  glm::mat4 GetViewMatrix();
  float getZoom() const;
  void ProcessKeyboard(CamMovement direction, float deltaTime);
  void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch);
  void ProcessMouseScroll(float yoffset);

private:
  void updateCameraVectors();
};
#endif