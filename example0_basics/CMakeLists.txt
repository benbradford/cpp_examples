cmake_minimum_required(VERSION 1.0)

project(hello_world)

include_directories(inc/ )

file(GLOB SOURCES "src/*.cpp" )

add_executable(hello_world ${SOURCES})