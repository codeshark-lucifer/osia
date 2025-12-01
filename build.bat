@echo off
REM Check Vulkan SDK
IF NOT DEFINED VULKAN_SDK (
    echo ERROR: VULKAN_SDK environment variable not set!
    exit /b 1
)

REM Create build folder if it doesn't exist
IF NOT EXIST build (
    mkdir build
)

cd build

REM Configure CMake
cmake -S .. -G "Visual Studio 17 2022" -A x64
IF ERRORLEVEL 1 (
    echo CMake configuration failed!
    exit /b 1
)

REM Build the project (Debug)
cmake --build . --config Debug
IF ERRORLEVEL 1 (
    echo Build failed!
    exit /b 1
)

REM Run the executable
echo Running engine...
REM Make sure to change engine.exe to your actual executable name
Debug\engine.exe
cd ..
@REM pause
