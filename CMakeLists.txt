cmake_minimum_required(VERSION 3.15)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracing vec3.h ray.h ray_test.cpp)