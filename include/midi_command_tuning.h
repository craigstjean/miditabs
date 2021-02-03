#pragma once

#include <vector>

#include "midi_commands.h"

class MidiCommandTuning : public MidiCommand
{
public:
    MidiCommandTuning()
        : MidiCommand(MidiCommand::Type::Tuning) { }

    std::vector<MidiNote> notes;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
