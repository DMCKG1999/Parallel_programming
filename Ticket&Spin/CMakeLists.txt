cmake_minimum_required(VERSION 3.12)
project(Ticket_Spin)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ticket_Spin main.cpp
        cmake-build-debug/spin/spinlock.cpp
        cmake-build-debug/spin/spinlock.h
        cmake-build-debug/ticket/ticketlock.cpp
        cmake-build-debug/ticket/ticketlock.h
        cmake-build-debug/asm.h)