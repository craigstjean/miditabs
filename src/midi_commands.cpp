#include "midi_commands.h"

const std::vector<std::shared_ptr<MidiCommand>> MidiCommands::commands()
{
    return m_commands;
}

std::ostream& operator<<(std::ostream &out, const MidiCommand& data)
{
    out << "MidiCommand: {";
    data.os(out);
    out << "}\n";
    
    return out;
}
