#include "midi_command_notes.h"

void MidiCommandNotes::execute(std::shared_ptr<MidiContext> context)
{

}

void MidiCommandNotes::os(std::ostream &out) const
{
    out << "notes: {value: " << length << "}";
}
