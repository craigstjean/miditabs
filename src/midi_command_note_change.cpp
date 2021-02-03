#include "midi_command_note_change.h"

void MidiCommandNoteChange::execute()
{

}

void MidiCommandNoteChange::os(std::ostream &out) const
{
    out << "note_change: {value: " << length << "}";
}
