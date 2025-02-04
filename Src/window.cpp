#include "window.h"

// Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

Window::Window(const char * title, int scr_width, int scr_height)
    : m_width{scr_width}, m_height{scr_height}, m_mixValue{0.2f}, m_deltaTime{0.0f}
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    m_window = glfwCreateWindow(scr_width, scr_height, title, NULL, NULL);
    if (m_window == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
    glfwSetCursorPosCallback(m_window, mouse_callback);
    glfwSetScrollCallback(m_window, scroll_callback);
}

void Window::processInput()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(m_window, true);
    }

    if (glfwGetKey(m_window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        m_mixValue += 0.001f;
        if (m_mixValue > 1.0f)
        {
            m_mixValue = 1.0f;
        }
    }

    if (glfwGetKey(m_window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        m_mixValue -= 0.001f;
        if (m_mixValue < 0.0f)
        {
            m_mixValue = 0.0f;
        }
    }

    if(glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.processKeyBoard(FORWARD, m_deltaTime);
    }
    if(glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.processKeyBoard(BACKWARD, m_deltaTime);
    }
    if(glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.processKeyBoard(LEFT, m_deltaTime);
    }
    if(glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.processKeyBoard(RIGHT, m_deltaTime);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn)
{
    float xpos = static_cast<float>(xPosIn);
    float ypos = static_cast<float>(yPosIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = ypos - lastY;

    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.processMouseScroll(static_cast<float>(yoffset));
}