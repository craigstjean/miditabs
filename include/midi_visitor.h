#pragma once

#include <exception>

#include "antlr4-runtime.h"
#include "TabsBaseVisitor.h"
#include "midi_commands.h"

class TabInputError : public std::exception
{
public:
    TabInputError(const char *message)
        : m_message{message}
    {
    }

    virtual const char* what() const throw()
    {
        return m_message;
    }
private:
    const char *m_message;
};

class  MidiVisitor {
public:

    antlrcpp::Any visitTabs(TabsParser::TabsContext *context);

    std::unique_ptr<MidiCommand> visitLine(TabsParser::LineContext *context);

    std::unique_ptr<MidiCommand> visitTuning(TabsParser::TuningContext *context);

    std::unique_ptr<MidiCommand> visitFile(TabsParser::FileContext *context);

    std::unique_ptr<MidiCommand> visitInstrument(TabsParser::InstrumentContext *context);

    std::unique_ptr<MidiCommand> visitAttack(TabsParser::AttackContext *context);

    std::unique_ptr<MidiCommand> visitMeasures(TabsParser::MeasuresContext *context);

    std::unique_ptr<MidiCommand> visitNotes(TabsParser::NotesContext *context);

    std::unique_ptr<MidiCommand> visitTempo(TabsParser::TempoContext *context);

    std::unique_ptr<MidiCommand> visitLine_chg(TabsParser::Line_chgContext *context);

    std::unique_ptr<MidiCommand> visitChords(TabsParser::ChordsContext *context);

    std::unique_ptr<MidiCommand> visitNote_chg(TabsParser::Note_chgContext *context);

private:
    int m_string_count;
};

