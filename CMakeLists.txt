cmake_minimum_required(VERSION 4.1)
project(Tasks C)

set(CMAKE_C_STANDARD 11)

add_executable(Tasks main.c
        func.h
        func_task.c
)
