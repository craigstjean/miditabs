#include "midi_command_adjust_tick.h"

void MidiCommandAdjustTick::execute(std::shared_ptr<MidiContext> context)
{
    int tpq = context->midifile()->getTPQ();
    int ticks = adjustment * 2.0 * tpq;
    if (forward)
        context->set_track_tick(context->current_track, context->track_tick(context->current_track) + ticks);
    else
        context->set_track_tick(context->current_track, context->track_tick(context->current_track) - ticks);
}

void MidiCommandAdjustTick::os(std::ostream &out) const
{
    out << "adjust tick: {value: " << (forward ? "" : "-") << adjustment << "}";
}
