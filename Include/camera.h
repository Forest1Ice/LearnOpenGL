#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

class Camera
{
public:
    Camera() = delete;
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);

    inline glm::mat4 getViewMatrix()
    {
        return glm::lookAt(m_position, m_position + m_front, m_up);
    }

    // processes input received from any keyboard-like input system.
    void processKeyBoard(Camera_Movement direction, float deltaTime);

    // processes input received from a mouse input system.
    void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    // processes input received from a mouse scroll-wheel event.
    void processMouseScroll(float yoffset);

    inline float getZoom() const
    {
        return m_zoom;
    }

private:
    // calculates the front vector from the Camera's (updated) Euler Angles
    void updateCameraVectors();

private:
    // camera attributes
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;

    // euler angles
    float m_yaw;
    float m_pitch;

    // camera options
    float m_moveSpeed;
    float m_mouseSensitivity;
    float m_zoom;
};

#endif