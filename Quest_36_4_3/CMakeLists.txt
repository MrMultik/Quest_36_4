cmake_minimum_required(VERSION 3.16)

project(Quest_36_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Quest_36_4 main.cpp)

target_link_libraries(Quest_36_4 Qt6::Widgets)
