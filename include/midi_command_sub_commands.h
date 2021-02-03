#pragma once

#include <vector>

#include "midi_commands.h"

class MidiCommandSubCommands : public MidiCommand
{
public:
    MidiCommandSubCommands()
        : MidiCommand(MidiCommand::Type::SubCommands) { }

    void add_subcommand(std::shared_ptr<MidiCommand> command);
    const std::vector<std::shared_ptr<MidiCommand>> subcommands() const;

    virtual void execute(std::shared_ptr<MidiContext> context) override;
    virtual void os(std::ostream&) const override;
private:
    std::vector<std::shared_ptr<MidiCommand>> m_subcommands;
};
