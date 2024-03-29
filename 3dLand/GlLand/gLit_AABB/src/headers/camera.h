#ifndef CAMERA_H
#define CAMERA_H
#include <cstdio>
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

using namespace glm;

class Camera {
  struct CamData {
    float yaw,
      pitch,
      speed,
      sensitivity,
      zoom;
    CamData(float _yaw=-90.f, float _pitch=0.f, float _speed=0.1f, float _sensitivity=0.07f, float _zoom=45.f): pitch(_pitch), speed(_speed), sensitivity(_sensitivity), zoom(_zoom)  {};
  };
  struct CamTransform {
    vec3 Position,
      Front,
      Up,
      Right,
      WorldUp;
    CamTransform(vec3 _front = vec3(0.0f, 0.0f, -1.0f)): Front(_front) {};
  };

public:
  CamData cam;
  CamTransform transform;

  Camera(float screenWidth, float screenHeight, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 up = vec3(0.0f, 1.0f, 0.0f), float yaw = -90.f, float pitch = 0.f) {
    transform.Position = position;
    transform.WorldUp = up;
    cam.yaw = yaw;
    cam.pitch = pitch;

    updateCameraVectors();
  };

  /* @TODO - make these params vec3's, pos and up, for better readability? */
  Camera(float screenWidth, float screenHeight, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {
    transform.Position = vec3(posX, posY, posZ);
    transform.WorldUp = vec3(upX, upY, upZ);
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