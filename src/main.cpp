#include <iostream>

//glad.h is always included first!
#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool immediate_exit = false;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);

int main(int argc, char* argv[])
{
    std::cout << "I'm gonna create a window now!\n";
    glfwInit();

    //It means we use OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //It means we use OpenGL Core profile 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window;

    try
    {
        window = glfwCreateWindow(800, 600, "Told ya", NULL, NULL);
        if(window == nullptr)
        {
            throw std::runtime_error("Failed to create GLFW window\n");
        }

        glfwMakeContextCurrent(window);
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD\n");
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        glfwTerminate();

        return 1;
    }
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        //Processing input
        process_input(window);

        //Rendering commands here
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}