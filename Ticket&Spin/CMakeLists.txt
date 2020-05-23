cmake_minimum_required(VERSION 3.12)
project(Ticket_Spin)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ticket_Spin main.cpp)
add_executable(cmake-build-debug/spin/spinlock.cpp)
add_executable(cmake-build-debug/spin/spinlock.h)
add_executable(cmake-build-debug/ticket/ticketlock.cpp)
add_executable(cmake-build-debug/ticket/ticketlock.h)
add_executable(cmake-build-debug/asm.h)