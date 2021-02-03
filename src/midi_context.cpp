#include "midi_context.h"

void MidiContext::new_file(std::string filename)
{
    m_midi_file = std::make_unique<MidiFileWrapper>(filename);
}
