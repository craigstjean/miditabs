#include "midi_command_note_change.h"

void MidiCommandNoteChange::execute(std::shared_ptr<MidiContext> context)
{

}

void MidiCommandNoteChange::os(std::ostream &out) const
{
    out << "note_change: {value: " << length << "}";
}
