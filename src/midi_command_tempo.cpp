#include "midi_command_tempo.h"

void MidiCommandTempo::execute(std::shared_ptr<MidiContext> context)
{

}

void MidiCommandTempo::os(std::ostream &out) const
{
    out << "tempo: {value: " << tempo << "}";
}
