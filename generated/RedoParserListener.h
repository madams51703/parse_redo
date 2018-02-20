
// Generated from RedoParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "RedoParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RedoParser.
 */
class  RedoParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRedo_file(RedoParser::Redo_fileContext *ctx) = 0;
  virtual void exitRedo_file(RedoParser::Redo_fileContext *ctx) = 0;

  virtual void enterRedo_info(RedoParser::Redo_infoContext *ctx) = 0;
  virtual void exitRedo_info(RedoParser::Redo_infoContext *ctx) = 0;

  virtual void enterRedo_record(RedoParser::Redo_recordContext *ctx) = 0;
  virtual void exitRedo_record(RedoParser::Redo_recordContext *ctx) = 0;

  virtual void enterChange_records(RedoParser::Change_recordsContext *ctx) = 0;
  virtual void exitChange_records(RedoParser::Change_recordsContext *ctx) = 0;

  virtual void enterThread(RedoParser::ThreadContext *ctx) = 0;
  virtual void exitThread(RedoParser::ThreadContext *ctx) = 0;

  virtual void enterThread_number(RedoParser::Thread_numberContext *ctx) = 0;
  virtual void exitThread_number(RedoParser::Thread_numberContext *ctx) = 0;

  virtual void enterRba(RedoParser::RbaContext *ctx) = 0;
  virtual void exitRba(RedoParser::RbaContext *ctx) = 0;

  virtual void enterLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext *ctx) = 0;
  virtual void exitLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext *ctx) = 0;

  virtual void enterLog_file_block_number(RedoParser::Log_file_block_numberContext *ctx) = 0;
  virtual void exitLog_file_block_number(RedoParser::Log_file_block_numberContext *ctx) = 0;

  virtual void enterByte_offset(RedoParser::Byte_offsetContext *ctx) = 0;
  virtual void exitByte_offset(RedoParser::Byte_offsetContext *ctx) = 0;

  virtual void enterLen(RedoParser::LenContext *ctx) = 0;
  virtual void exitLen(RedoParser::LenContext *ctx) = 0;

  virtual void enterLen_value(RedoParser::Len_valueContext *ctx) = 0;
  virtual void exitLen_value(RedoParser::Len_valueContext *ctx) = 0;

  virtual void enterVld(RedoParser::VldContext *ctx) = 0;
  virtual void exitVld(RedoParser::VldContext *ctx) = 0;

  virtual void enterVld_value(RedoParser::Vld_valueContext *ctx) = 0;
  virtual void exitVld_value(RedoParser::Vld_valueContext *ctx) = 0;

  virtual void enterScn(RedoParser::ScnContext *ctx) = 0;
  virtual void exitScn(RedoParser::ScnContext *ctx) = 0;

  virtual void enterWrap(RedoParser::WrapContext *ctx) = 0;
  virtual void exitWrap(RedoParser::WrapContext *ctx) = 0;

  virtual void enterBase(RedoParser::BaseContext *ctx) = 0;
  virtual void exitBase(RedoParser::BaseContext *ctx) = 0;

  virtual void enterSubscn(RedoParser::SubscnContext *ctx) = 0;
  virtual void exitSubscn(RedoParser::SubscnContext *ctx) = 0;

  virtual void enterSubscn_value(RedoParser::Subscn_valueContext *ctx) = 0;
  virtual void exitSubscn_value(RedoParser::Subscn_valueContext *ctx) = 0;

  virtual void enterDate_value(RedoParser::Date_valueContext *ctx) = 0;
  virtual void exitDate_value(RedoParser::Date_valueContext *ctx) = 0;

  virtual void enterChange(RedoParser::ChangeContext *ctx) = 0;
  virtual void exitChange(RedoParser::ChangeContext *ctx) = 0;

  virtual void enterInvld(RedoParser::InvldContext *ctx) = 0;
  virtual void exitInvld(RedoParser::InvldContext *ctx) = 0;

  virtual void enterMedia_recovery_marker(RedoParser::Media_recovery_markerContext *ctx) = 0;
  virtual void exitMedia_recovery_marker(RedoParser::Media_recovery_markerContext *ctx) = 0;

  virtual void enterChange_number(RedoParser::Change_numberContext *ctx) = 0;
  virtual void exitChange_number(RedoParser::Change_numberContext *ctx) = 0;

  virtual void enterBlks(RedoParser::BlksContext *ctx) = 0;
  virtual void exitBlks(RedoParser::BlksContext *ctx) = 0;

  virtual void enterBlks_value(RedoParser::Blks_valueContext *ctx) = 0;
  virtual void exitBlks_value(RedoParser::Blks_valueContext *ctx) = 0;

  virtual void enterChg_type(RedoParser::Chg_typeContext *ctx) = 0;
  virtual void exitChg_type(RedoParser::Chg_typeContext *ctx) = 0;

  virtual void enterChg_type_value(RedoParser::Chg_type_valueContext *ctx) = 0;
  virtual void exitChg_type_value(RedoParser::Chg_type_valueContext *ctx) = 0;

  virtual void enterChg_class(RedoParser::Chg_classContext *ctx) = 0;
  virtual void exitChg_class(RedoParser::Chg_classContext *ctx) = 0;

  virtual void enterChg_class_value(RedoParser::Chg_class_valueContext *ctx) = 0;
  virtual void exitChg_class_value(RedoParser::Chg_class_valueContext *ctx) = 0;

  virtual void enterChg_afn(RedoParser::Chg_afnContext *ctx) = 0;
  virtual void exitChg_afn(RedoParser::Chg_afnContext *ctx) = 0;

  virtual void enterAfn_value(RedoParser::Afn_valueContext *ctx) = 0;
  virtual void exitAfn_value(RedoParser::Afn_valueContext *ctx) = 0;

  virtual void enterDba(RedoParser::DbaContext *ctx) = 0;
  virtual void exitDba(RedoParser::DbaContext *ctx) = 0;

  virtual void enterDba_value(RedoParser::Dba_valueContext *ctx) = 0;
  virtual void exitDba_value(RedoParser::Dba_valueContext *ctx) = 0;

  virtual void enterChg_obj(RedoParser::Chg_objContext *ctx) = 0;
  virtual void exitChg_obj(RedoParser::Chg_objContext *ctx) = 0;

  virtual void enterObj_value(RedoParser::Obj_valueContext *ctx) = 0;
  virtual void exitObj_value(RedoParser::Obj_valueContext *ctx) = 0;

  virtual void enterSeq(RedoParser::SeqContext *ctx) = 0;
  virtual void exitSeq(RedoParser::SeqContext *ctx) = 0;

  virtual void enterSeq_value(RedoParser::Seq_valueContext *ctx) = 0;
  virtual void exitSeq_value(RedoParser::Seq_valueContext *ctx) = 0;

  virtual void enterLayer_opcode(RedoParser::Layer_opcodeContext *ctx) = 0;
  virtual void exitLayer_opcode(RedoParser::Layer_opcodeContext *ctx) = 0;

  virtual void enterLayer(RedoParser::LayerContext *ctx) = 0;
  virtual void exitLayer(RedoParser::LayerContext *ctx) = 0;

  virtual void enterOpcode(RedoParser::OpcodeContext *ctx) = 0;
  virtual void exitOpcode(RedoParser::OpcodeContext *ctx) = 0;

  virtual void enterEnc(RedoParser::EncContext *ctx) = 0;
  virtual void exitEnc(RedoParser::EncContext *ctx) = 0;

  virtual void enterEnc_value(RedoParser::Enc_valueContext *ctx) = 0;
  virtual void exitEnc_value(RedoParser::Enc_valueContext *ctx) = 0;

  virtual void enterRbl(RedoParser::RblContext *ctx) = 0;
  virtual void exitRbl(RedoParser::RblContext *ctx) = 0;

  virtual void enterRbl_value(RedoParser::Rbl_valueContext *ctx) = 0;
  virtual void exitRbl_value(RedoParser::Rbl_valueContext *ctx) = 0;


};

