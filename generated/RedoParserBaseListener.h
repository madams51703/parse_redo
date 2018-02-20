
// Generated from RedoParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "RedoParserListener.h"


/**
 * This class provides an empty implementation of RedoParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RedoParserBaseListener : public RedoParserListener {
public:

  virtual void enterRedo_file(RedoParser::Redo_fileContext * /*ctx*/) override { }
  virtual void exitRedo_file(RedoParser::Redo_fileContext * /*ctx*/) override { }

  virtual void enterRedo_info(RedoParser::Redo_infoContext * /*ctx*/) override { }
  virtual void exitRedo_info(RedoParser::Redo_infoContext * /*ctx*/) override { }

  virtual void enterRedo_record(RedoParser::Redo_recordContext * /*ctx*/) override { }
  virtual void exitRedo_record(RedoParser::Redo_recordContext * /*ctx*/) override { }

  virtual void enterChange_records(RedoParser::Change_recordsContext * /*ctx*/) override { }
  virtual void exitChange_records(RedoParser::Change_recordsContext * /*ctx*/) override { }

  virtual void enterThread(RedoParser::ThreadContext * /*ctx*/) override { }
  virtual void exitThread(RedoParser::ThreadContext * /*ctx*/) override { }

  virtual void enterThread_number(RedoParser::Thread_numberContext * /*ctx*/) override { }
  virtual void exitThread_number(RedoParser::Thread_numberContext * /*ctx*/) override { }

  virtual void enterRba(RedoParser::RbaContext * /*ctx*/) override { }
  virtual void exitRba(RedoParser::RbaContext * /*ctx*/) override { }

  virtual void enterLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext * /*ctx*/) override { }
  virtual void exitLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext * /*ctx*/) override { }

  virtual void enterLog_file_block_number(RedoParser::Log_file_block_numberContext * /*ctx*/) override { }
  virtual void exitLog_file_block_number(RedoParser::Log_file_block_numberContext * /*ctx*/) override { }

  virtual void enterByte_offset(RedoParser::Byte_offsetContext * /*ctx*/) override { }
  virtual void exitByte_offset(RedoParser::Byte_offsetContext * /*ctx*/) override { }

  virtual void enterLen(RedoParser::LenContext * /*ctx*/) override { }
  virtual void exitLen(RedoParser::LenContext * /*ctx*/) override { }

  virtual void enterLen_value(RedoParser::Len_valueContext * /*ctx*/) override { }
  virtual void exitLen_value(RedoParser::Len_valueContext * /*ctx*/) override { }

  virtual void enterVld(RedoParser::VldContext * /*ctx*/) override { }
  virtual void exitVld(RedoParser::VldContext * /*ctx*/) override { }

  virtual void enterVld_value(RedoParser::Vld_valueContext * /*ctx*/) override { }
  virtual void exitVld_value(RedoParser::Vld_valueContext * /*ctx*/) override { }

  virtual void enterScn(RedoParser::ScnContext * /*ctx*/) override { }
  virtual void exitScn(RedoParser::ScnContext * /*ctx*/) override { }

  virtual void enterWrap(RedoParser::WrapContext * /*ctx*/) override { }
  virtual void exitWrap(RedoParser::WrapContext * /*ctx*/) override { }

  virtual void enterBase(RedoParser::BaseContext * /*ctx*/) override { }
  virtual void exitBase(RedoParser::BaseContext * /*ctx*/) override { }

  virtual void enterSubscn(RedoParser::SubscnContext * /*ctx*/) override { }
  virtual void exitSubscn(RedoParser::SubscnContext * /*ctx*/) override { }

  virtual void enterSubscn_value(RedoParser::Subscn_valueContext * /*ctx*/) override { }
  virtual void exitSubscn_value(RedoParser::Subscn_valueContext * /*ctx*/) override { }

  virtual void enterDate_value(RedoParser::Date_valueContext * /*ctx*/) override { }
  virtual void exitDate_value(RedoParser::Date_valueContext * /*ctx*/) override { }

  virtual void enterChange(RedoParser::ChangeContext * /*ctx*/) override { }
  virtual void exitChange(RedoParser::ChangeContext * /*ctx*/) override { }

  virtual void enterInvld(RedoParser::InvldContext * /*ctx*/) override { }
  virtual void exitInvld(RedoParser::InvldContext * /*ctx*/) override { }

  virtual void enterMedia_recovery_marker(RedoParser::Media_recovery_markerContext * /*ctx*/) override { }
  virtual void exitMedia_recovery_marker(RedoParser::Media_recovery_markerContext * /*ctx*/) override { }

  virtual void enterChange_number(RedoParser::Change_numberContext * /*ctx*/) override { }
  virtual void exitChange_number(RedoParser::Change_numberContext * /*ctx*/) override { }

  virtual void enterBlks(RedoParser::BlksContext * /*ctx*/) override { }
  virtual void exitBlks(RedoParser::BlksContext * /*ctx*/) override { }

  virtual void enterBlks_value(RedoParser::Blks_valueContext * /*ctx*/) override { }
  virtual void exitBlks_value(RedoParser::Blks_valueContext * /*ctx*/) override { }

  virtual void enterChg_type(RedoParser::Chg_typeContext * /*ctx*/) override { }
  virtual void exitChg_type(RedoParser::Chg_typeContext * /*ctx*/) override { }

  virtual void enterChg_type_value(RedoParser::Chg_type_valueContext * /*ctx*/) override { }
  virtual void exitChg_type_value(RedoParser::Chg_type_valueContext * /*ctx*/) override { }

  virtual void enterChg_class(RedoParser::Chg_classContext * /*ctx*/) override { }
  virtual void exitChg_class(RedoParser::Chg_classContext * /*ctx*/) override { }

  virtual void enterChg_class_value(RedoParser::Chg_class_valueContext * /*ctx*/) override { }
  virtual void exitChg_class_value(RedoParser::Chg_class_valueContext * /*ctx*/) override { }

  virtual void enterChg_afn(RedoParser::Chg_afnContext * /*ctx*/) override { }
  virtual void exitChg_afn(RedoParser::Chg_afnContext * /*ctx*/) override { }

  virtual void enterAfn_value(RedoParser::Afn_valueContext * /*ctx*/) override { }
  virtual void exitAfn_value(RedoParser::Afn_valueContext * /*ctx*/) override { }

  virtual void enterDba(RedoParser::DbaContext * /*ctx*/) override { }
  virtual void exitDba(RedoParser::DbaContext * /*ctx*/) override { }

  virtual void enterDba_value(RedoParser::Dba_valueContext * /*ctx*/) override { }
  virtual void exitDba_value(RedoParser::Dba_valueContext * /*ctx*/) override { }

  virtual void enterChg_obj(RedoParser::Chg_objContext * /*ctx*/) override { }
  virtual void exitChg_obj(RedoParser::Chg_objContext * /*ctx*/) override { }

  virtual void enterObj_value(RedoParser::Obj_valueContext * /*ctx*/) override { }
  virtual void exitObj_value(RedoParser::Obj_valueContext * /*ctx*/) override { }

  virtual void enterSeq(RedoParser::SeqContext * /*ctx*/) override { }
  virtual void exitSeq(RedoParser::SeqContext * /*ctx*/) override { }

  virtual void enterSeq_value(RedoParser::Seq_valueContext * /*ctx*/) override { }
  virtual void exitSeq_value(RedoParser::Seq_valueContext * /*ctx*/) override { }

  virtual void enterLayer_opcode(RedoParser::Layer_opcodeContext * /*ctx*/) override { }
  virtual void exitLayer_opcode(RedoParser::Layer_opcodeContext * /*ctx*/) override { }

  virtual void enterLayer(RedoParser::LayerContext * /*ctx*/) override { }
  virtual void exitLayer(RedoParser::LayerContext * /*ctx*/) override { }

  virtual void enterOpcode(RedoParser::OpcodeContext * /*ctx*/) override { }
  virtual void exitOpcode(RedoParser::OpcodeContext * /*ctx*/) override { }

  virtual void enterEnc(RedoParser::EncContext * /*ctx*/) override { }
  virtual void exitEnc(RedoParser::EncContext * /*ctx*/) override { }

  virtual void enterEnc_value(RedoParser::Enc_valueContext * /*ctx*/) override { }
  virtual void exitEnc_value(RedoParser::Enc_valueContext * /*ctx*/) override { }

  virtual void enterRbl(RedoParser::RblContext * /*ctx*/) override { }
  virtual void exitRbl(RedoParser::RblContext * /*ctx*/) override { }

  virtual void enterRbl_value(RedoParser::Rbl_valueContext * /*ctx*/) override { }
  virtual void exitRbl_value(RedoParser::Rbl_valueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

