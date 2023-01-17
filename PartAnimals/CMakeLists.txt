cmake_minimum_required(VERSION 3.10)

project(PartAnimals)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(cdhlog)

if (NOT TARGET cdhlog)
  message(FATAL_ERROR "cdhlog NOT Found")
endif ()

if (NOT TARGET s3ge)
  message(FATAL_ERROR "s3ge NOT Found")
endif ()

add_subdirectory(src)
