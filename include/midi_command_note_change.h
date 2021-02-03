#pragma once

#include "midi_commands.h"

class MidiCommandNoteChange : public MidiCommand
{
public:
    MidiCommandNoteChange()
        : MidiCommand(MidiCommand::Type::NoteChange) { }

    double length;

    virtual void execute() override;
    virtual void os(std::ostream&) const override;
};
