
// Generated from RedoParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  RedoParser : public antlr4::Parser {
public:
  enum {
    AFN = 1, BEGIN = 2, BCL = 3, BDDBA = 4, BIT = 5, BLKS = 6, BLOCK = 7, 
    BUEXT = 8, BUFFER = 9, BRB = 10, CACHE = 11, CHANGE = 12, CKIX = 13, 
    CLEANOUT = 14, CLS = 15, CMT = 16, CODE = 17, COL = 18, COMPAT = 19, 
    CTL = 20, DATE = 21, DBA = 22, DEPENDENCIES = 23, DISABLED = 24, ENC = 25, 
    ENTRIES = 26, EXT = 27, FBI = 28, FLAG = 29, FLG = 30, FLG2 = 31, FOLLOW = 32, 
    HDBA = 33, INFO = 34, INVALIDATION = 35, INVLD = 36, ISPAC = 37, ITLI = 38, 
    ITL = 39, KDO = 40, KGL = 41, KQR = 42, KTB = 43, KTUBL = 44, KTUCF = 45, 
    KTUCM = 46, KTUDB = 47, KTUDH = 48, LAST = 49, LEN = 50, LOCK = 51, 
    LOGON = 52, LWN = 53, MARKER = 54, MAXFR = 55, MAX = 56, MEDIA = 57, 
    METADATA = 58, NCOL = 59, NNEW = 60, NST = 61, OBJD = 62, OBJECT = 63, 
    OBJN = 64, OBJ = 65, OP = 66, OPT = 67, PADDING = 68, POST = 69, PREV = 70, 
    PXID = 71, RBA = 72, RBL = 73, RCI = 74, RECORD = 75, RECOVERY = 76, 
    REC = 77, REDO = 78, REGULAR = 79, ROW = 80, SCN = 81, SEQ = 82, SIZE = 83, 
    SIZ = 84, SLOT = 85, SLT = 86, SPC = 87, SPLIT = 88, SQN = 89, STANDBY = 90, 
    SUBSCN = 91, TABLESPACE = 92, TABN = 93, TEMP = 94, THREAD = 95, TRANS = 96, 
    TSN = 97, TX = 98, TXN = 99, TYP = 100, UNDO = 101, USER = 102, VLD = 103, 
    VER = 104, XA = 105, XID = 106, XTYPE = 107, COLON = 108, POUND = 109, 
    MINUS = 110, DOT = 111, HEX = 112, SPACES = 113
  };

  enum {
    RuleRedo_file = 0, RuleRedo_info = 1, RuleRedo_record = 2, RuleChange_records = 3, 
    RuleThread = 4, RuleThread_number = 5, RuleRba = 6, RuleLog_file_sequence_number = 7, 
    RuleLog_file_block_number = 8, RuleByte_offset = 9, RuleLen = 10, RuleLen_value = 11, 
    RuleVld = 12, RuleVld_value = 13, RuleScn = 14, RuleWrap = 15, RuleBase = 16, 
    RuleSubscn = 17, RuleSubscn_value = 18, RuleDate_value = 19, RuleChange = 20, 
    RuleInvld = 21, RuleMedia_recovery_marker = 22, RuleChange_number = 23, 
    RuleBlks = 24, RuleBlks_value = 25, RuleChg_type = 26, RuleChg_type_value = 27, 
    RuleChg_class = 28, RuleChg_class_value = 29, RuleChg_afn = 30, RuleAfn_value = 31, 
    RuleDba = 32, RuleDba_value = 33, RuleChg_obj = 34, RuleObj_value = 35, 
    RuleSeq = 36, RuleSeq_value = 37, RuleLayer_opcode = 38, RuleLayer = 39, 
    RuleOpcode = 40, RuleEnc = 41, RuleEnc_value = 42, RuleRbl = 43, RuleRbl_value = 44
  };

  RedoParser(antlr4::TokenStream *input);
  ~RedoParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Redo_fileContext;
  class Redo_infoContext;
  class Redo_recordContext;
  class Change_recordsContext;
  class ThreadContext;
  class Thread_numberContext;
  class RbaContext;
  class Log_file_sequence_numberContext;
  class Log_file_block_numberContext;
  class Byte_offsetContext;
  class LenContext;
  class Len_valueContext;
  class VldContext;
  class Vld_valueContext;
  class ScnContext;
  class WrapContext;
  class BaseContext;
  class SubscnContext;
  class Subscn_valueContext;
  class Date_valueContext;
  class ChangeContext;
  class InvldContext;
  class Media_recovery_markerContext;
  class Change_numberContext;
  class BlksContext;
  class Blks_valueContext;
  class Chg_typeContext;
  class Chg_type_valueContext;
  class Chg_classContext;
  class Chg_class_valueContext;
  class Chg_afnContext;
  class Afn_valueContext;
  class DbaContext;
  class Dba_valueContext;
  class Chg_objContext;
  class Obj_valueContext;
  class SeqContext;
  class Seq_valueContext;
  class Layer_opcodeContext;
  class LayerContext;
  class OpcodeContext;
  class EncContext;
  class Enc_valueContext;
  class RblContext;
  class Rbl_valueContext; 

  class  Redo_fileContext : public antlr4::ParserRuleContext {
  public:
    Redo_fileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Redo_infoContext *> redo_info();
    Redo_infoContext* redo_info(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Redo_fileContext* redo_file();

  class  Redo_infoContext : public antlr4::ParserRuleContext {
  public:
    Redo_infoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Redo_recordContext *redo_record();
    Change_recordsContext *change_records();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Redo_infoContext* redo_info();

  class  Redo_recordContext : public antlr4::ParserRuleContext {
  public:
    Redo_recordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REDO();
    antlr4::tree::TerminalNode *RECORD();
    antlr4::tree::TerminalNode *MINUS();
    ThreadContext *thread();
    RbaContext *rba();
    LenContext *len();
    VldContext *vld();
    ScnContext *scn();
    SubscnContext *subscn();
    Date_valueContext *date_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Redo_recordContext* redo_record();

  class  Change_recordsContext : public antlr4::ParserRuleContext {
  public:
    Change_recordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ChangeContext *> change();
    ChangeContext* change(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Change_recordsContext* change_records();

  class  ThreadContext : public antlr4::ParserRuleContext {
  public:
    ThreadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *THREAD();
    Thread_numberContext *thread_number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ThreadContext* thread();

  class  Thread_numberContext : public antlr4::ParserRuleContext {
  public:
    Thread_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Thread_numberContext* thread_number();

  class  RbaContext : public antlr4::ParserRuleContext {
  public:
    RbaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RBA();
    Log_file_sequence_numberContext *log_file_sequence_number();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    Log_file_block_numberContext *log_file_block_number();
    Byte_offsetContext *byte_offset();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RbaContext* rba();

  class  Log_file_sequence_numberContext : public antlr4::ParserRuleContext {
  public:
    Log_file_sequence_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Log_file_sequence_numberContext* log_file_sequence_number();

  class  Log_file_block_numberContext : public antlr4::ParserRuleContext {
  public:
    Log_file_block_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Log_file_block_numberContext* log_file_block_number();

  class  Byte_offsetContext : public antlr4::ParserRuleContext {
  public:
    Byte_offsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Byte_offsetContext* byte_offset();

  class  LenContext : public antlr4::ParserRuleContext {
  public:
    LenContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEN();
    Len_valueContext *len_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LenContext* len();

  class  Len_valueContext : public antlr4::ParserRuleContext {
  public:
    Len_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Len_valueContext* len_value();

  class  VldContext : public antlr4::ParserRuleContext {
  public:
    VldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VLD();
    Vld_valueContext *vld_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VldContext* vld();

  class  Vld_valueContext : public antlr4::ParserRuleContext {
  public:
    Vld_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Vld_valueContext* vld_value();

  class  ScnContext : public antlr4::ParserRuleContext {
  public:
    ScnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCN();
    WrapContext *wrap();
    antlr4::tree::TerminalNode *DOT();
    BaseContext *base();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScnContext* scn();

  class  WrapContext : public antlr4::ParserRuleContext {
  public:
    WrapContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WrapContext* wrap();

  class  BaseContext : public antlr4::ParserRuleContext {
  public:
    BaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BaseContext* base();

  class  SubscnContext : public antlr4::ParserRuleContext {
  public:
    SubscnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SUBSCN();
    Subscn_valueContext *subscn_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubscnContext* subscn();

  class  Subscn_valueContext : public antlr4::ParserRuleContext {
  public:
    Subscn_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Subscn_valueContext* subscn_value();

  class  Date_valueContext : public antlr4::ParserRuleContext {
  public:
    Date_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Date_valueContext* date_value();

  class  ChangeContext : public antlr4::ParserRuleContext {
  public:
    ChangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHANGE();
    Change_numberContext *change_number();
    Chg_typeContext *chg_type();
    Chg_classContext *chg_class();
    Chg_afnContext *chg_afn();
    DbaContext *dba();
    Chg_objContext *chg_obj();
    ScnContext *scn();
    SeqContext *seq();
    Layer_opcodeContext *layer_opcode();
    EncContext *enc();
    RblContext *rbl();
    Media_recovery_markerContext *media_recovery_marker();
    InvldContext *invld();
    BlksContext *blks();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ChangeContext* change();

  class  InvldContext : public antlr4::ParserRuleContext {
  public:
    InvldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INVLD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InvldContext* invld();

  class  Media_recovery_markerContext : public antlr4::ParserRuleContext {
  public:
    Media_recovery_markerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MEDIA();
    antlr4::tree::TerminalNode *RECOVERY();
    antlr4::tree::TerminalNode *MARKER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Media_recovery_markerContext* media_recovery_marker();

  class  Change_numberContext : public antlr4::ParserRuleContext {
  public:
    Change_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Change_numberContext* change_number();

  class  BlksContext : public antlr4::ParserRuleContext {
  public:
    BlksContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BLKS();
    Blks_valueContext *blks_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlksContext* blks();

  class  Blks_valueContext : public antlr4::ParserRuleContext {
  public:
    Blks_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Blks_valueContext* blks_value();

  class  Chg_typeContext : public antlr4::ParserRuleContext {
  public:
    Chg_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYP();
    Chg_type_valueContext *chg_type_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_typeContext* chg_type();

  class  Chg_type_valueContext : public antlr4::ParserRuleContext {
  public:
    Chg_type_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_type_valueContext* chg_type_value();

  class  Chg_classContext : public antlr4::ParserRuleContext {
  public:
    Chg_classContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLS();
    Chg_class_valueContext *chg_class_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_classContext* chg_class();

  class  Chg_class_valueContext : public antlr4::ParserRuleContext {
  public:
    Chg_class_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_class_valueContext* chg_class_value();

  class  Chg_afnContext : public antlr4::ParserRuleContext {
  public:
    Chg_afnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AFN();
    Afn_valueContext *afn_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_afnContext* chg_afn();

  class  Afn_valueContext : public antlr4::ParserRuleContext {
  public:
    Afn_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Afn_valueContext* afn_value();

  class  DbaContext : public antlr4::ParserRuleContext {
  public:
    DbaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DBA();
    Dba_valueContext *dba_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DbaContext* dba();

  class  Dba_valueContext : public antlr4::ParserRuleContext {
  public:
    Dba_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Dba_valueContext* dba_value();

  class  Chg_objContext : public antlr4::ParserRuleContext {
  public:
    Chg_objContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJ();
    Obj_valueContext *obj_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Chg_objContext* chg_obj();

  class  Obj_valueContext : public antlr4::ParserRuleContext {
  public:
    Obj_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Obj_valueContext* obj_value();

  class  SeqContext : public antlr4::ParserRuleContext {
  public:
    SeqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEQ();
    Seq_valueContext *seq_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SeqContext* seq();

  class  Seq_valueContext : public antlr4::ParserRuleContext {
  public:
    Seq_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Seq_valueContext* seq_value();

  class  Layer_opcodeContext : public antlr4::ParserRuleContext {
  public:
    Layer_opcodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OP();
    LayerContext *layer();
    antlr4::tree::TerminalNode *DOT();
    OpcodeContext *opcode();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Layer_opcodeContext* layer_opcode();

  class  LayerContext : public antlr4::ParserRuleContext {
  public:
    LayerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LayerContext* layer();

  class  OpcodeContext : public antlr4::ParserRuleContext {
  public:
    OpcodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OpcodeContext* opcode();

  class  EncContext : public antlr4::ParserRuleContext {
  public:
    EncContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENC();
    Enc_valueContext *enc_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EncContext* enc();

  class  Enc_valueContext : public antlr4::ParserRuleContext {
  public:
    Enc_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Enc_valueContext* enc_value();

  class  RblContext : public antlr4::ParserRuleContext {
  public:
    RblContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RBL();
    Rbl_valueContext *rbl_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RblContext* rbl();

  class  Rbl_valueContext : public antlr4::ParserRuleContext {
  public:
    Rbl_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rbl_valueContext* rbl_value();


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

