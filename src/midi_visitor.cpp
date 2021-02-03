#include <string>
#include <vector>

#include "midi_visitor.h"
#include "midi_commands.h"

#include "midi_command_chords.h"
#include "midi_command_file.h"
#include "midi_command_line_change.h"
#include "midi_command_measures.h"
#include "midi_command_note_change.h"
#include "midi_command_notes.h"
#include "midi_command_sub_commands.h"
#include "midi_command_tempo.h"
#include "midi_command_tuning.h"

antlrcpp::Any MidiVisitor::visitTabs(TabsParser::TabsContext *context)
{
    // tabs       : line+ EOF ;
    std::vector<std::shared_ptr<MidiCommand>> commands;

    for (auto element : context->line())
    {
        auto command = visitLine(element);
        commands.push_back(std::move(command));
    }

    antlrcpp::Any result = MidiCommands(commands);

    return result;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitLine(TabsParser::LineContext *context)
{
    // line       : (tuning | file | measures | notes | tempo | line_chg | chords) NEWLINE ;
    if (context->tuning())
    {
        return visitTuning(context->tuning());
    }
    else if (context->file())
    {
        return visitFile(context->file());
    }
    else if (context->measures())
    {
        return visitMeasures(context->measures());
    }
    else if (context->notes())
    {
        return visitNotes(context->notes());
    }
    else if (context->tempo())
    {
        return visitTempo(context->tempo());
    }
    else if (context->line_chg())
    {
        return visitLine_chg(context->line_chg());
    }
    else if (context->chords())
    {
        return visitChords(context->chords());
    }

    throw TabInputError(std::string("Invalid command: " + context->getText()).c_str());
}

std::unique_ptr<MidiCommand> MidiVisitor::visitTuning(TabsParser::TuningContext *context)
{
    // tuning     : TUNING NOTE* ;
    auto command = std::make_unique<MidiCommandTuning>();
    for (auto element : context->NOTE())
    {
        std::string text = element->getText();

        MidiNote::Note note;
        switch (text[0])
        {
            case 'A':
            case 'a':
                note = MidiNote::Note::a;
                break;
            case 'B':
            case 'b':
                note = MidiNote::Note::b;
                break;
            case 'C':
            case 'c':
                note = MidiNote::Note::c;
                break;
            case 'D':
            case 'd':
                note = MidiNote::Note::d;
                break;
            case 'E':
            case 'e':
                note = MidiNote::Note::e;
                break;
            case 'F':
            case 'f':
                note = MidiNote::Note::f;
                break;
            case 'G':
            case 'g':
                note = MidiNote::Note::g;
                break;
            default:
                throw TabInputError(std::string("Invalid note: " + text).c_str());
                break;
        }

        MidiNote::Type type = MidiNote::Type::normal;
        int octave;
        if (text.length() > 2)
        {
            if (text[1] == 'b')
                type = MidiNote::Type::flat;
            else if (text[1] == '#')
                type = MidiNote::Type::sharp;
            else
                throw TabInputError(std::string("Invalid note: " + context->getText()).c_str());

            octave = text[2] - '0';
        }
        else
        {
            octave = text[1] - '0';
        }
        
        command->notes.push_back(MidiNote
            {
                .note = note,
                .type = type,
                .octave = octave
            });
    }

    m_string_count = command->notes.size();

    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitFile(TabsParser::FileContext *context)
{
    // file       : FILE FILENAME ;
    auto command = std::make_unique<MidiCommandFile>();
    command->name = context->FILENAME()->getText();
    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitMeasures(TabsParser::MeasuresContext *context)
{
    // measures   : MEASURES NUMBER SEP NUMBER ;
    auto command = std::make_unique<MidiCommandMeasures>();
    command->notes = std::stoi(context->NUMBER().at(0)->getText());
    command->length = 1 / std::stod(context->NUMBER().at(1)->getText());
    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitNotes(TabsParser::NotesContext *context)
{
    // notes      : NOTES NUMBER SEP NUMBER ;
    auto command = std::make_unique<MidiCommandNotes>();
    command->length = std::stod(context->NUMBER().at(0)->getText()) / std::stod(context->NUMBER().at(1)->getText());
    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitTempo(TabsParser::TempoContext *context)
{
    // tempo      : TEMPO NUMBER ;
    auto command = std::make_unique<MidiCommandTempo>();
    command->tempo = std::stoi(context->NUMBER()->getText());
    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitLine_chg(TabsParser::Line_chgContext *context)
{
    // line_chg   : LINE_CHG NUMBER ;
    auto command = std::make_unique<MidiCommandLineChange>();
    command->line = std::stoi(context->NUMBER()->getText());
    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitChords(TabsParser::ChordsContext *context)
{
    // chords     : (EMPTY | MUTE | REST | REPEAT | NUMBER NUMBER_SEP? | note_chg)* ;
    auto command = std::make_unique<MidiCommandSubCommands>();

    bool long_number = false;
    int string_index = 0;
    std::vector<int> notes;

    for (auto child : context->children)
    {
        TabsParser::ChordsContext *cc = (TabsParser::ChordsContext *) child;

        std::string text = cc->getText();

        if (text == ".")
        {
            notes.push_back(-2); // TODO change to constant
            ++string_index;

            if (string_index == m_string_count)
            {
                auto subcommand = std::make_shared<MidiCommandChords>();
                subcommand->chord_type = MidiCommandChords::ChordType::Play;
                subcommand->values = notes;
                command->add_subcommand(subcommand);
                notes.clear();
                string_index = 0;
            }

            long_number = false;
        }
        else if (text == "x")
        {
            notes.push_back(-1); // TODO change to constant
            ++string_index;

            if (string_index == m_string_count)
            {
                auto subcommand = std::make_shared<MidiCommandChords>();
                subcommand->chord_type = MidiCommandChords::ChordType::Play;
                subcommand->values = notes;
                command->add_subcommand(subcommand);
                notes.clear();
                string_index = 0;
            }

            long_number = false;
        }
        else if (text == "-")
        {
            auto subcommand = std::make_shared<MidiCommandChords>();
            subcommand->chord_type = MidiCommandChords::ChordType::Repeat;
            command->add_subcommand(subcommand);
            long_number = false;
        }
        else if (text == "~")
        {
            auto subcommand = std::make_shared<MidiCommandChords>();
            subcommand->chord_type = MidiCommandChords::ChordType::Rest;
            command->add_subcommand(subcommand);
            long_number = false;
        }
        else if (text.length() > 0 && text[0] == 'N')
        {
            auto subcommand = std::make_shared<MidiCommandNoteChange>();
            
            std::string note_count;
            std::string length;

            auto start = 1;
            auto end = text.find("/");
            if (end != std::string::npos)
            {
                note_count = text.substr(start, end - start);
                start = end + 1;
                end = text.find("/", start);
            }

            length = text.substr(start, end);

            subcommand->length = std::stod(note_count) / std::stod(length);
            command->add_subcommand(subcommand);
            long_number = false;
        }
        else if (text.length() > 0 && text[0] >= '0' && text[0] <= '9')
        {
            for (auto i = 0; i < text.length(); i += (long_number ? 2 : 1))
            {
                notes.push_back(std::stoi(text.substr(i, long_number ? 2 : 1)));
                ++string_index;

                if (string_index == m_string_count)
                {
                    auto subcommand = std::make_shared<MidiCommandChords>();
                    subcommand->chord_type = MidiCommandChords::ChordType::Play;
                    subcommand->values = notes;
                    command->add_subcommand(subcommand);
                    notes.clear();
                    string_index = 0;
                }
            }
        }
        else if (text.length() > 0 && (text[0] == ' ' || text[0] == '\t'))
        {
            if (notes.size() > 0)
            {
                auto subcommand = std::make_shared<MidiCommandChords>();
                subcommand->chord_type = MidiCommandChords::ChordType::Play;
                subcommand->values = notes;
                command->add_subcommand(subcommand);
                notes.clear();
            }
            
            string_index = 0;
            long_number = false;
        }
        else if (text == "_")
        {
            long_number = !long_number;
        }
        else
        {
            throw TabInputError(std::string("Don't understand: " + text).c_str());
        }
    }

    if (notes.size() > 0)
    {
        auto subcommand = std::make_shared<MidiCommandChords>();
        subcommand->chord_type = MidiCommandChords::ChordType::Play;
        subcommand->values = notes;
        command->add_subcommand(subcommand);
    }

    return command;
}

std::unique_ptr<MidiCommand> MidiVisitor::visitNote_chg(TabsParser::Note_chgContext *context)
{
    // note_chg   : NOTE_CHANGE NUMBER SEP NUMBER ;
    auto command = std::make_unique<MidiCommandNoteChange>();
    command->length = std::stod(context->NUMBER().at(0)->getText()) / std::stod(context->NUMBER().at(1)->getText());
    return command;
}