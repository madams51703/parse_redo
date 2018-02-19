parser grammar RedoParser;

options { tokenVocab=RedoLexer; }


redo_file
    : redo_info* EOF
    ;

redo_info
    : redo_record change_records
    ;

redo_record
    : REDO RECORD MINUS thread rba len vld scn subscn date_value
    ;

change_records
    : change+
    ;

thread
    : THREAD ':' thread_number
    ;

thread_number
    : HEX
    ;

rba
    : RBA ':' log_file_sequence_number DOT log_file_block_number DOT byte_offset
    ;

log_file_sequence_number
    : HEX
    ;

log_file_block_number
    : HEX
    ;

byte_offset
    : HEX
    ;

len
    : LEN ':' len_value
    ;

len_value
    : HEX
    ;

vld
    : VLD ':' vld_value
    ;

vld_value
    : HEX
    ;

scn
    : SCN ':' wrap DOT base
    ;

wrap
    : HEX
    ;

base
    : HEX
    ;

subscn
    : SUBSCN ':' subscn_value
    ;

subscn_value
    : HEX
    ;

date_value
    : DATE
    ;

change
    : CHANGE  ( change_number chg_type chg_class chg_afn dba chg_obj 
                               scn seq layer_opcode enc rbl
              | change_number media_recovery_marker scn seq layer_opcode enc
              | change_number invld chg_afn dba blks chg_obj scn seq layer_opcode enc
              )
    ;

invld
   : INVLD
   ;

media_recovery_marker
    : MEDIA RECOVERY MARKER
    ;
change_number
    : HEX
    ;

blks
    : BLKS ':' blks_value
    ;

blks_value
    : HEX
    ;

chg_type
    : TYP ':' chg_type_value
    ;

chg_type_value
    : HEX
    ;

chg_class
    : CLS ':' chg_class_value
    ;

chg_class_value
    : HEX
    ;

chg_afn
    : AFN ':' afn_value
    ;

afn_value
    : HEX
    ;

dba
    : DBA ':' dba_value
    ;

dba_value
    : HEX
    ;

chg_obj
    : OBJ ':' obj_value
    ;

obj_value
    : HEX
    ;

seq
    : SEQ ':' seq_value
    ;

seq_value
    : HEX
    ;

layer_opcode
    : OP ':' layer DOT opcode
    ;

layer
    : HEX
    ;

opcode
    : HEX
    ;

enc
    : ENC ':' enc_value
    ;

enc_value
    : HEX
    ;

rbl
    : RBL ':' rbl_value
    ;

rbl_value
    : HEX
    ;


