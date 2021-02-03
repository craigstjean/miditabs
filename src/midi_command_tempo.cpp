#include "midi_command_tempo.h"

void MidiCommandTempo::execute(std::shared_ptr<MidiContext> context)
{
    int tick = context->track_tick(context->current_track);
    for (auto i = 0; i < context->track_count(); ++i)
    {
        smf::MidiEvent tempo_event;
        tempo_event.tick = tick;
        tempo_event.setMetaTempo(tempo);
        context->midifile()->addEvent(tempo_event);
    }

    context->current_tempo = tempo;
}

void MidiCommandTempo::os(std::ostream &out) const
{
    out << "tempo: {value: " << tempo << "}";
}
