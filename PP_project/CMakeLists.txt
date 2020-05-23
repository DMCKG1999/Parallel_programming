cmake_minimum_required(VERSION 3.12)
project(PP_project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PP_project
        PP_project.cpp
        TTAS_spinlock.cpp ticketlock.cpp ticketlock.h spinlock.cpp spinlock.h asm.h)
