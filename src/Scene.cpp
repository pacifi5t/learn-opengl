#include <iostream>
#include <glad/glad.h>

#include "Scene.hpp"

Scene::Scene()
{
    if (!glfwInit())
    {
        return;
    }
    window = glfwCreateWindow(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT, "Hello World", nullptr, nullptr);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!window)
    {
        glfwTerminate();
        std::cout << "Failed to create window\n";
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
    }
    glViewport(0, 0, WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
}

Scene::~Scene()
{
    glfwTerminate();
}

GLFWwindow *Scene::getWindow()
{
    return window;
}
