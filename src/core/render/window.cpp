#include "window.hpp"

namespace osia
{
    Window::Window(int w, int h, std::string name) 
    : width{w}, height{h}, windowName{name}
    {
        Initialize();
    }

    Window::~Window(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    bool Window::shoudClose() {
        return glfwWindowShouldClose(window);
    }

    void Window::Initialize() {
        if(!glfwInit()) {
            std::cout << "Failed to initialize GLFW.\n";
            return;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}