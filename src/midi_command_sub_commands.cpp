#include "midi_command_sub_commands.h"

void MidiCommandSubCommands::add_subcommand(std::shared_ptr<MidiCommand> command)
{
    m_subcommands.push_back(command);
}

const std::vector<std::shared_ptr<MidiCommand>> MidiCommandSubCommands::subcommands() const
{
    return m_subcommands;
}

void MidiCommandSubCommands::execute(std::shared_ptr<MidiContext> context)
{
    for (auto sub : m_subcommands)
    {
        sub->execute(context);
    }
}

void MidiCommandSubCommands::os(std::ostream &out) const
{
    out << "[";
    for (auto sub : m_subcommands)
    {
        sub->os(out);
        out << ", ";
    }
    out << "]";
}
