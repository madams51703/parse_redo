#include "antlr4-runtime.h"
#include "RedoParserBaseListener.h"
public class RedoWalker extends RedoParserBaseListener
{

	private String change_date;
        private String layer_opcode_string;
	private String data_object_id_string;
        private String layer_string;
	private String opcode_string;	
	private String invalid_string="N";
	private String media_recovery_marker_string="N";

	private String[][] opcode_lookup =new String [50][150];
	
	@Override public void enterRedo_info(RedoParser.Redo_infoContext ctx) 
	{ 
        /** Fill in Layer and opcode array ****/

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
		opcode_lookup[10][30] = "IOT leaf block nonkey update - KDICLNU";
		opcode_lookup[10][31] = "Direct load root redo - KDICDLR";
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
		opcode_lookup[16][1] = "End Hot Backup - KCVOPEHB";
		opcode_lookup[16][2] = "ENable Thread - KCVOPENT";
		opcode_lookup[16][3] = "Crash Recovery Marker - KCVOPCRM";
		opcode_lookup[16][4] = "ReSiZeable datafiles - KCVOPRSZ";
		opcode_lookup[16][5] = "tablespace ONline - KCVOPONL";
		opcode_lookup[16][6] = "tablespace OFFline - KCVOPOFF";
		opcode_lookup[16][7] = "tablespace ReaD Write - KCVOPRDW";
		opcode_lookup[16][8] = "tablespace ReaD Only - KCVOPRDO";
		opcode_lookup[16][9] = "ADDing datafiles to database - KCVOPADD";
		opcode_lookup[16][10] = "tablespace DRoP - KCVOPDRP";
		opcode_lookup[16][11] = "Tablespace PitR - KCVOPTPR";
		opcode_lookup[16][12] = "PLUgging datafiles to database - KCVOPPLG_PRE10GR2";
		opcode_lookup[16][13] = "convert plugged in datafiles - KCVOPCNV";
		opcode_lookup[16][14] = "ADding dataFiles to database - KCVOPADF_PRE10GR2";
		opcode_lookup[16][15] = "heart-beat redo - KCVOPHBR";
		opcode_lookup[16][16] = "tablespace rename - KCVOPTRN";
		opcode_lookup[16][17] = "ENable Thread - KCVOPENT_10GR2";
		opcode_lookup[16][18] = "tablespace ONline - KCVOPONL_10GR2";
		opcode_lookup[16][19] = "tablespace OFFline - KCVOPOFF_10GR2";
		opcode_lookup[16][20] = "tablespace ReaD Write - KCVOPRDW_10GR2";
		opcode_lookup[16][21] = "tablespace ReaD Only - KCVOPRDO_10GR2";
		opcode_lookup[16][22] = "PLUgging datafiles to db - KCVOPPLG_10GR2";
		opcode_lookup[16][23] = "ADding dataFiles to database - KCVOPADF_10GR2";
		opcode_lookup[16][24] = "convert plugged in datafiles - KCVOPCNV_10GR2";
		opcode_lookup[16][25] = "Tablespace PitR - KCVOPTPR_10GR2";
		opcode_lookup[16][26] = "for file drop in tablespace - KCVOPFDP";
		opcode_lookup[16][27] = "for internal thread enable - KCVOPIEN";
		opcode_lookup[16][28] = "readable standby metadata flush - KCVOPMFL";
		opcode_lookup[16][29] = "database key creation (after bumping compatible to 11g) - KCVOPDBK";
		opcode_lookup[16][30] = "ADding dataFiles to database - KCVOPADF";
		opcode_lookup[16][31] = "PLUgging datafiles to db - KCVOPPLG";
		opcode_lookup[16][32] = "for modifying space header info - KCVOPSPHUPD";
		opcode_lookup[16][33] = "TSE Masterkey Rekey - KCVOPTMR";
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
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitRedo_info(RedoParser.Redo_infoContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterRedo_record(RedoParser.Redo_recordContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitRedo_record(RedoParser.Redo_recordContext ctx) 
	{
		change_date = ctx.date_value().getText();  ;
	}
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChange_records(RedoParser.Change_recordsContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChange_records(RedoParser.Change_recordsContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterThread(RedoParser.ThreadContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitThread(RedoParser.ThreadContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterThread_number(RedoParser.Thread_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitThread_number(RedoParser.Thread_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterRba(RedoParser.RbaContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitRba(RedoParser.RbaContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLog_file_sequence_number(RedoParser.Log_file_sequence_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLog_file_sequence_number(RedoParser.Log_file_sequence_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLog_file_block_number(RedoParser.Log_file_block_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLog_file_block_number(RedoParser.Log_file_block_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterByte_offset(RedoParser.Byte_offsetContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitByte_offset(RedoParser.Byte_offsetContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLen(RedoParser.LenContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLen(RedoParser.LenContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLen_value(RedoParser.Len_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLen_value(RedoParser.Len_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterVld(RedoParser.VldContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitVld(RedoParser.VldContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterVld_value(RedoParser.Vld_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitVld_value(RedoParser.Vld_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterScn(RedoParser.ScnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitScn(RedoParser.ScnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterWrap(RedoParser.WrapContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitWrap(RedoParser.WrapContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterBase(RedoParser.BaseContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitBase(RedoParser.BaseContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterSubscn(RedoParser.SubscnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitSubscn(RedoParser.SubscnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterSubscn_value(RedoParser.Subscn_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitSubscn_value(RedoParser.Subscn_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterDate_value(RedoParser.Date_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitDate_value(RedoParser.Date_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChange(RedoParser.ChangeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChange(RedoParser.ChangeContext ctx) 
	{ 
		if ( invalid_string.equals("N") && media_recovery_marker_string.equals("N") )
		{
			System.out.println(change_date + ',' + data_object_id_string + ',' + layer_string + '.' + opcode_string + ',' + opcode_lookup[Integer.valueOf(layer_string)][Integer.valueOf(opcode_string)]);
		}	

		if (media_recovery_marker_string.equals("Y") )
		{ 
			System.out.println(change_date + ',' + "MEDIA RECOVERY MARKER" + ',' + layer_string + '.' + opcode_string + ',' + opcode_lookup[Integer.valueOf(layer_string)][Integer.valueOf(opcode_string)]);
		}

		if (invalid_string.equals("Y") )
		{ 
			System.out.println(change_date + ',' + "INVALID" + ',' + layer_string + '.' + opcode_string + ',' + opcode_lookup[Integer.valueOf(layer_string)][Integer.valueOf(opcode_string)]);
		}

		media_recovery_marker_string = "N";
		invalid_string = "N";
	}
	@Override public void enterMedia_recovery_marker(RedoParser.Media_recovery_markerContext ctx) { }
        /**
         * {@inheritDoc}
         *
         * <p>The default implementation does nothing.</p>
         */
        @Override public void exitMedia_recovery_marker(RedoParser.Media_recovery_markerContext ctx) 
	{
		media_recovery_marker_string = "Y";
       	}
        /**
         * {@inheritDoc}
         *
         * <p>The default implementation does nothing.</p>
         */

	 @Override public void enterInvld(RedoParser.InvldContext ctx) { }
        /**
         * {@inheritDoc}
         *
         * <p>The default implementation does nothing.</p>
         */
        @Override public void exitInvld(RedoParser.InvldContext ctx) 
	{ 
		invalid_string = "Y";	
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChange_number(RedoParser.Change_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChange_number(RedoParser.Change_numberContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterBlks(RedoParser.BlksContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitBlks(RedoParser.BlksContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterBlks_value(RedoParser.Blks_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitBlks_value(RedoParser.Blks_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_type(RedoParser.Chg_typeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_type(RedoParser.Chg_typeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_type_value(RedoParser.Chg_type_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_type_value(RedoParser.Chg_type_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_class(RedoParser.Chg_classContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_class(RedoParser.Chg_classContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_class_value(RedoParser.Chg_class_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_class_value(RedoParser.Chg_class_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_afn(RedoParser.Chg_afnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_afn(RedoParser.Chg_afnContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterAfn_value(RedoParser.Afn_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitAfn_value(RedoParser.Afn_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterDba(RedoParser.DbaContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitDba(RedoParser.DbaContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterDba_value(RedoParser.Dba_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitDba_value(RedoParser.Dba_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterChg_obj(RedoParser.Chg_objContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitChg_obj(RedoParser.Chg_objContext ctx) 
	{
		data_object_id_string =  ctx.obj_value().getText(); 
       	}
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterObj_value(RedoParser.Obj_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitObj_value(RedoParser.Obj_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterSeq(RedoParser.SeqContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitSeq(RedoParser.SeqContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterSeq_value(RedoParser.Seq_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitSeq_value(RedoParser.Seq_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLayer_opcode(RedoParser.Layer_opcodeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLayer_opcode(RedoParser.Layer_opcodeContext ctx) 
	{ 
		  layer_string = ctx.layer().getText(); 
		  opcode_string =  ctx.opcode().getText(); 
		  
	}
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterLayer(RedoParser.LayerContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitLayer(RedoParser.LayerContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterOpcode(RedoParser.OpcodeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitOpcode(RedoParser.OpcodeContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterEnc(RedoParser.EncContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitEnc(RedoParser.EncContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterEnc_value(RedoParser.Enc_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitEnc_value(RedoParser.Enc_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterRbl(RedoParser.RblContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitRbl(RedoParser.RblContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterRbl_value(RedoParser.Rbl_valueContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitRbl_value(RedoParser.Rbl_valueContext ctx) { }

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void enterEveryRule(ParserRuleContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void exitEveryRule(ParserRuleContext ctx) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void visitTerminal(TerminalNode node) { }
	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation does nothing.</p>
	 */
	@Override public void visitErrorNode(ErrorNode node) { }
}
