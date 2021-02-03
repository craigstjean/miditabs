#pragma once

#include "midi_commands.h"

class MidiCommandNotes : public MidiCommand
{
public:
    MidiCommandNotes()
        : MidiCommand(MidiCommand::Type::Notes) { }

    double length;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
