cmake_minimum_required(VERSION 3.10)
project(S3GE)

set(CMAKE_CXX_STANDARD 17)

# Boost
find_package(Boost REQUIRED COMPONENTS log log_setup)
include_directories(${Boost_INCLUDE_DIR})

# cdhlog
find_package(cdhlog REQUIRED)

# Vulkan
# target: Vulkan
# ubuntu package: vulkan-tools libvulkan-dev vulkan-validationlayers-dev spriv-tools
find_package(Vulkan REQUIRED)

# glm
# target: glm::glm
find_package(glm REQUIRED)

add_subdirectory(src)
add_subdirectory(PartAnimals)
