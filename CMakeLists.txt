cmake_minimum_required(VERSION 3.1.3)
project(Klondike)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src)
#add_subdirectory(test)

