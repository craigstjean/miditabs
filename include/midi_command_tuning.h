#pragma once

#include <vector>

#include "midi_commands.h"

class MidiCommandTuning : public MidiCommand
{
public:
    MidiCommandTuning()
        : MidiCommand(MidiCommand::Type::Tuning) { }

    std::vector<MidiNote> notes;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
