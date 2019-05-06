parser grammar RedoParser;

options { tokenVocab=RedoLexer; }


redo_file
    : redo_record_info* EOF
    ;

redo_record_info
    : redo_record change_records+ 
    ;

redo_info
    :
      ktelk_redo
    | ktecush_redo
    | ktucm_redo
    | ktudb_redo
    | ktudh_redo
    | ktudbu_redo
    ;

redo_record
    : REDO RECORD MINUS thread rba len vld con_uid? scn subscn date_value
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
    : SCN ':' wrap (DOT base)?
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
    : CHANGE  ( change_number con_id? chg_type chg_class chg_afn dba chg_obj 
                               scn seq layer_opcode enc rbl flg? redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo? ktsfrblnk_redo? ktsfrbfmt_redo?
              | change_number media_recovery_marker con_id? scn seq layer_opcode enc flg? xid?
              | change_number con_id? invld chg_afn dba blks chg_obj scn seq layer_opcode enc redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo?  ktsfrblnk_redo? ktsfrbfmt_redo?
              )
    ;

ktsfrbfmt_redo
    : KTSFRBFMT REDO ':' segobjd type itls cscn
    ;

cscn
    : CSCN ':' cscn_value
    ;

cscn_value
    : HEX 
    ;

itls
    : ITLS ':' itls_value
    ;
 
itls_value
    : HEX
    ;

type
    : TYPE ':' type_value
    ;

type_value
    : HEX
    ;

segobjd
    : SEGOBJD ':' segobjd_value
    ;

segobjd_value
    : HEX
    ;


ktsfrblnk_redo
    : KTSFRBLNK REDO ':' OPCODE ':' ktsfrblnk_redo_opcode
    ;

ktsfrblnk_redo_opcode
    : LWRT
    | LSET
    ;
 
ktucm_redo
    : KTUCM REDO ':' slt sqn srt sta flg ktucf_redo?
    ;

ktucf_redo
    : KTUCF REDO ':' uba ext spc fbi
    ;

ext
    : EXT ':' ext_value
    ;

ext_value
    : HEX
    ;

uba
    : UBA ':' uba_value
    ;

uba_value
    : HEX '.' HEX '.' HEX
    ;

sta
    : STA ':' sta_value
    ;

sta_value
    : HEX
    ;

srt
   : SRT ':' srt_value
   ;

srt_value
   : HEX
   ;

ktecush_redo
    : KTECUSH REDO ':' CLEAR EXTENT CONTROL LOCK
    ;    

ktsfrgrp_redo
    : KTSFRGRP LPAREN FGB FSLASH SHDR MODIFY FREELIST RPAREN REDO ':'
    ;

ktubl_redo
   : KTUBL REDO ':' slt rci opc LSQUARE objn objd tsn RSQUARE
   ;

ktubu_redo
   : KTUBU REDO ':' slt rci opc objn objd tsn 
   ;

ktelk_redo
   : KTELK REDO ':' xid
   ; 

ktudb_redo
   : KTUDB REDO ':' siz spc flg seq rec
   ;

ktudbu_redo
    : KTUDBU REDO ':' slt rci opc objn objd tsn
    ;

objn
    : OBJN ':' objn_value
    ;

objn_value
    : HEX
    ;

objd
   : OBJD ':' objd_value
   ;

objd_value
   : HEX
   ;

tsn
   : TSN ':' tsn_value
   ;

tsn_value
   : HEX
   ;


opc
    : OPC ':'  opc_value
    ;

opc_value
    : HEX '.' HEX
    ;


ktudh_redo
    : KTUDH REDO ':' slt sqn flg siz fbi
    ;

fbi
   : FBI ':' fbi_value
   ;

fbi_value
   : HEX
   ;

siz
    : SIZ ':' siz_value
    ;

siz_value
    : HEX
    ;

sqn
    : SQN ':' sqn_value
    ;

sqn_value
    : HEX
    ;


spc
    : SPC ':' spc_value
    ;

spc_value
    : HEX
    ;

rec
    : REC ':' rec_value
    ;

rec_value
    : HEX
    ;    

rci
    : RCI ':' rci_value
    ;

rci_value
    : HEX
    ;


slt
   : SLT ':' slt_value
   ;

slt_value
   :  HEX
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

xid
    : XID ':' xid_value
    ;

xid_value
    : HEX '.' HEX '.' HEX
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

flg
    : FLG ':' flg_value
    ;

flg_value
    : HEX
    ;

con_id
    : CON_ID ':' con_id_value
    ;

con_id_value
    : HEX
    ;

con_uid
    : CON_UID ':' con_uid_value
    ;

con_uid_value
    : HEX
    ;

