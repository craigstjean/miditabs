cmake_minimum_required(VERSION 3.13)
project(miditabs)
set(CMAKE_CXX_STANDARD 17)
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
                 src/midi_command_attack.cpp
                 src/midi_command_chords.cpp
                 src/midi_command_file.cpp
                 src/midi_command_instrument.cpp
                 src/midi_command_line_change.cpp
                 src/midi_command_measures.cpp
                 src/midi_command_note_change.cpp
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
target_link_libraries(miditabs midifile antlr4_static)
