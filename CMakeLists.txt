##########################################
cmake_minimum_required(VERSION 3.2) 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(mapgen)

set(SRCS
src/generator2D.cpp
src/generator3D.cpp
)

include_directories( ${PROJECT_SOURCE_DIR}/include/)
add_library(mapgenlib SHARED ${SRCS})

add_executable(main2d src/main2D.cpp)
#add_executable(main3d main3D.cpp)

target_link_libraries(main2d mapgenlib)
