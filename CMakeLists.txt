cmake_minimum_required(VERSION 3.13)
project(miditabs)
set(CMAKE_CXX_STANDARD 14)

include_directories(deps/midifile/include)
add_subdirectory(deps/midifile midifile)

set(SOURCE_FILES src/main.cpp)

add_executable(miditabs ${SOURCE_FILES})
target_link_libraries(miditabs midifile)

