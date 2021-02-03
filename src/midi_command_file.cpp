#include "midi_command_file.h"

void MidiCommandFile::execute(std::shared_ptr<MidiContext> context)
{
    context->new_file(name);
}

void MidiCommandFile::os(std::ostream &out) const
{
    out << "file: {name: '" << name << "'}";
}
