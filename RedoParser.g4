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
    | ktsbifm_redo
    | ktudbr_redo
    ;

redo_record
    : REDO RECORD MINUS thread rba len vld con_uid? scn subscn date_value lwn_info?
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

lwn_info
    : '(' LWN rba len nst scn ')'
    ;

nst
    : NST ':' nst_value
    ;

nst_value
    : HEX
    ;

chg_prefix_exists
    : PREFIX EXISTS ON BLOCK COMMA SNO COLON HEX len
    ;
change
    : lfdba? chg_prefix_exists?  CHANGE  (  change_number con_id? chg_type chg_class chg_afn dba chg_obj scn seq layer_opcode enc rbl flg? redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo? ktsfrblnk_redo? ktust_redo? ktsfrbfmt_redo? ktsfm_redo? undo_info? begin_trans? buext_info? kdo_undo_info? ktb_redo_info? block_cleanout_record? column_info?
              |  change_number media_recovery_marker con_id? scn seq layer_opcode enc flg? xid? datafile_resize_marker?
              |  change_number con_id? invld chg_afn dba blks chg_obj scn seq layer_opcode enc redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo?  ktsfrblnk_redo? ktsfrbfmt_redo? ktsfm_redo? block_cleanout_record? column_info?
              )
    ;

ktudbr_redo
    :  KTUDBR REDO ':'  DISABLE BLOCK LEVEL RECO ON xid
    ;

ktsbifm_redo
    :KTSBIFM REDO ':' JUST A MARKER
    ; 

ktust_redo
    : KTUST REDO ':' slt sqn sta cfl
    ;


ktsfrbfmt_redo
    : KTSFRBFMT REDO ':' segobjd type itls cscn
    ;

cfl
    : CFL ':' cfl_value
    ;

cfl_value
    : HEX
    ;


cscn
    : CSCN ':' cscn_value
    ;

cscn_value
    : HEX '.'? HEX?
    ;

itls
    : ITLS ':' itls_value
    ;
 
itls_value
    : HEX
    ;

itl
    : ITL ':' itl_value?
    ;

itl_value
    : HEX
    ;

typ
    : TYP ':' typ_value
    ;

typ_value
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

ktsfm_redo
    : KTSFM REDO ':' dba tsn obj typ nfl
    ;

nfl
    : NFL ':' nfl_value
    ;

nfl_value
    : HEX
    ;

ktsfrblnk_redo
    : KTSFRBLNK REDO ':' OPCODE ':' ktsfrblnk_redo_opcode
    ;

ktsfrblnk_redo_opcode
    : LWRT
    | LSET
    | LCLR
    ;
 
ktucm_redo
    : KTUCM REDO ':' slt sqn srt sta flg ktucf_redo?
    | KTUCM REDO ':' slt sqn srt sta flg scn
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
   | KTUBL REDO ':' slt wrp flg prev_dba rci opc '[' objn objd tsn ']'
   ;

ktubu_redo
   : KTUBU REDO ':' slt rci opc objn objd tsn 
   | KTUBU REDO ':' slt wrp flg prev_dba rci opc '[' objn objd tsn ']'
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

undo_info
    : undo_type user_undo_done? last_buffer_split temp_object tablespace_undo user_only?
    ;

undo_type
    : '['? UNDO TYPE ']'? regular_undo    
    ;

begin_trans
    : BEGIN TRANS begin_trans_info
    ;

begin_trans_info
    : prev_ctl_uba prev_ctl_max_cmt_scn prev_tx_cmt_scn txn_start_scn logon_user prev_brb prev_bcl
    ;

regular_undo
    : REGULAR UNDO
    ;


user_undo_done
    : '[' USER UNDO DONE ']'? NO
    | '[' USER UNDO DONE ']'? YES
    ;

user_only
    : '['? USER ONLY ']'? NO
    | '['? USER ONLY ']'? YES
    ;


last_buffer_split
    : '[' LAST BUFFER SPLIT ']'? ':'?  last_buffer_split_value
    ;

last_buffer_split_value
    : YES
    | NO
    ;

temp_object
    : '['? TEMP OBJECT ']'?  temp_object_value
    ;


temp_object_value
    : YES
    | NO
    ;

tablespace_undo
    : '['? TABLESPACE UNDO ']'? tablespace_undo_value
    ;

tablespace_undo_value
    : YES
    | NO
    ;




object_uba
    : HEX prev_ctl_uba
    ;

prev_ctl_uba
    : PREV CTL uba
    ;

prev_ctl_max_cmt_scn
    : PREV CTL MAX CMT scn
    ;


prev_tx_cmt_scn
    : PREV TX CMT scn
    ;

txn_start_scn
    : TXN START scn
    ;

logon_user
    : LOGON USER ':' HEX
    ;

prev_brb
    : PREV BRB ':' HEX
    ;


prev_bcl
    : PREV BCL ':' HEX
    ;

buext_info
    : buext_idx flg2
    ;

buext_idx
    : BUEXT IDX ':' HEX
    ;

flg2
    : FLG2 ':' HEX
    ;

col_info
    : COL HEX ':' col_values
    ;

col_values
    : NULL_COLUMN_VALUE {std::cout << "FOUND NULL COLUMN\n"; }
    | HEXBYTE+ {std::cout << "found HEXBYTE \n"; }
    ;

kdo_op_code_info
    : kdo_op_code kdo_itli_info  tabn_info ncol_info
    | kdo_op_code kdo_itli_info  tabn_info fb_info nrid
    ;

kdo_itli_info
   : kdo_itli ispac maxfr
   ;

maxfr
   : MAXFR ':' maxfr_value
   ;

maxfr_value
   : HEX
   ;


ispac
   : ISPAC ':' ispac_value
   ;

ispac_value
   : HEX
   ;


tabn_info
   : tabn tabn_slot flag lock ckix
   | tabn tabn_slot size_delt 
   ;

size_delt
   : SIZE '/' DELT ':' size_delt_value
   ;

size_delt_value
   : HEX
   ;

nrid 
   : NRID ':' nrid_value
   ;

nrid_value
   : HEX DOT HEX
   ;
   
fb_info
   : fb lb cc
   ;

fb
   : FB ':' fb_value
   ;

fb_value
   : FB_FLAG_VALUE
   ;

lb
   : LB ':' lb_value
   ;

lb_value
   : HEX
   ;

cc
   : CC ':' cc_value
   ;

cc_value
   : HEX
   ;

tabn
   : TABN ':' tabn_value
   ;

tabn_value
   : HEX
   ;

tabn_slot
   : SLOT ':' tabn_slot_value
   ;

tabn_slot_value
   : HEX '(' HEX ')'
   ;

flag
   : FLAG ':' flag_value
   ;

flag_value
   : HEX
   ;

lock
   : LOCK ':' lock_value
   ;

lock_value
   : HEX
   ;

ckix
   : CKIX ':' ckix_value
   ;

ckix_value
   : HEX
   ;

ncol_info
   : ncol nnew size
   ;

ncol
   : NCOL ':' ncol_value
   ;

ncol_value
   : HEX
   ;

nnew
   : NNEW ':' nnew_value
   ;

nnew_value
   : HEX
   ;

size
   : SIZE ':' size_value
   ;

size_value
   : '-'? HEX
   ; 

kdo_itli
   : ITLI ':' kdo_itli_value 
   ;

kdo_itli_value
   : HEX
   ;

kdo_op_code
    : KDO OP CODE ':' rp_dependencies
    ;

rp_dependencies
    : DRP ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | URP ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | IRP ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    ;


bdba
    : BDBA ':' bdba_value
    ;

bdba_value
    :  HEX
    ;

hdba
    : HDBA ':' hdba_value
    ;

hdba_value
    : HEX
    ;

xtype
    : XTYPE ':' xtype_value?
    ;

xtype_value
    : HEX
    ;

xa_flags
    : XA FLAGS ':' xa_flags_value
    ;

xa_flags_value
    : HEX
    ;


ktb_redo_info
   : KTB REDO ktb_redo_clause
   ;

kdo_undo_info
   : kdo_undo_record ktb_redo_clause
   ;

kdo_undo_record
   : KDO UNDO RECORD ':' KTB REDO 
   ;


ktb_redo_clause
   : ktb_redo_op1 ktb_redo_compat_bit padding ktb_redo_op2 kdo_op_code_info
   ;

ktb_redo_op1
   : OP ':' HEX  ver
   ;

ktb_redo_compat_bit
   : COMPAT BIT ':' compat_bit_value '(' POST MINUS_ELEVEN ')'
   ;

compat_bit_value
   : HEX
   ;

padding
   : PADDING ':' padding_value
   ;

padding_value
   : HEX
   ;

ktb_redo_op2
   : OP ':' ktb_redo_op_l
   | OP ':' ktb_redo_op_f
   | OP ':' ktb_redo_op_c
   ;

ktb_redo_op_l
   : L itl xid uba ktb_redo_flg lkc scn
   ;

ktb_redo_flg
   : FLG ':' ktb_redo_flg_value
   ;

ktb_redo_flg_value
   : KTB_REDO_FLG_VALUE
   ;

ktb_redo_op_c
   : C uba
   ;

ktb_redo_op_f
   : F xid uba block_cleanout_record
   ;


itli_entries
   : itli
   ;

itli
   : ITLI ':' itli_value flg scn
   ;


itli_value
   :  HEX
   ;

lkc
   : LKC ':' lkc_value
   ;

lkc_value
   : HEX
   ;

wrp
    :WRP ':' wrp_value
    ;

wrp_value
    : HEX
    ;

prev_dba
    : PREV DBA ':' prev_dba_value
    ;


prev_dba_value
    : HEX
    ;

obj
    : OBJ ':' obj_value
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
    : KTUDH REDO ':' slt sqn flg siz fbi uba pxid
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

pxid
    : PXID ':' pxid_value
    ;

pxid_value
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
    | '(' OPT EQUAL HEX WHR EQUAL HEX ')'
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

column_info
    : column_info_detail+
    ;
column_info_detail
    : COL column_number ':' column_datatype? column_value
    ;

column_datatype
    : '[' HEX ']'
    ;

column_number
    : HEX
    ; 

column_value
    : HEX+
    | NULL_COLUMN_VALUE 
    ;

block_cleanout_record
    : BLOCK CLEANOUT RECORD COMMA scn ver opt bigscn? compact? spare? COMMA ENTRIES FOLLOW DOT DOT DOT  itli_entries+
    ;

opt
    : OPT ':' opt_value
    ;

opt_value
    : HEX
    ;

ver
    : VER ':' ver_value
    ;

ver_value
    : HEX
    ;
 
bigscn
    : BIGSCN ':' (Y|N)
    ;

compact:
    COMPACT ':' (Y|N)
    ;

spare
    : SPARE ':' spare_value
    ;

spare_value
    : HEX
    ;

lfdba
    : LFDBA ':' lfdba_value
    ;

lfdba_value
    : HEX
    ;

datafile_resize_marker:
    DATAFILE RESIZE MARKER '-' file old_size new_size
    ;

file:
    FILE COLON file_value
    ;

file_value
    : HEX
    ;

old_size:
    OLD SIZE COLON old_size_value
    ;

old_size_value
    :HEX
    ;

new_size:
    NEW SIZE COLON new_size_value
    ;

new_size_value:
    HEX
    ;
