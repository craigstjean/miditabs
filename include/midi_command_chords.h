#pragma once

#include <vector>

#include "midi_commands.h"

class MidiCommandChords : public MidiCommand
{
public:
    MidiCommandChords()
        : MidiCommand(MidiCommand::Type::Chords) { }

    enum ChordType
    {
        Play, Rest, Repeat
    } chord_type;

    std::vector<int> values;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
