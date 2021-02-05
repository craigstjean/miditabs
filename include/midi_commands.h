#pragma once

#include <ostream>
#include <string>
#include <vector>

#include "midi_context.h"

class MidiCommand
{
public:
    enum Type
    {
        Tuning,
        File,
        Measures,
        Notes,
        Tempo,
        LineChange,
        Chords,
        NoteChange,
        SubCommands,
        Attack,
        Instrument,
        AdjustTick
    } type;

    virtual void execute(std::shared_ptr<MidiContext> context) = 0;
    virtual void os(std::ostream&) const = 0;

    MidiCommand(MidiCommand::Type wantedType)
        : type{wantedType}
    {
        
    }

    virtual ~MidiCommand()
    {

    }

    friend std::ostream& operator<<(std::ostream &out, const MidiCommand& data);
};

class MidiCommands
{
public:
    MidiCommands(std::vector<std::shared_ptr<MidiCommand>> commands)
        : m_commands{commands}
    {
    }

    const std::vector<std::shared_ptr<MidiCommand>> commands();
private:
    std::vector<std::shared_ptr<MidiCommand>> m_commands;
};
