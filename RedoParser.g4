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
    | ktucm_redo rolled_back_transaction?
    | ktudb_redo
    | ktudh_redo
    | ktudbu_redo
    | ktsbifm_redo
    | ktfbh_redo
    | ktfbb_redo
    | ktfbn_redo
    | ktudbr_redo
    | kteop_redo
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
    : SCN ':' scn_value
    ;

scn_value
    : wrap (DOT base)?
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
    : lfdba? chg_prefix_exists?  CHANGE  (  change_number con_id? chg_type chg_class chg_afn dba chg_obj scn seq layer_opcode enc rbl flg? star_date? redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo? ktsfrblnk_redo? ktust_redo? ktsfrbfmt_redo? ktsph_redo? ktsfm_redo? undo_info? ktuxv_info? begin_trans? buext_info? kdo_undo_info? index_undo_info? ktb_redo_info? hwms? block_cleanout_record? column_info? block_written* bitmap_redo?
              |  change_number media_recovery_marker con_id?  scn seq layer_opcode enc flg? standby_metadata_info? reuse_redo_entry? xid? datafile_resize_marker? block_written*
              |  change_number con_id? invld chg_afn dba blks chg_obj scn seq layer_opcode enc redo_info? xid? ktubl_redo? ktubu_redo? ktsfrgrp_redo?  ktsfrblnk_redo? ktsfrbfmt_redo? ktsfm_redo? block_cleanout_record? column_info? block_written* bitmap_redo?
              )
    ;


hwms
    : BOTH THE HWMS
           LOW HWM highwater_info  lfdba
           HIGH HWM highwater_info  lfdba
    |       LOW HWM highwater_info  lfdba?
    |       HIGH HWM highwater_info  lfdba?
    ;

bitmap_redo
    : REDO ON LEVEL bitmap_level_value BITMAP BLOCK
          REDO bitmap_redo_op
    | BMB STATE CHANGE_RAW len offset state
    | KTSPBFREDO MINUS FORMAT PAGETABLE DATABLOCK ktspbredo
    | KTSPSFREDO MINUS FORMAT LEVEL HEX BITMAP BLOCK parent_dba startdba number incn
    | KTSPFFREDO MINUS FORMAT LEVEL HEX BITMAP BLOCK 
             startdba_of_the_range number_of_blocks
             nbits inst nmrk parent_dba offset             
    ;

nbits
    : NBITS ':' nbits_value
    ;

nbits_value
    : HEX
    ;

inst
    : INST ':' inst_value
    ;

inst_value
    : HEX
    ;

nmrk
    : NMRK ':' nmrk_value
    ;

nmrk_value
    : HEX
    ;


number_of_blocks
    : NUMBER OF BLOCKS ':' number_of_blocks_value
    ;

number_of_blocks_value
    : HEX
    ;

startdba_of_the_range
    : START DBA OF THE RANGE ':' startdba_of_the_range_value
    ;

startdba_of_the_range_value
    : HEX
    ;

number
    : NUMBER ':' number_value
    ;

number_value
    : HEX
    ;

incn
    : INCN ':' incn_value
    ;

incn_value
    : HEX
    ;

ktspbredo
    : parent_dba typ objd itls fmt_flag poff cscn inc_pound
    ;

fmt_flag
    : FMT_FLAG ':' fmt_flag_value
    ;

fmt_flag_value
    : HEX
    ;

poff
    : POFF ':' poff_value
    ;

poff_value
    : HEX
    ;

inc_pound
    : INC_POUND ':' inc_pound_value
    ;

inc_pound_value
    : HEX
    ;

parent_dba
    : PARENT (LPAREN L HEX RPAREN)? DBA ':' parent_dba_value
    ;

parent_dba_value
    : HEX
    ;

reuse_redo_entry
    : REUSE REDO ENTRY object_reuse
    ;

object_reuse
    : OBJECT REUSE ':' PDB EQUAL HEX COMMA TSN EQUAL HEX OBJD EQUAL HEX
    ;


bitmap_redo_op
    : FOR STATE CHANGE_RAW len offset newstate
    | TO SET REJECTION CODE len off rc state
    | TO MARK BLOCK FREE  redo_to_mark_block_free
    | TO SET HWM OPCODE ':' HEX highwater_info
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

bi_tran
    : TRANS LAYER B DOT I DOT
    ;


index_undo_info
   : INDEX UNDO FOR LEAF KEY OPERATIONS
   | INDEX GENERAL UNDO LPAREN BRANCH RPAREN OPERATIONS
   | INDEX REDO LPAREN KDXAIR RPAREN ':' APPLY XAT DO TO ITL HEX LPAREN COUNT EQUAL HEX RPAREN
   | INDEX REDO LPAREN KDXBIN RPAREN ':' INSERT BRANCH BLOCK ROW COMMA COUNT EQUAL HEX
   | INDEX REDO LPAREN KDXBNE RPAREN ':' INITIALIZE BRANCH BLOCK COMMA COUNT EQUAL HEX 
   | INDEX REDO LPAREN KDXBPU RPAREN ':' PURGE BRANCH BLOCK ROW COMMA COUNT EQUAL HEX 
   | INDEX REDO LPAREN KDXIMA RPAREN ':' RESTORE BEFORE BLOCK IMAGE COMMA COUNT EQUAL HEX bi_tran
   | INDEX REDO LPAREN KDXIMA RPAREN ':' RESTORED BLOCK BEFORE IMAGE COMMA COUNT EQUAL HEX bi_tran
   | INDEX REDO LPAREN KDXLEM RPAREN ':' LPAREN REDO RPAREN MAKE LEAF BLOCK EMPTY 
   						 COMMA ITL EQUAL HEX COMMA COUNT EQUAL HEX
   | INDEX REDO LPAREN KDXLIN RPAREN ':' INSERT LEAF ROW
   | INDEX REDO LPAREN KDXLNE RPAREN ':' LPAREN COUNT EQUAL HEX RPAREN
                                           INIT HEADER OF NEWLY ALLOCATED LEAF BLOCK
   | INDEX REDO LPAREN KDXLNE RPAREN ':' LPAREN COUNT EQUAL HEX RPAREN 
                                           INIT LEAF BLOCK BEING SPLIT init_leaf_block_being_split
   | INDEX REDO LPAREN KDXLDE RPAREN ':' DELETE LEAF ROW
   | INDEX REDO LPAREN KDXLOK RPAREN ':' LOCK BLOCK COMMA COUNT EQUAL HEX
   | INDEX REDO LPAREN KDXLPR RPAREN ':' LPAREN REDO RPAREN 
	SET (KDXLENXT
            |KDXLEPRV
	    )	
	     EQUAL HEX COMMA ITL EQUAL HEX COMMA COUNT EQUAL HEX
   | INDEX REDO LPAREN KDXLRE RPAREN ':' RESTORE LEAF ROW
   | INDEX REDO LPAREN KDXLPU RPAREN ':' PURGE LEAF ROW LPAREN COUNT EQUAL HEX RPAREN
   | INDEX REDO LPAREN KDXLUP RPAREN ':' UPDATE KEYDATA COMMA COUNT EQUAL HEX
   | INDEX REDO LPAREN KDXULO RPAREN ':' CLEAR BLOCK OPCODE DURING COMMIT
   | INDEX REDO LPAREN KDXULO RPAREN ':' UNLOCK BLOCK DURING UNDO
   | ktfbh_undo
   ;

init_leaf_block_being_split
   : ZEROED LOCK COUNT AND FREE SPACE COMMA KDXLENXT EQUAL HEX new_block_has_rows dumping_row_index? dumping_rows?
   ;

lock_block
   : lock_itl
   ;

new_itl
   : NEW ITL ':' new_itl_value nco lev lmc
   ;

new_itl_value
   : HEX
   ;

lev
   : LEV ':' lev_value
   ;

lev_value
   : HEX
   ;

nco
   : NCO ':' nco_value
   ;

nco_value
   : HEX
   ;

lmc
   : LMC ':' lmc_value
   ;

lmc_value
   : HEX
   ;


split_itl
   : SPLIT ITL ':' split_itl_value
   ;

split_itl_value
   : HEX
   ;

lock_itl
   : LOCK ITL HEX OPERATION EQUAL HEX COMMA PRE MINUS SPLIT
   ;

seghdr_dba
   : SEGHDR DBA ':' seghdr_dba_value
   ;

seghdr_dba_value
   : HEX
   ;

unlock_block
   : UNLOCK BLOCK LPAREN HEX RPAREN ':' unlock_block_value
   ;

unlock_block_value
   : HEX
   ;


header_opcode
   : HEADER OPCODE ':'
   ;

save
   : SAVE ':' NO? pending_op?
   ;

pending_op
   : PENDING OP
   ;
using_extent
   : USING EXTENT ':'
   ;

begin
   : BEGIN ':' begin_value
   ;

begin_value
   : HEX
   ;


instance
   : INSTANCE ':' instance_value
   ;

instance_value
   : HEX
   ;

begin_clause
   : begin COMMA length COMMA instance
   ;

use_bits
   : USE BITS ':' begin_clause 
   ;

ktfbn_redo
   : KTFBN REDO MINUS FILE PROPERTY MAP BLOCK LPAREN FPM RPAREN
           HEX ':' STAT UPDATE REDO
           off len utime
   ;

utime
   : UTIME ':' utime_value
   ;

utime_value
   : HEX
   ;

ktfbb_redo
    : KTFBBREDO MINUS FILE BITMAP BLOCK REDO ':' use_bits
    ;

space_header
    : space_header_dba COMMA file
    ;

space_header_dba
    : SPACE HEADER DBA ':' space_header_dba_value 
    ;

space_header_dba_value
    : HEX
    ;

free_extent
    : FREE EXTENT ':'
    ;

ktfbh_undo
    : KTFBHUNDO MINUS FILE SPACE HEADER UNDO ':' 
			space_header header_opcode save (NO pending_op
                                                        |save_using
                                                        )?
                                                          free_extent?
                                                          begin_clause?
                                                         
    ;

ktfbh_redo
    : KTFBHREDO MINUS FILE SPACE HEADER REDO ':' header_opcode save (NO pending_op
                                                                    |save_using
                                                                    )
    ;


save_using
    : using_extent begin COMMA length COMMA instance
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

nblks
   : NBLKS ':' nblks_value
   ;

nblks_value
   : HEX
   ;

forcel3
   : FORCEL3 ':' forcel3_value
   ;

forcel3_value
   : HEX
   ;

startdba
   : START DBA ':'? startdba_value
   ;

startdba_value
   : HEX
   ;

ktsph_redo
   : ktsphfredo
   ;

ktsphfredo 
    : KTSPHFREDO MINUS FORMAT PAGETABLE SEGMENT HEADER startdba nblks forcel3 tsn objd
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
    : undo_type user_undo_done? last_buffer_split star_date? temp_object tablespace_undo user_only?
    ;

undo_type
    : '['? UNDO TYPE ']'? regular_undo    
    ;

begin_trans
    : BEGIN TRANS begin_trans_info?
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

kdo_info
    : array_update
    | vect 
    | kdo_flag_info (bkw
                    |fwd
                    )
    ;

fwd
    : FWD ':' fwd_value
    ;

fwd_value
    : HEX DOT (HEX
              |A
              |B
              |C
              |F
              )
    ;

bkw
    : BKW ':' bkw_value
    ;

bkw_value
    : HEX DOT (HEX
              |A
              |B
              |C
              |F
              )
    ;


kdo_flag_info
    : ktb_redo_flag  lock tabn_slot
    ;

vect
    : VECT EQUAL MINUS? HEX
    ;

array_update
    : ARRAY UPDATE OF HEX ROWS ':'
    ;

kdo_op_code_info
    : kdo_op_code_info_more+
    ;

kdo_op_code_info_more
    : kdo_op_code kdo_itli_info kdo_info? tabn_info? ncol_info? vector_content?
    | kdo_op_code kdo_itli_info  tabn_info fb_info  (nrid|hrid)  null_emum null_enum_list? null_enum_info? many_cols? 
/*
    | kdo_op_code kdo_itli_info  tabn_info fb_info curc_info? null_emum null_enum_list null_enum_info many_cols?
*/
    | kdo_op_code kdo_itli_info  tabn_info fb_info curc_info? null_emum null_enum_list? null_enum_info? many_cols?
    | kdo_op_code kdo_itli_info  tabn_info+
    ;

vector_content
    : VECTOR CONTENT ':' col_info*
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

hrid
   : HRID ':' hrid_value
   ;

hrid_value
   : HEX DOT (HEX
             |A
             |B
             |C
             |F
             )
   ;


nrid 
   : NRID ':' nrid_value
   ;

nrid_value
   : HEX DOT (HEX
             |A
             |B
             |C
             |F
             )
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
    | ORP ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | QMD ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | QMI ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | LKR ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | HEX ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
    | SKL ROW DEPENDENCIES DISABLED xtype xa_flags bdba hdba
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
    | XAXTYPE KDO_KDOM2
    | XA
    | XR
    ;

xa_flags
    : FLAGS ':' xa_flags_value
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

itl_equal
   : ITL EQUAL HEX
   ;

ktb_redo_clause
   : ktb_redo_op1 ktb_redo_compat_bit padding ktb_redo_op2 ktb_redo_clause_options
   ;

ktb_redo_clause_options
    : star_date? dump_kd_info? kdo_op_code_info?
    | single_array_redo_info star_date? leaf_itl_info? insert_key?
    | itl_equal
    | insert_leaf
    | purge_leaf
    | insert_into_slot
    | delete_leaf
    | lock_block
    | purge_branch
    | kdxlup_info
    ;
   

insert_into_slot
   : REDO itl INSERT INTO SLOT HEX COMMA child_dba new_key
   ;

child_dba
   : CHILD DBA child_dba_value
   ;

child_dba_value
   : HEX
   ;

new_key
   : NEW KEY ':' LPAREN HEX RPAREN ':' new_key_value
   ;

new_key_value
   : HEX+
   ;

purge_branch
   : REDO itl purge_slot
   ;

purge_slot
   : SLOT  purge_slot_value
   ;

purge_slot_value
   : MINUS? HEX
   ;

kdxdumpcompdo
   : KDXDUMPCOMPDO LEN HEX HEX LPAREN HEX RPAREN ':' HEX+
   ;

kdxlup_info
   : REDO ':' HEX (SINGLE|ARRAY) FSLASH '-' '-' FSLASH '-' '-' leaf_itl_info number_of_keys? keydata? kdxdumpcompdo star_date?
   ;

purge_leaf
   : UNDO ':' HEX SINGLE SPLIT FLAG FSLASH CLEAR FSLASH '-' '-' FSLASH '-' '-' FSLASH '-' '-' FSLASH '-' '-' leaf_itl_info? 
   ;

leaf_itl_info
   : itl COMMA sno COMMA ROW SIZE HEX star_date?
   ;

single_array_redo_info
   : REDO ':' HEX (SINGLE|ARRAY) FSLASH '-' '-' FSLASH '-' '-'
   ;

insert_leaf
   : REDO ':' HEX (SINGLE|ARRAY) FSLASH '-' '-' FSLASH '-' '-' leaf_itl_info number_of_keys? leaf_slots? insert_key  each_key_size_is? keydata?

   ;

delete_leaf
   : REDO ':' HEX (SINGLE|ARRAY) FSLASH '-' '-' FSLASH '-' '-' itl COMMA sno COMMA ROW SIZE HEX number_of_keys? leaf_slots?
   ;

number_of_keys
   : NUMBER OF KEYS ':' number_of_keys_value
   ;

number_of_keys_value
   : HEX
   ;

leaf_slots
   : SLOTS ':' leaf_slots_value
   ;

leaf_slots_value
   : HEX+
   ;

sno
   : SNO ':' sno_value
   ;

sno_value
   : HEX
   ;

each_key_size_is
   : EACH KEY SIZE IS ':' each_key_size_value
   ;

each_key_size_value
   : HEX+
   ;

insert_key
   : INSERT KEY ':' LPAREN HEX RPAREN ':' insert_key_value+
   ;

insert_key_value
   : HEX
     | star_date
   ;

keydata
   : KEYDATA (FSLASH BITMAP)? ':' LPAREN HEX RPAREN ':' keydata_value
   ;

keydata_value
   : HEX+
   ;

dump_kd_info
   : dump_kdilk kdxlpu number_of_keys? key_sizes? kdx_key selflock? kdx_bitmap?
   | dump_kdilk kdxlre kdx_key kdx_bitmap?
   | dump_kdilk kdxlre number_of_keys key_sizes kdx_key selflock kdx_bitmap
   | dump_kdilk kdxlde kdx_key keydata?
   | dump_kdilk kdxlup kdx_key keydata?
   | dump_kdige 
	(restore_block_before_image
	 |restore_block_to_btree
	 |set_leaf_block_previous_link
	 |branch_block_row_insert
         |branch_block_row_purge
         |make_leaf_block_empty
	)?
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

block_dba
   : BLOCK DBA ':' block_dba_value
   ;

block_dba_value
   : HEX
   ;

kdxlup
   : LPAREN KDXLUP RPAREN ':' UPDATE KEYDATA IN ROW
   ;

kdxlde
   : INDEX REDO LPAREN KDXLDE RPAREN ':' DELETE LEAF ROW
   | LPAREN KDXLDE RPAREN ':' MARK LEAF ROW DELETED
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

dump_kdige
  : DUMP KDIGE ':' block_dba COMMA seghdr_dba unlock_block?
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
   : MINUS? HEX
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
   | OP ':' ktb_redo_op_r
   | OP ':' ktb_redo_op_Z
   ;

ktb_redo_op_Z
   : Z 
   ;

ktb_redo_op_l
   : L itl xid uba ktb_redo_flg lkc scn
   ;

ktb_redo_flag
   : FLAG ':' ktb_redo_flag_values
   ;

ktb_redo_flg
   : FLG ':' ktb_redo_flg_values
   ;

ktb_redo_op_r
   : R itc itl_list kdxln_info? dumping_row_index? dumping_rows? data_block_bi?
   ;

itl_list
   : ITL XID UBA FLAG LCK SCN FSLASH FSC itl_list_entries+
   ;

itl_list_entries
   : itl_list_itl itl_list_xid itl_list_uba itl_list_flag
        itl_list_lck itl_list_scn_or_fsc_indicator itl_list_scn_or_fsc
   | star_date
   ;

itl_list_uba
   : uba_value
   ;

itl_list_itl
   : itl_value
   ;

itl_list_xid
   : xid_value
   ;

itl_list_list_uba
   : uba_value
   ;

itl_list_flag
   : ktb_redo_flg_values
   ;

itl_list_lck
   : HEX
   ;

itl_list_scn_or_fsc_indicator
   : FSC
   | SCN
   ;

itl_list_scn_or_fsc
   : scn_value
   | fsc_value
   ;

fsc_value
   : scn_value
   ;

itc
   : ITC ':' itc_value
   ;

itc_value
   : HEX
   ;


ktb_redo_op_c
   : C uba block_cleanout_record? kdo_op_code_info?
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

kteop_redo
    : KTEOP REDO MINUS extent_map_redo
    ;

sethwm
    : SET HWM ':' 
    ;
    
highwater
    : HIGHWATER ':' ':' highwater_value
    ;

highwater_value
    : HEX
    ;

ext_pound
    : EXT_POUND ':' ext_pound_value
    ;

ext_pound_value
    : HEX
    ;

blk_pound
    : BLK_POUND ':' blk_pound_value
    ;

blk_pound_value
    : HEX
    ;

ext_size
    : EXT SIZE ':' ext_size_value
    ;

ext_size_value
    : HEX
    ;

blocks_in_seg_hdr_freelist
    : POUND_BLOCKS IN SEG DOT HDRS FREELISTS ':' blocks_in_seg_hdr_freelist_value
    ;

blocks_in_seg_hdr_freelist_value
    : HEX
    ;

blocks_below
    : POUND_BLOCKS BELOW ':'  blocks_below_value
    ;

blocks_below_value
    : HEX
    ;

mapblk
    : MAPBLK  mapblk_value
    ;

mapblk_value
    : HEX
    ;

extent_map_redo
    : REDO OPERATION ON EXTENT MAP (extent_map_redo_sethwm
                                   |extent_map_redo_add
				   )
    ;

at_offset
    : AT OFFSET ':' at_offset_value
    ;

at_offset_value
    : HEX
    ;

ctime
    : CTIME ':' ctime_value
    ;

ctime_value
    : HEX
    ;

exts
    : EXTS ':' exts_value
    ;

exts_value
    : HEX
    ;

lastmap
    : LASTMAP ':' lastmap_value
    ;

lastmap_value
    : HEX
    ;

mapcnt
    : MAPCNT ':' mapcnt_value
    ;

mapcnt_value
    : HEX
    ;

extent
    : EXTENT ':' extent_value
    ;

extent_value
    : HEX
    ;

add
    : ADD ':' (TRUE
              | FALSE
              )
    ;

updxnt
    : UPDXNT ':' extent add
    ;

setstat
    : SETSTAT ':' exts blks lastmap mapcnt
    ;

addret
    : ADDRET ':' offset ctime
    ;


extent_map_redo_add
    : ADD ':' dba len at_offset addret setstat updxnt
    ;
     

extent_map_redo_sethwm
    : sethwm highwater_info
    ;

highwater_info
    :  highwater ext_pound blk_pound ext_size blocks_in_seg_hdr_freelist blocks_below mapblk offset
    ;

ktudh_redo
    : KTUDH REDO ':' slt sqn flg siz fbi uba pxid pdbuid? kteop_redo?
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

off
    : OFF ':' off_value
    ;

off_value
    : HEX
    ;

rc
    : RC ':' rc_value
    ;

rc_value
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
    : BLOCK CLEANOUT RECORD COMMA scn ver opt bigscn? compact? spare? COMMA ENTRIES FOLLOW DOT DOT DOT   itli_entries+ 
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

ktuxv_info
    : ktuxvoff ktuxvflg
    ;

ktuxvoff
    : KTUXVOFF ':' ktuxvoff_value
    ;

ktuxvoff_value
    : HEX
    ;

ktuxvflg
    : KTUXVFLG ':' ktuxvflg_value
    ;

ktuxvflg_value
    : HEX
    ;
    

kgl_info
    : KGL INFO ':' kgl_info_value*
    ;

kgl_info_value
    : '[' HEX DOT HEX DOT HEX DOT HEX COMMA HEX ']'
    ;

kqr_info
    : KQR INFO ':' kqr_info_value*
    ;

kqr_info_value 
    : '[' HEX COMMA HEX COMMA HEX ']'
    ;


standby_metadata_cache_invalidation
    : STANDBY METADATA CACHE INVALIDATION
    ;

restore_block_to_btree
    : RESTORE BLOCK TO B MINUS TREE LPAREN HEX RPAREN ':' HEX btree_block+
    ;

btree_block
    : LPAREN HEX RPAREN ':' btree_block_image
    ;
   
btree_block_image
    : block_image
    ;

restore_block_before_image
    : RESTORE BLOCK BEFORE IMAGE LPAREN HEX RPAREN ':' block_image
    ;

block_image
    : HEX+
    ;

set_leaf_block_previous_link
    : SET LEAF BLOCK PREVIOUS LINK LPAREN HEX RPAREN ':' previous_link
    ;

previous_link
    : HEX+
    ;

rolled_back_transaction
    : ROLLED BACK TRANSACTION
    ;
branch_block_row_purge
    : BRANCH BLOCK ROW PURGE branch_block_rows+
    ;

branch_block_row_insert
    : BRANCH BLOCK ROW INSERT branch_block_rows+
    ;

branch_block_rows
    : LPAREN HEX RPAREN ':' HEX+
    ;

make_leaf_block_empty
   : MAKE LEAF BLOCK EMPTY make_leaf_block_empty_clause
   ;

make_leaf_block_empty_clause
   : LPAREN HEX RPAREN ':' HEX+
   ;

kdxln_info
   : kdxlnitl kdxlnnco kdxlndsz kdxlncol kdxlnflg kdxlnnxt kdxlnprv new_block_has_rows
   | split_itl new_block_has_rows
   | new_itl new_block_has_rows
   ;

kdxlnitl
   : KDXLNITL EQUAL kdxlnitl_value
   ;

kdxlnitl_value
   : HEX
   ;

kdxlnnco
   : KDXLNNCO EQUAL kdxlnnco_value
   ;

kdxlnnco_value
   : HEX
   ;

kdxlndsz
   : KDXLNDSZ EQUAL kdxlndsz_value
   ;

kdxlndsz_value
   : HEX
   ;

kdxlncol
   : KDXLNCOL EQUAL kdxlncol_value
   ;

kdxlncol_value
   : HEX
   ;

kdxlnflg
   : KDXLNFLG EQUAL kdxlnflg_value
   ;

kdxlnflg_value
   : HEX
   ;

kdxlnnxt
   : KDXLNNXT EQUAL kdxlnnxt_value
   ;

kdxlnnxt_value
   : HEX
   ;

kdxlnprv
   : KDXLNPRV EQUAL kdxlnprv_value
   ;

kdxlnprv_value
   : HEX
   ;

cu_itl
   : CU ITL COUNT MINUS HEX
   ;

lvec_size
   : LVEC SIZE HEX
   ;

new_block_has_rows
   : NEW BLOCK HAS HEX ROWS
   ;

data_block_bi
   : DATA_BLOCK_BI dump_memory
   ;

dumping_row_index
   : DUMPING_ROW_INDEX dump_memory
   ;

dumping_rows
   : DUMPING_ROWS dump_memory auto_clause?
   ;

auto_clause
   : AUTO MINUS PREFIX KDXLNCOL EQUAL MINUS HEX cu_itl lvec_size
   ;
dump_memory
   : DUMP OF MEMORY FROM HEX TO HEX memory_info+
   ;

memory_info
   : memory_address memory_line memory_display
   | STARDATE2
   ;

memory_display
   : MEMORY_DISPLAY
   ;

memory_address
   : HEX
   ;

memory_line
   : HEX HEX? HEX? HEX?
   ;

ktb_redo_flag_values
    : ((F|C|MINUS)(B|H|MINUS)|HEX) 
    ;

ktb_redo_flg_values
    : ((C|MINUS)(B|H|MINUS)|HEX) (U|MINUS) (L|MINUS)
    ;

fb_flag_values
    : (K|MINUS) (C|MINUS) (H|MINUS) MINUS (F|MINUS) (L|MINUS) MINUS MINUS
    ;

