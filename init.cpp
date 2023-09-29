#include "init.h"

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>

GLFWwindow* window;

class Setup {
public:
    GLFWwindow* window;
    int height;
    int width;
    void framebuffer_size_callback();

    int init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }
    }

    int setupWindow() {
        GLFWwindow* window = glfwCreateWindow(height, width, "engine", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, glViewport(0, 0, width, height));
    }

    GLFWwindow* getWindow(void) {
        return window;
    }

};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}