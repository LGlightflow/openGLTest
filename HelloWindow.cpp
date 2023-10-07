
#include <iostream>
#include <GL/gl.h>
#include "glfw3.h"

// GLEW
#define GLEW_STATIC

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 1080, HEIGHT = 960;

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW 初始化
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // 创建一个窗口对象，这个窗口对象存放了所有和窗口相关的数据，而且会被GLFW的其他函数频繁地用到。
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);    
    
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // Set the required callback functions,回调函数
    glfwSetKeyCallback(window, key_callback);


    // Define the viewport dimensions
    int width, height;

    glfwGetFramebufferSize(window, &width, &height); 
    // 设置窗口维度
    // 前两个参数：左下角位置，第三四个：宽高
    glViewport(0, 0, width, height);

    // Game loop
    while (!glfwWindowShouldClose(window))
    {   
        // 检查glfw是否倍还要求退出
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        // 事件检查
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        // 渲染指令
        glClearColor(1.2f, 1.3f, 1.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    
    // 释放内存
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    std::cout << key << std::endl;
    // 当用户按下ESC键,我们设置window窗口的WindowShouldClose属性为true
    // 关闭应用程序
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}