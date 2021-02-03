#include "midi_command_attack.h"

void MidiCommandAttack::execute(std::shared_ptr<MidiContext> context)
{
    context->velocity = velocity;
}

void MidiCommandAttack::os(std::ostream &out) const
{
    out << "attack: {value: " << velocity << "}";
}
