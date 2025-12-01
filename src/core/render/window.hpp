#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

namespace osia
{
    class Window
    {
    public:
        Window(int width, int height, std::string name);
        ~Window();

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        bool shoudClose();

    private:
        void Initialize();

        const int width;
        const int height;

        std::string windowName;
        GLFWwindow *window;
    };

} // namespace osia
