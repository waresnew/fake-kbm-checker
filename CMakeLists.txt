cmake_minimum_required(VERSION 3.24)
project(fake_kbm_checker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(fake_kbm_checker src/main.cpp src/check/check.cpp src/check/check.h src/api/api.cpp src/api/api.h)
