cmake_minimum_required(VERSION 3.15)
project(raytracing)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3")

add_executable(raytracing vec3.h ray.h util.h image.h hit.h sphere.h camera.h aggregate.h material.h random.h light.h radiance.h sky.h path_tracing.cpp)
add_executable(montecarlo montecarlo.cpp)
add_executable(importance importance.cpp)