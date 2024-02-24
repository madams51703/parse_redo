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
    unsigned long log_file_block_number;
    unsigned long log_file_block_byte_offset;
    unsigned long redo_record_len;
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

    unsigned long dl_rows=0;



    // Member Functions()

    void print_raw_change_vector(char * raw_redo_log_name)
    {

    	std::fstream f;
        int i;
    	std::FILE* fp = std::fopen(raw_redo_log_name, "rb");
    	assert(fp);

    	std::fseek(fp, 0, SEEK_END); // seek to end
    	const std::size_t filesize = std::ftell(fp);
    	std::vector<char> buffer(filesize);

    	std::fseek(fp, (512*log_file_block_number) + log_file_block_byte_offset , SEEK_SET); // seek to start
    	int msa ;
   	msa = std::fread(&(buffer[0]), sizeof(char),redo_record_len, fp);
    	f.open("raw.redo."  + std::to_string( log_file_block_number) + "." + std::to_string(log_file_block_byte_offset) , fstream::out );
        for (i = 0 ; i < redo_record_len ; i ++ )
        {
    		f << buffer[i];
        }
    	f.close();
    	std::fclose(fp);
   }

    void printobjd() { cout << " OBJ is:" << obj; }
    void print_change_vector( array <std::string,17> block_classes,string opcodes[100][100],int print_option) {
	if (print_option == 1)
	{
		print_csv_change_vector(block_classes,opcodes);
	}
	if (print_option == 2)
	{
		print_direct_loader();
	}
    }
   
    void print_direct_loader()
    {
		if ( layer == 19 and opcode==1 )
		{
			cout << "Direct Load rows: " << dl_rows << " Object: " << obj << "\n" ;
		}

   }

    void print_csv_change_vector( array <std::string,17> block_classes,string opcodes[100][100]) {
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
public:

    char  raw_redo_log_name[10000];
    int enable_raw_redo=0;
    int display_layer=0;
    int display_opcode=0;
    unsigned long display_object=0;
    int display_column=0;
    int print_option=0;
    long column_of_interest=-1;

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

array<change_vector,40000000> change_vectors;
long number_of_change_vectors=0;
long change_vectors_at_redo_record=0;
long change_vectors_at_last_xid=0;
long current_objd=0;
std::string current_seq="";

public:
RedoWalker() {
//              cout << "Starting\n";
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
/*
   int i;   
	for(i=0; i < (number_of_change_vectors) ; i++ )
	{
//For Debug         cout << "RECORD:" << i << "\n";	
	 change_vectors[i].print_change_vector(block_classes_real,opcode_lookup);
	}
*/
  }
void enterRedo_record_info(RedoParser::Redo_record_infoContext * ctx)  { }
void exitRedo_record_info(RedoParser::Redo_record_infoContext * ctx)  {
int i=0; 

        for (i=change_vectors_at_redo_record ; i < number_of_change_vectors   ; i++ )
        {
                change_vectors[i].date = ctx->redo_record()->date_value()->getText();

                change_vectors[i].log_file_block_number  = string_to_number.convert_hex_str_to_ulong(ctx->redo_record()->rba()->log_file_block_number()->getText() );

                change_vectors[i].log_file_block_byte_offset  = string_to_number.convert_hex_str_to_ulong(ctx->redo_record()->rba()->byte_offset()->getText() );

                change_vectors[i].redo_record_len  = string_to_number.convert_hex_str_to_ulong(ctx->redo_record()->len()->len_value()->getText() );

 		change_vectors[i].print_change_vector(block_classes_real,opcode_lookup,print_option);


		if (enable_raw_redo == 1)
		{
                	change_vectors[i].print_raw_change_vector(raw_redo_log_name);
		}
        }
        change_vectors_at_redo_record=number_of_change_vectors;

 }
void enterRedo_info(RedoParser::Redo_infoContext * /*ctx*/)  { /* cout << "In Redo Info\n" ; */ }
void exitRedo_info(RedoParser::Redo_infoContext * /*ctx*/)  { }
void enterRedo_record(RedoParser::Redo_recordContext * ctx)  {  }
void exitRedo_record(RedoParser::Redo_recordContext * ctx)  { }
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
void exitChange(RedoParser::ChangeContext * ctx)  {    number_of_change_vectors++;  }
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
void exitKtubu_redo(RedoParser::Ktubu_redoContext * ctx)  {change_vectors[number_of_change_vectors].ktubu_redo_slt = string_to_number.convert_hex_str_to_long(ctx->slt()->slt_value()->getText() ) ; /* change_vectors[number_of_change_vectors].ktubu_redo_wrp = string_to_number.convert_hex_str_to_ulong(ctx->wrp()->wrp_value()->getText() ) ; */ }
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


void enterTabn_qmi_slot_info(RedoParser::Tabn_qmi_slot_infoContext * ctx) { 
//cout << "Entering Tabn_qmi_slot_info at line : " << ctx->getStart()->getLine() << "\n"; 
}
void exitTabn_qmi_slot_info(RedoParser::Tabn_qmi_slot_infoContext * ctx) { 
//cout << "Exiting Tabn_qmi_slot_info at line : " << ctx->getStop()->getLine() << "\n"; 

}


void enterTabn_qmi_slot_info_do(RedoParser::Tabn_qmi_slot_info_doContext * ctx )  {
//cout << "Entering Tabn_qmi_slot_info_do at line : " << ctx->getStop()->getLine() << "\n";

 }
void exitTabn_qmi_slot_info_do(RedoParser::Tabn_qmi_slot_info_doContext * ctx) { 
//cout << "Exiting  Tabn_qmi_slot_info_do at line : " << ctx->getStop()->getLine() << "\n";

}
void enterTabn_qm_slot(RedoParser::Tabn_qm_slotContext * ctx) {
//cout << "Entering  Tabn_qm_slot at line : " << ctx->getStart()->getLine() << "\n";

 }
void exitTabn_qm_slot(RedoParser::Tabn_qm_slotContext * ctx) {
//cout << "Exiting  Tabn_qm_slot at line : " << ctx->getStop()->getLine() << "\n";

 }



void enterBlock_written(RedoParser::Block_writtenContext * ctx ) { }
void exitBlock_written(RedoParser::Block_writtenContext * ctx ) { }
void enterRdba(RedoParser::RdbaContext * ctx ) { }
void exitRdba(RedoParser::RdbaContext * ctx ) { }
void enterRdba_value(RedoParser::Rdba_valueContext * ctx ) { }
void exitRdba_value(RedoParser::Rdba_valueContext * ctx ) { }
void enterBft(RedoParser::BftContext * ctx ) { }
void exitBft(RedoParser::BftContext * ctx ) { }
void enterBft_value(RedoParser::Bft_valueContext * ctx ) { }
void exitBft_value(RedoParser::Bft_valueContext * ctx ) { }
void enterNon_bft(RedoParser::Non_bftContext * ctx ) { }
void exitNon_bft(RedoParser::Non_bftContext * ctx ) { }
void enterNon_bft_value(RedoParser::Non_bft_valueContext * ctx ) { }
void exitNon_bft_value(RedoParser::Non_bft_valueContext * ctx ) { }
void enterLwn_info(RedoParser::Lwn_infoContext * ctx ) { }
void exitLwn_info(RedoParser::Lwn_infoContext * ctx ) { }
void enterNst(RedoParser::NstContext * ctx ) { }
void exitNst(RedoParser::NstContext * ctx ) { }
void enterNst_value(RedoParser::Nst_valueContext * ctx ) { }
void exitNst_value(RedoParser::Nst_valueContext * ctx ) { }
void enterHwms(RedoParser::HwmsContext * ctx ) { }
void exitHwms(RedoParser::HwmsContext * ctx ) { }
void enterSegment_header_undo(RedoParser::Segment_header_undoContext * ctx ) { }
void exitSegment_header_undo(RedoParser::Segment_header_undoContext * ctx ) { }
void enterLasts_in_header(RedoParser::Lasts_in_headerContext * ctx ) { }
void exitLasts_in_header(RedoParser::Lasts_in_headerContext * ctx ) { }
void enterLf(RedoParser::LfContext * ctx ) { }
void exitLf(RedoParser::LfContext * ctx ) { }
void enterLf_value(RedoParser::Lf_valueContext * ctx ) { }
void exitLf_value(RedoParser::Lf_valueContext * ctx ) { }
void enterLs(RedoParser::LsContext * ctx ) { }
void exitLs(RedoParser::LsContext * ctx ) { }
void enterLs_value(RedoParser::Ls_valueContext * ctx ) { }
void exitLs_value(RedoParser::Ls_valueContext * ctx ) { }
void enterLt(RedoParser::LtContext * ctx ) { }
void exitLt(RedoParser::LtContext * ctx ) { }
void enterLt_value(RedoParser::Lt_valueContext * ctx ) { }
void exitLt_value(RedoParser::Lt_valueContext * ctx ) { }
void enterFt(RedoParser::FtContext * ctx ) { }
void exitFt(RedoParser::FtContext * ctx ) { }
void enterFt_value(RedoParser::Ft_valueContext * ctx ) { }
void exitFt_value(RedoParser::Ft_valueContext * ctx ) { }
void enterMcls(RedoParser::MclsContext * ctx ) { }
void exitMcls(RedoParser::MclsContext * ctx ) { }
void enterMcls_value(RedoParser::Mcls_valueContext * ctx ) { }
void exitMcls_value(RedoParser::Mcls_valueContext * ctx ) { }
void enterMapredo_offset(RedoParser::Mapredo_offsetContext * ctx ) { }
void exitMapredo_offset(RedoParser::Mapredo_offsetContext * ctx ) { }
void enterMapredo_offset_value(RedoParser::Mapredo_offset_valueContext * ctx ) { }
void exitMapredo_offset_value(RedoParser::Mapredo_offset_valueContext * ctx ) { }
void enterMapblock_dba(RedoParser::Mapblock_dbaContext * ctx ) { }
void exitMapblock_dba(RedoParser::Mapblock_dbaContext * ctx ) { }
void enterMapblock_dba_value(RedoParser::Mapblock_dba_valueContext * ctx ) { }
void exitMapblock_dba_value(RedoParser::Mapblock_dba_valueContext * ctx ) { }
void enterHint_dba(RedoParser::Hint_dbaContext * ctx ) { }
void exitHint_dba(RedoParser::Hint_dbaContext * ctx ) { }
void enterHint_dba_value(RedoParser::Hint_dba_valueContext * ctx ) { }
void exitHint_dba_value(RedoParser::Hint_dba_valueContext * ctx ) { }
void enterBitmap_undo(RedoParser::Bitmap_undoContext * ctx ) { }
void exitBitmap_undo(RedoParser::Bitmap_undoContext * ctx ) { }
void enterBitmap_undo_lev(RedoParser::Bitmap_undo_levContext * ctx ) { }
void exitBitmap_undo_lev(RedoParser::Bitmap_undo_levContext * ctx ) { }
void enterBitmap_undo_lev_value(RedoParser::Bitmap_undo_lev_valueContext * ctx ) { }
void exitBitmap_undo_lev_value(RedoParser::Bitmap_undo_lev_valueContext * ctx ) { }
void enterBitmap_undo_op(RedoParser::Bitmap_undo_opContext * ctx ) { }
void exitBitmap_undo_op(RedoParser::Bitmap_undo_opContext * ctx ) { }
void enterFcls(RedoParser::FclsContext * ctx ) { }
void exitFcls(RedoParser::FclsContext * ctx ) { }
void enterFcls_value(RedoParser::Fcls_valueContext * ctx ) { }
void exitFcls_value(RedoParser::Fcls_valueContext * ctx ) { }
void enterScls(RedoParser::SclsContext * ctx ) { }
void exitScls(RedoParser::SclsContext * ctx ) { }
void enterScls_value(RedoParser::Scls_valueContext * ctx ) { }
void exitScls_value(RedoParser::Scls_valueContext * ctx ) { }
void enterL_dba(RedoParser::L_dbaContext * ctx ) { }
void exitL_dba(RedoParser::L_dbaContext * ctx ) { }
void enterL_dba_value(RedoParser::L_dba_valueContext * ctx ) { }
void exitL_dba_value(RedoParser::L_dba_valueContext * ctx ) { }
void enterBitmap_redo(RedoParser::Bitmap_redoContext * ctx ) { }
void exitBitmap_redo(RedoParser::Bitmap_redoContext * ctx ) { }
void enterBitmap_redo_options(RedoParser::Bitmap_redo_optionsContext * ctx ) { }
void exitBitmap_redo_options(RedoParser::Bitmap_redo_optionsContext * ctx ) { }
void enterNbits(RedoParser::NbitsContext * ctx ) { }
void exitNbits(RedoParser::NbitsContext * ctx ) { }
void enterNbits_value(RedoParser::Nbits_valueContext * ctx ) { }
void exitNbits_value(RedoParser::Nbits_valueContext * ctx ) { }
void enterInst(RedoParser::InstContext * ctx ) { }
void exitInst(RedoParser::InstContext * ctx ) { }
void enterInst_value(RedoParser::Inst_valueContext * ctx ) { }
void exitInst_value(RedoParser::Inst_valueContext * ctx ) { }
void enterNmrk(RedoParser::NmrkContext * ctx ) { }
void exitNmrk(RedoParser::NmrkContext * ctx ) { }
void enterNmrk_value(RedoParser::Nmrk_valueContext * ctx ) { }
void exitNmrk_value(RedoParser::Nmrk_valueContext * ctx ) { }
void enterNumber_of_blocks(RedoParser::Number_of_blocksContext * ctx ) { }
void exitNumber_of_blocks(RedoParser::Number_of_blocksContext * ctx ) { }
void enterNumber_of_blocks_value(RedoParser::Number_of_blocks_valueContext * ctx ) { }
void exitNumber_of_blocks_value(RedoParser::Number_of_blocks_valueContext * ctx ) { }
void enterNumber(RedoParser::NumberContext * ctx ) { }
void exitNumber(RedoParser::NumberContext * ctx ) { }
void enterNumber_value(RedoParser::Number_valueContext * ctx ) { }
void exitNumber_value(RedoParser::Number_valueContext * ctx ) { }
void enterIncn(RedoParser::IncnContext * ctx ) { }
void exitIncn(RedoParser::IncnContext * ctx ) { }
void enterIncn_value(RedoParser::Incn_valueContext * ctx ) { }
void exitIncn_value(RedoParser::Incn_valueContext * ctx ) { }
void enterKtspbredo(RedoParser::KtspbredoContext * ctx ) { }
void exitKtspbredo(RedoParser::KtspbredoContext * ctx ) { }
void enterFmt_flag(RedoParser::Fmt_flagContext * ctx ) { }
void exitFmt_flag(RedoParser::Fmt_flagContext * ctx ) { }
void enterFmt_flag_value(RedoParser::Fmt_flag_valueContext * ctx ) { }
void exitFmt_flag_value(RedoParser::Fmt_flag_valueContext * ctx ) { }
void enterPoff(RedoParser::PoffContext * ctx ) { }
void exitPoff(RedoParser::PoffContext * ctx ) { }
void enterPoff_value(RedoParser::Poff_valueContext * ctx ) { }
void exitPoff_value(RedoParser::Poff_valueContext * ctx ) { }
void enterInc_pound(RedoParser::Inc_poundContext * ctx ) { }
void exitInc_pound(RedoParser::Inc_poundContext * ctx ) { }
void enterInc_pound_value(RedoParser::Inc_pound_valueContext * ctx ) { }
void exitInc_pound_value(RedoParser::Inc_pound_valueContext * ctx ) { }
void enterParent_dba(RedoParser::Parent_dbaContext * ctx ) { }
void exitParent_dba(RedoParser::Parent_dbaContext * ctx ) { }
void enterParent_dba_value(RedoParser::Parent_dba_valueContext * ctx ) { }
void exitParent_dba_value(RedoParser::Parent_dba_valueContext * ctx ) { }
void enterReuse_redo_entry(RedoParser::Reuse_redo_entryContext * ctx ) { }
void exitReuse_redo_entry(RedoParser::Reuse_redo_entryContext * ctx ) { }
void enterBitmap_redo_op(RedoParser::Bitmap_redo_opContext * ctx ) { }
void exitBitmap_redo_op(RedoParser::Bitmap_redo_opContext * ctx ) { }
void enterBitmap_opcode(RedoParser::Bitmap_opcodeContext * ctx ) { }
void exitBitmap_opcode(RedoParser::Bitmap_opcodeContext * ctx ) { }
void enterBitmap_opcode_value(RedoParser::Bitmap_opcode_valueContext * ctx ) { }
void exitBitmap_opcode_value(RedoParser::Bitmap_opcode_valueContext * ctx ) { }
void enterRedo_to_mark_block_free(RedoParser::Redo_to_mark_block_freeContext * ctx ) { }
void exitRedo_to_mark_block_free(RedoParser::Redo_to_mark_block_freeContext * ctx ) { }
void enterNcmt(RedoParser::NcmtContext * ctx ) { }
void exitNcmt(RedoParser::NcmtContext * ctx ) { }
void enterNcmt_value(RedoParser::Ncmt_valueContext * ctx ) { }
void exitNcmt_value(RedoParser::Ncmt_valueContext * ctx ) { }
void enterCommit_slot_list(RedoParser::Commit_slot_listContext * ctx ) { }
void exitCommit_slot_list(RedoParser::Commit_slot_listContext * ctx ) { }
void enterCommit_slot_info(RedoParser::Commit_slot_infoContext * ctx ) { }
void exitCommit_slot_info(RedoParser::Commit_slot_infoContext * ctx ) { }
void enterSlot(RedoParser::SlotContext * ctx ) { }
void exitSlot(RedoParser::SlotContext * ctx ) { }
void enterSlot_value(RedoParser::Slot_valueContext * ctx ) { }
void exitSlot_value(RedoParser::Slot_valueContext * ctx ) { }
void enterLocking_transaction(RedoParser::Locking_transactionContext * ctx ) { }
void exitLocking_transaction(RedoParser::Locking_transactionContext * ctx ) { }
void enterLocking_transaction_value(RedoParser::Locking_transaction_valueContext * ctx ) { }
void exitLocking_transaction_value(RedoParser::Locking_transaction_valueContext * ctx ) { }
void enterOffset(RedoParser::OffsetContext * ctx ) { }
void exitOffset(RedoParser::OffsetContext * ctx ) { }
void enterOffset_value(RedoParser::Offset_valueContext * ctx ) { }
void exitOffset_value(RedoParser::Offset_valueContext * ctx ) { }
void enterNewstate(RedoParser::NewstateContext * ctx ) { }
void exitNewstate(RedoParser::NewstateContext * ctx ) { }
void enterNewstate_value(RedoParser::Newstate_valueContext * ctx ) { }
void exitNewstate_value(RedoParser::Newstate_valueContext * ctx ) { }
void enterBitmap_level_value(RedoParser::Bitmap_level_valueContext * ctx ) { }
void exitBitmap_level_value(RedoParser::Bitmap_level_valueContext * ctx ) { }
void enterBi_tran(RedoParser::Bi_tranContext * ctx ) { }
void exitBi_tran(RedoParser::Bi_tranContext * ctx ) { }
void enterCreate_load_index(RedoParser::Create_load_indexContext * ctx ) { }
void exitCreate_load_index(RedoParser::Create_load_indexContext * ctx ) { }
void enterCreate_load_index_info(RedoParser::Create_load_index_infoContext * ctx ) { }
void exitCreate_load_index_info(RedoParser::Create_load_index_infoContext * ctx ) { }
void enterCreate_load_scn_fsc(RedoParser::Create_load_scn_fscContext * ctx ) { }
void exitCreate_load_scn_fsc(RedoParser::Create_load_scn_fscContext * ctx ) { }
void enterKd_off_info(RedoParser::Kd_off_infoContext * ctx ) { }
void exitKd_off_info(RedoParser::Kd_off_infoContext * ctx ) { }
void enterIndex_undo_info(RedoParser::Index_undo_infoContext * ctx ) { }
void exitIndex_undo_info(RedoParser::Index_undo_infoContext * ctx ) { }
void enterInit_leaf_block_being_split(RedoParser::Init_leaf_block_being_splitContext * ctx ) { }
void exitInit_leaf_block_being_split(RedoParser::Init_leaf_block_being_splitContext * ctx ) { }
void enterLock_block(RedoParser::Lock_blockContext * ctx ) { }
void exitLock_block(RedoParser::Lock_blockContext * ctx ) { }
void enterNew_itl(RedoParser::New_itlContext * ctx ) { }
void exitNew_itl(RedoParser::New_itlContext * ctx ) { }
void enterNew_itl_value(RedoParser::New_itl_valueContext * ctx ) { }
void exitNew_itl_value(RedoParser::New_itl_valueContext * ctx ) { }
void enterLev(RedoParser::LevContext * ctx ) { }
void exitLev(RedoParser::LevContext * ctx ) { }
void enterLev_value(RedoParser::Lev_valueContext * ctx ) { }
void exitLev_value(RedoParser::Lev_valueContext * ctx ) { }
void enterNco(RedoParser::NcoContext * ctx ) { }
void exitNco(RedoParser::NcoContext * ctx ) { }
void enterNco_value(RedoParser::Nco_valueContext * ctx ) { }
void exitNco_value(RedoParser::Nco_valueContext * ctx ) { }
void enterLmc(RedoParser::LmcContext * ctx ) { }
void exitLmc(RedoParser::LmcContext * ctx ) { }
void enterLmc_value(RedoParser::Lmc_valueContext * ctx ) { }
void exitLmc_value(RedoParser::Lmc_valueContext * ctx ) { }
void enterSplit_itl(RedoParser::Split_itlContext * ctx ) { }
void exitSplit_itl(RedoParser::Split_itlContext * ctx ) { }
void enterSplit_itl_value(RedoParser::Split_itl_valueContext * ctx ) { }
void exitSplit_itl_value(RedoParser::Split_itl_valueContext * ctx ) { }
void enterLock_itl(RedoParser::Lock_itlContext * ctx ) { }
void exitLock_itl(RedoParser::Lock_itlContext * ctx ) { }
void enterLock_itl_operation(RedoParser::Lock_itl_operationContext * ctx ) { }
void exitLock_itl_operation(RedoParser::Lock_itl_operationContext * ctx ) { }
void enterSeghdr_dba(RedoParser::Seghdr_dbaContext * ctx ) { }
void exitSeghdr_dba(RedoParser::Seghdr_dbaContext * ctx ) { }
void enterSeghdr_dba_value(RedoParser::Seghdr_dba_valueContext * ctx ) { }
void exitSeghdr_dba_value(RedoParser::Seghdr_dba_valueContext * ctx ) { }
void enterUnlock_block(RedoParser::Unlock_blockContext * ctx ) { }
void exitUnlock_block(RedoParser::Unlock_blockContext * ctx ) { }
void enterUnlock_block_value(RedoParser::Unlock_block_valueContext * ctx ) { }
void exitUnlock_block_value(RedoParser::Unlock_block_valueContext * ctx ) { }
void enterHeader_opcode(RedoParser::Header_opcodeContext * ctx ) { }
void exitHeader_opcode(RedoParser::Header_opcodeContext * ctx ) { }
void enterSave(RedoParser::SaveContext * ctx ) { }
void exitSave(RedoParser::SaveContext * ctx ) { }
void enterPending_op(RedoParser::Pending_opContext * ctx ) { }
void exitPending_op(RedoParser::Pending_opContext * ctx ) { }
void enterUsing_extent(RedoParser::Using_extentContext * ctx ) { }
void exitUsing_extent(RedoParser::Using_extentContext * ctx ) { }
void enterBegin(RedoParser::BeginContext * ctx ) { }
void exitBegin(RedoParser::BeginContext * ctx ) { }
void enterBegin_value(RedoParser::Begin_valueContext * ctx ) { }
void exitBegin_value(RedoParser::Begin_valueContext * ctx ) { }
void enterInstance(RedoParser::InstanceContext * ctx ) { }
void exitInstance(RedoParser::InstanceContext * ctx ) { }
void enterInstance_value(RedoParser::Instance_valueContext * ctx ) { }
void exitInstance_value(RedoParser::Instance_valueContext * ctx ) { }
void enterBegin_clause(RedoParser::Begin_clauseContext * ctx ) { }
void exitBegin_clause(RedoParser::Begin_clauseContext * ctx ) { }
void enterUse_bits(RedoParser::Use_bitsContext * ctx ) { }
void exitUse_bits(RedoParser::Use_bitsContext * ctx ) { }
void enterKtfbn_redo(RedoParser::Ktfbn_redoContext * ctx ) { }
void exitKtfbn_redo(RedoParser::Ktfbn_redoContext * ctx ) { }
void enterUtime(RedoParser::UtimeContext * ctx ) { }
void exitUtime(RedoParser::UtimeContext * ctx ) { }
void enterUtime_value(RedoParser::Utime_valueContext * ctx ) { }
void exitUtime_value(RedoParser::Utime_valueContext * ctx ) { }
void enterKtfbb_redo(RedoParser::Ktfbb_redoContext * ctx ) { }
void exitKtfbb_redo(RedoParser::Ktfbb_redoContext * ctx ) { }
void enterSpace_header(RedoParser::Space_headerContext * ctx ) { }
void exitSpace_header(RedoParser::Space_headerContext * ctx ) { }
void enterSpace_header_dba(RedoParser::Space_header_dbaContext * ctx ) { }
void exitSpace_header_dba(RedoParser::Space_header_dbaContext * ctx ) { }
void enterSpace_header_dba_value(RedoParser::Space_header_dba_valueContext * ctx ) { }
void exitSpace_header_dba_value(RedoParser::Space_header_dba_valueContext * ctx ) { }
void enterFree_extent(RedoParser::Free_extentContext * ctx ) { }
void exitFree_extent(RedoParser::Free_extentContext * ctx ) { }
void enterKtfbh_undo(RedoParser::Ktfbh_undoContext * ctx ) { }
void exitKtfbh_undo(RedoParser::Ktfbh_undoContext * ctx ) { }
void enterKtfbh_redo(RedoParser::Ktfbh_redoContext * ctx ) { }
void exitKtfbh_redo(RedoParser::Ktfbh_redoContext * ctx ) { }
void enterSave_using(RedoParser::Save_usingContext * ctx ) { }
void exitSave_using(RedoParser::Save_usingContext * ctx ) { }
void enterKtudbr_redo(RedoParser::Ktudbr_redoContext * ctx ) { }
void exitKtudbr_redo(RedoParser::Ktudbr_redoContext * ctx ) { }
void enterKtsbifm_redo(RedoParser::Ktsbifm_redoContext * ctx ) { }
void exitKtsbifm_redo(RedoParser::Ktsbifm_redoContext * ctx ) { }
void enterNblks(RedoParser::NblksContext * ctx ) { }
void exitNblks(RedoParser::NblksContext * ctx ) { }
void enterNblks_value(RedoParser::Nblks_valueContext * ctx ) { }
void exitNblks_value(RedoParser::Nblks_valueContext * ctx ) { }
void enterForcel3(RedoParser::Forcel3Context * ctx ) { }
void exitForcel3(RedoParser::Forcel3Context * ctx ) { }
void enterForcel3_value(RedoParser::Forcel3_valueContext * ctx ) { }
void exitForcel3_value(RedoParser::Forcel3_valueContext * ctx ) { }
void enterKtsl_undo(RedoParser::Ktsl_undoContext * ctx ) { }
void exitKtsl_undo(RedoParser::Ktsl_undoContext * ctx ) { }
void enterKtsl_redo(RedoParser::Ktsl_redoContext * ctx ) { }
void exitKtsl_redo(RedoParser::Ktsl_redoContext * ctx ) { }
void enterPua_options(RedoParser::Pua_optionsContext * ctx ) { }
void exitPua_options(RedoParser::Pua_optionsContext * ctx ) { }
void enterOn_disk_rollback(RedoParser::On_disk_rollbackContext * ctx ) { }
void exitOn_disk_rollback(RedoParser::On_disk_rollbackContext * ctx ) { }
void enterMark_chunk_free(RedoParser::Mark_chunk_freeContext * ctx ) { }
void exitMark_chunk_free(RedoParser::Mark_chunk_freeContext * ctx ) { }
void enterMark_chunk_free_value(RedoParser::Mark_chunk_free_valueContext * ctx ) { }
void exitMark_chunk_free_value(RedoParser::Mark_chunk_free_valueContext * ctx ) { }
void enterClass(RedoParser::ClassContext * ctx ) { }
void exitClass(RedoParser::ClassContext * ctx ) { }
void enterClass_value(RedoParser::Class_valueContext * ctx ) { }
void exitClass_value(RedoParser::Class_valueContext * ctx ) { }
void enterPua_chunk(RedoParser::Pua_chunkContext * ctx ) { }
void exitPua_chunk(RedoParser::Pua_chunkContext * ctx ) { }
void enterPua_chunk_value(RedoParser::Pua_chunk_valueContext * ctx ) { }
void exitPua_chunk_value(RedoParser::Pua_chunk_valueContext * ctx ) { }
void enterSplit_length(RedoParser::Split_lengthContext * ctx ) { }
void exitSplit_length(RedoParser::Split_lengthContext * ctx ) { }
void enterSplit_length_value(RedoParser::Split_length_valueContext * ctx ) { }
void exitSplit_length_value(RedoParser::Split_length_valueContext * ctx ) { }
void enterRedo_to_change_opcode(RedoParser::Redo_to_change_opcodeContext * ctx ) { }
void exitRedo_to_change_opcode(RedoParser::Redo_to_change_opcodeContext * ctx ) { }
void enterKtsbi_redo(RedoParser::Ktsbi_redoContext * ctx ) { }
void exitKtsbi_redo(RedoParser::Ktsbi_redoContext * ctx ) { }
void enterResettok(RedoParser::ResettokContext * ctx ) { }
void exitResettok(RedoParser::ResettokContext * ctx ) { }
void enterBit_no(RedoParser::Bit_noContext * ctx ) { }
void exitBit_no(RedoParser::Bit_noContext * ctx ) { }
void enterBit_no_value(RedoParser::Bit_no_valueContext * ctx ) { }
void exitBit_no_value(RedoParser::Bit_no_valueContext * ctx ) { }
void enterKtsph_redo(RedoParser::Ktsph_redoContext * ctx ) { }
void exitKtsph_redo(RedoParser::Ktsph_redoContext * ctx ) { }
void enterKtsphfredo(RedoParser::KtsphfredoContext * ctx ) { }
void exitKtsphfredo(RedoParser::KtsphfredoContext * ctx ) { }
void enterCsc(RedoParser::CscContext * ctx ) { }
void exitCsc(RedoParser::CscContext * ctx ) { }
void enterCsc_value(RedoParser::Csc_valueContext * ctx ) { }
void exitCsc_value(RedoParser::Csc_valueContext * ctx ) { }
void enterItl(RedoParser::ItlContext * ctx ) { }
void exitItl(RedoParser::ItlContext * ctx ) { }
void enterItl_value(RedoParser::Itl_valueContext * ctx ) { }
void exitItl_value(RedoParser::Itl_valueContext * ctx ) { }
void enterNext_dba(RedoParser::Next_dbaContext * ctx ) { }
void exitNext_dba(RedoParser::Next_dbaContext * ctx ) { }
void enterNext_dba_value(RedoParser::Next_dba_valueContext * ctx ) { }
void exitNext_dba_value(RedoParser::Next_dba_valueContext * ctx ) { }
void enterKtsfrblnk_itli(RedoParser::Ktsfrblnk_itliContext * ctx ) { }
void exitKtsfrblnk_itli(RedoParser::Ktsfrblnk_itliContext * ctx ) { }
void enterKtsfrblnk_itli_value(RedoParser::Ktsfrblnk_itli_valueContext * ctx ) { }
void exitKtsfrblnk_itli_value(RedoParser::Ktsfrblnk_itli_valueContext * ctx ) { }
void enterKtsfrgrp_opcode_info(RedoParser::Ktsfrgrp_opcode_infoContext * ctx ) { }
void exitKtsfrgrp_opcode_info(RedoParser::Ktsfrgrp_opcode_infoContext * ctx ) { }
void enterHead(RedoParser::HeadContext * ctx ) { }
void exitHead(RedoParser::HeadContext * ctx ) { }
void enterHead_value(RedoParser::Head_valueContext * ctx ) { }
void exitHead_value(RedoParser::Head_valueContext * ctx ) { }
void enterTail(RedoParser::TailContext * ctx ) { }
void exitTail(RedoParser::TailContext * ctx ) { }
void enterTail_value(RedoParser::Tail_valueContext * ctx ) { }
void exitTail_value(RedoParser::Tail_valueContext * ctx ) { }
void enterKtsfrgrp_flag(RedoParser::Ktsfrgrp_flagContext * ctx ) { }
void exitKtsfrgrp_flag(RedoParser::Ktsfrgrp_flagContext * ctx ) { }
void enterCcnt(RedoParser::CcntContext * ctx ) { }
void exitCcnt(RedoParser::CcntContext * ctx ) { }
void enterCcnt_value(RedoParser::Ccnt_valueContext * ctx ) { }
void exitCcnt_value(RedoParser::Ccnt_valueContext * ctx ) { }
void enterNbk(RedoParser::NbkContext * ctx ) { }
void exitNbk(RedoParser::NbkContext * ctx ) { }
void enterNbk_value(RedoParser::Nbk_valueContext * ctx ) { }
void exitNbk_value(RedoParser::Nbk_valueContext * ctx ) { }
void enterKtsfrgrp_opcode(RedoParser::Ktsfrgrp_opcodeContext * ctx ) { }
void exitKtsfrgrp_opcode(RedoParser::Ktsfrgrp_opcodeContext * ctx ) { }
void enterKtsfrgrp_opcode_value(RedoParser::Ktsfrgrp_opcode_valueContext * ctx ) { }
void exitKtsfrgrp_opcode_value(RedoParser::Ktsfrgrp_opcode_valueContext * ctx ) { }
void enterKtsfrgrp_slot(RedoParser::Ktsfrgrp_slotContext * ctx ) { }
void exitKtsfrgrp_slot(RedoParser::Ktsfrgrp_slotContext * ctx ) { }
void enterKtsfrgrp_slot_value(RedoParser::Ktsfrgrp_slot_valueContext * ctx ) { }
void exitKtsfrgrp_slot_value(RedoParser::Ktsfrgrp_slot_valueContext * ctx ) { }
void enterKteopu_undo(RedoParser::Kteopu_undoContext * ctx ) { }
void exitKteopu_undo(RedoParser::Kteopu_undoContext * ctx ) { }
void enterSegdba(RedoParser::SegdbaContext * ctx ) { }
void exitSegdba(RedoParser::SegdbaContext * ctx ) { }
void enterMapdba(RedoParser::MapdbaContext * ctx ) { }
void exitMapdba(RedoParser::MapdbaContext * ctx ) { }
void enterMapdba_value(RedoParser::Mapdba_valueContext * ctx ) { }
void exitMapdba_value(RedoParser::Mapdba_valueContext * ctx ) { }
void enterSegdba_value(RedoParser::Segdba_valueContext * ctx ) { }
void exitSegdba_value(RedoParser::Segdba_valueContext * ctx ) { }
void enterKdli_info(RedoParser::Kdli_infoContext * ctx ) { }
void exitKdli_info(RedoParser::Kdli_infoContext * ctx ) { }
void enterKdli_common(RedoParser::Kdli_commonContext * ctx ) { }
void exitKdli_common(RedoParser::Kdli_commonContext * ctx ) { }
void enterKdli_specific(RedoParser::Kdli_specificContext * ctx ) { }
void exitKdli_specific(RedoParser::Kdli_specificContext * ctx ) { }
void enterKdli_data_load(RedoParser::Kdli_data_loadContext * ctx ) { }
void exitKdli_data_load(RedoParser::Kdli_data_loadContext * ctx ) { }
void enterKdli_op(RedoParser::Kdli_opContext * ctx ) { }
void exitKdli_op(RedoParser::Kdli_opContext * ctx ) { }
void enterKdli_op_value(RedoParser::Kdli_op_valueContext * ctx ) { }
void exitKdli_op_value(RedoParser::Kdli_op_valueContext * ctx ) { }
void enterKdli_type(RedoParser::Kdli_typeContext * ctx ) { }
void exitKdli_type(RedoParser::Kdli_typeContext * ctx ) { }
void enterKdli_type_value(RedoParser::Kdli_type_valueContext * ctx ) { }
void exitKdli_type_value(RedoParser::Kdli_type_valueContext * ctx ) { }
void enterKdli_flg0(RedoParser::Kdli_flg0Context * ctx ) { }
void exitKdli_flg0(RedoParser::Kdli_flg0Context * ctx ) { }
void enterKdli_flg0_option(RedoParser::Kdli_flg0_optionContext * ctx ) { }
void exitKdli_flg0_option(RedoParser::Kdli_flg0_optionContext * ctx ) { }
void enterKdli_flg0_value(RedoParser::Kdli_flg0_valueContext * ctx ) { }
void exitKdli_flg0_value(RedoParser::Kdli_flg0_valueContext * ctx ) { }
void enterKdli_flg1(RedoParser::Kdli_flg1Context * ctx ) { }
void exitKdli_flg1(RedoParser::Kdli_flg1Context * ctx ) { }
void enterKdli_flg1_value(RedoParser::Kdli_flg1_valueContext * ctx ) { }
void exitKdli_flg1_value(RedoParser::Kdli_flg1_valueContext * ctx ) { }
void enterKdli_poff(RedoParser::Kdli_poffContext * ctx ) { }
void exitKdli_poff(RedoParser::Kdli_poffContext * ctx ) { }
void enterKdli_dba(RedoParser::Kdli_dbaContext * ctx ) { }
void exitKdli_dba(RedoParser::Kdli_dbaContext * ctx ) { }
void enterKdli_psiz(RedoParser::Kdli_psizContext * ctx ) { }
void exitKdli_psiz(RedoParser::Kdli_psizContext * ctx ) { }
void enterKdli_psiz_value(RedoParser::Kdli_psiz_valueContext * ctx ) { }
void exitKdli_psiz_value(RedoParser::Kdli_psiz_valueContext * ctx ) { }
void enterKdli_fpload(RedoParser::Kdli_fploadContext * ctx ) { }
void exitKdli_fpload(RedoParser::Kdli_fploadContext * ctx ) { }
void enterKdli_bsz(RedoParser::Kdli_bszContext * ctx ) { }
void exitKdli_bsz(RedoParser::Kdli_bszContext * ctx ) { }
void enterKdli_bsz_value(RedoParser::Kdli_bsz_valueContext * ctx ) { }
void exitKdli_bsz_value(RedoParser::Kdli_bsz_valueContext * ctx ) { }
void enterKdli_scn(RedoParser::Kdli_scnContext * ctx ) { }
void exitKdli_scn(RedoParser::Kdli_scnContext * ctx ) { }
void enterKdli_scn_value(RedoParser::Kdli_scn_valueContext * ctx ) { }
void exitKdli_scn_value(RedoParser::Kdli_scn_valueContext * ctx ) { }
void enterKdli_xid(RedoParser::Kdli_xidContext * ctx ) { }
void exitKdli_xid(RedoParser::Kdli_xidContext * ctx ) { }
void enterKdli_objd(RedoParser::Kdli_objdContext * ctx ) { }
void exitKdli_objd(RedoParser::Kdli_objdContext * ctx ) { }
void enterKdli_load_data(RedoParser::Kdli_load_dataContext * ctx ) { }
void exitKdli_load_data(RedoParser::Kdli_load_dataContext * ctx ) { }
void enterKdli_bdba(RedoParser::Kdli_bdbaContext * ctx ) { }
void exitKdli_bdba(RedoParser::Kdli_bdbaContext * ctx ) { }
void enterKdli_kdlich(RedoParser::Kdli_kdlichContext * ctx ) { }
void exitKdli_kdlich(RedoParser::Kdli_kdlichContext * ctx ) { }
void enterKdli_kdlich_flg1(RedoParser::Kdli_kdlich_flg1Context * ctx ) { }
void exitKdli_kdlich_flg1(RedoParser::Kdli_kdlich_flg1Context * ctx ) { }
void enterKdli_kdlich_flg1_value(RedoParser::Kdli_kdlich_flg1_valueContext * ctx ) { }
void exitKdli_kdlich_flg1_value(RedoParser::Kdli_kdlich_flg1_valueContext * ctx ) { }
void enterKdli_kdlich_scn(RedoParser::Kdli_kdlich_scnContext * ctx ) { }
void exitKdli_kdlich_scn(RedoParser::Kdli_kdlich_scnContext * ctx ) { }
void enterKdli_kdlich_flg0(RedoParser::Kdli_kdlich_flg0Context * ctx ) { }
void exitKdli_kdlich_flg0(RedoParser::Kdli_kdlich_flg0Context * ctx ) { }
void enterLock_equal(RedoParser::Lock_equalContext * ctx ) { }
void exitLock_equal(RedoParser::Lock_equalContext * ctx ) { }
void enterLock_equal_value(RedoParser::Lock_equal_valueContext * ctx ) { }
void exitLock_equal_value(RedoParser::Lock_equal_valueContext * ctx ) { }
void enterKdli_kdlich_lid(RedoParser::Kdli_kdlich_lidContext * ctx ) { }
void exitKdli_kdlich_lid(RedoParser::Kdli_kdlich_lidContext * ctx ) { }
void enterKdli_kdlich_lid_value(RedoParser::Kdli_kdlich_lid_valueContext * ctx ) { }
void exitKdli_kdlich_lid_value(RedoParser::Kdli_kdlich_lid_valueContext * ctx ) { }
void enterKdli_kdlich_spare(RedoParser::Kdli_kdlich_spareContext * ctx ) { }
void exitKdli_kdlich_spare(RedoParser::Kdli_kdlich_spareContext * ctx ) { }
void enterKdli_kdlich_spare_value(RedoParser::Kdli_kdlich_spare_valueContext * ctx ) { }
void exitKdli_kdlich_spare_value(RedoParser::Kdli_kdlich_spare_valueContext * ctx ) { }
void enterKdli_kdlidh(RedoParser::Kdli_kdlidhContext * ctx ) { }
void exitKdli_kdlidh(RedoParser::Kdli_kdlidhContext * ctx ) { }
void enterKdli_kdlidh_flg2(RedoParser::Kdli_kdlidh_flg2Context * ctx ) { }
void exitKdli_kdlidh_flg2(RedoParser::Kdli_kdlidh_flg2Context * ctx ) { }
void enterKdli_kdlidh_flg2_options(RedoParser::Kdli_kdlidh_flg2_optionsContext * ctx ) { }
void exitKdli_kdlidh_flg2_options(RedoParser::Kdli_kdlidh_flg2_optionsContext * ctx ) { }
void enterKdli_kdlidh_flg2_value(RedoParser::Kdli_kdlidh_flg2_valueContext * ctx ) { }
void exitKdli_kdlidh_flg2_value(RedoParser::Kdli_kdlidh_flg2_valueContext * ctx ) { }
void enterKdli_kdlidh_lid_equal(RedoParser::Kdli_kdlidh_lid_equalContext * ctx ) { }
void exitKdli_kdlidh_lid_equal(RedoParser::Kdli_kdlidh_lid_equalContext * ctx ) { }
void enterKdli_kdlidh_lid_value(RedoParser::Kdli_kdlidh_lid_valueContext * ctx ) { }
void exitKdli_kdlidh_lid_value(RedoParser::Kdli_kdlidh_lid_valueContext * ctx ) { }
void enterKdli_kdlidh_flg3(RedoParser::Kdli_kdlidh_flg3Context * ctx ) { }
void exitKdli_kdlidh_flg3(RedoParser::Kdli_kdlidh_flg3Context * ctx ) { }
void enterKdli_kdlidh_flg3_value(RedoParser::Kdli_kdlidh_flg3_valueContext * ctx ) { }
void exitKdli_kdlidh_flg3_value(RedoParser::Kdli_kdlidh_flg3_valueContext * ctx ) { }
void enterKdli_kdlidh_pskip(RedoParser::Kdli_kdlidh_pskipContext * ctx ) { }
void exitKdli_kdlidh_pskip(RedoParser::Kdli_kdlidh_pskipContext * ctx ) { }
void enterKdli_kdlidh_pskip_value(RedoParser::Kdli_kdlidh_pskip_valueContext * ctx ) { }
void exitKdli_kdlidh_pskip_value(RedoParser::Kdli_kdlidh_pskip_valueContext * ctx ) { }
void enterKdli_kdlidh_sskip(RedoParser::Kdli_kdlidh_sskipContext * ctx ) { }
void exitKdli_kdlidh_sskip(RedoParser::Kdli_kdlidh_sskipContext * ctx ) { }
void enterKdli_kdlidh_sskip_value(RedoParser::Kdli_kdlidh_sskip_valueContext * ctx ) { }
void exitKdli_kdlidh_sskip_value(RedoParser::Kdli_kdlidh_sskip_valueContext * ctx ) { }
void enterKdli_kdlidh_hash_equal(RedoParser::Kdli_kdlidh_hash_equalContext * ctx ) { }
void exitKdli_kdlidh_hash_equal(RedoParser::Kdli_kdlidh_hash_equalContext * ctx ) { }
void enterKdli_kdlidh_hash_equal_value(RedoParser::Kdli_kdlidh_hash_equal_valueContext * ctx ) { }
void exitKdli_kdlidh_hash_equal_value(RedoParser::Kdli_kdlidh_hash_equal_valueContext * ctx ) { }
void enterKdli_kdlidh_hash(RedoParser::Kdli_kdlidh_hashContext * ctx ) { }
void exitKdli_kdlidh_hash(RedoParser::Kdli_kdlidh_hashContext * ctx ) { }
void enterKdli_kdlidh_hash_value(RedoParser::Kdli_kdlidh_hash_valueContext * ctx ) { }
void exitKdli_kdlidh_hash_value(RedoParser::Kdli_kdlidh_hash_valueContext * ctx ) { }
void enterKdli_kdlidh_cmap(RedoParser::Kdli_kdlidh_cmapContext * ctx ) { }
void exitKdli_kdlidh_cmap(RedoParser::Kdli_kdlidh_cmapContext * ctx ) { }
void enterKdli_kdlidh_cmap_value(RedoParser::Kdli_kdlidh_cmap_valueContext * ctx ) { }
void exitKdli_kdlidh_cmap_value(RedoParser::Kdli_kdlidh_cmap_valueContext * ctx ) { }
void enterKdli_kdlidh_pfill(RedoParser::Kdli_kdlidh_pfillContext * ctx ) { }
void exitKdli_kdlidh_pfill(RedoParser::Kdli_kdlidh_pfillContext * ctx ) { }
void enterKdli_kdlidh_pfill_value(RedoParser::Kdli_kdlidh_pfill_valueContext * ctx ) { }
void exitKdli_kdlidh_pfill_value(RedoParser::Kdli_kdlidh_pfill_valueContext * ctx ) { }
void enterKdli_kdlidh_hwm(RedoParser::Kdli_kdlidh_hwmContext * ctx ) { }
void exitKdli_kdlidh_hwm(RedoParser::Kdli_kdlidh_hwmContext * ctx ) { }
void enterKdli_kdlidh_hwm_value(RedoParser::Kdli_kdlidh_hwm_valueContext * ctx ) { }
void exitKdli_kdlidh_hwm_value(RedoParser::Kdli_kdlidh_hwm_valueContext * ctx ) { }
void enterKdli_kdlidh_spr(RedoParser::Kdli_kdlidh_sprContext * ctx ) { }
void exitKdli_kdlidh_spr(RedoParser::Kdli_kdlidh_sprContext * ctx ) { }
void enterKdli_kdlidh_spr_value(RedoParser::Kdli_kdlidh_spr_valueContext * ctx ) { }
void exitKdli_kdlidh_spr_value(RedoParser::Kdli_kdlidh_spr_valueContext * ctx ) { }
void enterKdi_data_load(RedoParser::Kdi_data_loadContext * ctx ) { }
void exitKdi_data_load(RedoParser::Kdi_data_loadContext * ctx ) { }
void enterUndo_info(RedoParser::Undo_infoContext * ctx ) { }
void exitUndo_info(RedoParser::Undo_infoContext * ctx ) { }
void enterUndo_prefix_info(RedoParser::Undo_prefix_infoContext * ctx ) { }
void exitUndo_prefix_info(RedoParser::Undo_prefix_infoContext * ctx ) { }
void enterUndo_type(RedoParser::Undo_typeContext * ctx ) { }
void exitUndo_type(RedoParser::Undo_typeContext * ctx ) { }
void enterBegin_trans(RedoParser::Begin_transContext * ctx ) { }
void exitBegin_trans(RedoParser::Begin_transContext * ctx ) { }
void enterBegin_trans_info(RedoParser::Begin_trans_infoContext * ctx ) { }
void exitBegin_trans_info(RedoParser::Begin_trans_infoContext * ctx ) { }
void enterRegular_undo(RedoParser::Regular_undoContext * ctx ) { }
void exitRegular_undo(RedoParser::Regular_undoContext * ctx ) { }
void enterUser_undo_done(RedoParser::User_undo_doneContext * ctx ) { }
void exitUser_undo_done(RedoParser::User_undo_doneContext * ctx ) { }
void enterUser_only(RedoParser::User_onlyContext * ctx ) { }
void exitUser_only(RedoParser::User_onlyContext * ctx ) { }
void enterLast_buffer_split(RedoParser::Last_buffer_splitContext * ctx ) { }
void exitLast_buffer_split(RedoParser::Last_buffer_splitContext * ctx ) { }
void enterLast_buffer_split_value(RedoParser::Last_buffer_split_valueContext * ctx ) { }
void exitLast_buffer_split_value(RedoParser::Last_buffer_split_valueContext * ctx ) { }
void enterTemp_object(RedoParser::Temp_objectContext * ctx ) { }
void exitTemp_object(RedoParser::Temp_objectContext * ctx ) { }
void enterTemp_object_value(RedoParser::Temp_object_valueContext * ctx ) { }
void exitTemp_object_value(RedoParser::Temp_object_valueContext * ctx ) { }
void enterTablespace_undo(RedoParser::Tablespace_undoContext * ctx ) { }
void exitTablespace_undo(RedoParser::Tablespace_undoContext * ctx ) { }
void enterTablespace_undo_value(RedoParser::Tablespace_undo_valueContext * ctx ) { }
void exitTablespace_undo_value(RedoParser::Tablespace_undo_valueContext * ctx ) { }
void enterPrev_ctl_uba(RedoParser::Prev_ctl_ubaContext * ctx ) { }
void exitPrev_ctl_uba(RedoParser::Prev_ctl_ubaContext * ctx ) { }
void enterPrev_ctl_max_cmt_scn(RedoParser::Prev_ctl_max_cmt_scnContext * ctx ) { }
void exitPrev_ctl_max_cmt_scn(RedoParser::Prev_ctl_max_cmt_scnContext * ctx ) { }
void enterPrev_tx_cmt_scn(RedoParser::Prev_tx_cmt_scnContext * ctx ) { }
void exitPrev_tx_cmt_scn(RedoParser::Prev_tx_cmt_scnContext * ctx ) { }
void enterTxn_start_scn(RedoParser::Txn_start_scnContext * ctx ) { }
void exitTxn_start_scn(RedoParser::Txn_start_scnContext * ctx ) { }
void enterLogon_user(RedoParser::Logon_userContext * ctx ) { }
void exitLogon_user(RedoParser::Logon_userContext * ctx ) { }
void enterPrev_brb(RedoParser::Prev_brbContext * ctx ) { }
void exitPrev_brb(RedoParser::Prev_brbContext * ctx ) { }
void enterPrev_bcl(RedoParser::Prev_bclContext * ctx ) { }
void exitPrev_bcl(RedoParser::Prev_bclContext * ctx ) { }
void enterBuext_info(RedoParser::Buext_infoContext * ctx ) { }
void exitBuext_info(RedoParser::Buext_infoContext * ctx ) { }
void enterBuext_idx(RedoParser::Buext_idxContext * ctx ) { }
void exitBuext_idx(RedoParser::Buext_idxContext * ctx ) { }
void enterCol_info(RedoParser::Col_infoContext * ctx ) { }
void exitCol_info(RedoParser::Col_infoContext * ctx ) { }
void enterCol_element_count_value(RedoParser::Col_element_count_valueContext * ctx ) { }
void exitCol_element_count_value(RedoParser::Col_element_count_valueContext * ctx ) { }
void enterCol_values(RedoParser::Col_valuesContext * ctx ) { }
void exitCol_values(RedoParser::Col_valuesContext * ctx ) { }
void enterHex_byte(RedoParser::Hex_byteContext * ctx ) { }
void exitHex_byte(RedoParser::Hex_byteContext * ctx ) { }
void enterKdo_info(RedoParser::Kdo_infoContext * ctx ) { }
void exitKdo_info(RedoParser::Kdo_infoContext * ctx ) { }
void enterFwd(RedoParser::FwdContext * ctx ) { }
void exitFwd(RedoParser::FwdContext * ctx ) { }
void enterFwd_value(RedoParser::Fwd_valueContext * ctx ) { }
void exitFwd_value(RedoParser::Fwd_valueContext * ctx ) { }
void enterBkw(RedoParser::BkwContext * ctx ) { }
void exitBkw(RedoParser::BkwContext * ctx ) { }
void enterBkw_value(RedoParser::Bkw_valueContext * ctx ) { }
void exitBkw_value(RedoParser::Bkw_valueContext * ctx ) { }
void enterKdo_flag_info(RedoParser::Kdo_flag_infoContext * ctx ) { }
void exitKdo_flag_info(RedoParser::Kdo_flag_infoContext * ctx ) { }
void enterVect(RedoParser::VectContext * ctx ) { }
void exitVect(RedoParser::VectContext * ctx ) { }
void enterArray_update(RedoParser::Array_updateContext * ctx ) { }
void exitArray_update(RedoParser::Array_updateContext * ctx ) { }
void enterKdo_op_code_info(RedoParser::Kdo_op_code_infoContext * ctx ) { }
void exitKdo_op_code_info(RedoParser::Kdo_op_code_infoContext * ctx ) { }
void enterKdo_op_code_info_more(RedoParser::Kdo_op_code_info_moreContext * ctx ) { }
void exitKdo_op_code_info_more(RedoParser::Kdo_op_code_info_moreContext * ctx ) { }
void enterVector_content(RedoParser::Vector_contentContext * ctx ) { }
void exitVector_content(RedoParser::Vector_contentContext * ctx ) { }
void enterCurc_info(RedoParser::Curc_infoContext * ctx ) { }
void exitCurc_info(RedoParser::Curc_infoContext * ctx ) { }
void enterNk(RedoParser::NkContext * ctx ) { }
void exitNk(RedoParser::NkContext * ctx ) { }
void enterNk_value(RedoParser::Nk_valueContext * ctx ) { }
void exitNk_value(RedoParser::Nk_valueContext * ctx ) { }
void enterPk(RedoParser::PkContext * ctx ) { }
void exitPk(RedoParser::PkContext * ctx ) { }
void enterPk_value(RedoParser::Pk_valueContext * ctx ) { }
void exitPk_value(RedoParser::Pk_valueContext * ctx ) { }
void enterComc(RedoParser::ComcContext * ctx ) { }
void exitComc(RedoParser::ComcContext * ctx ) { }
void enterComc_value(RedoParser::Comc_valueContext * ctx ) { }
void exitComc_value(RedoParser::Comc_valueContext * ctx ) { }
void enterCurc(RedoParser::CurcContext * ctx ) { }
void exitCurc(RedoParser::CurcContext * ctx ) { }
void enterCurc_value(RedoParser::Curc_valueContext * ctx ) { }
void exitCurc_value(RedoParser::Curc_valueContext * ctx ) { }
void enterNull_emum(RedoParser::Null_emumContext * ctx ) { }
void exitNull_emum(RedoParser::Null_emumContext * ctx ) { }
void enterNull_enum_list(RedoParser::Null_enum_listContext * ctx ) { }
void exitNull_enum_list(RedoParser::Null_enum_listContext * ctx ) { }
void enterNull_enum_info(RedoParser::Null_enum_infoContext * ctx ) { }
void exitNull_enum_info(RedoParser::Null_enum_infoContext * ctx ) { }
void enterNull_enum(RedoParser::Null_enumContext * ctx ) { }
void exitNull_enum(RedoParser::Null_enumContext * ctx ) { }
void enterKdo_itli_info(RedoParser::Kdo_itli_infoContext * ctx ) { }
void exitKdo_itli_info(RedoParser::Kdo_itli_infoContext * ctx ) { }
void enterMaxfr(RedoParser::MaxfrContext * ctx ) { }
void exitMaxfr(RedoParser::MaxfrContext * ctx ) { }
void enterMaxfr_value(RedoParser::Maxfr_valueContext * ctx ) { }
void exitMaxfr_value(RedoParser::Maxfr_valueContext * ctx ) { }
void enterIspac(RedoParser::IspacContext * ctx ) { }
void exitIspac(RedoParser::IspacContext * ctx ) { }
void enterIspac_value(RedoParser::Ispac_valueContext * ctx ) { }
void exitIspac_value(RedoParser::Ispac_valueContext * ctx ) { }
void enterTabn_info(RedoParser::Tabn_infoContext * ctx ) { }
void exitTabn_info(RedoParser::Tabn_infoContext * ctx ) { }
void enterHrid(RedoParser::HridContext * ctx ) { }
void exitHrid(RedoParser::HridContext * ctx ) { }
void enterHrid_value(RedoParser::Hrid_valueContext * ctx ) { }
void exitHrid_value(RedoParser::Hrid_valueContext * ctx ) { }
void enterNrid(RedoParser::NridContext * ctx ) { }
void exitNrid(RedoParser::NridContext * ctx ) { }
void enterNrid_value(RedoParser::Nrid_valueContext * ctx ) { }
void exitNrid_value(RedoParser::Nrid_valueContext * ctx ) { }
void enterNrow(RedoParser::NrowContext * ctx ) { }
void exitNrow(RedoParser::NrowContext * ctx ) { }
void enterNrow_value(RedoParser::Nrow_valueContext * ctx ) { }
void exitNrow_value(RedoParser::Nrow_valueContext * ctx ) { }
void enterTl_info(RedoParser::Tl_infoContext * ctx ) { }
void exitTl_info(RedoParser::Tl_infoContext * ctx ) { }
void enterTl(RedoParser::TlContext * ctx ) { }
void exitTl(RedoParser::TlContext * ctx ) { }
void enterTl_value(RedoParser::Tl_valueContext * ctx ) { }
void exitTl_value(RedoParser::Tl_valueContext * ctx ) { }
void enterFb_info(RedoParser::Fb_infoContext * ctx ) { }
void exitFb_info(RedoParser::Fb_infoContext * ctx ) { }
void enterFb(RedoParser::FbContext * ctx ) { }
void exitFb(RedoParser::FbContext * ctx ) { }
void enterFb_value(RedoParser::Fb_valueContext * ctx ) { }
void exitFb_value(RedoParser::Fb_valueContext * ctx ) { }
void enterLb(RedoParser::LbContext * ctx ) { }
void exitLb(RedoParser::LbContext * ctx ) { }
void enterLb_value(RedoParser::Lb_valueContext * ctx ) { }
void exitLb_value(RedoParser::Lb_valueContext * ctx ) { }
void enterCc(RedoParser::CcContext * ctx ) { }
void exitCc(RedoParser::CcContext * ctx ) { }
void enterCc_value(RedoParser::Cc_valueContext * ctx ) { }
void exitCc_value(RedoParser::Cc_valueContext * ctx ) { }
void enterCki(RedoParser::CkiContext * ctx ) { }
void exitCki(RedoParser::CkiContext * ctx ) { }
void enterCki_value(RedoParser::Cki_valueContext * ctx ) { }
void exitCki_value(RedoParser::Cki_valueContext * ctx ) { }
void enterTabn_qmd_slot_info(RedoParser::Tabn_qmd_slot_infoContext * ctx ) { }
void exitTabn_qmd_slot_info(RedoParser::Tabn_qmd_slot_infoContext * ctx ) { }
void enterMany_cols(RedoParser::Many_colsContext * ctx ) { }
void exitMany_cols(RedoParser::Many_colsContext * ctx ) { }
void enterTabn(RedoParser::TabnContext * ctx ) { }
void exitTabn(RedoParser::TabnContext * ctx ) { }
void enterTabn_value(RedoParser::Tabn_valueContext * ctx ) { }
void exitTabn_value(RedoParser::Tabn_valueContext * ctx ) { }
void enterTabn_slot(RedoParser::Tabn_slotContext * ctx ) { }
void exitTabn_slot(RedoParser::Tabn_slotContext * ctx ) { }
void enterTabn_slot_value(RedoParser::Tabn_slot_valueContext * ctx ) { }
void exitTabn_slot_value(RedoParser::Tabn_slot_valueContext * ctx ) { }
void enterTabn_slot_to(RedoParser::Tabn_slot_toContext * ctx ) { }
void exitTabn_slot_to(RedoParser::Tabn_slot_toContext * ctx ) { }
void enterTabn_slot_to_value(RedoParser::Tabn_slot_to_valueContext * ctx ) { }
void exitTabn_slot_to_value(RedoParser::Tabn_slot_to_valueContext * ctx ) { }
void enterFlag(RedoParser::FlagContext * ctx ) { }
void exitFlag(RedoParser::FlagContext * ctx ) { }
void enterFlag_value(RedoParser::Flag_valueContext * ctx ) { }
void exitFlag_value(RedoParser::Flag_valueContext * ctx ) { }
void enterLock(RedoParser::LockContext * ctx ) { }
void exitLock(RedoParser::LockContext * ctx ) { }
void enterLock_value(RedoParser::Lock_valueContext * ctx ) { }
void exitLock_value(RedoParser::Lock_valueContext * ctx ) { }
void enterCkix(RedoParser::CkixContext * ctx ) { }
void exitCkix(RedoParser::CkixContext * ctx ) { }
void enterCkix_value(RedoParser::Ckix_valueContext * ctx ) { }
void exitCkix_value(RedoParser::Ckix_valueContext * ctx ) { }
void enterNcol_info(RedoParser::Ncol_infoContext * ctx ) { }
void exitNcol_info(RedoParser::Ncol_infoContext * ctx ) { }
void enterNcol(RedoParser::NcolContext * ctx ) { }
void exitNcol(RedoParser::NcolContext * ctx ) { }
void enterNcol_value(RedoParser::Ncol_valueContext * ctx ) { }
void exitNcol_value(RedoParser::Ncol_valueContext * ctx ) { }
void enterNnew(RedoParser::NnewContext * ctx ) { }
void exitNnew(RedoParser::NnewContext * ctx ) { }
void enterNnew_value(RedoParser::Nnew_valueContext * ctx ) { }
void exitNnew_value(RedoParser::Nnew_valueContext * ctx ) { }
void enterKdo_itli(RedoParser::Kdo_itliContext * ctx ) { }
void exitKdo_itli(RedoParser::Kdo_itliContext * ctx ) { }
void enterKdo_itli_value(RedoParser::Kdo_itli_valueContext * ctx ) { }
void exitKdo_itli_value(RedoParser::Kdo_itli_valueContext * ctx ) { }
void enterKdo_op_code(RedoParser::Kdo_op_codeContext * ctx ) { }
void exitKdo_op_code(RedoParser::Kdo_op_codeContext * ctx ) { }
void enterRp_dependencies(RedoParser::Rp_dependenciesContext * ctx ) { }
void exitRp_dependencies(RedoParser::Rp_dependenciesContext * ctx ) { }
void enterBdba(RedoParser::BdbaContext * ctx ) { }
void exitBdba(RedoParser::BdbaContext * ctx ) { }
void enterBdba_value(RedoParser::Bdba_valueContext * ctx ) { }
void exitBdba_value(RedoParser::Bdba_valueContext * ctx ) { }
void enterHdba(RedoParser::HdbaContext * ctx ) { }
void exitHdba(RedoParser::HdbaContext * ctx ) { }
void enterHdba_value(RedoParser::Hdba_valueContext * ctx ) { }
void exitHdba_value(RedoParser::Hdba_valueContext * ctx ) { }
void enterXtype(RedoParser::XtypeContext * ctx ) { }
void exitXtype(RedoParser::XtypeContext * ctx ) { }
void enterXtype_value(RedoParser::Xtype_valueContext * ctx ) { }
void exitXtype_value(RedoParser::Xtype_valueContext * ctx ) { }
void enterXa_flags(RedoParser::Xa_flagsContext * ctx ) { }
void exitXa_flags(RedoParser::Xa_flagsContext * ctx ) { }
void enterXa_flags_value(RedoParser::Xa_flags_valueContext * ctx ) { }
void exitXa_flags_value(RedoParser::Xa_flags_valueContext * ctx ) { }
void enterKtb_redo_info(RedoParser::Ktb_redo_infoContext * ctx ) { }
void exitKtb_redo_info(RedoParser::Ktb_redo_infoContext * ctx ) { }
void enterKdo_undo_info(RedoParser::Kdo_undo_infoContext * ctx ) { }
void exitKdo_undo_info(RedoParser::Kdo_undo_infoContext * ctx ) { }
void enterKdo_undo_record(RedoParser::Kdo_undo_recordContext * ctx ) { }
void exitKdo_undo_record(RedoParser::Kdo_undo_recordContext * ctx ) { }
void enterItl_equal(RedoParser::Itl_equalContext * ctx ) { }
void exitItl_equal(RedoParser::Itl_equalContext * ctx ) { }
void enterKtb_redo_clause(RedoParser::Ktb_redo_clauseContext * ctx ) { }
void exitKtb_redo_clause(RedoParser::Ktb_redo_clauseContext * ctx ) { }
void enterKtb_redo_clause_options(RedoParser::Ktb_redo_clause_optionsContext * ctx ) { }
void exitKtb_redo_clause_options(RedoParser::Ktb_redo_clause_optionsContext * ctx ) { }
void enterInsert_into_slot(RedoParser::Insert_into_slotContext * ctx ) { }
void exitInsert_into_slot(RedoParser::Insert_into_slotContext * ctx ) { }
void enterChild_dba(RedoParser::Child_dbaContext * ctx ) { }
void exitChild_dba(RedoParser::Child_dbaContext * ctx ) { }
void enterChild_dba_value(RedoParser::Child_dba_valueContext * ctx ) { }
void exitChild_dba_value(RedoParser::Child_dba_valueContext * ctx ) { }
void enterNew_key(RedoParser::New_keyContext * ctx ) { }
void exitNew_key(RedoParser::New_keyContext * ctx ) { }
void enterNew_key_value(RedoParser::New_key_valueContext * ctx ) { }
void exitNew_key_value(RedoParser::New_key_valueContext * ctx ) { }
void enterPurge_branch(RedoParser::Purge_branchContext * ctx ) { }
void exitPurge_branch(RedoParser::Purge_branchContext * ctx ) { }
void enterPurge_slot(RedoParser::Purge_slotContext * ctx ) { }
void exitPurge_slot(RedoParser::Purge_slotContext * ctx ) { }
void enterPurge_slot_value(RedoParser::Purge_slot_valueContext * ctx ) { }
void exitPurge_slot_value(RedoParser::Purge_slot_valueContext * ctx ) { }
void enterKdxdumpcompdo(RedoParser::KdxdumpcompdoContext * ctx ) { }
void exitKdxdumpcompdo(RedoParser::KdxdumpcompdoContext * ctx ) { }
void enterKdxlup_info(RedoParser::Kdxlup_infoContext * ctx ) { }
void exitKdxlup_info(RedoParser::Kdxlup_infoContext * ctx ) { }
void enterPurge_leaf(RedoParser::Purge_leafContext * ctx ) { }
void exitPurge_leaf(RedoParser::Purge_leafContext * ctx ) { }
void enterLeaf_itl_info(RedoParser::Leaf_itl_infoContext * ctx ) { }
void exitLeaf_itl_info(RedoParser::Leaf_itl_infoContext * ctx ) { }
void enterSingle_array_redo_info(RedoParser::Single_array_redo_infoContext * ctx ) { }
void exitSingle_array_redo_info(RedoParser::Single_array_redo_infoContext * ctx ) { }
void enterInsert_leaf(RedoParser::Insert_leafContext * ctx ) { }
void exitInsert_leaf(RedoParser::Insert_leafContext * ctx ) { }
void enterDelete_leaf(RedoParser::Delete_leafContext * ctx ) { }
void exitDelete_leaf(RedoParser::Delete_leafContext * ctx ) { }
void enterNumber_of_keys(RedoParser::Number_of_keysContext * ctx ) { }
void exitNumber_of_keys(RedoParser::Number_of_keysContext * ctx ) { }
void enterNumber_of_keys_value(RedoParser::Number_of_keys_valueContext * ctx ) { }
void exitNumber_of_keys_value(RedoParser::Number_of_keys_valueContext * ctx ) { }
void enterLeaf_slots(RedoParser::Leaf_slotsContext * ctx ) { }
void exitLeaf_slots(RedoParser::Leaf_slotsContext * ctx ) { }
void enterLeaf_slots_value(RedoParser::Leaf_slots_valueContext * ctx ) { }
void exitLeaf_slots_value(RedoParser::Leaf_slots_valueContext * ctx ) { }
void enterSno(RedoParser::SnoContext * ctx ) { }
void exitSno(RedoParser::SnoContext * ctx ) { }
void enterSno_value(RedoParser::Sno_valueContext * ctx ) { }
void exitSno_value(RedoParser::Sno_valueContext * ctx ) { }
void enterEach_key_size_is(RedoParser::Each_key_size_isContext * ctx ) { }
void exitEach_key_size_is(RedoParser::Each_key_size_isContext * ctx ) { }
void enterEach_key_size_value(RedoParser::Each_key_size_valueContext * ctx ) { }
void exitEach_key_size_value(RedoParser::Each_key_size_valueContext * ctx ) { }
void enterInsert_key(RedoParser::Insert_keyContext * ctx ) { }
void exitInsert_key(RedoParser::Insert_keyContext * ctx ) { }
void enterInsert_key_value(RedoParser::Insert_key_valueContext * ctx ) { }
void exitInsert_key_value(RedoParser::Insert_key_valueContext * ctx ) { }
void enterKeydata(RedoParser::KeydataContext * ctx ) { }
void exitKeydata(RedoParser::KeydataContext * ctx ) { }
void enterKeydata_value(RedoParser::Keydata_valueContext * ctx ) { }
void exitKeydata_value(RedoParser::Keydata_valueContext * ctx ) { }
void enterDump_kd_info(RedoParser::Dump_kd_infoContext * ctx ) { }
void exitDump_kd_info(RedoParser::Dump_kd_infoContext * ctx ) { }
void enterKdx_bitmap(RedoParser::Kdx_bitmapContext * ctx ) { }
void exitKdx_bitmap(RedoParser::Kdx_bitmapContext * ctx ) { }
void enterKdx_bitmap_value(RedoParser::Kdx_bitmap_valueContext * ctx ) { }
void exitKdx_bitmap_value(RedoParser::Kdx_bitmap_valueContext * ctx ) { }
void enterSelflock(RedoParser::SelflockContext * ctx ) { }
void exitSelflock(RedoParser::SelflockContext * ctx ) { }
void enterSelflock_value(RedoParser::Selflock_valueContext * ctx ) { }
void exitSelflock_value(RedoParser::Selflock_valueContext * ctx ) { }
void enterKey_sizes(RedoParser::Key_sizesContext * ctx ) { }
void exitKey_sizes(RedoParser::Key_sizesContext * ctx ) { }
void enterKey_sizes_value(RedoParser::Key_sizes_valueContext * ctx ) { }
void exitKey_sizes_value(RedoParser::Key_sizes_valueContext * ctx ) { }
void enterKdxlre(RedoParser::KdxlreContext * ctx ) { }
void exitKdxlre(RedoParser::KdxlreContext * ctx ) { }
void enterBlock_dba(RedoParser::Block_dbaContext * ctx ) { }
void exitBlock_dba(RedoParser::Block_dbaContext * ctx ) { }
void enterBlock_dba_value(RedoParser::Block_dba_valueContext * ctx ) { }
void exitBlock_dba_value(RedoParser::Block_dba_valueContext * ctx ) { }
void enterKdxlin(RedoParser::KdxlinContext * ctx ) { }
void exitKdxlin(RedoParser::KdxlinContext * ctx ) { }
void enterKdxlup(RedoParser::KdxlupContext * ctx ) { }
void exitKdxlup(RedoParser::KdxlupContext * ctx ) { }
void enterKdxlde(RedoParser::KdxldeContext * ctx ) { }
void exitKdxlde(RedoParser::KdxldeContext * ctx ) { }
void enterKdxlpu(RedoParser::KdxlpuContext * ctx ) { }
void exitKdxlpu(RedoParser::KdxlpuContext * ctx ) { }
void enterKdx_key(RedoParser::Kdx_keyContext * ctx ) { }
void exitKdx_key(RedoParser::Kdx_keyContext * ctx ) { }
void enterKdx_key_value(RedoParser::Kdx_key_valueContext * ctx ) { }
void exitKdx_key_value(RedoParser::Kdx_key_valueContext * ctx ) { }
void enterDump_kdige(RedoParser::Dump_kdigeContext * ctx ) { }
void exitDump_kdige(RedoParser::Dump_kdigeContext * ctx ) { }
void enterDump_kdilk(RedoParser::Dump_kdilkContext * ctx ) { }
void exitDump_kdilk(RedoParser::Dump_kdilkContext * ctx ) { }
void enterKdxlkflg(RedoParser::KdxlkflgContext * ctx ) { }
void exitKdxlkflg(RedoParser::KdxlkflgContext * ctx ) { }
void enterKdxlkflg_value(RedoParser::Kdxlkflg_valueContext * ctx ) { }
void exitKdxlkflg_value(RedoParser::Kdxlkflg_valueContext * ctx ) { }
void enterSdc(RedoParser::SdcContext * ctx ) { }
void exitSdc(RedoParser::SdcContext * ctx ) { }
void enterSdc_value(RedoParser::Sdc_valueContext * ctx ) { }
void exitSdc_value(RedoParser::Sdc_valueContext * ctx ) { }
void enterIndexid(RedoParser::IndexidContext * ctx ) { }
void exitIndexid(RedoParser::IndexidContext * ctx ) { }
void enterIndexid_value(RedoParser::Indexid_valueContext * ctx ) { }
void exitIndexid_value(RedoParser::Indexid_valueContext * ctx ) { }
void enterKdx_block(RedoParser::Kdx_blockContext * ctx ) { }
void exitKdx_block(RedoParser::Kdx_blockContext * ctx ) { }
void enterKdx_block_value(RedoParser::Kdx_block_valueContext * ctx ) { }
void exitKdx_block_value(RedoParser::Kdx_block_valueContext * ctx ) { }
void enterKtb_redo_op1(RedoParser::Ktb_redo_op1Context * ctx ) { }
void exitKtb_redo_op1(RedoParser::Ktb_redo_op1Context * ctx ) { }
void enterKtb_redo_compat_bit(RedoParser::Ktb_redo_compat_bitContext * ctx ) { }
void exitKtb_redo_compat_bit(RedoParser::Ktb_redo_compat_bitContext * ctx ) { }
void enterCompat_bit_value(RedoParser::Compat_bit_valueContext * ctx ) { }
void exitCompat_bit_value(RedoParser::Compat_bit_valueContext * ctx ) { }
void enterPadding(RedoParser::PaddingContext * ctx ) { }
void exitPadding(RedoParser::PaddingContext * ctx ) { }
void enterPadding_value(RedoParser::Padding_valueContext * ctx ) { }
void exitPadding_value(RedoParser::Padding_valueContext * ctx ) { }
void enterKtb_redo_op2(RedoParser::Ktb_redo_op2Context * ctx ) { }
void exitKtb_redo_op2(RedoParser::Ktb_redo_op2Context * ctx ) { }
void enterKtb_redo_op_Z(RedoParser::Ktb_redo_op_ZContext * ctx ) { }
void exitKtb_redo_op_Z(RedoParser::Ktb_redo_op_ZContext * ctx ) { }
void enterKtb_redo_op_l(RedoParser::Ktb_redo_op_lContext * ctx ) { }
void exitKtb_redo_op_l(RedoParser::Ktb_redo_op_lContext * ctx ) { }
void enterKtb_redo_flag(RedoParser::Ktb_redo_flagContext * ctx ) { }
void exitKtb_redo_flag(RedoParser::Ktb_redo_flagContext * ctx ) { }
void enterKtb_redo_flg(RedoParser::Ktb_redo_flgContext * ctx ) { }
void exitKtb_redo_flg(RedoParser::Ktb_redo_flgContext * ctx ) { }
void enterKtb_redo_op_r(RedoParser::Ktb_redo_op_rContext * ctx ) { }
void exitKtb_redo_op_r(RedoParser::Ktb_redo_op_rContext * ctx ) { }
void enterItl_list(RedoParser::Itl_listContext * ctx ) { }
void exitItl_list(RedoParser::Itl_listContext * ctx ) { }
void enterItl_list_entries(RedoParser::Itl_list_entriesContext * ctx ) { }
void exitItl_list_entries(RedoParser::Itl_list_entriesContext * ctx ) { }
void enterItl_list_uba(RedoParser::Itl_list_ubaContext * ctx ) { }
void exitItl_list_uba(RedoParser::Itl_list_ubaContext * ctx ) { }
void enterItl_list_itl(RedoParser::Itl_list_itlContext * ctx ) { }
void exitItl_list_itl(RedoParser::Itl_list_itlContext * ctx ) { }
void enterItl_list_xid(RedoParser::Itl_list_xidContext * ctx ) { }
void exitItl_list_xid(RedoParser::Itl_list_xidContext * ctx ) { }
void enterItl_list_list_uba(RedoParser::Itl_list_list_ubaContext * ctx ) { }
void exitItl_list_list_uba(RedoParser::Itl_list_list_ubaContext * ctx ) { }
void enterItl_list_flag(RedoParser::Itl_list_flagContext * ctx ) { }
void exitItl_list_flag(RedoParser::Itl_list_flagContext * ctx ) { }
void enterItl_list_lck(RedoParser::Itl_list_lckContext * ctx ) { }
void exitItl_list_lck(RedoParser::Itl_list_lckContext * ctx ) { }
void enterItl_list_scn_or_fsc_indicator(RedoParser::Itl_list_scn_or_fsc_indicatorContext * ctx ) { }
void exitItl_list_scn_or_fsc_indicator(RedoParser::Itl_list_scn_or_fsc_indicatorContext * ctx ) { }
void enterItl_list_scn_or_fsc(RedoParser::Itl_list_scn_or_fscContext * ctx ) { }
void exitItl_list_scn_or_fsc(RedoParser::Itl_list_scn_or_fscContext * ctx ) { }
void enterFsc_value(RedoParser::Fsc_valueContext * ctx ) { }
void exitFsc_value(RedoParser::Fsc_valueContext * ctx ) { }
void enterItc(RedoParser::ItcContext * ctx ) { }
void exitItc(RedoParser::ItcContext * ctx ) { }
void enterItc_value(RedoParser::Itc_valueContext * ctx ) { }
void exitItc_value(RedoParser::Itc_valueContext * ctx ) { }
void enterKtb_redo_op_c(RedoParser::Ktb_redo_op_cContext * ctx ) { }
void exitKtb_redo_op_c(RedoParser::Ktb_redo_op_cContext * ctx ) { }
void enterKtb_redo_op_f(RedoParser::Ktb_redo_op_fContext * ctx ) { }
void exitKtb_redo_op_f(RedoParser::Ktb_redo_op_fContext * ctx ) { }
void enterItli_entries(RedoParser::Itli_entriesContext * ctx ) { }
void exitItli_entries(RedoParser::Itli_entriesContext * ctx ) { }
void enterItli(RedoParser::ItliContext * ctx ) { }
void exitItli(RedoParser::ItliContext * ctx ) { }
void enterItli_value(RedoParser::Itli_valueContext * ctx ) { }
void exitItli_value(RedoParser::Itli_valueContext * ctx ) { }
void enterLkc(RedoParser::LkcContext * ctx ) { }
void exitLkc(RedoParser::LkcContext * ctx ) { }
void enterLkc_value(RedoParser::Lkc_valueContext * ctx ) { }
void exitLkc_value(RedoParser::Lkc_valueContext * ctx ) { }
void enterWrp(RedoParser::WrpContext * ctx ) { }
void exitWrp(RedoParser::WrpContext * ctx ) { }
void enterWrp_value(RedoParser::Wrp_valueContext * ctx ) { }
void exitWrp_value(RedoParser::Wrp_valueContext * ctx ) { }
void enterPrev_dba(RedoParser::Prev_dbaContext * ctx ) { }
void exitPrev_dba(RedoParser::Prev_dbaContext * ctx ) { }
void enterPrev_dba_value(RedoParser::Prev_dba_valueContext * ctx ) { }
void exitPrev_dba_value(RedoParser::Prev_dba_valueContext * ctx ) { }
void enterKteop_redo(RedoParser::Kteop_redoContext * ctx ) { }
void exitKteop_redo(RedoParser::Kteop_redoContext * ctx ) { }
void enterSethwm(RedoParser::SethwmContext * ctx ) { }
void exitSethwm(RedoParser::SethwmContext * ctx ) { }
void enterHighwater(RedoParser::HighwaterContext * ctx ) { }
void exitHighwater(RedoParser::HighwaterContext * ctx ) { }
void enterHighwater_value(RedoParser::Highwater_valueContext * ctx ) { }
void exitHighwater_value(RedoParser::Highwater_valueContext * ctx ) { }
void enterBlk_pound(RedoParser::Blk_poundContext * ctx ) { }
void exitBlk_pound(RedoParser::Blk_poundContext * ctx ) { }
void enterBlk_pound_value(RedoParser::Blk_pound_valueContext * ctx ) { }
void exitBlk_pound_value(RedoParser::Blk_pound_valueContext * ctx ) { }
void enterBlocks_in_seg_hdr_freelist(RedoParser::Blocks_in_seg_hdr_freelistContext * ctx ) { }
void exitBlocks_in_seg_hdr_freelist(RedoParser::Blocks_in_seg_hdr_freelistContext * ctx ) { }
void enterBlocks_in_seg_hdr_freelist_value(RedoParser::Blocks_in_seg_hdr_freelist_valueContext * ctx ) { }
void exitBlocks_in_seg_hdr_freelist_value(RedoParser::Blocks_in_seg_hdr_freelist_valueContext * ctx ) { }
void enterBlocks_below(RedoParser::Blocks_belowContext * ctx ) { }
void exitBlocks_below(RedoParser::Blocks_belowContext * ctx ) { }
void enterBlocks_below_value(RedoParser::Blocks_below_valueContext * ctx ) { }
void exitBlocks_below_value(RedoParser::Blocks_below_valueContext * ctx ) { }
void enterMapblk(RedoParser::MapblkContext * ctx ) { }
void exitMapblk(RedoParser::MapblkContext * ctx ) { }
void enterMapblk_value(RedoParser::Mapblk_valueContext * ctx ) { }
void exitMapblk_value(RedoParser::Mapblk_valueContext * ctx ) { }
void enterAt_offset(RedoParser::At_offsetContext * ctx ) { }
void exitAt_offset(RedoParser::At_offsetContext * ctx ) { }
void enterAt_offset_value(RedoParser::At_offset_valueContext * ctx ) { }
void exitAt_offset_value(RedoParser::At_offset_valueContext * ctx ) { }
void enterCtime(RedoParser::CtimeContext * ctx ) { }
void exitCtime(RedoParser::CtimeContext * ctx ) { }
void enterCtime_value(RedoParser::Ctime_valueContext * ctx ) { }
void exitCtime_value(RedoParser::Ctime_valueContext * ctx ) { }
void enterLastmap(RedoParser::LastmapContext * ctx ) { }
void exitLastmap(RedoParser::LastmapContext * ctx ) { }
void enterLastmap_value(RedoParser::Lastmap_valueContext * ctx ) { }
void exitLastmap_value(RedoParser::Lastmap_valueContext * ctx ) { }
void enterMapcnt(RedoParser::MapcntContext * ctx ) { }
void exitMapcnt(RedoParser::MapcntContext * ctx ) { }
void enterMapcnt_value(RedoParser::Mapcnt_valueContext * ctx ) { }
void exitMapcnt_value(RedoParser::Mapcnt_valueContext * ctx ) { }
void enterAdd(RedoParser::AddContext * ctx ) { }
void exitAdd(RedoParser::AddContext * ctx ) { }
void enterUpdxnt(RedoParser::UpdxntContext * ctx ) { }
void exitUpdxnt(RedoParser::UpdxntContext * ctx ) { }
void enterSetstat(RedoParser::SetstatContext * ctx ) { }
void exitSetstat(RedoParser::SetstatContext * ctx ) { }
void enterAddret(RedoParser::AddretContext * ctx ) { }
void exitAddret(RedoParser::AddretContext * ctx ) { }
void enterAddaxt(RedoParser::AddaxtContext * ctx ) { }
void exitAddaxt(RedoParser::AddaxtContext * ctx ) { }
void enterShift_back(RedoParser::Shift_backContext * ctx ) { }
void exitShift_back(RedoParser::Shift_backContext * ctx ) { }
void enterHighwater_info(RedoParser::Highwater_infoContext * ctx ) { }
void exitHighwater_info(RedoParser::Highwater_infoContext * ctx ) { }
void enterPdbuid(RedoParser::PdbuidContext * ctx ) { }
void exitPdbuid(RedoParser::PdbuidContext * ctx ) { }
void enterPdbuid_value(RedoParser::Pdbuid_valueContext * ctx ) { }
void exitPdbuid_value(RedoParser::Pdbuid_valueContext * ctx ) { }
void enterOff(RedoParser::OffContext * ctx ) { }
void exitOff(RedoParser::OffContext * ctx ) { }
void enterOff_value(RedoParser::Off_valueContext * ctx ) { }
void exitOff_value(RedoParser::Off_valueContext * ctx ) { }
void enterRc(RedoParser::RcContext * ctx ) { }
void exitRc(RedoParser::RcContext * ctx ) { }
void enterRc_value(RedoParser::Rc_valueContext * ctx ) { }
void exitRc_value(RedoParser::Rc_valueContext * ctx ) { }
void enterAfn(RedoParser::AfnContext * ctx ) { }
void exitAfn(RedoParser::AfnContext * ctx ) { }
void enterPxid(RedoParser::PxidContext * ctx ) { }
void exitPxid(RedoParser::PxidContext * ctx ) { }
void enterPxid_value(RedoParser::Pxid_valueContext * ctx ) { }
void exitPxid_value(RedoParser::Pxid_valueContext * ctx ) { }
void enterFdba(RedoParser::FdbaContext * ctx ) { }
void exitFdba(RedoParser::FdbaContext * ctx ) { }
void enterFdba_value(RedoParser::Fdba_valueContext * ctx ) { }
void exitFdba_value(RedoParser::Fdba_valueContext * ctx ) { }
void enterKtuxv_info(RedoParser::Ktuxv_infoContext * ctx ) { }
void exitKtuxv_info(RedoParser::Ktuxv_infoContext * ctx ) { }
void enterKtuxvoff(RedoParser::KtuxvoffContext * ctx ) { }
void exitKtuxvoff(RedoParser::KtuxvoffContext * ctx ) { }
void enterKtuxvoff_value(RedoParser::Ktuxvoff_valueContext * ctx ) { }
void exitKtuxvoff_value(RedoParser::Ktuxvoff_valueContext * ctx ) { }
void enterKtuxvflg(RedoParser::KtuxvflgContext * ctx ) { }
void exitKtuxvflg(RedoParser::KtuxvflgContext * ctx ) { }
void enterKtuxvflg_value(RedoParser::Ktuxvflg_valueContext * ctx ) { }
void exitKtuxvflg_value(RedoParser::Ktuxvflg_valueContext * ctx ) { }
void enterKgl_info(RedoParser::Kgl_infoContext * ctx ) { }
void exitKgl_info(RedoParser::Kgl_infoContext * ctx ) { }
void enterKgl_info_value(RedoParser::Kgl_info_valueContext * ctx ) { }
void exitKgl_info_value(RedoParser::Kgl_info_valueContext * ctx ) { }
void enterKqr_info(RedoParser::Kqr_infoContext * ctx ) { }
void exitKqr_info(RedoParser::Kqr_infoContext * ctx ) { }
void enterKqr_info_value(RedoParser::Kqr_info_valueContext * ctx ) { }
void exitKqr_info_value(RedoParser::Kqr_info_valueContext * ctx ) { }
void enterRestore_block_to_btree(RedoParser::Restore_block_to_btreeContext * ctx ) { }
void exitRestore_block_to_btree(RedoParser::Restore_block_to_btreeContext * ctx ) { }
void enterBtree_block(RedoParser::Btree_blockContext * ctx ) { }
void exitBtree_block(RedoParser::Btree_blockContext * ctx ) { }
void enterBtree_block_image(RedoParser::Btree_block_imageContext * ctx ) { }
void exitBtree_block_image(RedoParser::Btree_block_imageContext * ctx ) { }
void enterRestore_block_before_image(RedoParser::Restore_block_before_imageContext * ctx ) { }
void exitRestore_block_before_image(RedoParser::Restore_block_before_imageContext * ctx ) { }
void enterBlock_image(RedoParser::Block_imageContext * ctx ) { }
void exitBlock_image(RedoParser::Block_imageContext * ctx ) { }
void enterSet_leaf_block_previous_link(RedoParser::Set_leaf_block_previous_linkContext * ctx ) { }
void exitSet_leaf_block_previous_link(RedoParser::Set_leaf_block_previous_linkContext * ctx ) { }
void enterPrevious_link(RedoParser::Previous_linkContext * ctx ) { }
void exitPrevious_link(RedoParser::Previous_linkContext * ctx ) { }
void enterRolled_back_transaction(RedoParser::Rolled_back_transactionContext * ctx ) { }
void exitRolled_back_transaction(RedoParser::Rolled_back_transactionContext * ctx ) { }
void enterBranch_block_row_purge(RedoParser::Branch_block_row_purgeContext * ctx ) { }
void exitBranch_block_row_purge(RedoParser::Branch_block_row_purgeContext * ctx ) { }
void enterBranch_block_row_insert(RedoParser::Branch_block_row_insertContext * ctx ) { }
void exitBranch_block_row_insert(RedoParser::Branch_block_row_insertContext * ctx ) { }
void enterBranch_block_rows(RedoParser::Branch_block_rowsContext * ctx ) { }
void exitBranch_block_rows(RedoParser::Branch_block_rowsContext * ctx ) { }
void enterMake_leaf_block_empty(RedoParser::Make_leaf_block_emptyContext * ctx ) { }
void exitMake_leaf_block_empty(RedoParser::Make_leaf_block_emptyContext * ctx ) { }
void enterMake_leaf_block_empty_clause(RedoParser::Make_leaf_block_empty_clauseContext * ctx ) { }
void exitMake_leaf_block_empty_clause(RedoParser::Make_leaf_block_empty_clauseContext * ctx ) { }
void enterKdxln_info(RedoParser::Kdxln_infoContext * ctx ) { }
void exitKdxln_info(RedoParser::Kdxln_infoContext * ctx ) { }
void enterKdxlnitl(RedoParser::KdxlnitlContext * ctx ) { }
void exitKdxlnitl(RedoParser::KdxlnitlContext * ctx ) { }
void enterKdxlnitl_value(RedoParser::Kdxlnitl_valueContext * ctx ) { }
void exitKdxlnitl_value(RedoParser::Kdxlnitl_valueContext * ctx ) { }
void enterKdxlnnco(RedoParser::KdxlnncoContext * ctx ) { }
void exitKdxlnnco(RedoParser::KdxlnncoContext * ctx ) { }
void enterKdxlnnco_value(RedoParser::Kdxlnnco_valueContext * ctx ) { }
void exitKdxlnnco_value(RedoParser::Kdxlnnco_valueContext * ctx ) { }
void enterKdxlndsz(RedoParser::KdxlndszContext * ctx ) { }
void exitKdxlndsz(RedoParser::KdxlndszContext * ctx ) { }
void enterKdxlndsz_value(RedoParser::Kdxlndsz_valueContext * ctx ) { }
void exitKdxlndsz_value(RedoParser::Kdxlndsz_valueContext * ctx ) { }
void enterKdxlncol(RedoParser::KdxlncolContext * ctx ) { }
void exitKdxlncol(RedoParser::KdxlncolContext * ctx ) { }
void enterKdxlncol_value(RedoParser::Kdxlncol_valueContext * ctx ) { }
void exitKdxlncol_value(RedoParser::Kdxlncol_valueContext * ctx ) { }
void enterKdxlnflg(RedoParser::KdxlnflgContext * ctx ) { }
void exitKdxlnflg(RedoParser::KdxlnflgContext * ctx ) { }
void enterKdxlnflg_value(RedoParser::Kdxlnflg_valueContext * ctx ) { }
void exitKdxlnflg_value(RedoParser::Kdxlnflg_valueContext * ctx ) { }
void enterKdxlnnxt(RedoParser::KdxlnnxtContext * ctx ) { }
void exitKdxlnnxt(RedoParser::KdxlnnxtContext * ctx ) { }
void enterKdxlnnxt_value(RedoParser::Kdxlnnxt_valueContext * ctx ) { }
void exitKdxlnnxt_value(RedoParser::Kdxlnnxt_valueContext * ctx ) { }
void enterKdxlnprv(RedoParser::KdxlnprvContext * ctx ) { }
void exitKdxlnprv(RedoParser::KdxlnprvContext * ctx ) { }
void enterKdxlnprv_value(RedoParser::Kdxlnprv_valueContext * ctx ) { }
void exitKdxlnprv_value(RedoParser::Kdxlnprv_valueContext * ctx ) { }
void enterCu_itl(RedoParser::Cu_itlContext * ctx ) { }
void exitCu_itl(RedoParser::Cu_itlContext * ctx ) { }
void enterLvec_size(RedoParser::Lvec_sizeContext * ctx ) { }
void exitLvec_size(RedoParser::Lvec_sizeContext * ctx ) { }
void enterDirect_block_loader_redo(RedoParser::Direct_block_loader_redoContext * ctx ) { }
void exitDirect_block_loader_redo(RedoParser::Direct_block_loader_redoContext * ctx ) { 
   change_vectors[number_of_change_vectors].dl_rows=string_to_number.convert_dec_str_to_ulong(ctx->data_block_dump()->nrow_equal()->nrow_equal_value()->getText() ) ;
}
void enterBlock_header_dump(RedoParser::Block_header_dumpContext * ctx ) { }
void exitBlock_header_dump(RedoParser::Block_header_dumpContext * ctx ) { }
void enterMy_opc(RedoParser::My_opcContext * ctx ) { }
void exitMy_opc(RedoParser::My_opcContext * ctx ) { }
void enterLeaf_block_dump(RedoParser::Leaf_block_dumpContext * ctx ) { }
void exitLeaf_block_dump(RedoParser::Leaf_block_dumpContext * ctx ) { }
void enterFive_minus(RedoParser::Five_minusContext * ctx ) { }
void exitFive_minus(RedoParser::Five_minusContext * ctx ) { }
void enterLeaf_row(RedoParser::Leaf_rowContext * ctx ) { }
void exitLeaf_row(RedoParser::Leaf_rowContext * ctx ) { }
void enterLeaf_row_entry(RedoParser::Leaf_row_entryContext * ctx ) { }
void exitLeaf_row_entry(RedoParser::Leaf_row_entryContext * ctx ) { }
void enterHeader_address(RedoParser::Header_addressContext * ctx ) { }
void exitHeader_address(RedoParser::Header_addressContext * ctx ) { }
void enterKdxcolok(RedoParser::KdxcolokContext * ctx ) { }
void exitKdxcolok(RedoParser::KdxcolokContext * ctx ) { }
void enterKdxcoopc(RedoParser::KdxcoopcContext * ctx ) { }
void exitKdxcoopc(RedoParser::KdxcoopcContext * ctx ) { }
void enterIot_flags(RedoParser::Iot_flagsContext * ctx ) { }
void exitIot_flags(RedoParser::Iot_flagsContext * ctx ) { }
void enterKdxconco(RedoParser::KdxconcoContext * ctx ) { }
void exitKdxconco(RedoParser::KdxconcoContext * ctx ) { }
void enterKdxcosdc(RedoParser::KdxcosdcContext * ctx ) { }
void exitKdxcosdc(RedoParser::KdxcosdcContext * ctx ) { }
void enterKdxconro(RedoParser::KdxconroContext * ctx ) { }
void exitKdxconro(RedoParser::KdxconroContext * ctx ) { }
void enterKdxcofbo(RedoParser::KdxcofboContext * ctx ) { }
void exitKdxcofbo(RedoParser::KdxcofboContext * ctx ) { }
void enterKdxcofeo(RedoParser::KdxcofeoContext * ctx ) { }
void exitKdxcofeo(RedoParser::KdxcofeoContext * ctx ) { }
void enterKdxcoavs(RedoParser::KdxcoavsContext * ctx ) { }
void exitKdxcoavs(RedoParser::KdxcoavsContext * ctx ) { }
void enterKdxlespl(RedoParser::KdxlesplContext * ctx ) { }
void exitKdxlespl(RedoParser::KdxlesplContext * ctx ) { }
void enterKdxlende(RedoParser::KdxlendeContext * ctx ) { }
void exitKdxlende(RedoParser::KdxlendeContext * ctx ) { }
void enterKdxlenxt(RedoParser::KdxlenxtContext * ctx ) { }
void exitKdxlenxt(RedoParser::KdxlenxtContext * ctx ) { }
void enterKdxleprv(RedoParser::KdxleprvContext * ctx ) { }
void exitKdxleprv(RedoParser::KdxleprvContext * ctx ) { }
void enterKdxledsz(RedoParser::KdxledszContext * ctx ) { }
void exitKdxledsz(RedoParser::KdxledszContext * ctx ) { }
void enterKdxlebksz(RedoParser::KdxlebkszContext * ctx ) { }
void exitKdxlebksz(RedoParser::KdxlebkszContext * ctx ) { }
void enterKdxcolev_flags(RedoParser::Kdxcolev_flagsContext * ctx ) { }
void exitKdxcolev_flags(RedoParser::Kdxcolev_flagsContext * ctx ) { }
void enterKdxcolev(RedoParser::KdxcolevContext * ctx ) { }
void exitKdxcolev(RedoParser::KdxcolevContext * ctx ) { }
void enterKdxcolev_value(RedoParser::Kdxcolev_valueContext * ctx ) { }
void exitKdxcolev_value(RedoParser::Kdxcolev_valueContext * ctx ) { }
void enterData_block_dump(RedoParser::Data_block_dumpContext * ctx ) { }
void exitData_block_dump(RedoParser::Data_block_dumpContext * ctx ) { }
void enterData_block_underline(RedoParser::Data_block_underlineContext * ctx ) { }
void exitData_block_underline(RedoParser::Data_block_underlineContext * ctx ) { }
void enterBlock_row_dump(RedoParser::Block_row_dumpContext * ctx ) { }
void exitBlock_row_dump(RedoParser::Block_row_dumpContext * ctx ) { }
void enterBlock_row(RedoParser::Block_rowContext * ctx ) { }
void exitBlock_row(RedoParser::Block_rowContext * ctx ) {
        if (column_of_interest >= 0 )
	{	
		cout <<"Found " << ctx->many_cols()->col_info(column_of_interest)->getText() << " " << "\n";
        }
 }
void enterBlock_row_info(RedoParser::Block_row_infoContext * ctx ) { }
void exitBlock_row_info(RedoParser::Block_row_infoContext * ctx ) { }
void enterEnd_of_block_dump(RedoParser::End_of_block_dumpContext * ctx ) { }
void exitEnd_of_block_dump(RedoParser::End_of_block_dumpContext * ctx ) { }
void enterRow_piece_offset(RedoParser::Row_piece_offsetContext * ctx ) { }
void exitRow_piece_offset(RedoParser::Row_piece_offsetContext * ctx ) { }
void enterBlock_tab_info(RedoParser::Block_tab_infoContext * ctx ) { }
void exitBlock_tab_info(RedoParser::Block_tab_infoContext * ctx ) { }
void enterOffs(RedoParser::OffsContext * ctx ) { }
void exitOffs(RedoParser::OffsContext * ctx ) { }
void enterOffs_value(RedoParser::Offs_valueContext * ctx ) { }
void exitOffs_value(RedoParser::Offs_valueContext * ctx ) { }
void enterTable_directory(RedoParser::Table_directoryContext * ctx ) { }
void exitTable_directory(RedoParser::Table_directoryContext * ctx ) { }
void enterTable_directory_entry(RedoParser::Table_directory_entryContext * ctx ) { }
void exitTable_directory_entry(RedoParser::Table_directory_entryContext * ctx ) { }
void enterRow_directory(RedoParser::Row_directoryContext * ctx ) { }
void exitRow_directory(RedoParser::Row_directoryContext * ctx ) { }
void enterRow_directory_slot(RedoParser::Row_directory_slotContext * ctx ) { }
void exitRow_directory_slot(RedoParser::Row_directory_slotContext * ctx ) { }
void enterRow_directory_entry(RedoParser::Row_directory_entryContext * ctx ) { }
void exitRow_directory_entry(RedoParser::Row_directory_entryContext * ctx ) { }
void enterNtab_equal(RedoParser::Ntab_equalContext * ctx ) { }
void exitNtab_equal(RedoParser::Ntab_equalContext * ctx ) { }
void enterNtab_equal_value(RedoParser::Ntab_equal_valueContext * ctx ) { }
void exitNtab_equal_value(RedoParser::Ntab_equal_valueContext * ctx ) { }
void enterNrow_equal(RedoParser::Nrow_equalContext * ctx ) { }
void exitNrow_equal(RedoParser::Nrow_equalContext * ctx ) { }
void enterNrow_equal_value(RedoParser::Nrow_equal_valueContext * ctx ) { }
void exitNrow_equal_value(RedoParser::Nrow_equal_valueContext * ctx ) { }
void enterTosp(RedoParser::TospContext * ctx ) { }
void exitTosp(RedoParser::TospContext * ctx ) { }
void enterTosp_value(RedoParser::Tosp_valueContext * ctx ) { }
void exitTosp_value(RedoParser::Tosp_valueContext * ctx ) { }
void enterAvsp(RedoParser::AvspContext * ctx ) { }
void exitAvsp(RedoParser::AvspContext * ctx ) { }
void enterAvsp_value(RedoParser::Avsp_valueContext * ctx ) { }
void exitAvsp_value(RedoParser::Avsp_valueContext * ctx ) { }
void enterFseo(RedoParser::FseoContext * ctx ) { }
void exitFseo(RedoParser::FseoContext * ctx ) { }
void enterFseo_value(RedoParser::Fseo_valueContext * ctx ) { }
void exitFseo_value(RedoParser::Fseo_valueContext * ctx ) { }
void enterFsbo(RedoParser::FsboContext * ctx ) { }
void exitFsbo(RedoParser::FsboContext * ctx ) { }
void enterFsbo_value(RedoParser::Fsbo_valueContext * ctx ) { }
void exitFsbo_value(RedoParser::Fsbo_valueContext * ctx ) { }
void enterFrre(RedoParser::FrreContext * ctx ) { }
void exitFrre(RedoParser::FrreContext * ctx ) { }
void enterFrre_value(RedoParser::Frre_valueContext * ctx ) { }
void exitFrre_value(RedoParser::Frre_valueContext * ctx ) { }
void enterNtab(RedoParser::NtabContext * ctx ) { }
void exitNtab(RedoParser::NtabContext * ctx ) { }
void enterNtab_values(RedoParser::Ntab_valuesContext * ctx ) { }
void exitNtab_values(RedoParser::Ntab_valuesContext * ctx ) { }
void enterBlock_dump_flag(RedoParser::Block_dump_flagContext * ctx ) { }
void exitBlock_dump_flag(RedoParser::Block_dump_flagContext * ctx ) { }
void enterBlock_dump_flag_value(RedoParser::Block_dump_flag_valueContext * ctx ) { }
void exitBlock_dump_flag_value(RedoParser::Block_dump_flag_valueContext * ctx ) { }
void enterTsiz(RedoParser::TsizContext * ctx ) { }
void exitTsiz(RedoParser::TsizContext * ctx ) { }
void enterTsiz_value(RedoParser::Tsiz_valueContext * ctx ) { }
void exitTsiz_value(RedoParser::Tsiz_valueContext * ctx ) { }
void enterHsiz(RedoParser::HsizContext * ctx ) { }
void exitHsiz(RedoParser::HsizContext * ctx ) { }
void enterHsiz_value(RedoParser::Hsiz_valueContext * ctx ) { }
void exitHsiz_value(RedoParser::Hsiz_valueContext * ctx ) { }
void enterPbl(RedoParser::PblContext * ctx ) { }
void exitPbl(RedoParser::PblContext * ctx ) { }
void enterPbl_value(RedoParser::Pbl_valueContext * ctx ) { }
void exitPbl_value(RedoParser::Pbl_valueContext * ctx ) { }
void enterExflg(RedoParser::ExflgContext * ctx ) { }
void exitExflg(RedoParser::ExflgContext * ctx ) { }
void enterExflg_value(RedoParser::Exflg_valueContext * ctx ) { }
void exitExflg_value(RedoParser::Exflg_valueContext * ctx ) { }
void enterInc(RedoParser::IncContext * ctx ) { }
void exitInc(RedoParser::IncContext * ctx ) { }
void enterInc_value(RedoParser::Inc_valueContext * ctx ) { }
void exitInc_value(RedoParser::Inc_valueContext * ctx ) { }
void enterBlock_hdr_flg(RedoParser::Block_hdr_flgContext * ctx ) { }
void exitBlock_hdr_flg(RedoParser::Block_hdr_flgContext * ctx ) { }
void enterBlock_hdr_flg_value(RedoParser::Block_hdr_flg_valueContext * ctx ) { }
void exitBlock_hdr_flg_value(RedoParser::Block_hdr_flg_valueContext * ctx ) { }
void enterBlock_hdr_typ(RedoParser::Block_hdr_typContext * ctx ) { }
void exitBlock_hdr_typ(RedoParser::Block_hdr_typContext * ctx ) { }
void enterBlock_hdr_typ_value(RedoParser::Block_hdr_typ_valueContext * ctx ) { }
void exitBlock_hdr_typ_value(RedoParser::Block_hdr_typ_valueContext * ctx ) { }
void enterBrn(RedoParser::BrnContext * ctx ) { }
void exitBrn(RedoParser::BrnContext * ctx ) { }
void enterBrn_value(RedoParser::Brn_valueContext * ctx ) { }
void exitBrn_value(RedoParser::Brn_valueContext * ctx ) { }
void enterSeg_obj(RedoParser::Seg_objContext * ctx ) { }
void exitSeg_obj(RedoParser::Seg_objContext * ctx ) { }
void enterSeg_obj_value(RedoParser::Seg_obj_valueContext * ctx ) { }
void exitSeg_obj_value(RedoParser::Seg_obj_valueContext * ctx ) { }
void enterBlock_header_dump_value(RedoParser::Block_header_dump_valueContext * ctx ) { }
void exitBlock_header_dump_value(RedoParser::Block_header_dump_valueContext * ctx ) { }
void enterNew_block_has_rows(RedoParser::New_block_has_rowsContext * ctx ) { }
void exitNew_block_has_rows(RedoParser::New_block_has_rowsContext * ctx ) { }
void enterData_block_bi(RedoParser::Data_block_biContext * ctx ) { }
void exitData_block_bi(RedoParser::Data_block_biContext * ctx ) { }
void enterDumping_row_index(RedoParser::Dumping_row_indexContext * ctx ) { }
void exitDumping_row_index(RedoParser::Dumping_row_indexContext * ctx ) { }
void enterDumping_rows(RedoParser::Dumping_rowsContext * ctx ) { }
void exitDumping_rows(RedoParser::Dumping_rowsContext * ctx ) { }
void enterAuto_clause(RedoParser::Auto_clauseContext * ctx ) { }
void exitAuto_clause(RedoParser::Auto_clauseContext * ctx ) { }
void enterDump_memory(RedoParser::Dump_memoryContext * ctx ) { }
void exitDump_memory(RedoParser::Dump_memoryContext * ctx ) { }
void enterMemory_info(RedoParser::Memory_infoContext * ctx ) { }
void exitMemory_info(RedoParser::Memory_infoContext * ctx ) { }
void enterMemory_display(RedoParser::Memory_displayContext * ctx ) { }
void exitMemory_display(RedoParser::Memory_displayContext * ctx ) { }
void enterMemory_address(RedoParser::Memory_addressContext * ctx ) { }
void exitMemory_address(RedoParser::Memory_addressContext * ctx ) { }
void enterMemory_line(RedoParser::Memory_lineContext * ctx ) { }
void exitMemory_line(RedoParser::Memory_lineContext * ctx ) { }
void enterKtb_redo_flag_values(RedoParser::Ktb_redo_flag_valuesContext * ctx ) { }
void exitKtb_redo_flag_values(RedoParser::Ktb_redo_flag_valuesContext * ctx ) { }
void enterKtb_redo_flg_values(RedoParser::Ktb_redo_flg_valuesContext * ctx ) { }
void exitKtb_redo_flg_values(RedoParser::Ktb_redo_flg_valuesContext * ctx ) { }
void enterFb_flag_values(RedoParser::Fb_flag_valuesContext * ctx ) { }
void exitFb_flag_values(RedoParser::Fb_flag_valuesContext * ctx ) { }
void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/)  { }
void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/)  { }
void visitTerminal(antlr4::tree::TerminalNode * /*node*/)  { }
void visitErrorNode(antlr4::tree::ErrorNode * /*node*/)  { }
};

