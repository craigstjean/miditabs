#include "midi_command_tuning.h"

void MidiCommandTuning::execute(std::shared_ptr<MidiContext> context)
{

}

void MidiCommandTuning::os(std::ostream &out) const
{
    out << "tuning: [";
    for (auto note : notes)
    {
        out << "{note: '" << (char) note.note;
        switch (note.type)
        {
            case MidiNote::Type::sharp:
                out << "#";
                break;
            case MidiNote::Type::flat:
                out << "b";
                break;
            default:
                break;
        }
        out << "', octave: " << note.octave;
        out << "},";
    }
    out << "]";
}
