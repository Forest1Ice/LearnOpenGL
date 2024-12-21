#ifndef WINDOW_H
#define WINDOW_H

#include <glfw/glfw3.h>

#include <iostream>

// utility function
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window
{
public:
    explicit Window(const char * title, int width = 800, int height = 600);

    // process all input
    void processInput();

    // access glfw window
    inline GLFWwindow * getWindow() const
    {
        return m_window;
    }

    // access mixValue
    inline float getMixValue() const
    {
        return m_mixValue;
    }

private:
    // glfw window
    GLFWwindow * m_window;

    // stores how much we're seeing of either texture
    float m_mixValue;
};

#endif