#ifndef WINDOW_H
#define WINDOW_H

#include <glfw/glfw3.h>

#include <iostream>

// utility function
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window
{
public:
    Window() = delete;
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

private:
    // glfw window
    GLFWwindow * m_window;

    // window settings
    int m_width;
    int m_height;

    // stores how much we're seeing of either texture
    float m_mixValue;
};

#endif