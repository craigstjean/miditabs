#pragma once

#include <string>

#include "midi_commands.h"

class MidiCommandFile : public MidiCommand
{
public:
    MidiCommandFile()
        : MidiCommand(MidiCommand::Type::File) { }

    std::string name;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
