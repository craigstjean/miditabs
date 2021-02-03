#pragma once

#include "midi_commands.h"

class MidiCommandMeasures : public MidiCommand
{
public:
    MidiCommandMeasures()
        : MidiCommand(MidiCommand::Type::Measures) { }

    int notes;
    double length;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
