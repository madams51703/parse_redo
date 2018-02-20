
// Generated from RedoParser.g4 by ANTLR 4.7.1


#include "RedoParserListener.h"

#include "RedoParser.h"


using namespace antlrcpp;
using namespace antlr4;

RedoParser::RedoParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RedoParser::~RedoParser() {
  delete _interpreter;
}

std::string RedoParser::getGrammarFileName() const {
  return "RedoParser.g4";
}

const std::vector<std::string>& RedoParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RedoParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Redo_fileContext ------------------------------------------------------------------

RedoParser::Redo_fileContext::Redo_fileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Redo_fileContext::EOF() {
  return getToken(RedoParser::EOF, 0);
}

std::vector<RedoParser::Redo_infoContext *> RedoParser::Redo_fileContext::redo_info() {
  return getRuleContexts<RedoParser::Redo_infoContext>();
}

RedoParser::Redo_infoContext* RedoParser::Redo_fileContext::redo_info(size_t i) {
  return getRuleContext<RedoParser::Redo_infoContext>(i);
}


size_t RedoParser::Redo_fileContext::getRuleIndex() const {
  return RedoParser::RuleRedo_file;
}

void RedoParser::Redo_fileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRedo_file(this);
}

void RedoParser::Redo_fileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRedo_file(this);
}

RedoParser::Redo_fileContext* RedoParser::redo_file() {
  Redo_fileContext *_localctx = _tracker.createInstance<Redo_fileContext>(_ctx, getState());
  enterRule(_localctx, 0, RedoParser::RuleRedo_file);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RedoParser::REDO) {
      setState(90);
      redo_info();
      setState(95);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(96);
    match(RedoParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Redo_infoContext ------------------------------------------------------------------

RedoParser::Redo_infoContext::Redo_infoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RedoParser::Redo_recordContext* RedoParser::Redo_infoContext::redo_record() {
  return getRuleContext<RedoParser::Redo_recordContext>(0);
}

RedoParser::Change_recordsContext* RedoParser::Redo_infoContext::change_records() {
  return getRuleContext<RedoParser::Change_recordsContext>(0);
}


size_t RedoParser::Redo_infoContext::getRuleIndex() const {
  return RedoParser::RuleRedo_info;
}

void RedoParser::Redo_infoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRedo_info(this);
}

void RedoParser::Redo_infoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRedo_info(this);
}

RedoParser::Redo_infoContext* RedoParser::redo_info() {
  Redo_infoContext *_localctx = _tracker.createInstance<Redo_infoContext>(_ctx, getState());
  enterRule(_localctx, 2, RedoParser::RuleRedo_info);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    redo_record();
    setState(99);
    change_records();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Redo_recordContext ------------------------------------------------------------------

RedoParser::Redo_recordContext::Redo_recordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Redo_recordContext::REDO() {
  return getToken(RedoParser::REDO, 0);
}

tree::TerminalNode* RedoParser::Redo_recordContext::RECORD() {
  return getToken(RedoParser::RECORD, 0);
}

tree::TerminalNode* RedoParser::Redo_recordContext::MINUS() {
  return getToken(RedoParser::MINUS, 0);
}

RedoParser::ThreadContext* RedoParser::Redo_recordContext::thread() {
  return getRuleContext<RedoParser::ThreadContext>(0);
}

RedoParser::RbaContext* RedoParser::Redo_recordContext::rba() {
  return getRuleContext<RedoParser::RbaContext>(0);
}

RedoParser::LenContext* RedoParser::Redo_recordContext::len() {
  return getRuleContext<RedoParser::LenContext>(0);
}

RedoParser::VldContext* RedoParser::Redo_recordContext::vld() {
  return getRuleContext<RedoParser::VldContext>(0);
}

RedoParser::ScnContext* RedoParser::Redo_recordContext::scn() {
  return getRuleContext<RedoParser::ScnContext>(0);
}

RedoParser::SubscnContext* RedoParser::Redo_recordContext::subscn() {
  return getRuleContext<RedoParser::SubscnContext>(0);
}

RedoParser::Date_valueContext* RedoParser::Redo_recordContext::date_value() {
  return getRuleContext<RedoParser::Date_valueContext>(0);
}


size_t RedoParser::Redo_recordContext::getRuleIndex() const {
  return RedoParser::RuleRedo_record;
}

void RedoParser::Redo_recordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRedo_record(this);
}

void RedoParser::Redo_recordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRedo_record(this);
}

RedoParser::Redo_recordContext* RedoParser::redo_record() {
  Redo_recordContext *_localctx = _tracker.createInstance<Redo_recordContext>(_ctx, getState());
  enterRule(_localctx, 4, RedoParser::RuleRedo_record);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(RedoParser::REDO);
    setState(102);
    match(RedoParser::RECORD);
    setState(103);
    match(RedoParser::MINUS);
    setState(104);
    thread();
    setState(105);
    rba();
    setState(106);
    len();
    setState(107);
    vld();
    setState(108);
    scn();
    setState(109);
    subscn();
    setState(110);
    date_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Change_recordsContext ------------------------------------------------------------------

RedoParser::Change_recordsContext::Change_recordsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RedoParser::ChangeContext *> RedoParser::Change_recordsContext::change() {
  return getRuleContexts<RedoParser::ChangeContext>();
}

RedoParser::ChangeContext* RedoParser::Change_recordsContext::change(size_t i) {
  return getRuleContext<RedoParser::ChangeContext>(i);
}


size_t RedoParser::Change_recordsContext::getRuleIndex() const {
  return RedoParser::RuleChange_records;
}

void RedoParser::Change_recordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChange_records(this);
}

void RedoParser::Change_recordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChange_records(this);
}

RedoParser::Change_recordsContext* RedoParser::change_records() {
  Change_recordsContext *_localctx = _tracker.createInstance<Change_recordsContext>(_ctx, getState());
  enterRule(_localctx, 6, RedoParser::RuleChange_records);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(112);
      change();
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RedoParser::CHANGE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThreadContext ------------------------------------------------------------------

RedoParser::ThreadContext::ThreadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::ThreadContext::THREAD() {
  return getToken(RedoParser::THREAD, 0);
}

RedoParser::Thread_numberContext* RedoParser::ThreadContext::thread_number() {
  return getRuleContext<RedoParser::Thread_numberContext>(0);
}


size_t RedoParser::ThreadContext::getRuleIndex() const {
  return RedoParser::RuleThread;
}

void RedoParser::ThreadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThread(this);
}

void RedoParser::ThreadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThread(this);
}

RedoParser::ThreadContext* RedoParser::thread() {
  ThreadContext *_localctx = _tracker.createInstance<ThreadContext>(_ctx, getState());
  enterRule(_localctx, 8, RedoParser::RuleThread);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(RedoParser::THREAD);
    setState(118);
    match(RedoParser::COLON);
    setState(119);
    thread_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Thread_numberContext ------------------------------------------------------------------

RedoParser::Thread_numberContext::Thread_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Thread_numberContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Thread_numberContext::getRuleIndex() const {
  return RedoParser::RuleThread_number;
}

void RedoParser::Thread_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThread_number(this);
}

void RedoParser::Thread_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThread_number(this);
}

RedoParser::Thread_numberContext* RedoParser::thread_number() {
  Thread_numberContext *_localctx = _tracker.createInstance<Thread_numberContext>(_ctx, getState());
  enterRule(_localctx, 10, RedoParser::RuleThread_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RbaContext ------------------------------------------------------------------

RedoParser::RbaContext::RbaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::RbaContext::RBA() {
  return getToken(RedoParser::RBA, 0);
}

RedoParser::Log_file_sequence_numberContext* RedoParser::RbaContext::log_file_sequence_number() {
  return getRuleContext<RedoParser::Log_file_sequence_numberContext>(0);
}

std::vector<tree::TerminalNode *> RedoParser::RbaContext::DOT() {
  return getTokens(RedoParser::DOT);
}

tree::TerminalNode* RedoParser::RbaContext::DOT(size_t i) {
  return getToken(RedoParser::DOT, i);
}

RedoParser::Log_file_block_numberContext* RedoParser::RbaContext::log_file_block_number() {
  return getRuleContext<RedoParser::Log_file_block_numberContext>(0);
}

RedoParser::Byte_offsetContext* RedoParser::RbaContext::byte_offset() {
  return getRuleContext<RedoParser::Byte_offsetContext>(0);
}


size_t RedoParser::RbaContext::getRuleIndex() const {
  return RedoParser::RuleRba;
}

void RedoParser::RbaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRba(this);
}

void RedoParser::RbaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRba(this);
}

RedoParser::RbaContext* RedoParser::rba() {
  RbaContext *_localctx = _tracker.createInstance<RbaContext>(_ctx, getState());
  enterRule(_localctx, 12, RedoParser::RuleRba);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(RedoParser::RBA);
    setState(124);
    match(RedoParser::COLON);
    setState(125);
    log_file_sequence_number();
    setState(126);
    match(RedoParser::DOT);
    setState(127);
    log_file_block_number();
    setState(128);
    match(RedoParser::DOT);
    setState(129);
    byte_offset();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Log_file_sequence_numberContext ------------------------------------------------------------------

RedoParser::Log_file_sequence_numberContext::Log_file_sequence_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Log_file_sequence_numberContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Log_file_sequence_numberContext::getRuleIndex() const {
  return RedoParser::RuleLog_file_sequence_number;
}

void RedoParser::Log_file_sequence_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLog_file_sequence_number(this);
}

void RedoParser::Log_file_sequence_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLog_file_sequence_number(this);
}

RedoParser::Log_file_sequence_numberContext* RedoParser::log_file_sequence_number() {
  Log_file_sequence_numberContext *_localctx = _tracker.createInstance<Log_file_sequence_numberContext>(_ctx, getState());
  enterRule(_localctx, 14, RedoParser::RuleLog_file_sequence_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Log_file_block_numberContext ------------------------------------------------------------------

RedoParser::Log_file_block_numberContext::Log_file_block_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Log_file_block_numberContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Log_file_block_numberContext::getRuleIndex() const {
  return RedoParser::RuleLog_file_block_number;
}

void RedoParser::Log_file_block_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLog_file_block_number(this);
}

void RedoParser::Log_file_block_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLog_file_block_number(this);
}

RedoParser::Log_file_block_numberContext* RedoParser::log_file_block_number() {
  Log_file_block_numberContext *_localctx = _tracker.createInstance<Log_file_block_numberContext>(_ctx, getState());
  enterRule(_localctx, 16, RedoParser::RuleLog_file_block_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Byte_offsetContext ------------------------------------------------------------------

RedoParser::Byte_offsetContext::Byte_offsetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Byte_offsetContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Byte_offsetContext::getRuleIndex() const {
  return RedoParser::RuleByte_offset;
}

void RedoParser::Byte_offsetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterByte_offset(this);
}

void RedoParser::Byte_offsetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitByte_offset(this);
}

RedoParser::Byte_offsetContext* RedoParser::byte_offset() {
  Byte_offsetContext *_localctx = _tracker.createInstance<Byte_offsetContext>(_ctx, getState());
  enterRule(_localctx, 18, RedoParser::RuleByte_offset);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LenContext ------------------------------------------------------------------

RedoParser::LenContext::LenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::LenContext::LEN() {
  return getToken(RedoParser::LEN, 0);
}

RedoParser::Len_valueContext* RedoParser::LenContext::len_value() {
  return getRuleContext<RedoParser::Len_valueContext>(0);
}


size_t RedoParser::LenContext::getRuleIndex() const {
  return RedoParser::RuleLen;
}

void RedoParser::LenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLen(this);
}

void RedoParser::LenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLen(this);
}

RedoParser::LenContext* RedoParser::len() {
  LenContext *_localctx = _tracker.createInstance<LenContext>(_ctx, getState());
  enterRule(_localctx, 20, RedoParser::RuleLen);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(RedoParser::LEN);
    setState(138);
    match(RedoParser::COLON);
    setState(139);
    len_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Len_valueContext ------------------------------------------------------------------

RedoParser::Len_valueContext::Len_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Len_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Len_valueContext::getRuleIndex() const {
  return RedoParser::RuleLen_value;
}

void RedoParser::Len_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLen_value(this);
}

void RedoParser::Len_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLen_value(this);
}

RedoParser::Len_valueContext* RedoParser::len_value() {
  Len_valueContext *_localctx = _tracker.createInstance<Len_valueContext>(_ctx, getState());
  enterRule(_localctx, 22, RedoParser::RuleLen_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VldContext ------------------------------------------------------------------

RedoParser::VldContext::VldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::VldContext::VLD() {
  return getToken(RedoParser::VLD, 0);
}

RedoParser::Vld_valueContext* RedoParser::VldContext::vld_value() {
  return getRuleContext<RedoParser::Vld_valueContext>(0);
}


size_t RedoParser::VldContext::getRuleIndex() const {
  return RedoParser::RuleVld;
}

void RedoParser::VldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVld(this);
}

void RedoParser::VldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVld(this);
}

RedoParser::VldContext* RedoParser::vld() {
  VldContext *_localctx = _tracker.createInstance<VldContext>(_ctx, getState());
  enterRule(_localctx, 24, RedoParser::RuleVld);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(RedoParser::VLD);
    setState(144);
    match(RedoParser::COLON);
    setState(145);
    vld_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Vld_valueContext ------------------------------------------------------------------

RedoParser::Vld_valueContext::Vld_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Vld_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Vld_valueContext::getRuleIndex() const {
  return RedoParser::RuleVld_value;
}

void RedoParser::Vld_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVld_value(this);
}

void RedoParser::Vld_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVld_value(this);
}

RedoParser::Vld_valueContext* RedoParser::vld_value() {
  Vld_valueContext *_localctx = _tracker.createInstance<Vld_valueContext>(_ctx, getState());
  enterRule(_localctx, 26, RedoParser::RuleVld_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScnContext ------------------------------------------------------------------

RedoParser::ScnContext::ScnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::ScnContext::SCN() {
  return getToken(RedoParser::SCN, 0);
}

RedoParser::WrapContext* RedoParser::ScnContext::wrap() {
  return getRuleContext<RedoParser::WrapContext>(0);
}

tree::TerminalNode* RedoParser::ScnContext::DOT() {
  return getToken(RedoParser::DOT, 0);
}

RedoParser::BaseContext* RedoParser::ScnContext::base() {
  return getRuleContext<RedoParser::BaseContext>(0);
}


size_t RedoParser::ScnContext::getRuleIndex() const {
  return RedoParser::RuleScn;
}

void RedoParser::ScnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScn(this);
}

void RedoParser::ScnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScn(this);
}

RedoParser::ScnContext* RedoParser::scn() {
  ScnContext *_localctx = _tracker.createInstance<ScnContext>(_ctx, getState());
  enterRule(_localctx, 28, RedoParser::RuleScn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(RedoParser::SCN);
    setState(150);
    match(RedoParser::COLON);
    setState(151);
    wrap();
    setState(152);
    match(RedoParser::DOT);
    setState(153);
    base();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WrapContext ------------------------------------------------------------------

RedoParser::WrapContext::WrapContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::WrapContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::WrapContext::getRuleIndex() const {
  return RedoParser::RuleWrap;
}

void RedoParser::WrapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWrap(this);
}

void RedoParser::WrapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWrap(this);
}

RedoParser::WrapContext* RedoParser::wrap() {
  WrapContext *_localctx = _tracker.createInstance<WrapContext>(_ctx, getState());
  enterRule(_localctx, 30, RedoParser::RuleWrap);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseContext ------------------------------------------------------------------

RedoParser::BaseContext::BaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::BaseContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::BaseContext::getRuleIndex() const {
  return RedoParser::RuleBase;
}

void RedoParser::BaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBase(this);
}

void RedoParser::BaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBase(this);
}

RedoParser::BaseContext* RedoParser::base() {
  BaseContext *_localctx = _tracker.createInstance<BaseContext>(_ctx, getState());
  enterRule(_localctx, 32, RedoParser::RuleBase);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubscnContext ------------------------------------------------------------------

RedoParser::SubscnContext::SubscnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::SubscnContext::SUBSCN() {
  return getToken(RedoParser::SUBSCN, 0);
}

RedoParser::Subscn_valueContext* RedoParser::SubscnContext::subscn_value() {
  return getRuleContext<RedoParser::Subscn_valueContext>(0);
}


size_t RedoParser::SubscnContext::getRuleIndex() const {
  return RedoParser::RuleSubscn;
}

void RedoParser::SubscnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscn(this);
}

void RedoParser::SubscnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscn(this);
}

RedoParser::SubscnContext* RedoParser::subscn() {
  SubscnContext *_localctx = _tracker.createInstance<SubscnContext>(_ctx, getState());
  enterRule(_localctx, 34, RedoParser::RuleSubscn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(RedoParser::SUBSCN);
    setState(160);
    match(RedoParser::COLON);
    setState(161);
    subscn_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subscn_valueContext ------------------------------------------------------------------

RedoParser::Subscn_valueContext::Subscn_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Subscn_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Subscn_valueContext::getRuleIndex() const {
  return RedoParser::RuleSubscn_value;
}

void RedoParser::Subscn_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscn_value(this);
}

void RedoParser::Subscn_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscn_value(this);
}

RedoParser::Subscn_valueContext* RedoParser::subscn_value() {
  Subscn_valueContext *_localctx = _tracker.createInstance<Subscn_valueContext>(_ctx, getState());
  enterRule(_localctx, 36, RedoParser::RuleSubscn_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Date_valueContext ------------------------------------------------------------------

RedoParser::Date_valueContext::Date_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Date_valueContext::DATE() {
  return getToken(RedoParser::DATE, 0);
}


size_t RedoParser::Date_valueContext::getRuleIndex() const {
  return RedoParser::RuleDate_value;
}

void RedoParser::Date_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDate_value(this);
}

void RedoParser::Date_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDate_value(this);
}

RedoParser::Date_valueContext* RedoParser::date_value() {
  Date_valueContext *_localctx = _tracker.createInstance<Date_valueContext>(_ctx, getState());
  enterRule(_localctx, 38, RedoParser::RuleDate_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    match(RedoParser::DATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChangeContext ------------------------------------------------------------------

RedoParser::ChangeContext::ChangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::ChangeContext::CHANGE() {
  return getToken(RedoParser::CHANGE, 0);
}

RedoParser::Change_numberContext* RedoParser::ChangeContext::change_number() {
  return getRuleContext<RedoParser::Change_numberContext>(0);
}

RedoParser::Chg_typeContext* RedoParser::ChangeContext::chg_type() {
  return getRuleContext<RedoParser::Chg_typeContext>(0);
}

RedoParser::Chg_classContext* RedoParser::ChangeContext::chg_class() {
  return getRuleContext<RedoParser::Chg_classContext>(0);
}

RedoParser::Chg_afnContext* RedoParser::ChangeContext::chg_afn() {
  return getRuleContext<RedoParser::Chg_afnContext>(0);
}

RedoParser::DbaContext* RedoParser::ChangeContext::dba() {
  return getRuleContext<RedoParser::DbaContext>(0);
}

RedoParser::Chg_objContext* RedoParser::ChangeContext::chg_obj() {
  return getRuleContext<RedoParser::Chg_objContext>(0);
}

RedoParser::ScnContext* RedoParser::ChangeContext::scn() {
  return getRuleContext<RedoParser::ScnContext>(0);
}

RedoParser::SeqContext* RedoParser::ChangeContext::seq() {
  return getRuleContext<RedoParser::SeqContext>(0);
}

RedoParser::Layer_opcodeContext* RedoParser::ChangeContext::layer_opcode() {
  return getRuleContext<RedoParser::Layer_opcodeContext>(0);
}

RedoParser::EncContext* RedoParser::ChangeContext::enc() {
  return getRuleContext<RedoParser::EncContext>(0);
}

RedoParser::RblContext* RedoParser::ChangeContext::rbl() {
  return getRuleContext<RedoParser::RblContext>(0);
}

RedoParser::Media_recovery_markerContext* RedoParser::ChangeContext::media_recovery_marker() {
  return getRuleContext<RedoParser::Media_recovery_markerContext>(0);
}

RedoParser::InvldContext* RedoParser::ChangeContext::invld() {
  return getRuleContext<RedoParser::InvldContext>(0);
}

RedoParser::BlksContext* RedoParser::ChangeContext::blks() {
  return getRuleContext<RedoParser::BlksContext>(0);
}


size_t RedoParser::ChangeContext::getRuleIndex() const {
  return RedoParser::RuleChange;
}

void RedoParser::ChangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChange(this);
}

void RedoParser::ChangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChange(this);
}

RedoParser::ChangeContext* RedoParser::change() {
  ChangeContext *_localctx = _tracker.createInstance<ChangeContext>(_ctx, getState());
  enterRule(_localctx, 40, RedoParser::RuleChange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(RedoParser::CHANGE);
    setState(198);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(168);
      change_number();
      setState(169);
      chg_type();
      setState(170);
      chg_class();
      setState(171);
      chg_afn();
      setState(172);
      dba();
      setState(173);
      chg_obj();
      setState(174);
      scn();
      setState(175);
      seq();
      setState(176);
      layer_opcode();
      setState(177);
      enc();
      setState(178);
      rbl();
      break;
    }

    case 2: {
      setState(180);
      change_number();
      setState(181);
      media_recovery_marker();
      setState(182);
      scn();
      setState(183);
      seq();
      setState(184);
      layer_opcode();
      setState(185);
      enc();
      break;
    }

    case 3: {
      setState(187);
      change_number();
      setState(188);
      invld();
      setState(189);
      chg_afn();
      setState(190);
      dba();
      setState(191);
      blks();
      setState(192);
      chg_obj();
      setState(193);
      scn();
      setState(194);
      seq();
      setState(195);
      layer_opcode();
      setState(196);
      enc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InvldContext ------------------------------------------------------------------

RedoParser::InvldContext::InvldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::InvldContext::INVLD() {
  return getToken(RedoParser::INVLD, 0);
}


size_t RedoParser::InvldContext::getRuleIndex() const {
  return RedoParser::RuleInvld;
}

void RedoParser::InvldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvld(this);
}

void RedoParser::InvldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvld(this);
}

RedoParser::InvldContext* RedoParser::invld() {
  InvldContext *_localctx = _tracker.createInstance<InvldContext>(_ctx, getState());
  enterRule(_localctx, 42, RedoParser::RuleInvld);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(RedoParser::INVLD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Media_recovery_markerContext ------------------------------------------------------------------

RedoParser::Media_recovery_markerContext::Media_recovery_markerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Media_recovery_markerContext::MEDIA() {
  return getToken(RedoParser::MEDIA, 0);
}

tree::TerminalNode* RedoParser::Media_recovery_markerContext::RECOVERY() {
  return getToken(RedoParser::RECOVERY, 0);
}

tree::TerminalNode* RedoParser::Media_recovery_markerContext::MARKER() {
  return getToken(RedoParser::MARKER, 0);
}


size_t RedoParser::Media_recovery_markerContext::getRuleIndex() const {
  return RedoParser::RuleMedia_recovery_marker;
}

void RedoParser::Media_recovery_markerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMedia_recovery_marker(this);
}

void RedoParser::Media_recovery_markerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMedia_recovery_marker(this);
}

RedoParser::Media_recovery_markerContext* RedoParser::media_recovery_marker() {
  Media_recovery_markerContext *_localctx = _tracker.createInstance<Media_recovery_markerContext>(_ctx, getState());
  enterRule(_localctx, 44, RedoParser::RuleMedia_recovery_marker);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(RedoParser::MEDIA);
    setState(203);
    match(RedoParser::RECOVERY);
    setState(204);
    match(RedoParser::MARKER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Change_numberContext ------------------------------------------------------------------

RedoParser::Change_numberContext::Change_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Change_numberContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Change_numberContext::getRuleIndex() const {
  return RedoParser::RuleChange_number;
}

void RedoParser::Change_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChange_number(this);
}

void RedoParser::Change_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChange_number(this);
}

RedoParser::Change_numberContext* RedoParser::change_number() {
  Change_numberContext *_localctx = _tracker.createInstance<Change_numberContext>(_ctx, getState());
  enterRule(_localctx, 46, RedoParser::RuleChange_number);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlksContext ------------------------------------------------------------------

RedoParser::BlksContext::BlksContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::BlksContext::BLKS() {
  return getToken(RedoParser::BLKS, 0);
}

RedoParser::Blks_valueContext* RedoParser::BlksContext::blks_value() {
  return getRuleContext<RedoParser::Blks_valueContext>(0);
}


size_t RedoParser::BlksContext::getRuleIndex() const {
  return RedoParser::RuleBlks;
}

void RedoParser::BlksContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlks(this);
}

void RedoParser::BlksContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlks(this);
}

RedoParser::BlksContext* RedoParser::blks() {
  BlksContext *_localctx = _tracker.createInstance<BlksContext>(_ctx, getState());
  enterRule(_localctx, 48, RedoParser::RuleBlks);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    match(RedoParser::BLKS);
    setState(209);
    match(RedoParser::COLON);
    setState(210);
    blks_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Blks_valueContext ------------------------------------------------------------------

RedoParser::Blks_valueContext::Blks_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Blks_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Blks_valueContext::getRuleIndex() const {
  return RedoParser::RuleBlks_value;
}

void RedoParser::Blks_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlks_value(this);
}

void RedoParser::Blks_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlks_value(this);
}

RedoParser::Blks_valueContext* RedoParser::blks_value() {
  Blks_valueContext *_localctx = _tracker.createInstance<Blks_valueContext>(_ctx, getState());
  enterRule(_localctx, 50, RedoParser::RuleBlks_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_typeContext ------------------------------------------------------------------

RedoParser::Chg_typeContext::Chg_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_typeContext::TYP() {
  return getToken(RedoParser::TYP, 0);
}

RedoParser::Chg_type_valueContext* RedoParser::Chg_typeContext::chg_type_value() {
  return getRuleContext<RedoParser::Chg_type_valueContext>(0);
}


size_t RedoParser::Chg_typeContext::getRuleIndex() const {
  return RedoParser::RuleChg_type;
}

void RedoParser::Chg_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_type(this);
}

void RedoParser::Chg_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_type(this);
}

RedoParser::Chg_typeContext* RedoParser::chg_type() {
  Chg_typeContext *_localctx = _tracker.createInstance<Chg_typeContext>(_ctx, getState());
  enterRule(_localctx, 52, RedoParser::RuleChg_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(RedoParser::TYP);
    setState(215);
    match(RedoParser::COLON);
    setState(216);
    chg_type_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_type_valueContext ------------------------------------------------------------------

RedoParser::Chg_type_valueContext::Chg_type_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_type_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Chg_type_valueContext::getRuleIndex() const {
  return RedoParser::RuleChg_type_value;
}

void RedoParser::Chg_type_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_type_value(this);
}

void RedoParser::Chg_type_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_type_value(this);
}

RedoParser::Chg_type_valueContext* RedoParser::chg_type_value() {
  Chg_type_valueContext *_localctx = _tracker.createInstance<Chg_type_valueContext>(_ctx, getState());
  enterRule(_localctx, 54, RedoParser::RuleChg_type_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_classContext ------------------------------------------------------------------

RedoParser::Chg_classContext::Chg_classContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_classContext::CLS() {
  return getToken(RedoParser::CLS, 0);
}

RedoParser::Chg_class_valueContext* RedoParser::Chg_classContext::chg_class_value() {
  return getRuleContext<RedoParser::Chg_class_valueContext>(0);
}


size_t RedoParser::Chg_classContext::getRuleIndex() const {
  return RedoParser::RuleChg_class;
}

void RedoParser::Chg_classContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_class(this);
}

void RedoParser::Chg_classContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_class(this);
}

RedoParser::Chg_classContext* RedoParser::chg_class() {
  Chg_classContext *_localctx = _tracker.createInstance<Chg_classContext>(_ctx, getState());
  enterRule(_localctx, 56, RedoParser::RuleChg_class);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(RedoParser::CLS);
    setState(221);
    match(RedoParser::COLON);
    setState(222);
    chg_class_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_class_valueContext ------------------------------------------------------------------

RedoParser::Chg_class_valueContext::Chg_class_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_class_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Chg_class_valueContext::getRuleIndex() const {
  return RedoParser::RuleChg_class_value;
}

void RedoParser::Chg_class_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_class_value(this);
}

void RedoParser::Chg_class_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_class_value(this);
}

RedoParser::Chg_class_valueContext* RedoParser::chg_class_value() {
  Chg_class_valueContext *_localctx = _tracker.createInstance<Chg_class_valueContext>(_ctx, getState());
  enterRule(_localctx, 58, RedoParser::RuleChg_class_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_afnContext ------------------------------------------------------------------

RedoParser::Chg_afnContext::Chg_afnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_afnContext::AFN() {
  return getToken(RedoParser::AFN, 0);
}

RedoParser::Afn_valueContext* RedoParser::Chg_afnContext::afn_value() {
  return getRuleContext<RedoParser::Afn_valueContext>(0);
}


size_t RedoParser::Chg_afnContext::getRuleIndex() const {
  return RedoParser::RuleChg_afn;
}

void RedoParser::Chg_afnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_afn(this);
}

void RedoParser::Chg_afnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_afn(this);
}

RedoParser::Chg_afnContext* RedoParser::chg_afn() {
  Chg_afnContext *_localctx = _tracker.createInstance<Chg_afnContext>(_ctx, getState());
  enterRule(_localctx, 60, RedoParser::RuleChg_afn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(RedoParser::AFN);
    setState(227);
    match(RedoParser::COLON);
    setState(228);
    afn_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Afn_valueContext ------------------------------------------------------------------

RedoParser::Afn_valueContext::Afn_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Afn_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Afn_valueContext::getRuleIndex() const {
  return RedoParser::RuleAfn_value;
}

void RedoParser::Afn_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAfn_value(this);
}

void RedoParser::Afn_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAfn_value(this);
}

RedoParser::Afn_valueContext* RedoParser::afn_value() {
  Afn_valueContext *_localctx = _tracker.createInstance<Afn_valueContext>(_ctx, getState());
  enterRule(_localctx, 62, RedoParser::RuleAfn_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DbaContext ------------------------------------------------------------------

RedoParser::DbaContext::DbaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::DbaContext::DBA() {
  return getToken(RedoParser::DBA, 0);
}

RedoParser::Dba_valueContext* RedoParser::DbaContext::dba_value() {
  return getRuleContext<RedoParser::Dba_valueContext>(0);
}


size_t RedoParser::DbaContext::getRuleIndex() const {
  return RedoParser::RuleDba;
}

void RedoParser::DbaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDba(this);
}

void RedoParser::DbaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDba(this);
}

RedoParser::DbaContext* RedoParser::dba() {
  DbaContext *_localctx = _tracker.createInstance<DbaContext>(_ctx, getState());
  enterRule(_localctx, 64, RedoParser::RuleDba);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(RedoParser::DBA);
    setState(233);
    match(RedoParser::COLON);
    setState(234);
    dba_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dba_valueContext ------------------------------------------------------------------

RedoParser::Dba_valueContext::Dba_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Dba_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Dba_valueContext::getRuleIndex() const {
  return RedoParser::RuleDba_value;
}

void RedoParser::Dba_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDba_value(this);
}

void RedoParser::Dba_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDba_value(this);
}

RedoParser::Dba_valueContext* RedoParser::dba_value() {
  Dba_valueContext *_localctx = _tracker.createInstance<Dba_valueContext>(_ctx, getState());
  enterRule(_localctx, 66, RedoParser::RuleDba_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Chg_objContext ------------------------------------------------------------------

RedoParser::Chg_objContext::Chg_objContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Chg_objContext::OBJ() {
  return getToken(RedoParser::OBJ, 0);
}

RedoParser::Obj_valueContext* RedoParser::Chg_objContext::obj_value() {
  return getRuleContext<RedoParser::Obj_valueContext>(0);
}


size_t RedoParser::Chg_objContext::getRuleIndex() const {
  return RedoParser::RuleChg_obj;
}

void RedoParser::Chg_objContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChg_obj(this);
}

void RedoParser::Chg_objContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChg_obj(this);
}

RedoParser::Chg_objContext* RedoParser::chg_obj() {
  Chg_objContext *_localctx = _tracker.createInstance<Chg_objContext>(_ctx, getState());
  enterRule(_localctx, 68, RedoParser::RuleChg_obj);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(RedoParser::OBJ);
    setState(239);
    match(RedoParser::COLON);
    setState(240);
    obj_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Obj_valueContext ------------------------------------------------------------------

RedoParser::Obj_valueContext::Obj_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Obj_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Obj_valueContext::getRuleIndex() const {
  return RedoParser::RuleObj_value;
}

void RedoParser::Obj_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObj_value(this);
}

void RedoParser::Obj_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObj_value(this);
}

RedoParser::Obj_valueContext* RedoParser::obj_value() {
  Obj_valueContext *_localctx = _tracker.createInstance<Obj_valueContext>(_ctx, getState());
  enterRule(_localctx, 70, RedoParser::RuleObj_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SeqContext ------------------------------------------------------------------

RedoParser::SeqContext::SeqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::SeqContext::SEQ() {
  return getToken(RedoParser::SEQ, 0);
}

RedoParser::Seq_valueContext* RedoParser::SeqContext::seq_value() {
  return getRuleContext<RedoParser::Seq_valueContext>(0);
}


size_t RedoParser::SeqContext::getRuleIndex() const {
  return RedoParser::RuleSeq;
}

void RedoParser::SeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSeq(this);
}

void RedoParser::SeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSeq(this);
}

RedoParser::SeqContext* RedoParser::seq() {
  SeqContext *_localctx = _tracker.createInstance<SeqContext>(_ctx, getState());
  enterRule(_localctx, 72, RedoParser::RuleSeq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(RedoParser::SEQ);
    setState(245);
    match(RedoParser::COLON);
    setState(246);
    seq_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Seq_valueContext ------------------------------------------------------------------

RedoParser::Seq_valueContext::Seq_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Seq_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Seq_valueContext::getRuleIndex() const {
  return RedoParser::RuleSeq_value;
}

void RedoParser::Seq_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSeq_value(this);
}

void RedoParser::Seq_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSeq_value(this);
}

RedoParser::Seq_valueContext* RedoParser::seq_value() {
  Seq_valueContext *_localctx = _tracker.createInstance<Seq_valueContext>(_ctx, getState());
  enterRule(_localctx, 74, RedoParser::RuleSeq_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Layer_opcodeContext ------------------------------------------------------------------

RedoParser::Layer_opcodeContext::Layer_opcodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Layer_opcodeContext::OP() {
  return getToken(RedoParser::OP, 0);
}

RedoParser::LayerContext* RedoParser::Layer_opcodeContext::layer() {
  return getRuleContext<RedoParser::LayerContext>(0);
}

tree::TerminalNode* RedoParser::Layer_opcodeContext::DOT() {
  return getToken(RedoParser::DOT, 0);
}

RedoParser::OpcodeContext* RedoParser::Layer_opcodeContext::opcode() {
  return getRuleContext<RedoParser::OpcodeContext>(0);
}


size_t RedoParser::Layer_opcodeContext::getRuleIndex() const {
  return RedoParser::RuleLayer_opcode;
}

void RedoParser::Layer_opcodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLayer_opcode(this);
}

void RedoParser::Layer_opcodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLayer_opcode(this);
}

RedoParser::Layer_opcodeContext* RedoParser::layer_opcode() {
  Layer_opcodeContext *_localctx = _tracker.createInstance<Layer_opcodeContext>(_ctx, getState());
  enterRule(_localctx, 76, RedoParser::RuleLayer_opcode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(RedoParser::OP);
    setState(251);
    match(RedoParser::COLON);
    setState(252);
    layer();
    setState(253);
    match(RedoParser::DOT);
    setState(254);
    opcode();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LayerContext ------------------------------------------------------------------

RedoParser::LayerContext::LayerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::LayerContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::LayerContext::getRuleIndex() const {
  return RedoParser::RuleLayer;
}

void RedoParser::LayerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLayer(this);
}

void RedoParser::LayerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLayer(this);
}

RedoParser::LayerContext* RedoParser::layer() {
  LayerContext *_localctx = _tracker.createInstance<LayerContext>(_ctx, getState());
  enterRule(_localctx, 78, RedoParser::RuleLayer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpcodeContext ------------------------------------------------------------------

RedoParser::OpcodeContext::OpcodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::OpcodeContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::OpcodeContext::getRuleIndex() const {
  return RedoParser::RuleOpcode;
}

void RedoParser::OpcodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpcode(this);
}

void RedoParser::OpcodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpcode(this);
}

RedoParser::OpcodeContext* RedoParser::opcode() {
  OpcodeContext *_localctx = _tracker.createInstance<OpcodeContext>(_ctx, getState());
  enterRule(_localctx, 80, RedoParser::RuleOpcode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EncContext ------------------------------------------------------------------

RedoParser::EncContext::EncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::EncContext::ENC() {
  return getToken(RedoParser::ENC, 0);
}

RedoParser::Enc_valueContext* RedoParser::EncContext::enc_value() {
  return getRuleContext<RedoParser::Enc_valueContext>(0);
}


size_t RedoParser::EncContext::getRuleIndex() const {
  return RedoParser::RuleEnc;
}

void RedoParser::EncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnc(this);
}

void RedoParser::EncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnc(this);
}

RedoParser::EncContext* RedoParser::enc() {
  EncContext *_localctx = _tracker.createInstance<EncContext>(_ctx, getState());
  enterRule(_localctx, 82, RedoParser::RuleEnc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(RedoParser::ENC);
    setState(261);
    match(RedoParser::COLON);
    setState(262);
    enc_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enc_valueContext ------------------------------------------------------------------

RedoParser::Enc_valueContext::Enc_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Enc_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Enc_valueContext::getRuleIndex() const {
  return RedoParser::RuleEnc_value;
}

void RedoParser::Enc_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnc_value(this);
}

void RedoParser::Enc_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnc_value(this);
}

RedoParser::Enc_valueContext* RedoParser::enc_value() {
  Enc_valueContext *_localctx = _tracker.createInstance<Enc_valueContext>(_ctx, getState());
  enterRule(_localctx, 84, RedoParser::RuleEnc_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RblContext ------------------------------------------------------------------

RedoParser::RblContext::RblContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::RblContext::RBL() {
  return getToken(RedoParser::RBL, 0);
}

RedoParser::Rbl_valueContext* RedoParser::RblContext::rbl_value() {
  return getRuleContext<RedoParser::Rbl_valueContext>(0);
}


size_t RedoParser::RblContext::getRuleIndex() const {
  return RedoParser::RuleRbl;
}

void RedoParser::RblContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRbl(this);
}

void RedoParser::RblContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRbl(this);
}

RedoParser::RblContext* RedoParser::rbl() {
  RblContext *_localctx = _tracker.createInstance<RblContext>(_ctx, getState());
  enterRule(_localctx, 86, RedoParser::RuleRbl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(RedoParser::RBL);
    setState(267);
    match(RedoParser::COLON);
    setState(268);
    rbl_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rbl_valueContext ------------------------------------------------------------------

RedoParser::Rbl_valueContext::Rbl_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RedoParser::Rbl_valueContext::HEX() {
  return getToken(RedoParser::HEX, 0);
}


size_t RedoParser::Rbl_valueContext::getRuleIndex() const {
  return RedoParser::RuleRbl_value;
}

void RedoParser::Rbl_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRbl_value(this);
}

void RedoParser::Rbl_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RedoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRbl_value(this);
}

RedoParser::Rbl_valueContext* RedoParser::rbl_value() {
  Rbl_valueContext *_localctx = _tracker.createInstance<Rbl_valueContext>(_ctx, getState());
  enterRule(_localctx, 88, RedoParser::RuleRbl_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(RedoParser::HEX);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> RedoParser::_decisionToDFA;
atn::PredictionContextCache RedoParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RedoParser::_atn;
std::vector<uint16_t> RedoParser::_serializedATN;

std::vector<std::string> RedoParser::_ruleNames = {
  "redo_file", "redo_info", "redo_record", "change_records", "thread", "thread_number", 
  "rba", "log_file_sequence_number", "log_file_block_number", "byte_offset", 
  "len", "len_value", "vld", "vld_value", "scn", "wrap", "base", "subscn", 
  "subscn_value", "date_value", "change", "invld", "media_recovery_marker", 
  "change_number", "blks", "blks_value", "chg_type", "chg_type_value", "chg_class", 
  "chg_class_value", "chg_afn", "afn_value", "dba", "dba_value", "chg_obj", 
  "obj_value", "seq", "seq_value", "layer_opcode", "layer", "opcode", "enc", 
  "enc_value", "rbl", "rbl_value"
};

std::vector<std::string> RedoParser::_literalNames = {
  "", "'AFN'", "'BEGIN'", "'BCL'", "'BDDBA'", "'BIT'", "'BLKS'", "'BLOCK'", 
  "'BUEXT'", "'BUFFER'", "'BRB'", "'CACHE'", "'CHANGE #'", "'CKIX'", "'CLEANOUT'", 
  "'CLS'", "'CMT'", "'CODE'", "'COL'", "'COMPAT'", "'CTL'", "", "'DBA'", 
  "'DEPENDENCIES'", "'DISABLED'", "'ENC'", "'ENTRIES'", "'EXT'", "'FBI'", 
  "'FLAG'", "'FLG'", "'FLG2'", "'FOLLOW'", "'HDBA'", "'INFO'", "'INVALIDATION'", 
  "'INVLD'", "'ISPAC'", "'ITLI'", "'ITL'", "'KDO'", "'KGL'", "'KQR'", "'KTB'", 
  "'KTUBL'", "'KTUCF'", "'KTUCM'", "'KTDB'", "'KTUDH'", "'LAST'", "'LEN'", 
  "'LOCK'", "'LOGON'", "'LWN'", "'MARKER'", "'MAXFR'", "'MAX'", "'MEDIA'", 
  "'METADATA'", "'NCOL'", "'NNEW'", "'NST'", "'OBJD'", "'OBJECT'", "'OBJN'", 
  "'OBJ'", "'OP'", "'OPT'", "'PADDING'", "'POST'", "'PREV'", "'PXID'", "'RBA'", 
  "'RBL'", "'RCI'", "'RECORD'", "'RECOVERY'", "'REC'", "'REDO'", "'REGULAR'", 
  "'ROW'", "'SCN'", "'SEQ'", "'SIZE'", "'SIZ'", "'SLOT'", "'SLT'", "'SPC'", 
  "'SPLIT'", "'SQN'", "'STANDBY'", "'SUBSCN'", "'TABLESPACE'", "'TABN'", 
  "'TEMP'", "'THREAD'", "'TRANS'", "'TSN'", "'TX'", "'TXN'", "'TYP'", "'UNDO'", 
  "'USER'", "'VLD'", "'VER'", "'XA'", "'XID'", "'XTYPE'", "':'", "'#'", 
  "'-'", "'.'"
};

std::vector<std::string> RedoParser::_symbolicNames = {
  "", "AFN", "BEGIN", "BCL", "BDDBA", "BIT", "BLKS", "BLOCK", "BUEXT", "BUFFER", 
  "BRB", "CACHE", "CHANGE", "CKIX", "CLEANOUT", "CLS", "CMT", "CODE", "COL", 
  "COMPAT", "CTL", "DATE", "DBA", "DEPENDENCIES", "DISABLED", "ENC", "ENTRIES", 
  "EXT", "FBI", "FLAG", "FLG", "FLG2", "FOLLOW", "HDBA", "INFO", "INVALIDATION", 
  "INVLD", "ISPAC", "ITLI", "ITL", "KDO", "KGL", "KQR", "KTB", "KTUBL", 
  "KTUCF", "KTUCM", "KTUDB", "KTUDH", "LAST", "LEN", "LOCK", "LOGON", "LWN", 
  "MARKER", "MAXFR", "MAX", "MEDIA", "METADATA", "NCOL", "NNEW", "NST", 
  "OBJD", "OBJECT", "OBJN", "OBJ", "OP", "OPT", "PADDING", "POST", "PREV", 
  "PXID", "RBA", "RBL", "RCI", "RECORD", "RECOVERY", "REC", "REDO", "REGULAR", 
  "ROW", "SCN", "SEQ", "SIZE", "SIZ", "SLOT", "SLT", "SPC", "SPLIT", "SQN", 
  "STANDBY", "SUBSCN", "TABLESPACE", "TABN", "TEMP", "THREAD", "TRANS", 
  "TSN", "TX", "TXN", "TYP", "UNDO", "USER", "VLD", "VER", "XA", "XID", 
  "XTYPE", "COLON", "POUND", "MINUS", "DOT", "HEX", "SPACES"
};

dfa::Vocabulary RedoParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RedoParser::_tokenNames;

RedoParser::Initializer::Initializer() {
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
    0x3, 0x73, 0x113, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x3, 0x2, 
    0x7, 0x2, 0x5e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x61, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x6, 0x5, 0x74, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x75, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0xc9, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x2, 0x2, 0x2f, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 
    0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x2, 0x2, 0x2, 0xe9, 0x2, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x64, 0x3, 0x2, 0x2, 0x2, 0x6, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x73, 0x3, 0x2, 0x2, 0x2, 0xa, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x7b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x85, 0x3, 0x2, 0x2, 0x2, 0x12, 0x87, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x16, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x91, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x97, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x28, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xca, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0x30, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x32, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x36, 0xd8, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x3e, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x42, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0xee, 0x3, 0x2, 0x2, 0x2, 0x46, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0x4a, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x4c, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x50, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x104, 0x3, 0x2, 0x2, 0x2, 0x54, 0x106, 0x3, 0x2, 
    0x2, 0x2, 0x56, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x10c, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x110, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x5, 0x4, 0x3, 0x2, 
    0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5f, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 
    0x2, 0x2, 0x3, 0x63, 0x3, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x5, 0x6, 
    0x4, 0x2, 0x65, 0x66, 0x5, 0x8, 0x5, 0x2, 0x66, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x68, 0x7, 0x50, 0x2, 0x2, 0x68, 0x69, 0x7, 0x4d, 0x2, 0x2, 
    0x69, 0x6a, 0x7, 0x70, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0xa, 0x6, 0x2, 0x6b, 
    0x6c, 0x5, 0xe, 0x8, 0x2, 0x6c, 0x6d, 0x5, 0x16, 0xc, 0x2, 0x6d, 0x6e, 
    0x5, 0x1a, 0xe, 0x2, 0x6e, 0x6f, 0x5, 0x1e, 0x10, 0x2, 0x6f, 0x70, 0x5, 
    0x24, 0x13, 0x2, 0x70, 0x71, 0x5, 0x28, 0x15, 0x2, 0x71, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x74, 0x5, 0x2a, 0x16, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x9, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x78, 0x7, 0x61, 0x2, 0x2, 0x78, 0x79, 0x7, 0x6e, 0x2, 0x2, 0x79, 0x7a, 
    0x5, 0xc, 0x7, 0x2, 0x7a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 
    0x72, 0x2, 0x2, 0x7c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x4a, 
    0x2, 0x2, 0x7e, 0x7f, 0x7, 0x6e, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x10, 0x9, 
    0x2, 0x80, 0x81, 0x7, 0x71, 0x2, 0x2, 0x81, 0x82, 0x5, 0x12, 0xa, 0x2, 
    0x82, 0x83, 0x7, 0x71, 0x2, 0x2, 0x83, 0x84, 0x5, 0x14, 0xb, 0x2, 0x84, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x72, 0x2, 0x2, 0x86, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x72, 0x2, 0x2, 0x88, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x72, 0x2, 0x2, 0x8a, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x7, 0x34, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x6e, 0x2, 
    0x2, 0x8d, 0x8e, 0x5, 0x18, 0xd, 0x2, 0x8e, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x90, 0x7, 0x72, 0x2, 0x2, 0x90, 0x19, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x92, 0x7, 0x69, 0x2, 0x2, 0x92, 0x93, 0x7, 0x6e, 0x2, 0x2, 0x93, 0x94, 
    0x5, 0x1c, 0xf, 0x2, 0x94, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 
    0x72, 0x2, 0x2, 0x96, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x53, 
    0x2, 0x2, 0x98, 0x99, 0x7, 0x6e, 0x2, 0x2, 0x99, 0x9a, 0x5, 0x20, 0x11, 
    0x2, 0x9a, 0x9b, 0x7, 0x71, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0x22, 0x12, 0x2, 
    0x9c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x72, 0x2, 0x2, 0x9e, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x72, 0x2, 0x2, 0xa0, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x5d, 0x2, 0x2, 0xa2, 0xa3, 0x7, 
    0x6e, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x26, 0x14, 0x2, 0xa4, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa6, 0x7, 0x72, 0x2, 0x2, 0xa6, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa8, 0x7, 0x17, 0x2, 0x2, 0xa8, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xc8, 0x7, 0xe, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x30, 0x19, 0x2, 0xab, 
    0xac, 0x5, 0x36, 0x1c, 0x2, 0xac, 0xad, 0x5, 0x3a, 0x1e, 0x2, 0xad, 
    0xae, 0x5, 0x3e, 0x20, 0x2, 0xae, 0xaf, 0x5, 0x42, 0x22, 0x2, 0xaf, 
    0xb0, 0x5, 0x46, 0x24, 0x2, 0xb0, 0xb1, 0x5, 0x1e, 0x10, 0x2, 0xb1, 
    0xb2, 0x5, 0x4a, 0x26, 0x2, 0xb2, 0xb3, 0x5, 0x4e, 0x28, 0x2, 0xb3, 
    0xb4, 0x5, 0x54, 0x2b, 0x2, 0xb4, 0xb5, 0x5, 0x58, 0x2d, 0x2, 0xb5, 
    0xc9, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x30, 0x19, 0x2, 0xb7, 0xb8, 
    0x5, 0x2e, 0x18, 0x2, 0xb8, 0xb9, 0x5, 0x1e, 0x10, 0x2, 0xb9, 0xba, 
    0x5, 0x4a, 0x26, 0x2, 0xba, 0xbb, 0x5, 0x4e, 0x28, 0x2, 0xbb, 0xbc, 
    0x5, 0x54, 0x2b, 0x2, 0xbc, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x5, 
    0x30, 0x19, 0x2, 0xbe, 0xbf, 0x5, 0x2c, 0x17, 0x2, 0xbf, 0xc0, 0x5, 
    0x3e, 0x20, 0x2, 0xc0, 0xc1, 0x5, 0x42, 0x22, 0x2, 0xc1, 0xc2, 0x5, 
    0x32, 0x1a, 0x2, 0xc2, 0xc3, 0x5, 0x46, 0x24, 0x2, 0xc3, 0xc4, 0x5, 
    0x1e, 0x10, 0x2, 0xc4, 0xc5, 0x5, 0x4a, 0x26, 0x2, 0xc5, 0xc6, 0x5, 
    0x4e, 0x28, 0x2, 0xc6, 0xc7, 0x5, 0x54, 0x2b, 0x2, 0xc7, 0xc9, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xcb, 0x7, 0x26, 0x2, 0x2, 0xcb, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xcd, 0x7, 0x3b, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x4e, 0x2, 0x2, 0xce, 
    0xcf, 0x7, 0x38, 0x2, 0x2, 0xcf, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 
    0x7, 0x72, 0x2, 0x2, 0xd1, 0x31, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 
    0x8, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x6e, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x34, 
    0x1b, 0x2, 0xd5, 0x33, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0x72, 0x2, 
    0x2, 0xd7, 0x35, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x66, 0x2, 0x2, 
    0xd9, 0xda, 0x7, 0x6e, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x38, 0x1d, 0x2, 0xdb, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x72, 0x2, 0x2, 0xdd, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x11, 0x2, 0x2, 0xdf, 0xe0, 0x7, 
    0x6e, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x3c, 0x1f, 0x2, 0xe1, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xe3, 0x7, 0x72, 0x2, 0x2, 0xe3, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0xe4, 0xe5, 0x7, 0x3, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x6e, 0x2, 0x2, 
    0xe6, 0xe7, 0x5, 0x40, 0x21, 0x2, 0xe7, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x7, 0x72, 0x2, 0x2, 0xe9, 0x41, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x18, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x6e, 0x2, 0x2, 0xec, 0xed, 0x5, 
    0x44, 0x23, 0x2, 0xed, 0x43, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x72, 
    0x2, 0x2, 0xef, 0x45, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x43, 0x2, 
    0x2, 0xf1, 0xf2, 0x7, 0x6e, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x48, 0x25, 0x2, 
    0xf3, 0x47, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0x72, 0x2, 0x2, 0xf5, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x54, 0x2, 0x2, 0xf7, 0xf8, 
    0x7, 0x6e, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x4c, 0x27, 0x2, 0xf9, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x72, 0x2, 0x2, 0xfb, 0x4d, 0x3, 0x2, 
    0x2, 0x2, 0xfc, 0xfd, 0x7, 0x44, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x6e, 0x2, 
    0x2, 0xfe, 0xff, 0x5, 0x50, 0x29, 0x2, 0xff, 0x100, 0x7, 0x71, 0x2, 
    0x2, 0x100, 0x101, 0x5, 0x52, 0x2a, 0x2, 0x101, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x102, 0x103, 0x7, 0x72, 0x2, 0x2, 0x103, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x105, 0x7, 0x72, 0x2, 0x2, 0x105, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x1b, 0x2, 0x2, 0x107, 0x108, 0x7, 0x6e, 0x2, 
    0x2, 0x108, 0x109, 0x5, 0x56, 0x2c, 0x2, 0x109, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x10a, 0x10b, 0x7, 0x72, 0x2, 0x2, 0x10b, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x7, 0x4b, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x6e, 0x2, 
    0x2, 0x10e, 0x10f, 0x5, 0x5a, 0x2e, 0x2, 0x10f, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0x111, 0x7, 0x72, 0x2, 0x2, 0x111, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x5, 0x5f, 0x75, 0xc8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RedoParser::Initializer RedoParser::_init;
