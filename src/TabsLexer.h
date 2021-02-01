
// Generated from src/Tabs.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  TabsLexer : public antlr4::Lexer {
public:
  enum {
    TUNING = 1, FILE = 2, MEASURES = 3, NOTES = 4, TEMPO = 5, NUMBER = 6, 
    SEP = 7, EMPTY = 8, MUTE = 9, NUMBER_SEP = 10, NOTE = 11, FILENAME = 12, 
    NEWLINE = 13, WHITESPACE = 14, MEASURE_SP = 15
  };

  explicit TabsLexer(antlr4::CharStream *input);
  ~TabsLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

