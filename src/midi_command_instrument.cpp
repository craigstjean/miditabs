#include "midi_command_instrument.h"

void MidiCommandInstrument::execute(std::shared_ptr<MidiContext> context)
{
    context->instrument = instrument;
    context->midifile().get()->addTimbre(0, 0, 0, instrument);
}

void MidiCommandInstrument::os(std::ostream &out) const
{
    out << "instrument: {value: " << instrument << "}";
}
