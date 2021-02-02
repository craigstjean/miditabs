#include "midi_commands.h"

const std::vector<MidiCommand> MidiCommands::commands()
{
    return m_commands;
}

void MidiCommand::add_subcommand(std::shared_ptr<MidiCommand> command)
{
    m_subcommands.push_back(*command.get());
}

const std::vector<MidiCommand> MidiCommand::subcommands()
{
    return m_subcommands;
}

std::ostream& operator<<(std::ostream &out, const MidiCommand& data)
{
    bool found;

    out << "MidiCommand: {";

    switch (data.type)
    {
        case MidiCommand::Type::Tuning:
            out << "notes: [";
            for (auto note : data.tuning.notes)
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
            break;
        case MidiCommand::Type::File:
            out << "file: {name: '" << data.file.name << "'}";
            break;
        case MidiCommand::Type::Measures:
            out << "measures: {value: '" << data.measures.notes << "/";

            found = false;
            for (double i = 1; i <= 12; ++i)
            {
                if (data.measures.length == 1 / i)
                {
                    found = true;
                    out << i;
                    break;
                }
            }

            if (!found)
                out << data.measures.length;
            
            out << "'}";
            break;
        case MidiCommand::Type::Notes:
            out << "notes: {value: " << data.notes.length << "}";
            break;
        case MidiCommand::Type::Tempo:
            out << "tempo: {value: " << data.tempo.tempo << "}";
            break;
        case MidiCommand::Type::LineChange:
            out << "line_change: {value: " << data.line_change.line << "}";
            break;
        case MidiCommand::Type::Chords:
            out << "chords: {";
            out << "type: '";
            switch (data.chords.type)
            {
                case MidiCommand::chords::Type::Play:
                    out << "play";
                    break;
                case MidiCommand::chords::Type::Rest:
                    out << "rest";
                    break;
                case MidiCommand::chords::Type::Repeat:
                    out << "repeat";
                    break;
                default:
                    break;
            }
            out << "', values: [";
            for (auto value : data.chords.values)
            {
                out << value << ", ";
            }
            out << "]}";
            // TODO
            break;
        case MidiCommand::Type::NoteChange:
            out << "note_change: {value: " << data.note_change.length << "}";
            break;
        default:
            break;
    }

    out << "}";
    
    return out;
}
