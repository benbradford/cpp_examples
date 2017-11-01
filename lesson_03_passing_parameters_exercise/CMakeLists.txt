cmake_minimum_required(VERSION 2.4)

project(params)

include_directories(inc/ )

file(GLOB SOURCES "src/*.cpp" )

add_executable(params ${SOURCES})