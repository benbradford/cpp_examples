cmake_minimum_required(VERSION 2.4)

project(branches_conditionals)

include_directories(inc/ )

file(GLOB SOURCES "src/*.cpp" )

add_executable(branches_conditionals ${SOURCES})