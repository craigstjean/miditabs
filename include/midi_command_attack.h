#pragma once

#include "midi_commands.h"

class MidiCommandAttack : public MidiCommand
{
public:
    MidiCommandAttack()
        : MidiCommand(MidiCommand::Type::Attack) { }

    int velocity;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
