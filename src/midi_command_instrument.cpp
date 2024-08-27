#include "midi_command_instrument.h"

void MidiCommandInstrument::execute(std::shared_ptr<MidiContext> context)
{
    auto track = context->current_track;
    context->set_instrument(track, instrument);
    context->midifile().get()->addTimbre(track, context->get_track_tick(track), track, instrument);
}

void MidiCommandInstrument::os(std::ostream &out) const
{
    out << "instrument: {value: " << instrument << "}";
}
