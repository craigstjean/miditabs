
// Generated from src/Tabs.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "TabsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TabsParser.
 */
class  TabsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TabsParser.
   */
    virtual antlrcpp::Any visitTabs(TabsParser::TabsContext *context) = 0;

    virtual antlrcpp::Any visitLine(TabsParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitTuning(TabsParser::TuningContext *context) = 0;

    virtual antlrcpp::Any visitFile(TabsParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitMeasures(TabsParser::MeasuresContext *context) = 0;

    virtual antlrcpp::Any visitNotes(TabsParser::NotesContext *context) = 0;

    virtual antlrcpp::Any visitTempo(TabsParser::TempoContext *context) = 0;

    virtual antlrcpp::Any visitChords(TabsParser::ChordsContext *context) = 0;


};

