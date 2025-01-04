cmake_minimum_required(VERSION 3.29)
project(todo_program)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(todo_program
    listItem.cpp
    listItem.h
        main.cpp
        todoList.cpp
        todoList.h)
