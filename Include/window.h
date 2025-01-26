#ifndef WINDOW_H
#define WINDOW_H

#include <glfw/glfw3.h>
#include "camera.h"

#include <iostream>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera declaration
extern Camera camera;

// utility function
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

class Window
{
public:
    Window() = delete;
    Window(const char * title, int scr_width = SCR_WIDTH, int scr_height = SCR_HEIGHT);

    // process all input
    void processInput();

    // access glfw window
    inline GLFWwindow * getWindow() const
    {
        return m_window;
    }

    // access screen width
    inline int getWidth() const
    {
        return m_width;
    }

    // access screen height
    inline int getHeight() const
    {
        return m_height;
    }

    // access mixValue
    inline float getMixValue() const
    {
        return m_mixValue;
    }

    // set deltaTime
    inline void setDeltaTime(float deltaTime)
    {
        m_deltaTime = deltaTime;
    }

private:
    // glfw window
    GLFWwindow * m_window;

    // window settings
    int m_width;
    int m_height;

    // stores how much we're seeing of either texture
    float m_mixValue;

    // timing
    float m_deltaTime;
};

#endif