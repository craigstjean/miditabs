cmake_minimum_required(VERSION 3.13)
project(miditabs)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    deps/midifile/include
    deps/antlr4/runtime/Cpp/runtime/src
    src)
add_subdirectory(deps/midifile midifile)
add_subdirectory(deps/antlr4/runtime/Cpp)

set(SOURCE_FILES src/main.cpp
                 src/TabsBaseVisitor.cpp
                 src/TabsLexer.cpp
                 src/TabsParser.cpp
                 src/TabsVisitor.cpp)

add_executable(miditabs ${SOURCE_FILES})
target_link_libraries(miditabs midifile antlr4_static)
