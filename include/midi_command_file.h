#pragma once

#include <string>

#include "midi_commands.h"

class MidiCommandFile : public MidiCommand
{
public:
    MidiCommandFile()
        : MidiCommand(MidiCommand::Type::File) { }

    std::string name;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
