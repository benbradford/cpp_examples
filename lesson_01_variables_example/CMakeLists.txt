cmake_minimum_required(VERSION 2.4)

project(vars)

file(GLOB SOURCES "src/main.cpp" )

add_executable(vars ${SOURCES})