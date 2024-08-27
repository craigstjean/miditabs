#include "midi_command_chords.h"

void MidiCommandChords::execute(std::shared_ptr<MidiContext> context)
{
    int channel = context->current_track;
    int velocity = context->velocity;
    int tick = context->track_tick(context->current_track);
    int tpq = context->midifile()->getTPQ();

    int endtick = tick;

    if (chord_type == ChordType::Repeat)
    {
        values = context->last_chord;
        chord_type = ChordType::Play;
    }

    // pitch 72 = C5
    // C1 = 24
    // C = +0
    // D = +2
    // E = +4
    // F = +5
    // G = +7
    // A = +9
    // B = +11
    // 24 + ((octave - 1) * 12) + X
    switch (chord_type)
    {
        case ChordType::Play:
            endtick = tick + int(context->tick_speed * 2.0 * tpq);
            context->last_chord = values;

            for (auto i = 0; i < values.size(); ++i)
            {
                // TODO -2 is nothing
                if (values.at(i) >= 0)
                {
                    auto string = context->tuning.at(i);

                    int pitch = 24 + (string.octave - 1) * 12;
                    switch (string.note)
                    {
                        case MidiNote::Note::c:
                            pitch += 0;
                            break;
                        case MidiNote::Note::d:
                            pitch += 2;
                            break;
                        case MidiNote::Note::e:
                            pitch += 4;
                            break;
                        case MidiNote::Note::f:
                            pitch += 5;
                            break;
                        case MidiNote::Note::g:
                            pitch += 7;
                            break;
                        case MidiNote::Note::a:
                            pitch += 9;
                            break;
                        case MidiNote::Note::b:
                            pitch += 11;
                            break;
                    }

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
            // Already handled
            break;
        case ChordType::Rest:
            endtick = tick + int(context->tick_speed * 2.0 * tpq);
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
