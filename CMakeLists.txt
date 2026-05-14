cmake_minimum_required(VERSION 3.10)

project(GraphicsProject)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(app 
    src/main.cpp 
    src/image.cpp 

    src/draw/line.cpp
    src/draw/rectangle.cpp
    src/draw/circle.cpp
    src/draw/ellipse.cpp
)

target_include_directories(app PRIVATE
    include
    include/draw
    ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(app PRIVATE ${SDL2_LIBRARIES})