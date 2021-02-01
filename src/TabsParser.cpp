
// Generated from src/Tabs.g4 by ANTLR 4.9.1


#include "TabsVisitor.h"

#include "TabsParser.h"


using namespace antlrcpp;
using namespace antlr4;

TabsParser::TabsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TabsParser::~TabsParser() {
  delete _interpreter;
}

std::string TabsParser::getGrammarFileName() const {
  return "Tabs.g4";
}

const std::vector<std::string>& TabsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TabsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- TabsContext ------------------------------------------------------------------

TabsParser::TabsContext::TabsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::TabsContext::EOF() {
  return getToken(TabsParser::EOF, 0);
}

std::vector<TabsParser::LineContext *> TabsParser::TabsContext::line() {
  return getRuleContexts<TabsParser::LineContext>();
}

TabsParser::LineContext* TabsParser::TabsContext::line(size_t i) {
  return getRuleContext<TabsParser::LineContext>(i);
}


size_t TabsParser::TabsContext::getRuleIndex() const {
  return TabsParser::RuleTabs;
}


antlrcpp::Any TabsParser::TabsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitTabs(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::TabsContext* TabsParser::tabs() {
  TabsContext *_localctx = _tracker.createInstance<TabsContext>(_ctx, getState());
  enterRule(_localctx, 0, TabsParser::RuleTabs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(18);
      line();
      setState(21); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TabsParser::TUNING)
      | (1ULL << TabsParser::FILE)
      | (1ULL << TabsParser::MEASURES)
      | (1ULL << TabsParser::NOTES)
      | (1ULL << TabsParser::TEMPO)
      | (1ULL << TabsParser::NUMBER)
      | (1ULL << TabsParser::EMPTY)
      | (1ULL << TabsParser::MUTE)
      | (1ULL << TabsParser::NOTE_CHANGE)
      | (1ULL << TabsParser::NEWLINE))) != 0));
    setState(23);
    match(TabsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

TabsParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::LineContext::NEWLINE() {
  return getToken(TabsParser::NEWLINE, 0);
}

TabsParser::TuningContext* TabsParser::LineContext::tuning() {
  return getRuleContext<TabsParser::TuningContext>(0);
}

TabsParser::FileContext* TabsParser::LineContext::file() {
  return getRuleContext<TabsParser::FileContext>(0);
}

TabsParser::MeasuresContext* TabsParser::LineContext::measures() {
  return getRuleContext<TabsParser::MeasuresContext>(0);
}

TabsParser::NotesContext* TabsParser::LineContext::notes() {
  return getRuleContext<TabsParser::NotesContext>(0);
}

TabsParser::TempoContext* TabsParser::LineContext::tempo() {
  return getRuleContext<TabsParser::TempoContext>(0);
}

TabsParser::ChordsContext* TabsParser::LineContext::chords() {
  return getRuleContext<TabsParser::ChordsContext>(0);
}


size_t TabsParser::LineContext::getRuleIndex() const {
  return TabsParser::RuleLine;
}


antlrcpp::Any TabsParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::LineContext* TabsParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, TabsParser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TabsParser::TUNING: {
        setState(25);
        tuning();
        break;
      }

      case TabsParser::FILE: {
        setState(26);
        file();
        break;
      }

      case TabsParser::MEASURES: {
        setState(27);
        measures();
        break;
      }

      case TabsParser::NOTES: {
        setState(28);
        notes();
        break;
      }

      case TabsParser::TEMPO: {
        setState(29);
        tempo();
        break;
      }

      case TabsParser::NUMBER:
      case TabsParser::EMPTY:
      case TabsParser::MUTE:
      case TabsParser::NOTE_CHANGE:
      case TabsParser::NEWLINE: {
        setState(30);
        chords();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(33);
    match(TabsParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TuningContext ------------------------------------------------------------------

TabsParser::TuningContext::TuningContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::TuningContext::TUNING() {
  return getToken(TabsParser::TUNING, 0);
}

std::vector<tree::TerminalNode *> TabsParser::TuningContext::NOTE() {
  return getTokens(TabsParser::NOTE);
}

tree::TerminalNode* TabsParser::TuningContext::NOTE(size_t i) {
  return getToken(TabsParser::NOTE, i);
}


size_t TabsParser::TuningContext::getRuleIndex() const {
  return TabsParser::RuleTuning;
}


antlrcpp::Any TabsParser::TuningContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitTuning(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::TuningContext* TabsParser::tuning() {
  TuningContext *_localctx = _tracker.createInstance<TuningContext>(_ctx, getState());
  enterRule(_localctx, 4, TabsParser::RuleTuning);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(TabsParser::TUNING);
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TabsParser::NOTE) {
      setState(36);
      match(TabsParser::NOTE);
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileContext ------------------------------------------------------------------

TabsParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::FileContext::FILE() {
  return getToken(TabsParser::FILE, 0);
}

tree::TerminalNode* TabsParser::FileContext::FILENAME() {
  return getToken(TabsParser::FILENAME, 0);
}


size_t TabsParser::FileContext::getRuleIndex() const {
  return TabsParser::RuleFile;
}


antlrcpp::Any TabsParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::FileContext* TabsParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 6, TabsParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    match(TabsParser::FILE);
    setState(43);
    match(TabsParser::FILENAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MeasuresContext ------------------------------------------------------------------

TabsParser::MeasuresContext::MeasuresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::MeasuresContext::MEASURES() {
  return getToken(TabsParser::MEASURES, 0);
}

std::vector<tree::TerminalNode *> TabsParser::MeasuresContext::NUMBER() {
  return getTokens(TabsParser::NUMBER);
}

tree::TerminalNode* TabsParser::MeasuresContext::NUMBER(size_t i) {
  return getToken(TabsParser::NUMBER, i);
}

tree::TerminalNode* TabsParser::MeasuresContext::SEP() {
  return getToken(TabsParser::SEP, 0);
}


size_t TabsParser::MeasuresContext::getRuleIndex() const {
  return TabsParser::RuleMeasures;
}


antlrcpp::Any TabsParser::MeasuresContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitMeasures(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::MeasuresContext* TabsParser::measures() {
  MeasuresContext *_localctx = _tracker.createInstance<MeasuresContext>(_ctx, getState());
  enterRule(_localctx, 8, TabsParser::RuleMeasures);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(TabsParser::MEASURES);
    setState(46);
    match(TabsParser::NUMBER);
    setState(47);
    match(TabsParser::SEP);
    setState(48);
    match(TabsParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NotesContext ------------------------------------------------------------------

TabsParser::NotesContext::NotesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::NotesContext::NOTES() {
  return getToken(TabsParser::NOTES, 0);
}

std::vector<tree::TerminalNode *> TabsParser::NotesContext::NUMBER() {
  return getTokens(TabsParser::NUMBER);
}

tree::TerminalNode* TabsParser::NotesContext::NUMBER(size_t i) {
  return getToken(TabsParser::NUMBER, i);
}

tree::TerminalNode* TabsParser::NotesContext::SEP() {
  return getToken(TabsParser::SEP, 0);
}


size_t TabsParser::NotesContext::getRuleIndex() const {
  return TabsParser::RuleNotes;
}


antlrcpp::Any TabsParser::NotesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitNotes(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::NotesContext* TabsParser::notes() {
  NotesContext *_localctx = _tracker.createInstance<NotesContext>(_ctx, getState());
  enterRule(_localctx, 10, TabsParser::RuleNotes);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(TabsParser::NOTES);
    setState(51);
    match(TabsParser::NUMBER);
    setState(52);
    match(TabsParser::SEP);
    setState(53);
    match(TabsParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempoContext ------------------------------------------------------------------

TabsParser::TempoContext::TempoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::TempoContext::TEMPO() {
  return getToken(TabsParser::TEMPO, 0);
}

tree::TerminalNode* TabsParser::TempoContext::NUMBER() {
  return getToken(TabsParser::NUMBER, 0);
}


size_t TabsParser::TempoContext::getRuleIndex() const {
  return TabsParser::RuleTempo;
}


antlrcpp::Any TabsParser::TempoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitTempo(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::TempoContext* TabsParser::tempo() {
  TempoContext *_localctx = _tracker.createInstance<TempoContext>(_ctx, getState());
  enterRule(_localctx, 12, TabsParser::RuleTempo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(TabsParser::TEMPO);
    setState(56);
    match(TabsParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChordsContext ------------------------------------------------------------------

TabsParser::ChordsContext::ChordsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TabsParser::ChordsContext::EMPTY() {
  return getTokens(TabsParser::EMPTY);
}

tree::TerminalNode* TabsParser::ChordsContext::EMPTY(size_t i) {
  return getToken(TabsParser::EMPTY, i);
}

std::vector<tree::TerminalNode *> TabsParser::ChordsContext::MUTE() {
  return getTokens(TabsParser::MUTE);
}

tree::TerminalNode* TabsParser::ChordsContext::MUTE(size_t i) {
  return getToken(TabsParser::MUTE, i);
}

std::vector<tree::TerminalNode *> TabsParser::ChordsContext::NUMBER() {
  return getTokens(TabsParser::NUMBER);
}

tree::TerminalNode* TabsParser::ChordsContext::NUMBER(size_t i) {
  return getToken(TabsParser::NUMBER, i);
}

std::vector<TabsParser::Note_chgContext *> TabsParser::ChordsContext::note_chg() {
  return getRuleContexts<TabsParser::Note_chgContext>();
}

TabsParser::Note_chgContext* TabsParser::ChordsContext::note_chg(size_t i) {
  return getRuleContext<TabsParser::Note_chgContext>(i);
}

std::vector<tree::TerminalNode *> TabsParser::ChordsContext::NUMBER_SEP() {
  return getTokens(TabsParser::NUMBER_SEP);
}

tree::TerminalNode* TabsParser::ChordsContext::NUMBER_SEP(size_t i) {
  return getToken(TabsParser::NUMBER_SEP, i);
}


size_t TabsParser::ChordsContext::getRuleIndex() const {
  return TabsParser::RuleChords;
}


antlrcpp::Any TabsParser::ChordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitChords(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::ChordsContext* TabsParser::chords() {
  ChordsContext *_localctx = _tracker.createInstance<ChordsContext>(_ctx, getState());
  enterRule(_localctx, 14, TabsParser::RuleChords);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << TabsParser::NUMBER)
      | (1ULL << TabsParser::EMPTY)
      | (1ULL << TabsParser::MUTE)
      | (1ULL << TabsParser::NOTE_CHANGE))) != 0)) {
      setState(65);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case TabsParser::EMPTY: {
          setState(58);
          match(TabsParser::EMPTY);
          break;
        }

        case TabsParser::MUTE: {
          setState(59);
          match(TabsParser::MUTE);
          break;
        }

        case TabsParser::NUMBER: {
          setState(60);
          match(TabsParser::NUMBER);
          setState(62);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TabsParser::NUMBER_SEP) {
            setState(61);
            match(TabsParser::NUMBER_SEP);
          }
          break;
        }

        case TabsParser::NOTE_CHANGE: {
          setState(64);
          note_chg();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(69);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Note_chgContext ------------------------------------------------------------------

TabsParser::Note_chgContext::Note_chgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TabsParser::Note_chgContext::NOTE_CHANGE() {
  return getToken(TabsParser::NOTE_CHANGE, 0);
}

std::vector<tree::TerminalNode *> TabsParser::Note_chgContext::NUMBER() {
  return getTokens(TabsParser::NUMBER);
}

tree::TerminalNode* TabsParser::Note_chgContext::NUMBER(size_t i) {
  return getToken(TabsParser::NUMBER, i);
}

tree::TerminalNode* TabsParser::Note_chgContext::SEP() {
  return getToken(TabsParser::SEP, 0);
}


size_t TabsParser::Note_chgContext::getRuleIndex() const {
  return TabsParser::RuleNote_chg;
}


antlrcpp::Any TabsParser::Note_chgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TabsVisitor*>(visitor))
    return parserVisitor->visitNote_chg(this);
  else
    return visitor->visitChildren(this);
}

TabsParser::Note_chgContext* TabsParser::note_chg() {
  Note_chgContext *_localctx = _tracker.createInstance<Note_chgContext>(_ctx, getState());
  enterRule(_localctx, 16, TabsParser::RuleNote_chg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(TabsParser::NOTE_CHANGE);
    setState(71);
    match(TabsParser::NUMBER);
    setState(72);
    match(TabsParser::SEP);
    setState(73);
    match(TabsParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> TabsParser::_decisionToDFA;
atn::PredictionContextCache TabsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TabsParser::_atn;
std::vector<uint16_t> TabsParser::_serializedATN;

std::vector<std::string> TabsParser::_ruleNames = {
  "tabs", "line", "tuning", "file", "measures", "notes", "tempo", "chords", 
  "note_chg"
};

std::vector<std::string> TabsParser::_literalNames = {
  "", "'Tuning'", "'File'", "'Measures'", "'Notes'", "'Tempo'", "", "'/'", 
  "'.'", "'x'", "'_'", "", "", "'N'", "", "", "'|'"
};

std::vector<std::string> TabsParser::_symbolicNames = {
  "", "TUNING", "FILE", "MEASURES", "NOTES", "TEMPO", "NUMBER", "SEP", "EMPTY", 
  "MUTE", "NUMBER_SEP", "NOTE", "FILENAME", "NOTE_CHANGE", "NEWLINE", "WHITESPACE", 
  "MEASURE_SP"
};

dfa::Vocabulary TabsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TabsParser::_tokenNames;

TabsParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x12, 0x4e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x6, 
    0x2, 0x16, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x17, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x22, 
    0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x28, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x2b, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x41, 0xa, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0x44, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x47, 0xb, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 0x2, 0xb, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x2, 0x2, 0x50, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x21, 0x3, 0x2, 0x2, 0x2, 0x6, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x2c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x34, 0x3, 0x2, 0x2, 0x2, 0xe, 0x39, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x12, 0x48, 0x3, 0x2, 0x2, 0x2, 0x14, 0x16, 
    0x5, 0x4, 0x3, 0x2, 0x15, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x2, 0x2, 
    0x3, 0x1a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x22, 0x5, 0x6, 0x4, 0x2, 
    0x1c, 0x22, 0x5, 0x8, 0x5, 0x2, 0x1d, 0x22, 0x5, 0xa, 0x6, 0x2, 0x1e, 
    0x22, 0x5, 0xc, 0x7, 0x2, 0x1f, 0x22, 0x5, 0xe, 0x8, 0x2, 0x20, 0x22, 
    0x5, 0x10, 0x9, 0x2, 0x21, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1c, 0x3, 
    0x2, 0x2, 0x2, 0x21, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1e, 0x3, 0x2, 
    0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x10, 0x2, 0x2, 
    0x24, 0x5, 0x3, 0x2, 0x2, 0x2, 0x25, 0x29, 0x7, 0x3, 0x2, 0x2, 0x26, 
    0x28, 0x7, 0xd, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x2a, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x2c, 0x2d, 0x7, 0x4, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0xe, 0x2, 
    0x2, 0x2e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x5, 0x2, 0x2, 
    0x30, 0x31, 0x7, 0x8, 0x2, 0x2, 0x31, 0x32, 0x7, 0x9, 0x2, 0x2, 0x32, 
    0x33, 0x7, 0x8, 0x2, 0x2, 0x33, 0xb, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 
    0x7, 0x6, 0x2, 0x2, 0x35, 0x36, 0x7, 0x8, 0x2, 0x2, 0x36, 0x37, 0x7, 
    0x9, 0x2, 0x2, 0x37, 0x38, 0x7, 0x8, 0x2, 0x2, 0x38, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x3a, 0x7, 0x7, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x8, 0x2, 
    0x2, 0x3b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x44, 0x7, 0xa, 0x2, 0x2, 
    0x3d, 0x44, 0x7, 0xb, 0x2, 0x2, 0x3e, 0x40, 0x7, 0x8, 0x2, 0x2, 0x3f, 
    0x41, 0x7, 0xc, 0x2, 0x2, 0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x5, 
    0x12, 0xa, 0x2, 0x43, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x11, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0xf, 0x2, 0x2, 0x49, 0x4a, 
    0x7, 0x8, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x9, 0x2, 0x2, 0x4b, 0x4c, 0x7, 
    0x8, 0x2, 0x2, 0x4c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0x17, 0x21, 0x29, 
    0x40, 0x43, 0x45, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TabsParser::Initializer TabsParser::_init;
