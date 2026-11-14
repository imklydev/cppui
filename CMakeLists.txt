cmake_minimum_required(VERSION 3.24)

project(cppui
    VERSION 1.0
    DESCRIPTION "A performant, full-stack desktop app framework for C++."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)
find_package(SDL3_ttf CONFIG REQUIRED)

add_library(cppui STATIC
    src/main.cpp
    src/misc/log.cpp
    src/rendering/rendering.cpp
    src/event_handling/get_events.cpp
    src/event_handling/mouse.cpp
    src/rendering/drawing.cpp
    src/components/text.cpp
    src/components/panel.cpp
    src/components/vertical_container.cpp
    src/components/horizontal_container.cpp
    src/components/button.cpp
    src/components/image.cpp
    )

target_link_libraries(cppui PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
)

target_include_directories(cppui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Print the paths for SDL static libs for the python build script to merge SDL3 dependencies with cppui
file(GENERATE
    OUTPUT "${CMAKE_BINARY_DIR}/bundle_libs.txt"
    CONTENT "$<TARGET_LINKER_FILE:cppui>
$<TARGET_LINKER_FILE:SDL3::SDL3>
$<TARGET_LINKER_FILE:SDL3_image::SDL3_image>
$<TARGET_LINKER_FILE:SDL3_ttf::SDL3_ttf>
")