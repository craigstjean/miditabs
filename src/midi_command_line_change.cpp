#include "midi_command_line_change.h"

void MidiCommandLineChange::execute()
{

}

void MidiCommandLineChange::os(std::ostream &out) const
{
    out << "line_change: {value: " << line << "}";
}
