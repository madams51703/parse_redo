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
    :  REDO RECORD MINUS thread rba len vld con_uid? scn subscn date_value lwn_info?
    ;

change_records
    : change+
    ;

block_written
    : BLOCK WRITTEN MINUS afn rdba bft non_bft scn seq flg
    ;

rdba
    : RDBA ':' rdba_value
    ;

rdba_value
    : HEX
    ;

bft
    : BFT ':' bft_value
    ;

bft_value
    : LPAREN HEX COMMA HEX RPAREN
    ;

non_bft
    : NONBFT ':' non_bft_value
    ;

non_bft_value
    : LPAREN HEX COMMA HEX RPAREN
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
    : lfdba? chg_prefix_exists?  CHANGE  (  change_number con_id? chg_type chg_class chg_afn dba chg_obj scn seq layer_opcode enc rbl flg? redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo? ktsfrblnk_redo? ktust_redo? ktsfrbfmt_redo? ktsfm_redo? undo_info? begin_trans? buext_info? kdo_undo_info? index_undo_info? ktb_redo_info? block_cleanout_record? column_info? block_written* bitmap_redo?
              |  change_number media_recovery_marker con_id?  scn seq layer_opcode enc flg? standby_metadata_info? xid? datafile_resize_marker? block_written*
              |  change_number con_id? invld chg_afn dba blks chg_obj scn seq layer_opcode enc redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo?  ktsfrblnk_redo? ktsfrbfmt_redo? ktsfm_redo? block_cleanout_record? column_info? block_written* bitmap_redo?
              )
    ;

bitmap_redo
    : REDO ON LEVEL bitmap_level_value BITMAP BLOCK
          REDO bitmap_redo_op
    ;

bitmap_redo_op
    : FOR STATE CHANGE_RAW len offset newstate
    | TO MARK BLOCK FREE  redo_to_mark_block_free
    ;

redo_to_mark_block_free
    : offset length xidslot state ncmt  commit_slot_list
    ;

length
    : LENGTH ':' length_value
    ;

length_value
    : HEX
    ;

state
    : STATE ':' state_value
    ;

state_value
    : HEX
    ;

xidslot
    : XIDSLOT ':' xidslot_value
    ;

xidslot_value
    : HEX
    ;

ncmt
    : NCMT ':' ncmt_value
    ;

ncmt_value
    : HEX
    ;

commit_slot_list
    : COMMIT SLOT LIST locking_transaction
    ;

locking_transaction
    : LOCKING TRANSACTION ':' locking_transaction_value
    ;

locking_transaction_value
    : HEX DOT HEX DOT HEX
    ;

offset
    : OFFSET ':' offset_value
    ;

offset_value
    : HEX
    ;

newstate
    : NEWSTATE ':' newstate_value
    ;

newstate_value
    : HEX
    ;


bitmap_level_value
    : HEX
    ;

index_undo_info
   : INDEX UNDO FOR LEAF KEY OPERATIONS
   | INDEX REDO LPAREN KDXLIN RPAREN ':' INSERT LEAF ROW
   | INDEX REDO LPAREN KDXLDE RPAREN ':' DELETE LEAF ROW
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
    : KTSFRBLNK REDO ':' OPCODE ':' ktsfrblnk_redo_opcode next_dba  ktsfrblnk_itli
    ;

next_dba
    : NEXT DBA ':' next_dba_value
    ;

next_dba_value
    :HEX
    ;

ktsfrblnk_itli
    : ITLI ':' ktsfrblnk_itli_value
    ;

ktsfrblnk_itli_value
    : HEX
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
    : KTSFRGRP LPAREN FGB FSLASH SHDR MODIFY FREELIST RPAREN REDO ':'  ktsfrgrp_opcode ktsfrgrp_slot ktsfrgrp_flag ccnt head tail
    ;

head
   : HEAD ':'  head_value
   ;

head_value
   : HEX
   ;

tail
   : TAIL ':' tail_value
   ;

tail_value
   : HEX
   ;

ktsfrgrp_flag
    : FLAG ':' EQUAL HEX XID OR SLOT HEX 
    ;

ccnt
   : CCNT ':' ccnt_value
   ;

ccnt_value 
   : HEX DOT HEX DOT HEX
   ;

ktsfrgrp_opcode
    : OPCODE ':' ktsfrgrp_opcode_value
    ;

ktsfrgrp_opcode_value
    : LUPD_UNLBLK LPAREN UNLINK BLOCK RPAREN
    ;

ktsfrgrp_slot
    :SLOT NO ':' ktsfrgrp_slot_value COMMA COUNT ':'  HEX
    ;


ktsfrgrp_slot_value
   : HEX
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
    : star_date? COL HEX ':' '[' col_element_count_value ']' col_values
    | star_date? COL HEX ':' NULL_COLUMN_VALUE
    ;

col_element_count_value
    : HEX
    ;
 
col_values
    : NULL_COLUMN_VALUE 
    | hex_byte+ 
    ;

hex_byte
    : HEX
    ;

kdo_op_code_info
    : kdo_op_code kdo_itli_info  tabn_info ncol_info
    | kdo_op_code kdo_itli_info  tabn_info fb_info  nrid  null_emum null_enum_list null_enum_info many_cols? 
/*
    | kdo_op_code kdo_itli_info  tabn_info fb_info curc_info? null_emum null_enum_list null_enum_info many_cols?
*/
    | kdo_op_code kdo_itli_info  tabn_info fb_info curc_info? null_emum null_enum_list? null_enum_info? many_cols?
    | kdo_op_code kdo_itli_info  tabn_info+
    ;

curc_info
    : curc comc pk nk
    ;

nk
    : NK ':' nk_value
    ;

nk_value
    : HEX DOT HEX
    ;

pk 
    : PK ':' pk_value
    ;

pk_value
    : HEX DOT HEX
    ;

comc
    : COMC ':' comc_value
    ;

comc_value
    : HEX
    ;
 
curc
    : CURC ':' curc_value 
    ;

curc_value
    : HEX
    ;

	
null_emum
    : NULL ':' 
    ;

null_enum_list
   :HEX+
   |MINUS+
   ;

null_enum_info
   : null_enum+
   ;

null_enum
    : MINUS
    | N
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
   : tabn star_date? tabn_slot flag lock ckix
   | tabn star_date?  tabn_slot size_delt 
   | tabn lock nrow tabn_qmd_slot_info 
   | tabn lock nrow tabn_qmi_slot_info+ 
   | tabn tabn_slot
   ;

star_date
   : STARDATE LPAREN CDBROOT LPAREN HEX RPAREN RPAREN
   | STARDATE
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
  
nrow
   : NROW ':' nrow_value
   ;

nrow_value
   : HEX
   ;

tl_info
   : tl fb lb cc
   ;

tl
   : TL ':' tl_value
   ;

tl_value
   : HEX
   ;
 
fb_info
   : fb lb cc cki?
   ;

fb
   : FB_COLON  fb_value
   ;

fb_value
   : fb_flag_values
   ;

lb
   : LB ':' lb_value
   ;

lb_value
   : HEX
   ;

cc
   : CC_COLON cc_value
   ;

cc_value
   : HEX
   ;

cki
   : CKI ':' cki_value
   ;

cki_value
   : HEX
   ;


tabn_qmd_slot_info
   : tabn_qm_slot+
   ;

tabn_qmi_slot_info
   : tabn_qmi_slot_info_do+
   ;

tabn_qmi_slot_info_do
   : tabn_qm_slot tl_info star_date? many_cols 
   ;

many_cols
  : col_info+
  ;

tabn_qm_slot
   : star_date? SLOT '[' tabn_qm_slot_idx ']' ':' tabn_qm_slot_value
   ;

tabn_qm_slot_idx
   : HEX
   ;

tabn_qm_slot_value
   : HEX
   ;

tabn
   : TABN ':' tabn_value
   ;

tabn_value
   : HEX
   ;

tabn_slot
   : SLOT ':' tabn_slot_value tabn_slot_to?
   ;

tabn_slot_value
   : HEX '('? HEX? ')'?
   ;

tabn_slot_to
   : TO ':' tabn_slot_to_value
   ;

tabn_slot_to_value
   : HEX
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
    | QMD ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | QMI ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | LKR ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
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
   : ktb_redo_op1 ktb_redo_compat_bit padding ktb_redo_op2 dump_kd_info? kdo_op_code_info?
   | ktb_redo_op1 ktb_redo_compat_bit padding ktb_redo_op2 insert_leaf 
   | ktb_redo_op1 ktb_redo_compat_bit padding ktb_redo_op2 delete_leaf 
   ;

insert_leaf
   : REDO ':' HEX SINGLE FSLASH '-' '-' FSLASH '-' '-' itl COMMA sno COMMA ROW SIZE HEX insert_key keydata?
   ;

delete_leaf
   : REDO ':' HEX (SINGLE|ARRAY) FSLASH '-' '-' FSLASH '-' '-' itl COMMA sno COMMA ROW SIZE HEX number_of_keys? delete_leaf_slots?
   ;

number_of_keys
   : NUMBER OF KEYS ':' number_of_keys_value
   ;

number_of_keys_value
   : HEX
   ;

delete_leaf_slots
   : SLOTS ':' delete_leaf_slots_value
   ;

delete_leaf_slots_value
   : HEX+
   ;

sno
   : SNO ':' sno_value
   ;

sno_value
   : HEX
   ;

insert_key
   : INSERT KEY ':' LPAREN HEX RPAREN ':' insert_key_value
   ;

insert_key_value
   : HEX+
   ;

keydata
   : KEYDATA ':' LPAREN HEX RPAREN ':' keydata_value
   ;

keydata_value
   : HEX+
   ;

dump_kd_info
   : dump_kdilk kdxlpu number_of_keys? key_sizes? kdx_key selflock? kdx_bitmap
   | dump_kdilk kdxlre kdx_key kdx_bitmap?
   | dump_kdilk kdxlre number_of_keys key_sizes kdx_key selflock kdx_bitmap
   | dump_kdilk kdxlde kdx_key
   ;

kdx_bitmap
   : KEYDATA? FSLASH? BITMAP ':' LPAREN HEX RPAREN ':' kdx_bitmap_value
   ;

kdx_bitmap_value
   : HEX+
   ;


selflock
   : SELFLOCK ':' LPAREN HEX RPAREN ':' selflock_value
   ;

selflock_value
   : HEX+
   ;


key_sizes
   : KEY SIZES ':' key_sizes_value
   ;

key_sizes_value
   : HEX+
   ;

kdxlre
   : LPAREN KDXLRE RPAREN ':' RESTORE LEAF ROW LPAREN CLEAR LEAF DELETE FLAGS RPAREN
   ;




kdxlde
   : INDEX REDO LPAREN KDXLDE RPAREN ':' DELETE LEAF ROW
   ;


kdxlpu
   : LPAREN KDXLPU RPAREN ':' PURGE LEAF ROW
   ;

kdx_key
   : KEY ':' LPAREN HEX RPAREN ':' kdx_key_value
   ;

kdx_key_value
   : (HEX|star_date)+
   ;



dump_kdilk
   : DUMP KDILK ':' ITL EQUAL HEX COMMA kdxlkflg sdc indexid kdx_block
   ;

kdxlkflg
   : KDXLKFLG EQUAL kdxlkflg_value
   ;    


kdxlkflg_value
   :HEX
   ;

sdc
   : SDC EQUAL sdc_value
   ;

sdc_value
   : HEX
   ;

indexid
   : INDEXID EQUAL indexid_value
   ;

indexid_value
   : HEX
   ;

kdx_block
   : BLOCK EQUAL kdx_block_value
   ;

kdx_block_value
   : HEX
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
   | OP ':' ktb_redo_op_Z
   ;

ktb_redo_op_Z
   : Z 
   ;

ktb_redo_op_l
   : L itl xid uba ktb_redo_flg lkc scn
   ;

ktb_redo_flg
   : FLG ':' ktb_redo_flg_values
   ;


ktb_redo_op_c
   : C uba
   ;

ktb_redo_op_f
   : F xid uba block_cleanout_record? 
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
    : KTUDH REDO ':' slt sqn flg siz fbi uba pxid pdbuid?
    ;


pdbuid
    : PDBUID ':' pdbuid_value
    ;

pdbuid_value
    : HEX
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

afn
    : AFN ':' afn_value
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

standby_metadata_info
    : standby_metadata_cache_invalidation kqr_info kgl_info
    ;

kgl_info
    : KGL INFO ':' kgl_info_value+
    ;

kgl_info_value
    : '[' HEX DOT HEX DOT HEX DOT HEX COMMA HEX ']'
    ;

kqr_info
    : KQR INFO ':' kqr_info_value
    ;

kqr_info_value 
    : '[' HEX COMMA HEX COMMA HEX ']'
    ;


standby_metadata_cache_invalidation
    : STANDBY METADATA CACHE INVALIDATION
    ;


ktb_redo_flg_values
    : (C|MINUS)(H|MINUS)(U|MINUS)(L|MINUS)
    ;

fb_flag_values
    : (K|MINUS) (C|MINUS) (H|MINUS) MINUS (F|MINUS) (L|MINUS) MINUS MINUS
    ;

