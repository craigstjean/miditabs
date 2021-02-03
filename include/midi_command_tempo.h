#pragma once

#include "midi_commands.h"

class MidiCommandTempo : public MidiCommand
{
public:
    MidiCommandTempo()
        : MidiCommand(MidiCommand::Type::Tempo) { }

    int tempo;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
