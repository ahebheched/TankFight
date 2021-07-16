cmake_minimum_required(VERSION 3.17)
project(tankfight)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-static")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

add_executable(tankfight main.cpp)

target_link_libraries(tankfight ${PROJECT_SOURCE_DIR}/lib/libgraphics64.a -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32 -lwinmm -lgdiplus)