#pragma once

#include <ostream>
#include <string>
#include <vector>

struct MidiNote
{
    enum Note
    {
        a = 'A',
        b = 'B',
        c = 'C',
        d = 'D',
        e = 'E',
        f = 'F',
        g = 'G'
    } note;

    enum Type
    {
        normal, sharp, flat
    } type;

    int octave;
};

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
        SubCommands
    } type;

    virtual void execute() = 0;
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
