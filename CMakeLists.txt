cmake_minimum_required(VERSION 3.24)

# Project name and version
project(MyProject VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/memory_pool)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/spscqueue)



add_executable(myapp test.cpp)

target_link_libraries(myapp PUBLIC memory_pool )
target_link_libraries(myapp PUBLIC SPSCQueue )
target_include_directories(myapp PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/common)



