cmake_minimum_required(VERSION 3.22.1)
project(zygisk-module-c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden -Wall -Wextra")

add_library(${MODULE_NAME} SHARED main.c)
target_link_libraries(${MODULE_NAME} log)
