#pragma once

#include "midi_commands.h"

class MidiCommandAdjustTick : public MidiCommand
{
public:
    MidiCommandAdjustTick()
        : MidiCommand(MidiCommand::Type::AdjustTick) { }

    bool forward;
    double adjustment;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
