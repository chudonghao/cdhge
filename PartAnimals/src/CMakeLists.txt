file(GLOB SRCS *.cpp *.h *.ui)
add_executable(PartAnimals ${SRCS})
target_link_libraries(PartAnimals Qt5::Widgets Vulkan::Vulkan cdhlog cdhge)
