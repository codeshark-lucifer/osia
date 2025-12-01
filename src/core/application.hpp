#pragma once
#include "render/window.hpp"
#include <osia/config.hpp>

namespace osia
{
    class Application
    {
        public :
        static constexpr int WIDTH = SCREEN_WIDTH;
        static constexpr int HEIGHT = SCREEN_HEIGHT;
        
        void Run();
    private:
        Window window{WIDTH, HEIGHT, APPLICATION_NAME};
    };
}