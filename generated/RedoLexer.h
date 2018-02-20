
// Generated from RedoLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  RedoLexer : public antlr4::Lexer {
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

  RedoLexer(antlr4::CharStream *input);
  ~RedoLexer();

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

