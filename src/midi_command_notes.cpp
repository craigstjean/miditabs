#include "midi_command_notes.h"

void MidiCommandNotes::execute()
{

}

void MidiCommandNotes::os(std::ostream &out) const
{
    out << "notes: {value: " << length << "}";
}
