#include "midi_command_tempo.h"

void MidiCommandTempo::execute()
{

}

void MidiCommandTempo::os(std::ostream &out) const
{
    out << "tempo: {value: " << tempo << "}";
}
