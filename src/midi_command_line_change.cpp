#include "midi_command_line_change.h"

void MidiCommandLineChange::execute(std::shared_ptr<MidiContext> context)
{
    context->current_track = line - 1;

    while (context->track_count() < line + 1)
    {
        context->midifile().get()->addTrack(1);
        context->set_track_tick(context->track_count(), 0);
    }
}

void MidiCommandLineChange::os(std::ostream &out) const
{
    out << "line_change: {value: " << line << "}";
}
