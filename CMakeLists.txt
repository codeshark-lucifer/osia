cmake_minimum_required(VERSION 3.22)
project(OsiaEngine VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Vulkan SDK
if(NOT DEFINED ENV{VULKAN_SDK})
    message(FATAL_ERROR "Please set VULKAN_SDK environment variable")
endif()
set(VULKAN_INCLUDE_DIR "$ENV{VULKAN_SDK}/Include")
set(VULKAN_LIB_DIR "$ENV{VULKAN_SDK}/Lib")

# GLFW include
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Executable
add_executable(engine ${SOURCES})

# Link Vulkan and GLFW
target_include_directories(engine PRIVATE ${VULKAN_INCLUDE_DIR})
target_link_directories(engine PRIVATE ${VULKAN_LIB_DIR})
target_link_libraries(engine PRIVATE glfw3 vulkan-1)
