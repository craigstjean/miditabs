cmake_minimum_required(VERSION 3.13)
project(miditabs)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
    set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")
    set(WITH_STATIC_CRT OFF)
    add_compile_options(
            $<$<CONFIG:>:/MD> #---------|
            $<$<CONFIG:Debug>:/MDd> #---|-- Statically link the runtime libraries
            $<$<CONFIG:Release>:/MD> #--|
    )
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

# For VSCode
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(
    deps/midifile/include
    deps/antlr4/runtime/Cpp/runtime/src
    include
    src/antlr)
add_subdirectory(deps/midifile midifile)
add_subdirectory(deps/antlr4/runtime/Cpp)

set(SOURCE_FILES src/main.cpp
                 src/processor.cpp
                 src/midi_visitor.cpp
                 src/midi_commands.cpp
                 src/midi_command_adjust_tick.cpp
                 src/midi_command_attack.cpp
                 src/midi_command_chords.cpp
                 src/midi_command_file.cpp
                 src/midi_command_instrument.cpp
                 src/midi_command_line_change.cpp
                 src/midi_command_measures.cpp
                 src/midi_command_notes.cpp
                 src/midi_command_sub_commands.cpp
                 src/midi_command_tempo.cpp
                 src/midi_command_tuning.cpp
                 src/midi_context.cpp
                 src/antlr/TabsBaseVisitor.cpp
                 src/antlr/TabsLexer.cpp
                 src/antlr/TabsParser.cpp
                 src/antlr/TabsVisitor.cpp)

add_executable(miditabs ${SOURCE_FILES})

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_libraries(miditabs midifile antlr4_shared)

    add_custom_command(TARGET miditabs POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_SOURCE_DIR}/dist/Debug/antlr4-runtime.dll"
        $<TARGET_FILE_DIR:miditabs>)
else()
    target_link_libraries(miditabs midifile antlr4_static)
endif()

