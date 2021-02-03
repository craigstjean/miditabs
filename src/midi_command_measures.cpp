#include "midi_command_measures.h"

void MidiCommandMeasures::execute()
{

}

void MidiCommandMeasures::os(std::ostream &out) const
{
    out << "measures: {value: '" << notes << "/";

    bool found = false;
    for (double i = 1; i <= 12; ++i)
    {
        if (length == 1 / i)
        {
            found = true;
            out << i;
            break;
        }
    }

    if (!found)
        out << length;
    
    out << "'}";
}
