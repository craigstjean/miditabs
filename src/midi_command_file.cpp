#include "midi_command_file.h"

void MidiCommandFile::execute()
{

}

void MidiCommandFile::os(std::ostream &out) const
{
    out << "file: {name: '" << name << "'}";
}
