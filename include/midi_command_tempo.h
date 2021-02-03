#pragma once

#include "midi_commands.h"

class MidiCommandTempo : public MidiCommand
{
public:
    MidiCommandTempo()
        : MidiCommand(MidiCommand::Type::Tempo) { }

    int tempo;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
