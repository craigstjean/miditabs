#include "midi_command_chords.h"

void MidiCommandChords::execute(std::shared_ptr<MidiContext> context)
{
    int channel = 0;
    int velocity = 50;
    int tick = context->track_tick(context->current_track);
    int tpq = context->midifile()->getTPQ();

    int endtick = tick;

    // pitch 72 = C5
    // C1 = 24
    // 24 + ((letter - 1 - 'A') * 12) * (octave - 1)
    // 24 + (('C' - 1 - 'A') * 12) * 5-1
    // 24 + (1 * 12) * 5-1
    switch (chord_type)
    {
        case ChordType::Play:
            endtick = tick + int(context->tick_speed * tpq);

            for (auto i = 0; i < values.size(); ++i)
            {
                // TODO -2 is nothing, -1 is muted
                if (values.at(i) >= 0)
                {
                    auto string = context->tuning.at(i);
                    int pitch = 24 + ((string.note - 'A' - 1) * 12) * (string.octave - 1);
                    if (string.type == MidiNote::Type::sharp)
                        ++pitch;
                    else if (string.type == MidiNote::Type::flat)
                        --pitch;
                    
                    pitch += values.at(i);
                    
                    context->midifile()->addNoteOn (context->current_track, tick, channel, pitch, velocity);
                    context->midifile()->addNoteOff(context->current_track, endtick, channel, pitch);
                }
            }

            break;
        case ChordType::Repeat:
        break;
        case ChordType::Rest:
            endtick = tick + int(context->tick_speed * tpq);
            break;
        default:
        break;
    }

    context->set_track_tick(context->current_track, endtick);
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
