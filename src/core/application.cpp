#include "application.hpp"

namespace osia
{
    void Application::Run()
    {
        while (!window.shoudClose())
        {
            glfwPollEvents();
        }
    }
}