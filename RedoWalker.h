#include "/usr/local/include/antlr4-runtime/antlr4-runtime.h"
#include "RedoParserBaseListener.h"

#include <iostream>
#include <cstdlib>
#include <array> // for array, at()
#include <tuple> // for get()
using namespace std;

class change_vector {
    // Access specifier
public:
    // Data  Members
    int con_id;
    int typ;
    int cls=0;
    int afn;
    unsigned long dba;
    unsigned long obj;
    long scn_base;
    long scn_wrap;
    int seq;
    int layer;
    int opcode;
    int enc;
    int rbl;
    unsigned int flg;
    std::string date;
    std::string xid="";
    long slt=0;
    unsigned long sqn=0;  //  Known as the wrap in Oracle lingo

    long ktust_redo_slt=0;
    unsigned long ktust_redo_sqn=0;
    

    long ktubl_redo_slt=0;
    unsigned long ktubl_redo_wrp=9;
    int ktubl_redo_rci=0; 

    long ktubu_redo_slt=0;
    unsigned long ktubu_redo_wrp=0;
    long ktubu_redo_flg=0;
    long ktubu_redo_prev_dba=0;
    long ktubu_redo_rci=0;
    int ktubu_redo_layer=0;
    int ktubu_redo_opcode=0;
    unsigned long ktubu_redo_objn=0;
    unsigned long ktubu_redo_objd=0;
    long ktubu_redo_ts=0;  

  
    string ktelk_redo_xid;


    long ktudbu_redo_slt;


    long ktudb_redo_siz=0;
    long ktudb_redo_sp=0;
    long ktudb_redo_flg=0;
    long ktudb_redo_seq=0;
    long ktudb_redo_rec=0;
    unsigned long ktudb_xid[3]={0,0,0};




    long ktudh_redo_slt;
    unsigned long ktudh_redo_sqn;
    long ktudh_redo_flg=0;
    long ktudh_redo_siz=0;
    long ktudh_redo_fbi=0;
    unsigned long ktudh_redo_uba[3]={0,0,0};
    unsigned long ktudh_redo_pxid[3]={0,0,0};
    
    long ktucm_redo_slt=0;
    unsigned long ktucm_redo_sqn=0;

    long ktucm_redo_srt=0;
    long ktucm_redo_sta=0;
    long ktucm_redo_flg=0;

    unsigned long ktucf_redo_uba[3]={0,0,0};
    long ktucf_redo_ext=0;
    long ktcuf_redo_spc=0;
    long kctuf_redo_fbi=0;

    long resize_afn=0;
    long resize_old_size=0;
    long resize_new_size=0;




    // Member Functions()
    void printobjd() { cout << " OBJ is:" << obj; }
    void print_change_vector( array <std::string,17> block_classes,string opcodes[100][100]) {
                int xid_printed=0; 
		long undo_segment=0;
                long long int dba_value = 0;
		long long int block;
		long long int block_mask = 4194303;
                div_t undo_segment_div;

	        xid_printed = 0;
	
		if (cls >16)
		{
			undo_segment_div = div( (cls - 16),2);
			undo_segment = undo_segment_div.quot;
		}

		if (dba != 0 )
		{ 
			block = dba  & block_mask;
		}
		else 
		{
			block =0;
		}

		if (ktudh_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktudh_redo_slt << "." << std::dec << ktudh_redo_sqn << ",";
			xid_printed =1;
		}

		if (ktust_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktust_redo_slt << "."  << std::dec << ktust_redo_sqn << ",";
			xid_printed =1;
		}

		if (ktucm_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktucm_redo_slt << "." << std::dec << ktucm_redo_sqn << ",";
			xid_printed =1;
		}

		if (ktubl_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktubl_redo_slt << "." << std::dec << ktubl_redo_wrp << ",";
			xid_printed =1;
		}

		if (ktubu_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktubu_redo_slt << "." <<std::dec << ktubu_redo_wrp << ",";
			xid_printed =1;
		}

		if (ktudbu_redo_slt != 0)
		{
			cout << std::dec << undo_segment << "." << std::dec << ktudbu_redo_slt << ",";
			xid_printed =1;
		}


		if (xid.compare("") !=0  && xid_printed ==0 )
		{
			cout << xid << ",";
			xid_printed =1;
		}	

		if ( xid_printed == 0)
		{

			cout << "NO_XID" << ",";
		}             
 	
		cout << date << ",";
		if ( obj == -1 )
		{
			cout << "MEDIA RECOVERY MARKER" << "," ;
		}

		else
		{
			cout << std::dec << obj << "," ;

		}

		cout << std::dec << layer << "." << std::dec << opcode << "," ;
		cout << opcodes[layer][opcode] <<","; 
		if ( cls <=16 )
		{
			cout << block_classes[cls] << "(" << cls <<")" << ",";
		}
		else
		{
			cout << "Block Class (" << cls << ")" << ",";
		}
		cout << std::dec<< afn << "," <<std::dec << block << ",";

		if ( resize_afn != 0 )
		{

		    cout << resize_afn << "," << resize_old_size << "," << resize_new_size << "," << (resize_new_size - resize_old_size)*8192 << ",";			

		}


		cout << "\n";

	}
};
class msa_convert
{

public:

    unsigned long convert_dec_str_to_ulong(std::string value)
    {
        std::istringstream converter_text { value };
        unsigned long ret_value = 0;
        converter_text >> std::dec >> ret_value;
        return ret_value;
    }
  
    long convert_dec_str_to_long(std::string value)
    {
        std::istringstream converter_text { value };
        long ret_value = 0;
        converter_text >> std::dec >> ret_value;
        return ret_value;
    }	

    int convert_dec_str_to_int(std::string value)
    {
        std::istringstream converter_text { value };
        int ret_value = 0;
        converter_text >> std::dec >> ret_value;
        return ret_value;
    }	

    unsigned int convert_dec_str_to_uint(std::string value)
    {
        std::istringstream converter_text { value };
        unsigned int ret_value = 0;
        converter_text >> std::dec >> ret_value;
        return ret_value;
    }	

//Start Hex Conversion

    unsigned long convert_hex_str_to_ulong(std::string value)
    {
        std::istringstream converter_text { value };
        unsigned long ret_value = 0;
        converter_text >> std::hex >> ret_value;
        return ret_value;
    }
  
    long convert_hex_str_to_long(std::string value)
    {
        std::istringstream converter_text { value };
        long ret_value = 0;
        converter_text >> std::hex >> ret_value;
        return ret_value;
    }	

    int convert_hex_str_to_int(std::string value)
    {
        std::istringstream converter_text { value };
        int ret_value = 0;
        converter_text >> std::hex >> ret_value;
        return ret_value;
    }	

    unsigned int convert_hex_str_to_uint(std::string value)
    {
        std::istringstream converter_text { value };
        unsigned int ret_value = 0;
        converter_text >> std::hex >> ret_value;
        return ret_value;
    }	

};

class RedoWalker : public RedoParserBaseListener
{

private:
msa_convert string_to_number;

string opcode_lookup[100][100];
array <std::string,17> block_classes_real = 
{
""
,"block"
,"sort block"
,"save undo block"
,"segment header"
,"save undo header"
,"free list"
,"extent map"
,"1st level bmb"
,"2nd level bmb"
,"3rd level bmb"
,"bitmap block"
,"bitmap index block"
,"file header block"
,"unused"
,"system undo header"
,"system undo block"
};

array<change_vector,400000> change_vectors;
long number_of_change_vectors=0;
long change_vectors_at_redo_record=0;
long change_vectors_at_last_xid=0;
long current_objd=0;
std::string current_seq="";

public:
RedoWalker() {
  		opcode_lookup[1][1] = "KTZ ForMaT block - KTZFMT";
		opcode_lookup[1][2] = "Transaction Z Redo Data Header - KTZRDH";
                opcode_lookup[1][3] = "KTZ Allocate Record Callback - KTZARC";
                opcode_lookup[1][4] = "KTZ REPlace record value - KTZREP";
                opcode_lookup[1][5] = "KTZ Undo for RePlace - KTZURP";
                opcode_lookup[4][1] = "Block cleanout opcode - KTBOPCLN";
                opcode_lookup[4][2] = "physical cleanout opcode - KTBPHCLN";
                opcode_lookup[4][3] = "single array change - KTBSARC";
                opcode_lookup[4][4] = "Multiple changes to an array - KTBMARC";
                opcode_lookup[4][5] = "format block - KTBOPFMB";
                opcode_lookup[4][6] = "commit-time block cleanout opcode - KTBOPBCC";
                opcode_lookup[4][7] = "ITL cleanout callback - KTBOPCLNL";
                opcode_lookup[4][8] = "Transaction Block Redo Block Commit Cleanout - KTBOPBCCL";
                opcode_lookup[5][1] = "Undo block or undo segment header - KTURDB";
                opcode_lookup[5][2] = "Update rollback segment header - KTURDH";
                opcode_lookup[5][3] = "Rollout a transaction begin - KTURBG";
                opcode_lookup[5][4] = "Commit transaction (transaction table update) - KTURCM";
    opcode_lookup[5][5] = "Create rollback segment (format) - no undo record - KTUFMT";
                opcode_lookup[5][6] = "Rollback record index in an undo block - KTUIRB";
                opcode_lookup[5][7] = "Begin transaction (transaction table update) - KTUUBG";
                opcode_lookup[5][8] = "Mark transaction as dead - KTURMR";
                opcode_lookup[5][9] = "Undo routine to rollback the extend of a rollback segment - KTUUAE";
                opcode_lookup[5][10] = "Redo to perform the rollback of extend of rollback segment - KTUREH";
                opcode_lookup[5][11] = "Rollback DBA in transaction table entry - KTUBRB";
                opcode_lookup[5][12] = "Change transaction state (in transaction table entry) - KTURST";
                opcode_lookup[5][13] = "Convert rollback segment format (V6 -> V7) - KTURCT";
                opcode_lookup[5][14] = "Change extent allocation parameters in a rollback segment - KTURUC";
                opcode_lookup[5][15] = "Undo Redo ConverT transaction table - KTURCTS";
                opcode_lookup[5][16] = "KTU - Redo for ConverT to Unlimited extents format - KTURCTU";
                opcode_lookup[5][17] = "KTU Redo - Convert for extent Move in extent map in - KTURCTM";
                opcode_lookup[5][18] = "Transaction Undo segment Redo set Parent Xid - KTURPX";
                opcode_lookup[5][19] = "Transaction start audit log record - KTUTSL";
                opcode_lookup[5][20] = "Transaction continue audit log record - KTUTSC";
                opcode_lookup[5][21] = "Transaction Control Redo ConverT undo seg Down to 8][0 format- KTURCVD";
                opcode_lookup[5][22] = "Transaction Redo - PHysical Changes - KTURPHC";
                opcode_lookup[5][23] = "Disable Block level Recovery - KTURDBR";
                opcode_lookup[5][24] = "Kernel Transaction Undo Relog CHanGe - KTURLGU";
                opcode_lookup[5][25] = "Join sub Transaction - KTURJT";
                opcode_lookup[5][26] = "Undo STopper undo callback - KTUUST";
                                                                                                    opcode_lookup[5][27] = "Transaction Control System Managed us Format - KTUSMFMT";
                opcode_lookup[5][28] = "Undo Need To Propagate - KTUUNTP  askmaclean][com";
                opcode_lookup[5][29] = "big undo - KTUBDB";
                opcode_lookup[5][30] = "change ondisk state for a distributed transaction - KTURCDTS";
                opcode_lookup[5][31] = "Flashback Archive Txn Table Redo Callback - KTUFATTRC";
                opcode_lookup[5][32] = "Flashback Archive Txn Table Redo Set - KTUFATTRS";
                opcode_lookup[5][33] = "change notification commit marker - KTUCHNF";
                opcode_lookup[5][34] = "NTP bit for change notfn - KTUQCNTTRC";
                opcode_lookup[5][35] = "Flashback Archive Collect Txn Table Redo Set - KTUFACTTRS";
                opcode_lookup[6][1] = "TaBleSpace Remove DataFile - TBSCRDF";
                opcode_lookup[6][2] = "TaBleSpace Add DataFile - TBSCADF";
                opcode_lookup[6][3] = "TaBleSpace OFfLine - TBSCOFL";
                opcode_lookup[6][4] = "TaBleSpace ONLine - TBSCONL";
                opcode_lookup[6][5] = "TaBleSpace ReaD-Write - TBSCRDW";
                opcode_lookup[6][6] = "TaBleSpace ReaD-Only - TBSCRDO";
                opcode_lookup[6][7] = "TaBleSpace Remove TableSpace - TBSCRTS";
                opcode_lookup[6][8] = "TaBleSpace Add TableSpace - TBSCATS";
                opcode_lookup[6][9] = "TaBleSpace Undo TsPitr - TBSCUTP";
                opcode_lookup[6][10] = "TaBleSpace undo plugged datafile convert - TBSCUCV";
                opcode_lookup[6][11] = "Tablespace Undo Rename - TBSCREN";
                opcode_lookup[10][1] = "load index block (Loader with direct mode) - KDICPDO";
                opcode_lookup[10][2] = "Insert leaf row - KDICLIN";
    opcode_lookup[10][3] = "Purge leaf row - KDICLPU";
                opcode_lookup[10][4] = "Mark leaf row deleted - KDICLDE";
                opcode_lookup[10][5] = "Restore leaf row (clear leaf delete flags) - KDICLRE";
                opcode_lookup[10][6] = "Lock index block - KDICLOK";
                opcode_lookup[10][7] = "Unlock index block - KDICULO";
                opcode_lookup[10][8] = "Initialize new leaf block - KDICLNE";
                opcode_lookup[10][9] = "Apply Itl Redo - KDICAIR";
                opcode_lookup[10][10] = "Set leaf block next link - KDICLNX";
                opcode_lookup[10][11] = "Set leaf block previous link - KDICLPR";
                opcode_lookup[10][12] = "Init root block after split - KDICRSP";
                opcode_lookup[10][13] = "Make leaf block empty - KDICLEM";
                opcode_lookup[10][14] = "Restore block before image - KDICIMA";
                opcode_lookup[10][15] = "Branch block row insert - KDICBIN";
                opcode_lookup[10][16] = "Branch block row purge - KDICBPU";
                opcode_lookup[10][17] = "Initialize new branch block - KDICBNE";
                opcode_lookup[10][18] = "Update keydata in row - KDICLUP";
                opcode_lookup[10][19] = "Clear row's split flag - KDICLCL";
                opcode_lookup[10][20] = "Set row's split flag - KDICLSE";
                opcode_lookup[10][21] = "General undo above the cache (undo) - KDICUGE";
                opcode_lookup[10][22] = "Undo operation on leaf key above the cache (undo) - KDICULK";
                opcode_lookup[10][23] = "Restore block to b-tree - KDICREB";
                opcode_lookup[10][24] = "Shrink ITL (transaction entries) - KDICSIT";
 opcode_lookup[10][25] = "Format root block redo - KDICFRB";
                opcode_lookup[10][26] = "Undo of format root block (undo) - KDICUFB";
                opcode_lookup[10][27] = "Redo for undo of format root block - KDICUFR";
                opcode_lookup[10][28] = "Undo for migrating block - KDICUMG";
                opcode_lookup[10][29] = "Redo for migrating block - KDICMG";
                opcode_lookup[10][32] = "Combine operation for insert and restore rows - KDICCOM";
                opcode_lookup[10][33] = "Temp index redo apply - KDICTIX  askmaclean][com";
                opcode_lookup[10][34] = "Remove block from b-tree and empty block - KDICFRE";
                opcode_lookup[10][35] = "- KDICLCU";
                opcode_lookup[10][36] = "Supplemental logging - KDICLMN";
                opcode_lookup[10][37] = "Undo of non-key updates - KDICULN";
                opcode_lookup[10][38] = "Logical non-key update - KDICICU";
                opcode_lookup[10][39] = "Branch update range - KDICBUR";
                opcode_lookup[10][40] = "Branch DBA update - KDICBDU";
                opcode_lookup[11][1] = "Interpret Undo Record (Undo) - KDOIUR";
                opcode_lookup[11][2] = "Insert Row Piece - KDOIRP";
                opcode_lookup[11][3] = "Drop Row Piece - KDODRP";
                opcode_lookup[11][4] = "Lock Row Piece - KDOLKR";
                opcode_lookup[11][5] = "Update Row Piece - KDOURP";
                opcode_lookup[11][6] = "Overwrite Row Piece - KDOORP";
        opcode_lookup[11][7] = "Manipulate First Column (add or delete the 1st column) - KDOMFC";
                opcode_lookup[11][8] = "Change Forwarding address - KDOCFA";
                opcode_lookup[11][9] = "Change the Cluster Key Index - KDOCKI";
                opcode_lookup[11][10] = "Set Key Links- KDOSKL";
                opcode_lookup[11][11] = "Quick Multi-Insert (ex";
                opcode_lookup[11][12] = "Quick Multi-Delete - KDOQMD";
                opcode_lookup[11][13] = "Toggle Block Header flags - KDOTBF";
                opcode_lookup[11][14] = "KDODSC";
                opcode_lookup[11][15] = "KDOMBC";
                opcode_lookup[11][16] = "Logminer support - RM for rowpiece with only logminer columns - KDOLMN";
                opcode_lookup[11][17] = "Logminer support - RM for LOB id key information - KDOLLB";
                opcode_lookup[11][18] = "Logminer support - RM for LOB operation errors - KDOLBE";
                opcode_lookup[11][19] = "Logminer support - array updates - KDOURA";
                opcode_lookup[11][20] = "Logminer support - KDOSHK";
                opcode_lookup[11][21] = "Logminer support - KDOURP2";
                opcode_lookup[11][22] = "Logminer support - KDOCMP";
                opcode_lookup[11][23] = "Logminer support - KDODCU";
                opcode_lookup[11][24] = "Logminer support - KDOMRK";
                opcode_lookup[11][25] = "Logminer support - KDOAIR";
                opcode_lookup[13][1] = "Data Segment Format - KTSDSF";
                opcode_lookup[13][2] = "format free list block - KTSFFB";
                opcode_lookup[13][3] = "redo for convert to unlimited extents format - KTSRCTU";
          opcode_lookup[13][4] = "fix segment header by moving its extent to ext 0 - KTSRFSH";
                opcode_lookup[13][5] = "format data block - KTSFRBFMT";
                opcode_lookup[13][6] = "set link value on block - KTSFRBLNK";
                opcode_lookup[13][7] = "freelist related fgroup/segheader redo - KTSFRGRP";
                opcode_lookup[13][8] = "freelist related fgroup/segheader undo - KTSFUGRP";
                opcode_lookup[13][9] = "undo for linking block to xnt freelist - KTSFUNLK";
                opcode_lookup[13][10] = "BITMAP - format segment header - KTSBSFO";
                opcode_lookup[13][11] = "BITMAP - format bitmap block - KTSBBFO";
                opcode_lookup[13][12] = "BITMAP - format bitmap index block - KTSBIFO";
                opcode_lookup[13][12] = "BITMAP - format bitmap index block - KTSBIFO";
                opcode_lookup[13][13] = "BITMAP - redo for bmb - KTSBBREDO";
                opcode_lookup[13][14] = "BITMAP - undo for BMB - KTSBBUNDO";
                opcode_lookup[13][15] = "BITMAP - redo for index map - KTSBIREDO";
                opcode_lookup[13][16] = "BITMAP - undo for index map - KTSBIUNDO";
                opcode_lookup[13][17] = "Bitmap Seg - format segment Header - KTSPHFO";
                opcode_lookup[13][18] = "Bitmap Seg - format First level bitmap block - KTSPFFO";
                opcode_lookup[13][19] = "Bitmap Seg - format Second level bitmap block - KTSPSFO";
                opcode_lookup[13][20] = "Bitmap Seg - format Third level bitmap block - KTSPTFO";
                opcode_lookup[13][21] = "Bitmap Seg - format data block - KTSPBFO";
                opcode_lookup[13][22] = "Bitmap Seg - Redo for L1 bmb - KTSPFREDO";
                opcode_lookup[13][23] = "Bitmap Seg - Undo for L1 BMB - KTSPFUNDO";
                opcode_lookup[13][24] = "Bitmap Seg - Redo for L2 bmb - KTSPSREDO";
  opcode_lookup[13][25] = "Bitmap Seg - Undo for L2 BMB - KTSPSUNDO";
                opcode_lookup[13][26] = "Bitmap Seg - Redo for L3 bmb - KTSPTREDO";
                opcode_lookup[13][27] = "Bitmap Seg - Undo for L3 BMB - KTSPTUNDO";
                opcode_lookup[13][28] = "Bitmap Seg - Redo for pagetable segment header block - KTSPHREDO";
                opcode_lookup[13][29] = "Bitmap Seg - Undo for pagetable segment header block - KTSPHUNDO";
                opcode_lookup[13][30] = "Bitmap Seg - format L1 BMB for LOB segments - KTSPLBFFO";
                opcode_lookup[13][31] = "Bitmap Seg - Shrink redo for L1 - KTSKFREDO";
                opcode_lookup[13][32] = "Bitmap Seg - Shrink redo for segment header - KTSKHREDO";
                opcode_lookup[13][33] = "Bitmap Seg - Shrink redo for extent map blk - KTSKEREDO";
                opcode_lookup[13][34] = "Bitmap Seg - Shrink undo for segment header - KTSKHUNDO";
                opcode_lookup[13][35] = "Bitmap Seg - Shrink undo for L1 - KTSKFUNDO";
                opcode_lookup[13][36] = "Bitmap Seg shrink related - KTSKSREDO";
                opcode_lookup[13][37] = "Bitmap Seg shrink related - KTSKSUNDO";
                opcode_lookup[13][38] = "Bitmap Seg shrink related - KTSKTREDO";
                opcode_lookup[13][39] = "Bitmap Seg shrink related - KTSKTUNDO";
                opcode_lookup[13][40] = "Bitmap Seg - Shrink redo for extent map blk - KTSKEUNDO";
                opcode_lookup[13][41] = "NGLOB format opcode Extent Header - KTSLEFREDO";
                opcode_lookup[13][42] = "NGLOB format opcode Persistent Undo - KTSLPFREDO";
                opcode_lookup[13][43] = "NGLOB format opcode Hash bucket - KTSLHFREDO";
                opcode_lookup[13][44] = "NGLOB format opcode Free SPace - KTSLFFREDO";
                opcode_lookup[13][45] = "NGLOB format opcode Segment Header - KTSLSFREDO";
                opcode_lookup[13][46] = "NGLOB format opcode data block - KTSLBFREDO";
             opcode_lookup[13][47] = "NGLOB block update Extent Header redo - KTSLEUREDO";
                opcode_lookup[13][48] = "NGLOB block update Extent Header undo - KTSLEUUNDO";
                opcode_lookup[13][49] = "NGLOB block update Hash Bucket redo - KTSLHUREDO";
                opcode_lookup[13][50] = "NGLOB block update Hash Bucket undo - KTSLHUUNDO";
                opcode_lookup[13][51] = "NGLOB block update Free Space redo - KTSLFUREDO";
                opcode_lookup[13][52] = "NGLOB block update Free Space undo - KTSLFUUNDO";
                opcode_lookup[13][53] = "NGLOB block update Persistent Undo redo - KTSLPUREDO";
                opcode_lookup[13][54] = "NGLOB block update Persistent Undo undo - KTSLPUUNDO";
                opcode_lookup[13][55] = "NGLOB block update Segment Header redo - KTSLSUREDO";
                opcode_lookup[13][56] = "NGLOB block update Segment Header undo - KTSLSUUNDO";
                opcode_lookup[14][1] = "Unlock Segment Header - KTECUSH";
                opcode_lookup[14][2] = "Redo set extent map disk LocK - KTECRLK";
                opcode_lookup[14][3] = "redo for conversion to unlimited format - KTEFRCU";
                opcode_lookup[14][4] = "extent operation redo - KTEOPEMREDO";
                opcode_lookup[14][5] = "extent operation undo - KTEOPEUNDO";
                opcode_lookup[14][6] = "extent map format redo - KTEOPEFREDO";
                opcode_lookup[14][7] = "redo - KTECNV";
                opcode_lookup[14][8] = "undo for truncate ops";
                opcode_lookup[14][9] = "undo for reformat of a ctl block - KTEFUCTL";
                opcode_lookup[14][10] = "redo to facilitate above undo - KTEFRCTL";
                opcode_lookup[14][11] = "redo to clean xids in seghdr/fgb - KTECRCLN";
                opcode_lookup[14][12] = "SMU-Retention";
             opcode_lookup[15][1] = "format save undo header - KTTFSU";
                opcode_lookup[15][2] = "add save undo record - KTTSUN";
                opcode_lookup[15][3] = "move to next block - KTTNBK";
                opcode_lookup[15][4] = "point to next save undo record - KTTNAS";
                opcode_lookup[15][5] = "update saveundo blk during save undo application - KTTUSB";
                opcode_lookup[17][1] = "End Hot Backup - KCVOPEHB";
                opcode_lookup[17][2] = "ENable Thread - KCVOPENT";
                opcode_lookup[17][3] = "Crash Recovery Marker - KCVOPCRM";
                opcode_lookup[17][4] = "ReSiZeable datafiles - KCVOPRSZ";
                opcode_lookup[17][5] = "tablespace ONline - KCVOPONL";
                opcode_lookup[17][6] = "tablespace OFFline - KCVOPOFF";
                opcode_lookup[17][7] = "tablespace ReaD Write - KCVOPRDW";
                opcode_lookup[17][8] = "tablespace ReaD Only - KCVOPRDO";
                opcode_lookup[17][9] = "ADDing datafiles to database - KCVOPADD";
                opcode_lookup[17][10] = "tablespace DRoP - KCVOPDRP";
                opcode_lookup[17][11] = "Tablespace PitR - KCVOPTPR";
                opcode_lookup[17][12] = "PLUgging datafiles to database - KCVOPPLG_PRE10GR2";
                opcode_lookup[17][13] = "convert plugged in datafiles - KCVOPCNV";
                opcode_lookup[17][14] = "ADding dataFiles to database - KCVOPADF_PRE10GR2";
                opcode_lookup[17][15] = "heart-beat redo - KCVOPHBR";
                opcode_lookup[17][16] = "tablespace rename - KCVOPTRN";
                opcode_lookup[17][17] = "ENable Thread - KCVOPENT_10GR2";
              opcode_lookup[17][18] = "tablespace ONline - KCVOPONL_10GR2";
                opcode_lookup[17][19] = "tablespace OFFline - KCVOPOFF_10GR2";
                opcode_lookup[17][20] = "tablespace ReaD Write - KCVOPRDW_10GR2";
                opcode_lookup[17][21] = "tablespace ReaD Only - KCVOPRDO_10GR2";
                opcode_lookup[17][22] = "PLUgging datafiles to db - KCVOPPLG_10GR2";
                opcode_lookup[17][23] = "ADding dataFiles to database - KCVOPADF_10GR2";
                opcode_lookup[17][24] = "convert plugged in datafiles - KCVOPCNV_10GR2";
                opcode_lookup[17][25] = "Tablespace PitR - KCVOPTPR_10GR2";
                opcode_lookup[17][26] = "for file drop in tablespace - KCVOPFDP";
                opcode_lookup[17][27] = "for internal thread enable - KCVOPIEN";
                opcode_lookup[17][28] = "readable standby metadata flush - KCVOPMFL";
                opcode_lookup[17][29] = "database key creation (after bumping compatible to 11g) - KCVOPDBK";
                opcode_lookup[17][30] = "ADding dataFiles to database - KCVOPADF";
                opcode_lookup[17][31] = "PLUgging datafiles to db - KCVOPPLG";
                opcode_lookup[17][32] = "for modifying space header info - KCVOPSPHUPD";
                opcode_lookup[17][33] = "TSE Masterkey Rekey - KCVOPTMR";
                opcode_lookup[18][1] = "Log block image - KCBKCOLB";
                opcode_lookup[18][2] = "Recovery testing - KCBKCORV";
                opcode_lookup[18][3] = "Object/Range reuse - KCBKCOREU";
                opcode_lookup[19][1] = "Direct block logging - KCBLCOLB";
                opcode_lookup[19][2] = "Invalidate range - KCBLCOIR";
                opcode_lookup[19][3] = "Direct block relogging - KCBLCRLB";
              opcode_lookup[19][4] = "Invalidate range relogging - KCBLCRIR";
                opcode_lookup[20][1] = "Format compatibility segment - KCKFCS";
                opcode_lookup[20][2] = "Update compatibility segment - KCKUCS";
                opcode_lookup[20][3] = "Update Root Dba in controlfile and file header 1 - KCKURD";
                opcode_lookup[20][4] = "Set bit in a SQL Tuning Existence Bit Vector - KCK_INV_SQL_SIG";
                opcode_lookup[20][5] = "Invalidate an SQL Statement by Signature - KCK_INV_SQL_SIG";
                opcode_lookup[20][6] = "Unauthorize cursors after sys privilege revoke - KCK_UNAUTH_CUR";
                opcode_lookup[21][1] = "Write data into ILOB data block - KDLOPWRI";
                opcode_lookup[22][1] = "format space header - KTFBHFO";
                opcode_lookup[22][2] = "space header generic redo - KTFBHREDO";
                opcode_lookup[22][3] = "space header undo - KTFBHUNDO";
                opcode_lookup[22][4] = "space bitmap block format - KTFBBFO";
                opcode_lookup[22][5] = "bitmap block generic redo - KTFBBREDO";
                opcode_lookup[23][1] = "Dummy block written callback - KCBBLWR";
                opcode_lookup[23][2] = "log reads - KCBBLRD";
                opcode_lookup[23][3] = "log DirectWrites - KCBBLDWR";
                opcode_lookup[24][1] = "common portion of the ddl - KRVDDL";
                opcode_lookup[24][2] = "direct load redo - KRVDLR";
                opcode_lookup[24][3] = "lob related info - KRVLOB";
                opcode_lookup[24][4] = "misc info - KRVMISC";
                opcode_lookup[24][5] = "user info - KRVUSER";
                opcode_lookup[24][6] = "direct load redo 10i - KRVDLR10";
      opcode_lookup[24][7] = "logminer undo opcode - KRVUOP";
                opcode_lookup[24][8] = "xmlredo - doc or dif - opcode - KRVXML";
                opcode_lookup[24][9] = "PL/SQL redo - KRVPLSQL";
                opcode_lookup[24][10] = "Uniform Redo Unchained - KRVURU";
                opcode_lookup[24][11] = "txn commit marker - KRVCMT";
                opcode_lookup[24][12] = "supplog marker - KRVCFF";
                opcode_lookup[25][1] = "undo - KDQSUN";
                opcode_lookup[25][2] = "init - KDQSIN";
                opcode_lookup[25][3] = "enqueue - KDQSEN";
                opcode_lookup[25][4] = "update - KDQSUP";
                opcode_lookup[25][5] = "delete - KDQSDL";
                opcode_lookup[25][6] = "lock - KDQSLK";
                opcode_lookup[25][7] = "min/max - KDQSMM";
                opcode_lookup[26][1] = "generic lob undo - KDLIRUNDO";
                opcode_lookup[26][2] = "generic lob redo - KDLIRREDO";
                opcode_lookup[26][3] = "lob block format redo - KDLIRFRMT";
                opcode_lookup[26][4] = "lob invalidation redo - KDLIRINVL";
                opcode_lookup[26][5] = "lob cache-load redo - KDLIRLOAD";
                opcode_lookup[26][6] = "direct lob direct-load redo - KDLIRBIMG";
                opcode_lookup[26][7] = "dummy calibration redo - KDLIRCALI";
                opcode_lookup[27][1] = "op-code for bitmap switch - KRCPBSW";

}

void enterRedo_file(RedoParser::Redo_fileContext * /*ctx*/)  { /* std::cout << "In Redo File: "  << std::endl; */ }
void exitRedo_file(RedoParser::Redo_fileContext * /*ctx*/)  {

//std::cout << "Found "<<number_of_change_vectors << " change vectors\n";

   int i;   
	for(i=0; i < (number_of_change_vectors) ; i++ )
	{
//For Debug         cout << "RECORD:" << i << "\n";	
	 change_vectors[i].print_change_vector(block_classes_real,opcode_lookup);
	}

  }
void enterRedo_record_info(RedoParser::Redo_record_infoContext * ctx)  { }
void exitRedo_record_info(RedoParser::Redo_record_infoContext * ctx)  { }
void enterRedo_info(RedoParser::Redo_infoContext * /*ctx*/)  { }
void exitRedo_info(RedoParser::Redo_infoContext * /*ctx*/)  { }
void enterRedo_record(RedoParser::Redo_recordContext * ctx)  {  }
void exitRedo_record(RedoParser::Redo_recordContext * ctx)  {
int i=0; 

//	cout << "B4 change_vectors_at_redo_record = " << change_vectors_at_redo_record << "\n"; 
        for (i=change_vectors_at_redo_record ; i <= number_of_change_vectors  ; i++ )
        {
                change_vectors[i].date = ctx->date_value()->getText();
        }
       change_vectors_at_redo_record=number_of_change_vectors;
//	cout << "AFTER change_vectors_at_redo_record = " << change_vectors_at_redo_record << "\n"; 
 }
void enterChange_records(RedoParser::Change_recordsContext * /*ctx*/)  { }
void exitChange_records(RedoParser::Change_recordsContext * ctx ) {   }
void enterThread(RedoParser::ThreadContext * /*ctx*/)  { }
void exitThread(RedoParser::ThreadContext * /*ctx*/)  { }
void enterThread_number(RedoParser::Thread_numberContext * /*ctx*/)  { }
void exitThread_number(RedoParser::Thread_numberContext * /*ctx*/)  { }
void enterRba(RedoParser::RbaContext * /*ctx*/)  { }
void exitRba(RedoParser::RbaContext * /*ctx*/)  { }
void enterLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext * /*ctx*/)  { }
void exitLog_file_sequence_number(RedoParser::Log_file_sequence_numberContext * /*ctx*/)  { }
void enterLog_file_block_number(RedoParser::Log_file_block_numberContext * /*ctx*/)  { }
void exitLog_file_block_number(RedoParser::Log_file_block_numberContext * /*ctx*/)  { }
void enterByte_offset(RedoParser::Byte_offsetContext * /*ctx*/)  { }
void exitByte_offset(RedoParser::Byte_offsetContext * /*ctx*/)  { }
void enterLen(RedoParser::LenContext * /*ctx*/)  { }
void exitLen(RedoParser::LenContext * /*ctx*/)  { }
void enterLen_value(RedoParser::Len_valueContext * /*ctx*/)  { }
void exitLen_value(RedoParser::Len_valueContext * /*ctx*/)  { }
void enterVld(RedoParser::VldContext * /*ctx*/)  { }
void exitVld(RedoParser::VldContext * /*ctx*/)  { }
void enterVld_value(RedoParser::Vld_valueContext * /*ctx*/)  { }
void exitVld_value(RedoParser::Vld_valueContext * /*ctx*/)  { }
void enterScn(RedoParser::ScnContext * /*ctx*/)  { }
void exitScn(RedoParser::ScnContext * /*ctx*/)  { }
void enterWrap(RedoParser::WrapContext * /*ctx*/)  { }
void exitWrap(RedoParser::WrapContext * /*ctx*/)  { }
void enterBase(RedoParser::BaseContext * /*ctx*/)  { }
void exitBase(RedoParser::BaseContext * /*ctx*/)  { }
void enterSubscn(RedoParser::SubscnContext * /*ctx*/)  { }
void exitSubscn(RedoParser::SubscnContext * /*ctx*/)  { }
void enterSubscn_value(RedoParser::Subscn_valueContext * /*ctx*/)  { }
void exitSubscn_value(RedoParser::Subscn_valueContext * /*ctx*/)  { }
void enterDate_value(RedoParser::Date_valueContext * /*ctx*/)  { }
void exitDate_value(RedoParser::Date_valueContext * /*ctx*/)  { }
void enterChg_prefix_exists(RedoParser::Chg_prefix_existsContext * /*ctx*/)  { }
void exitChg_prefix_exists(RedoParser::Chg_prefix_existsContext * /*ctx*/)  { }
void enterChange(RedoParser::ChangeContext * /*ctx*/)  { }
void exitChange(RedoParser::ChangeContext * ctx)  {   number_of_change_vectors++;  }
void enterKtust_redo(RedoParser::Ktust_redoContext * /*ctx*/)  { }
void exitKtust_redo(RedoParser::Ktust_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktust_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; change_vectors[number_of_change_vectors].ktust_redo_sqn = string_to_number.convert_hex_str_to_ulong(ctx->sqn()->sqn_value()->getText() ) ; }
void enterKtsfrbfmt_redo(RedoParser::Ktsfrbfmt_redoContext * /*ctx*/)  { }
void exitKtsfrbfmt_redo(RedoParser::Ktsfrbfmt_redoContext * /*ctx*/)  { }
void enterCfl(RedoParser::CflContext * /*ctx*/)  { }
void exitCfl(RedoParser::CflContext * /*ctx*/)  { }
void enterCfl_value(RedoParser::Cfl_valueContext * /*ctx*/)  { }
void exitCfl_value(RedoParser::Cfl_valueContext * /*ctx*/)  { }
void enterCscn(RedoParser::CscnContext * /*ctx*/)  { }
void exitCscn(RedoParser::CscnContext * /*ctx*/)  { }
void enterCscn_value(RedoParser::Cscn_valueContext * /*ctx*/)  { }
void exitCscn_value(RedoParser::Cscn_valueContext * /*ctx*/)  { }
void enterItls(RedoParser::ItlsContext * /*ctx*/)  { }
void exitItls(RedoParser::ItlsContext * /*ctx*/)  { }
void enterItls_value(RedoParser::Itls_valueContext * /*ctx*/)  { }
void exitItls_value(RedoParser::Itls_valueContext * /*ctx*/)  { }
void enterTyp(RedoParser::TypContext * /*ctx*/)  { }
void exitTyp(RedoParser::TypContext * /*ctx*/)  { }
void enterTyp_value(RedoParser::Typ_valueContext * /*ctx*/)  { }
void exitTyp_value(RedoParser::Typ_valueContext * ctx)  {  }
void enterType(RedoParser::TypeContext * /*ctx*/)  { }
void exitType(RedoParser::TypeContext * /*ctx*/)  { }
void enterType_value(RedoParser::Type_valueContext * /*ctx*/)  { }
void exitType_value(RedoParser::Type_valueContext * /*ctx*/)  { }
void enterSegobjd(RedoParser::SegobjdContext * /*ctx*/)  { }
void exitSegobjd(RedoParser::SegobjdContext * /*ctx*/)  { }
void enterSegobjd_value(RedoParser::Segobjd_valueContext * /*ctx*/)  { }
void exitSegobjd_value(RedoParser::Segobjd_valueContext * /*ctx*/)  { }
void enterKtsfm_redo(RedoParser::Ktsfm_redoContext * /*ctx*/)  { }
void exitKtsfm_redo(RedoParser::Ktsfm_redoContext * /*ctx*/)  { }
void enterNfl(RedoParser::NflContext * /*ctx*/)  { }
void exitNfl(RedoParser::NflContext * /*ctx*/)  { }
void enterNfl_value(RedoParser::Nfl_valueContext * /*ctx*/)  { }
void exitNfl_value(RedoParser::Nfl_valueContext * /*ctx*/)  { }
void enterKtsfrblnk_redo(RedoParser::Ktsfrblnk_redoContext * /*ctx*/)  { }
void exitKtsfrblnk_redo(RedoParser::Ktsfrblnk_redoContext * /*ctx*/)  { }
void enterKtsfrblnk_redo_opcode(RedoParser::Ktsfrblnk_redo_opcodeContext * /*ctx*/)  { }
void exitKtsfrblnk_redo_opcode(RedoParser::Ktsfrblnk_redo_opcodeContext * /*ctx*/)  { }
void enterKtucm_redo(RedoParser::Ktucm_redoContext * /*ctx*/)  { }
void exitKtucm_redo(RedoParser::Ktucm_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktucm_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; change_vectors[number_of_change_vectors].ktucm_redo_sqn = string_to_number.convert_hex_str_to_ulong(ctx->sqn()->sqn_value()->getText() ) ; }
void enterKtucf_redo(RedoParser::Ktucf_redoContext * /*ctx*/)  { }
void exitKtucf_redo(RedoParser::Ktucf_redoContext * /*ctx*/)  { }
void enterExt(RedoParser::ExtContext * /*ctx*/)  { }
void exitExt(RedoParser::ExtContext * /*ctx*/)  { }
void enterExt_value(RedoParser::Ext_valueContext * /*ctx*/)  { }
void exitExt_value(RedoParser::Ext_valueContext * /*ctx*/)  { }
void enterUba(RedoParser::UbaContext * /*ctx*/)  { }
void exitUba(RedoParser::UbaContext * /*ctx*/)  { }
void enterUba_value(RedoParser::Uba_valueContext * /*ctx*/)  { }
void exitUba_value(RedoParser::Uba_valueContext * /*ctx*/)  { }
void enterSta(RedoParser::StaContext * /*ctx*/)  { }
void exitSta(RedoParser::StaContext * /*ctx*/)  { }
void enterSta_value(RedoParser::Sta_valueContext * /*ctx*/)  { }
void exitSta_value(RedoParser::Sta_valueContext * /*ctx*/)  { }
void enterSrt(RedoParser::SrtContext * /*ctx*/)  { }
void exitSrt(RedoParser::SrtContext * /*ctx*/)  { }
void enterSrt_value(RedoParser::Srt_valueContext * /*ctx*/)  { }
void exitSrt_value(RedoParser::Srt_valueContext * /*ctx*/)  { }
void enterKtecush_redo(RedoParser::Ktecush_redoContext * /*ctx*/)  { }
void exitKtecush_redo(RedoParser::Ktecush_redoContext * /*ctx*/)  { }
void enterKtsfrgrp_redo(RedoParser::Ktsfrgrp_redoContext * /*ctx*/)  { }
void exitKtsfrgrp_redo(RedoParser::Ktsfrgrp_redoContext * /*ctx*/)  { }
void enterKtubl_redo(RedoParser::Ktubl_redoContext * /*ctx*/)  { }
void exitKtubl_redo(RedoParser::Ktubl_redoContext * ctx)  {  }
void enterKtubu_redo(RedoParser::Ktubu_redoContext * /*ctx*/)  { }
void exitKtubu_redo(RedoParser::Ktubu_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktubu_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; change_vectors[number_of_change_vectors].ktubu_redo_wrp = string_to_number.convert_hex_str_to_ulong(ctx->wrp()->wrp_value()->getText() ) ; }
void enterKtelk_redo(RedoParser::Ktelk_redoContext * /*ctx*/)  { }
void exitKtelk_redo(RedoParser::Ktelk_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktelk_redo_xid = ctx->xid()->xid_value()->getText()  ; }
void enterKtudb_redo(RedoParser::Ktudb_redoContext * /*ctx*/)  { }
void exitKtudb_redo(RedoParser::Ktudb_redoContext * ctx)  {  }
void enterKtudbu_redo(RedoParser::Ktudbu_redoContext * /*ctx*/)  { }
void exitKtudbu_redo(RedoParser::Ktudbu_redoContext * ctx)  { change_vectors[number_of_change_vectors].ktudbu_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; }
void enterObj(RedoParser::ObjContext * /*ctx*/)  { }
void exitObj(RedoParser::ObjContext * ctx)  {  change_vectors[number_of_change_vectors].obj = string_to_number.convert_dec_str_to_ulong(ctx->obj_value()->getText() ) ;}
void enterObjn(RedoParser::ObjnContext * /*ctx*/)  { }
void exitObjn(RedoParser::ObjnContext * /*ctx*/)  { }
void enterObjn_value(RedoParser::Objn_valueContext * /*ctx*/)  { }
void exitObjn_value(RedoParser::Objn_valueContext * /*ctx*/)  { }
void enterObjd(RedoParser::ObjdContext * /*ctx*/)  { }
void exitObjd(RedoParser::ObjdContext * ctx)  {current_objd = string_to_number.convert_dec_str_to_long(ctx->objd_value()->getText() ) ; }
void enterObjd_value(RedoParser::Objd_valueContext * /*ctx*/)  { }
void exitObjd_value(RedoParser::Objd_valueContext * /*ctx*/)  { }
void enterTsn(RedoParser::TsnContext * /*ctx*/)  { }
void exitTsn(RedoParser::TsnContext * /*ctx*/)  { }
void enterTsn_value(RedoParser::Tsn_valueContext * /*ctx*/)  { }
void exitTsn_value(RedoParser::Tsn_valueContext * /*ctx*/)  { }
void enterOpc(RedoParser::OpcContext * /*ctx*/)  { }
void exitOpc(RedoParser::OpcContext * /*ctx*/)  { }
void enterOpc_value(RedoParser::Opc_valueContext * /*ctx*/)  { }
void exitOpc_value(RedoParser::Opc_valueContext * /*ctx*/)  { }
void enterKtudh_redo(RedoParser::Ktudh_redoContext * /*ctx*/)  { }
void exitKtudh_redo(RedoParser::Ktudh_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktudh_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; change_vectors[number_of_change_vectors].ktudh_redo_sqn = string_to_number.convert_hex_str_to_ulong(ctx->sqn()->sqn_value()->getText() ) ; }
void enterFbi(RedoParser::FbiContext * /*ctx*/)  { }
void exitFbi(RedoParser::FbiContext * /*ctx*/)  { }
void enterFbi_value(RedoParser::Fbi_valueContext * /*ctx*/)  { }
void exitFbi_value(RedoParser::Fbi_valueContext * /*ctx*/)  { }
void enterSiz(RedoParser::SizContext * /*ctx*/)  { }
void exitSiz(RedoParser::SizContext * /*ctx*/)  { }
void enterSiz_value(RedoParser::Siz_valueContext * /*ctx*/)  { }
void exitSiz_value(RedoParser::Siz_valueContext * /*ctx*/)  { }
void enterSqn(RedoParser::SqnContext * /*ctx*/)  { }
void exitSqn(RedoParser::SqnContext * ctx)  {  }
void enterSqn_value(RedoParser::Sqn_valueContext * /*ctx*/)  { }
void exitSqn_value(RedoParser::Sqn_valueContext * /*ctx*/)  { }
void enterSpc(RedoParser::SpcContext * /*ctx*/)  { }
void exitSpc(RedoParser::SpcContext * /*ctx*/)  { }
void enterSpc_value(RedoParser::Spc_valueContext * /*ctx*/)  { }
void exitSpc_value(RedoParser::Spc_valueContext * /*ctx*/)  { }
void enterRec(RedoParser::RecContext * /*ctx*/)  { }
void exitRec(RedoParser::RecContext * /*ctx*/)  { }
void enterRec_value(RedoParser::Rec_valueContext * /*ctx*/)  { }
void exitRec_value(RedoParser::Rec_valueContext * /*ctx*/)  { }
void enterRci(RedoParser::RciContext * /*ctx*/)  { }
void exitRci(RedoParser::RciContext * /*ctx*/)  { }
void enterRci_value(RedoParser::Rci_valueContext * /*ctx*/)  { }
void exitRci_value(RedoParser::Rci_valueContext * /*ctx*/)  { }
void enterSlt(RedoParser::SltContext * /*ctx*/)  { }
void exitSlt(RedoParser::SltContext * ctx)  { }
void enterSlt_value(RedoParser::Slt_valueContext * /*ctx*/)  { }
void exitSlt_value(RedoParser::Slt_valueContext * /*ctx*/)  { }
void enterInvld(RedoParser::InvldContext * /*ctx*/)  { }
void exitInvld(RedoParser::InvldContext * /*ctx*/)  { }
void enterMedia_recovery_marker(RedoParser::Media_recovery_markerContext * /*ctx*/)  { }
void exitMedia_recovery_marker(RedoParser::Media_recovery_markerContext * ctx)  {change_vectors[number_of_change_vectors].obj = -1; }
void enterChange_number(RedoParser::Change_numberContext * /*ctx*/)  { }
void exitChange_number(RedoParser::Change_numberContext * /*ctx*/)  { }
void enterBlks(RedoParser::BlksContext * /*ctx*/)  { }
void exitBlks(RedoParser::BlksContext * /*ctx*/)  { }
void enterBlks_value(RedoParser::Blks_valueContext * /*ctx*/)  { }
void exitBlks_value(RedoParser::Blks_valueContext * /*ctx*/)  { }
void enterChg_type(RedoParser::Chg_typeContext * /*ctx*/)  { }
void exitChg_type(RedoParser::Chg_typeContext * /*ctx*/)  { }
void enterChg_type_value(RedoParser::Chg_type_valueContext * /*ctx*/)  { }
void exitChg_type_value(RedoParser::Chg_type_valueContext * /*ctx*/)  { }
void enterChg_class(RedoParser::Chg_classContext * /*ctx*/)  { }
void exitChg_class(RedoParser::Chg_classContext * ctx)  { change_vectors[number_of_change_vectors].cls = string_to_number.convert_dec_str_to_int(ctx->chg_class_value()->getText() ); }
void enterChg_class_value(RedoParser::Chg_class_valueContext * /*ctx*/)  { }
void exitChg_class_value(RedoParser::Chg_class_valueContext * /*ctx*/)  { }
void enterChg_afn(RedoParser::Chg_afnContext * /*ctx*/)  { }
void exitChg_afn(RedoParser::Chg_afnContext * ctx)  {change_vectors[number_of_change_vectors].afn = string_to_number.convert_dec_str_to_int(ctx->afn_value()->getText() ) ; }
void enterAfn_value(RedoParser::Afn_valueContext * /*ctx*/)  { }
void exitAfn_value(RedoParser::Afn_valueContext * ctx)  { }
void enterDba(RedoParser::DbaContext * /*ctx*/)  { }
void exitDba(RedoParser::DbaContext * ctx)  { change_vectors[number_of_change_vectors].dba = string_to_number.convert_hex_str_to_ulong(ctx->dba_value()->getText() ) ;}
void enterDba_value(RedoParser::Dba_valueContext * /*ctx*/)  { }
void exitDba_value(RedoParser::Dba_valueContext * /*ctx*/)  { }
void enterChg_obj(RedoParser::Chg_objContext * /*ctx*/)  { }
void exitChg_obj(RedoParser::Chg_objContext * ctx)  { change_vectors[number_of_change_vectors].obj = string_to_number.convert_dec_str_to_ulong(ctx->obj_value()->getText() );}
void enterObj_value(RedoParser::Obj_valueContext * /*ctx*/)  { }
void exitObj_value(RedoParser::Obj_valueContext * /*ctx*/)  { }
void enterSeq(RedoParser::SeqContext * /*ctx*/)  { }
void exitSeq(RedoParser::SeqContext * ctx)  {current_seq=string_to_number.convert_dec_str_to_int( ctx->seq_value()->getText() ); }
void enterSeq_value(RedoParser::Seq_valueContext * /*ctx*/)  { }
void exitSeq_value(RedoParser::Seq_valueContext * /*ctx*/)  { }
void enterXid(RedoParser::XidContext * /*ctx*/)  { }
void exitXid(RedoParser::XidContext * ctx)  {
/*
	int i=0; 
        for (i=change_vectors_at_last_xid ; i <= number_of_change_vectors  ; i++ )
        {
                change_vectors[i].xid = ctx->xid_value()->getText();
        }
 
      change_vectors_at_last_xid=number_of_change_vectors;
*/

       change_vectors[number_of_change_vectors].xid = ctx->xid_value()->getText();
	
 }

void enterXid_value(RedoParser::Xid_valueContext * /*ctx*/)  { }
void exitXid_value(RedoParser::Xid_valueContext * /*ctx*/)  { }
void enterLayer_opcode(RedoParser::Layer_opcodeContext * /*ctx*/)  { }
void exitLayer_opcode(RedoParser::Layer_opcodeContext * ctx)  {change_vectors[number_of_change_vectors].layer =string_to_number.convert_dec_str_to_int( ctx->layer()->getText() ) ; change_vectors[number_of_change_vectors].opcode = string_to_number.convert_dec_str_to_int(ctx->opcode()->getText() ); }
void enterLayer(RedoParser::LayerContext * /*ctx*/)  { }
void exitLayer(RedoParser::LayerContext * /*ctx*/)  { }
void enterOpcode(RedoParser::OpcodeContext * /*ctx*/)  { }
void exitOpcode(RedoParser::OpcodeContext * /*ctx*/)  { }
void enterEnc(RedoParser::EncContext * /*ctx*/)  { }
void exitEnc(RedoParser::EncContext * /*ctx*/)  { }
void enterEnc_value(RedoParser::Enc_valueContext * /*ctx*/)  { }
void exitEnc_value(RedoParser::Enc_valueContext * /*ctx*/)  { }
void enterRbl(RedoParser::RblContext * /*ctx*/)  { }
void exitRbl(RedoParser::RblContext * /*ctx*/)  { }
void enterRbl_value(RedoParser::Rbl_valueContext * /*ctx*/)  { }
void exitRbl_value(RedoParser::Rbl_valueContext * /*ctx*/)  { }
void enterFlg(RedoParser::FlgContext * /*ctx*/)  { }
void exitFlg(RedoParser::FlgContext * /*ctx*/)  { }
void enterFlg_value(RedoParser::Flg_valueContext * /*ctx*/)  { }
void exitFlg_value(RedoParser::Flg_valueContext * /*ctx*/)  { }
void enterCon_id(RedoParser::Con_idContext * /*ctx*/)  { }
void exitCon_id(RedoParser::Con_idContext * ctx)  { change_vectors[number_of_change_vectors].con_id = string_to_number.convert_dec_str_to_int(ctx->con_id_value()->getText() ); }
void enterCon_id_value(RedoParser::Con_id_valueContext * /*ctx*/)  { }
void exitCon_id_value(RedoParser::Con_id_valueContext * ctx)  {  }
void enterCon_uid(RedoParser::Con_uidContext * /*ctx*/)  { }
void exitCon_uid(RedoParser::Con_uidContext * /*ctx*/)  { }
void enterCon_uid_value(RedoParser::Con_uid_valueContext * /*ctx*/)  { }
void exitCon_uid_value(RedoParser::Con_uid_valueContext * /*ctx*/)  { }
void enterColumn_info(RedoParser::Column_infoContext * /*ctx*/)  { }
void exitColumn_info(RedoParser::Column_infoContext * /*ctx*/)  { }
void enterColumn_info_detail(RedoParser::Column_info_detailContext * /*ctx*/)  { }
void exitColumn_info_detail(RedoParser::Column_info_detailContext * /*ctx*/)  { }
void enterColumn_datatype(RedoParser::Column_datatypeContext * /*ctx*/)  { }
void exitColumn_datatype(RedoParser::Column_datatypeContext * /*ctx*/)  { }
void enterColumn_number(RedoParser::Column_numberContext * /*ctx*/)  { }
void exitColumn_number(RedoParser::Column_numberContext * /*ctx*/)  { }
void enterColumn_value(RedoParser::Column_valueContext * /*ctx*/)  { }
void exitColumn_value(RedoParser::Column_valueContext * /*ctx*/)  { }
void enterBlock_cleanout_record(RedoParser::Block_cleanout_recordContext * /*ctx*/)  { }
void exitBlock_cleanout_record(RedoParser::Block_cleanout_recordContext * /*ctx*/)  { }
void enterOpt(RedoParser::OptContext * /*ctx*/)  { }
void exitOpt(RedoParser::OptContext * /*ctx*/)  { }
void enterOpt_value(RedoParser::Opt_valueContext * /*ctx*/)  { }
void exitOpt_value(RedoParser::Opt_valueContext * /*ctx*/)  { }
void enterVer(RedoParser::VerContext * /*ctx*/)  { }
void exitVer(RedoParser::VerContext * /*ctx*/)  { }
void enterVer_value(RedoParser::Ver_valueContext * /*ctx*/)  { }
void exitVer_value(RedoParser::Ver_valueContext * /*ctx*/)  { }
void enterBigscn(RedoParser::BigscnContext * /*ctx*/)  { }
void exitBigscn(RedoParser::BigscnContext * /*ctx*/)  { }
void enterCompact(RedoParser::CompactContext * /*ctx*/)  { }
void exitCompact(RedoParser::CompactContext * /*ctx*/)  { }
void enterSpare(RedoParser::SpareContext * /*ctx*/)  { }
void exitSpare(RedoParser::SpareContext * /*ctx*/)  { }
void enterSpare_value(RedoParser::Spare_valueContext * /*ctx*/)  { }
void exitSpare_value(RedoParser::Spare_valueContext * /*ctx*/)  { }
void enterLfdba(RedoParser::LfdbaContext * /*ctx*/)  { }
void exitLfdba(RedoParser::LfdbaContext * /*ctx*/)  { }
void enterLfdba_value(RedoParser::Lfdba_valueContext * /*ctx*/)  { }
void exitLfdba_value(RedoParser::Lfdba_valueContext * /*ctx*/)  { }
void enterDatafile_resize_marker(RedoParser::Datafile_resize_markerContext * ctx)  { 
change_vectors[number_of_change_vectors].resize_afn = string_to_number.convert_dec_str_to_int(ctx->file()->file_value()->getText() );
change_vectors[number_of_change_vectors].resize_old_size= string_to_number.convert_dec_str_to_int(ctx->old_size()->old_size_value()->getText() );
change_vectors[number_of_change_vectors].resize_new_size= string_to_number.convert_dec_str_to_int(ctx->new_size()->new_size_value()->getText() );

}
void exitDatafile_resize_marker(RedoParser::Datafile_resize_markerContext * /*ctx*/)  { }
void enterFile(RedoParser::FileContext * /*ctx*/)  { }
void exitFile(RedoParser::FileContext * /*ctx*/)  { }
void enterFile_value(RedoParser::File_valueContext * /*ctx*/)  { }
void exitFile_value(RedoParser::File_valueContext * /*ctx*/)  { }
void enterOld_size(RedoParser::Old_sizeContext * /*ctx*/)  { }
void exitOld_size(RedoParser::Old_sizeContext * /*ctx*/)  { }
void enterOld_size_value(RedoParser::Old_size_valueContext * /*ctx*/)  { }
void exitOld_size_value(RedoParser::Old_size_valueContext * /*ctx*/)  { }
void enterNew_size(RedoParser::New_sizeContext * /*ctx*/)  { }
void exitNew_size(RedoParser::New_sizeContext * /*ctx*/)  { }
void enterNew_size_value(RedoParser::New_size_valueContext * /*ctx*/)  { }
void exitNew_size_value(RedoParser::New_size_valueContext * /*ctx*/)  { }
void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/)  { }
void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/)  { }
void visitTerminal(antlr4::tree::TerminalNode * /*node*/)  { }
void visitErrorNode(antlr4::tree::ErrorNode * /*node*/)  { }
};

