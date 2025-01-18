#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : m_position{position}, m_front{glm::vec3(0.0f, 0.0f, -1.0f)}, m_worldUp{up}, m_yaw{yaw}, m_pitch{pitch}, 
    m_moveSpeed{SPEED}, m_mouseSensitivity{SENSITIVITY}, m_zoom{ZOOM}   
{
    updateCameraVectors();
}

void Camera::processKeyBoard(Camera_Movement direction, float deltaTime)
{
    float velocity = m_moveSpeed * deltaTime;
    switch(direction)
    {
    case FORWARD:
        m_position += m_front * velocity;
        break;
    case BACKWARD:
        m_position -= m_front * velocity;
        break;
    case LEFT:
        m_position -= m_right * velocity;
        break;
    case RIGHT:
        m_position += m_right * velocity;
        break;
    }
}

void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
    xoffset *= m_mouseSensitivity;
    yoffset *= m_mouseSensitivity;
    m_yaw += xoffset;
    m_pitch += yoffset;

    if (constrainPitch)
    {
        m_pitch = glm::max(-89.0f, m_pitch);
        m_pitch = glm::min(89.0f, m_pitch);
    }

    updateCameraVectors();
}

void Camera::processMouseScroll(float yoffset)
{
    m_zoom -= yoffset;
    m_zoom = glm::max(1.0f, m_zoom);
    m_zoom = glm::min(45.0f, m_zoom);
}

void Camera::updateCameraVectors()
{
    // calculate new front vector
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);
    // recalculate the right and up vector
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}
