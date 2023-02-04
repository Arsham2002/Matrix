cmake_minimum_required(VERSION 3.0)
set(CMake_CXX_STANDARD 11)
project(Matrix)
set(SOURCES
	main
    src/Matrix
)
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(include)