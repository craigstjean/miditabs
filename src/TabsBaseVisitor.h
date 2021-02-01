
// Generated from src/Tabs.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "TabsVisitor.h"


/**
 * This class provides an empty implementation of TabsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TabsBaseVisitor : public TabsVisitor {
public:

  virtual antlrcpp::Any visitTabs(TabsParser::TabsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(TabsParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTuning(TabsParser::TuningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile(TabsParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMeasures(TabsParser::MeasuresContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotes(TabsParser::NotesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTempo(TabsParser::TempoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChords(TabsParser::ChordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNote_chg(TabsParser::Note_chgContext *ctx) override {
    return visitChildren(ctx);
  }


};

