#pragma once

#include <exception>

#include "antlr4-runtime.h"
#include "TabsBaseVisitor.h"

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

class  MidiVisitor : TabsBaseVisitor {
public:

    antlrcpp::Any visitTabs(TabsParser::TabsContext *context);

    antlrcpp::Any visitLine(TabsParser::LineContext *context);

    antlrcpp::Any visitTuning(TabsParser::TuningContext *context);

    antlrcpp::Any visitFile(TabsParser::FileContext *context);

    antlrcpp::Any visitMeasures(TabsParser::MeasuresContext *context);

    antlrcpp::Any visitNotes(TabsParser::NotesContext *context);

    antlrcpp::Any visitTempo(TabsParser::TempoContext *context);

    antlrcpp::Any visitLine_chg(TabsParser::Line_chgContext *context);

    antlrcpp::Any visitChords(TabsParser::ChordsContext *context);

    antlrcpp::Any visitNote_chg(TabsParser::Note_chgContext *context);

private:
    int m_string_count;
};

