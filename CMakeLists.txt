cmake_minimum_required(VERSION 3.6)
project(spring)
add_executable(spring main.cpp calculator.cpp)
set_property(TARGET spring PROPERTY CXX_STANDARD 14)
