
// Generated from src/Tabs.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  TabsParser : public antlr4::Parser {
public:
  enum {
    TUNING = 1, FILE = 2, MEASURES = 3, NOTES = 4, TEMPO = 5, NUMBER = 6, 
    SEP = 7, EMPTY = 8, MUTE = 9, NUMBER_SEP = 10, NOTE = 11, FILENAME = 12, 
    NOTE_CHANGE = 13, NEWLINE = 14, WHITESPACE = 15, MEASURE_SP = 16
  };

  enum {
    RuleTabs = 0, RuleLine = 1, RuleTuning = 2, RuleFile = 3, RuleMeasures = 4, 
    RuleNotes = 5, RuleTempo = 6, RuleChords = 7, RuleNote_chg = 8
  };

  explicit TabsParser(antlr4::TokenStream *input);
  ~TabsParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class TabsContext;
  class LineContext;
  class TuningContext;
  class FileContext;
  class MeasuresContext;
  class NotesContext;
  class TempoContext;
  class ChordsContext;
  class Note_chgContext; 

  class  TabsContext : public antlr4::ParserRuleContext {
  public:
    TabsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TabsContext* tabs();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    TuningContext *tuning();
    FileContext *file();
    MeasuresContext *measures();
    NotesContext *notes();
    TempoContext *tempo();
    ChordsContext *chords();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  TuningContext : public antlr4::ParserRuleContext {
  public:
    TuningContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TUNING();
    std::vector<antlr4::tree::TerminalNode *> NOTE();
    antlr4::tree::TerminalNode* NOTE(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TuningContext* tuning();

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *FILENAME();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  MeasuresContext : public antlr4::ParserRuleContext {
  public:
    MeasuresContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEASURES();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *SEP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MeasuresContext* measures();

  class  NotesContext : public antlr4::ParserRuleContext {
  public:
    NotesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTES();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *SEP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotesContext* notes();

  class  TempoContext : public antlr4::ParserRuleContext {
  public:
    TempoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEMPO();
    antlr4::tree::TerminalNode *NUMBER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TempoContext* tempo();

  class  ChordsContext : public antlr4::ParserRuleContext {
  public:
    ChordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EMPTY();
    antlr4::tree::TerminalNode* EMPTY(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUTE();
    antlr4::tree::TerminalNode* MUTE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    std::vector<Note_chgContext *> note_chg();
    Note_chgContext* note_chg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NUMBER_SEP();
    antlr4::tree::TerminalNode* NUMBER_SEP(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ChordsContext* chords();

  class  Note_chgContext : public antlr4::ParserRuleContext {
  public:
    Note_chgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOTE_CHANGE();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    antlr4::tree::TerminalNode *SEP();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Note_chgContext* note_chg();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

