#pragma once

#include "midi_commands.h"

class MidiCommandInstrument : public MidiCommand
{
public:
    MidiCommandInstrument()
        : MidiCommand(MidiCommand::Type::Instrument) { }

    int instrument;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
