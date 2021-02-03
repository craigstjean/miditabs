#pragma once

#include "midi_commands.h"

class MidiCommandNoteChange : public MidiCommand
{
public:
    MidiCommandNoteChange()
        : MidiCommand(MidiCommand::Type::NoteChange) { }

    double length;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
};
