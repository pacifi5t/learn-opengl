#pragma once

#include <GLFW/glfw3.h>

const int WINDOW_DEFAULT_WIDTH = 1280;
const int WINDOW_DEFAULT_HEIGHT = 720;

class Scene
{
private:
    GLFWwindow *window;

public:
    Scene();
    ~Scene();
    GLFWwindow *getWindow();
};

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
