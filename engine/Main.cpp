#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>

#include </Users/kraks/Desktop./GLfun/GLfun/sprites/stb_image.h>
#include </Users/kraks/Desktop/GLfun/GLfun/engine/shaders/shader.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int height = 1200;
int width = 1200;

int main()
{
    // init everything
    // ..............................
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // error chech
    // ................................
    GLFWwindow* window = glfwCreateWindow(width, height, "window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // shaders
    // ..................................
    Shader ourShader("shaders/3.3.shader.vs", "shaders/3.3.shader.fs");

    // data 
    // ..........................
    float vertices[] = {
       -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
        0.5f, 0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,
        0.0f,-0.5f, 0.0f,  0.0f, 0.0f, 1.0f,  0.5f, 1.0f
    };

    struct Vertex
    {
        glm::vec3 position;
        glm::vec4 color;
    };

    Vertex triangle[3] =
    {
        {glm::vec3(-0.5, 0.5f, 0.0f), glm::vec4(0.9f, 0.8f, 0.2f, 1.0f)},
        {glm::vec3(-0.5, 0.5f, 0.0f), glm::vec4(0.9f, 0.8f, 0.2f, 1.0f)},
        {glm::vec3(-0.5, 0.5f, 0.0f), glm::vec4(0.9f, 0.8f, 0.2f, 1.0f)}
    };

    unsigned int myVaoid;
    
    glCreateVertexArrays(1, &myVaoid);
    glBindVertexArray(myVaoid);
    
    unsigned int myVboid;

    glGenBuffers(1, &myVboid);
    glBindBuffer(GL_ARRAY_BUFFER, myVboid);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(1);

    // vertex buffers
    // ..........................

    // vertex buffer object = VBO
    // vertex array object  = VAO
    // element buffer object = EBO

    //unsigned int VBO, VAO, EBO;

    // bind vertex buffers
    //glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // send what we want to do with the specific buffers 
    // GL_STATIC_DRAW
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // binding array buffers 
    //glGenVertexArrays(1, &VAO); 
    //glBindVertexArray(VAO);

    // linking vertex attributes
    // ...........................

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    // binding colours ? 
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);

    // texture something
    //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)(6 * sizeof(float)));
    //glEnableVertexAttribArray(2);

    // loop
    // .....................................
    while (!glfwWindowShouldClose(window))
    {
        // inputs
        processInput(window);

        // bg render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render
        ourShader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // window shit
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &myVaoid);
    glDeleteBuffers(1, &myVboid);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}