#include "midi_command_chords.h"

void MidiCommandChords::execute()
{

}

void MidiCommandChords::os(std::ostream &out) const
{
    out << "chords: {";
    out << "type: '";
    switch (chord_type)
    {
        case MidiCommandChords::ChordType::Play:
            out << "play";
            break;
        case MidiCommandChords::ChordType::Rest:
            out << "rest";
            break;
        case MidiCommandChords::ChordType::Repeat:
            out << "repeat";
            break;
        default:
            break;
    }
    out << "', values: [";
    for (auto value : values)
    {
        out << value << ", ";
    }
    out << "]}";
}
