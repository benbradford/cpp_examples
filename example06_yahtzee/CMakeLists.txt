cmake_minimum_required(VERSION 2.4)

project(yahtzee)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(inc/ )

file(GLOB SOURCES "src/*.cpp" )

add_executable(yahtzee ${SOURCES})