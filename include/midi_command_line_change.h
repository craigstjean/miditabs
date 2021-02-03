#pragma once

#include "midi_commands.h"

class MidiCommandLineChange : public MidiCommand
{
public:
    MidiCommandLineChange()
        : MidiCommand(MidiCommand::Type::LineChange) { }

    int line;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
