cmake_minimum_required(VERSION 3.15)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3")

add_executable(path_tracing path_tracing.cpp)
add_executable(thinlens use_thinlens.cpp)
add_executable(sky use_sky.cpp)
add_executable(montecarlo montecarlo.cpp)
add_executable(importance importance.cpp)