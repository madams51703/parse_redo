
lexer grammar RedoLexer;

options { caseInsensitive = true; }
KDXDLR:                'KDXDLR';
KC:                    'KC';
KMINUS:                'K-';
CREATE:                'CREATE';
KD_OFF:                'KD_OFF' -> pushMode(MEMORY_DUMP);
ROOT:                  'ROOT';


END_OF_LEAF_BLOCK_LOGICAL_DUMP : 'END OF LEAF BLOCK LOGICAL DUMP' ;
END_OF_LEAF_BLOCK_DUMP: 'END OF LEAF BLOCK DUMP'  -> pushMode(MEMORY_DUMP);

END:                   'END';
LOGICAL:               'LOGICAL';
ADDRESS:               'ADDRESS';
KDXCOLOK:              'KDXCOLOK';
KDXCOOPC:              'KDXCOOPC';
CONVERTED:             'CONVERTED';
EQUALS:                'EQUALS';
IOT:                   'IOT';
KDXCONCO:              'KDXCONCO';
KDXCOSDC:              'KDXCOSDC';
KDXCONRO:              'KDXCONRO';
KDXCOFBO:              'KDXCOFBO';
KDXCOFEO:              'KDXCOFEO';
KDXCOAVS:              'KDXCOAVS';
KDXLESPL:              'KDXLESPL';
KDXLENDE:              'KDXLENDE';
KDXLEDSZ:              'KDXLEDSZ';
KDXLEBKSZ:             'KDXLEBKSZ';
KDXCOLEV:              'KDXCOLEV';


COMMITTED:             'COMMITTED';
HOLES:                 'HOLES';
ADVANCED:              'ADVANCED';
COMPRESSION:           'COMPRESSION';


LASTS:                 'LASTS';
LF:                    'LF';
LS:                    'LS';
LT:                    'LT';
FT:                    'FT';
MCLS:                  'MCLS';


FROM:                  'FROM';
CSC:                   'CSC';
DIRECT:                'DIRECT';
LOADER:                'LOADER';
ID:                    'ID';
DATA_BLOCK_DUMP:       'DATA_BLOCK_DUMP';
FBSO:                  'FBSO';
BLOCK_ROW_DUMP:        'BLOCK_ROW_DUMP';
TAB:                   'TAB';
END_OF_BLOCK_DUMP:     'END_OF_BLOCK_DUMP'  -> pushMode(MEMORY_DUMP);
OFFS:                  'OFFS';
PTI:                   'PTI';
PRI:                   'PRI';
NTAB:                  'NTAB';
TOSP:                  'TOSP';
AVSP:                  'AVSP';
FSEO:                  'FSEO';
FSBO:                  'FSBO';
FRRE:                  'FRRE';
TSIZ:                  'TSIZ';
HSIZ:                  'HSIZ';
PBL:                   'PBL';
EXFLG:                 'EXFLG';
INC:                   'INC';
BRN:                   'BRN';


ADDAXT:                'ADDAXT';
FDBA:                  'FDBA';


SHORT:                 'SHORT';
ROWID:                 'ROWID';
CMAP:                  'CMAP';
PFILL:                 'PFILL';

BIMG:                  'BIMG';
FPLOAD:                'FPLOAD';
BSZ:                   'BSZ';
LOAD:                  'LOAD';
DATA:                  'DATA';
KDLICH:                'KDLICH';
LID:                   'LID';
PSKIP:                 'PSKIP';
SSKIP:                 'SSKIP';
HASH:                  'HASH';
SPR:                   'SPR';
KDLIDH:                'KDLIDH';
FLG3:                  'FLG3';



DATA_BLOCK_BI:         'DATA BLOCK B.I.' -> pushMode(MEMORY_DUMP);
DUMPING_ROW_INDEX:     'DUMPING ROW INDEX' -> pushMode(MEMORY_DUMP);
DUMPING_ROWS:          'DUMPING ROWS' -> pushMode(MEMORY_DUMP);
A:		       'A';
B:                     'B';
C:                     'C';
D:                     'D';
E:                     'E';
F:                     'F';
H:                     'H';
I:                     'I';
L:                     'L';
Q:                     'Q';
R:                     'R';
S:                     'S';
U:                     'U';
Z:                     'Z';
ADD:                   'ADD';
ADDRET:                'ADDRET';
AFN:                   'AFN';
ALLOCATED:             'ALLOCATED';
AND:                   'AND';
APPLY:                 'APPLY';
ARRAY:                 'ARRAY';
AT:                    'AT';
AUTO:                  'AUTO';
BACK:                  'BACK';
BEGIN:                 'BEGIN';
BELOW:                 'BELOW';
BCL:                   'BCL';
BDDBA:                 'BDDBA';
BDBA:                  'BDBA';
BEFORE:                'BEFORE';
BEING:                 'BEING';
BFT:                   'BFT';
BIGSCN:                'BIGSCN';
BIT:                   'BIT';
BITS:                  'BITS';
BITMAP:                'BITMAP';
BKW:                   'BKW';
BLK_POUND:             'BLK#';
BLKS:                  'BLKS';
BLOCK:                 'BLOCK';
BLOCKS:                'BLOCKS';
BMB:                   'BMB';
BOTH:                  'BOTH';
BRB:                   'BRB';
BRANCH:                'BRANCH';
BUEXT:                 'BUEXT';
BUFFER:                'BUFFER';
CACHE:                 'CACHE';
CC_COLON:              'CC:';
CCNT:                  'CCNT';
CDBROOT:               'CDB$ROOT';
CFL:                   'CFL';
CHANGE:                'CHANGE #';
CHANGE_RAW:            'CHANGE';
CHILD:                 'CHILD';
CHUNKS:                'CHUNKS';
CHUNK:                 'CHUNK';
CKI:                   'CKI';
CKIX:                  'CKIX';
CLASS:                 'CLASS';
CLEANOUT:              'CLEANOUT';
CLEAR:                 'CLEAR';
CLS:                   'CLS';
CMT:                   'CMT';
CODE:                  'CODE';
COL:                   'COL';
COMC:                  'COMC';
COMMIT:                'COMMIT';
COMMON:                'COMMON';
COMPACT:               'COMPACT';
COMPAT:                'COMPAT';
CONTENT:               'CONTENT';
CONTROL:               'CONTROL';
CON_ID:                'CON_ID';
CON_UID:               'CON_UID';
COUNT:                 'COUNT';
CSCN:                  'CSCN';
CTIME:                 'CTIME';
CTL:                   'CTL';
CU:                    'CU';
CURC:                  'CURC';
DATABLOCK:             'DATABLOCK';
DATAFILE:              'DATAFILE';
DATE:                  [0-1][0-9][/][0-3][0-9][/][1-2][0-9][0-9][0-9][ ][0-2][0-9][:][0-5][0-9][:][0-5][0-9];
DBA:                   'DBA';
DEPENDENCIES:          'DEPENDENCIES';
DELETED:               'DELETED';
DELETE:                'DELETE';
DELT:                  'DELT';
DISABLE:               'DISABLE';
DISK:                  'DISK';
DISABLED:              'DISABLED';
DO:                    'DO';
DONE:                  'DONE';
DRP:                   'DRP';
DUMP:                  'DUMP';
DUMPING:               'DUMPING';
DURING:                'DURING';
EACH:                  'EACH';
EMPTY:                 'EMPTY';
ENC:                   'ENC';
ENTRIES:               'ENTRIES';
ENTRY:                 'ENTRY';
EXT:                   'EXT';
EXT_POUND:             'EXT#';
EXTS:                  'EXTS';
EXTENT:                'EXTENT';
EXISTS:		       'EXISTS';
FALSE:                 'FALSE';
FB_COLON:              'FB:';
FBI:                   'FBI';
FCLS:                  'FCLS';
FLAG:                  'FLAG';
FLAGS:                 'FLAGS';
FLG:                   'FLG';
FLG0:                  'FLG0';
FLG1:                  'FLG1';
FLG2:                  'FLG2';
FGB:                   'FGB';
FILE:                  'FILE';
FPM:                   'FPM';
FREE:                  'FREE';
FREELIST:              'FREELIST';
FREELISTS:             'FREELISTS';
FSC:                   'FSC';
FMT_FLAG:              'FMT_FLAG';
FOLLOW:                'FOLLOW';
FOR:                   'FOR';
FORCEL3:               'FORCEL3';
FORMAT:                'FORMAT';
FWD:                   'FWD';
GENERAL:               'GENERAL';
HAS:                   'HAS';
HDBA:                  'HDBA';
HDRS:                  'HDR'[']'S';
HEAD:                  'HEAD';
HEADER:                'HEADER';
HIGHWATER:             'HIGHWATER';
HIGH:                  'HIGH';
HINT:                  'HINT';
HWMMV:                 'HWMMV';
HWMS:                  'HWMS';
HWM:                   'HWM';
IDX:                   'IDX';
IMAGE:                 'IMAGE';
IN:                    'IN';
INCN:                  'INCN';
INC_POUND:             'INC#';
INDEX:                 'INDEX';
INDEXID:               'INDEXID';
INFO:                  'INFO'; 
INITIALIZE:            'INITIALIZE';
INIT:                  'INIT';
INSERT:                'INSERT';
INST:                  'INST';
INSTANCE:              'INSTANCE';
INTO:                  'INTO';
INVALIDATION:          'INVALIDATION';
INVLD:                 'INVLD';
IRP:                   'IRP';
IS:                    'IS';
ISPAC:                 'ISPAC';
ITC:                   'ITC';
ITLI:                  'ITLI';
ITLS:                  'ITLS';
ITL:                   'ITL';
JUST:                  'JUST';
KDIGE:                 'KDIGE';
KDLI:                  'KDLI';
KEY:                   'KEY';
KEYS:                  'KEYS';
KEYDATA:               'KEYDATA';
KDILK:                 'KDILK';
KDXAIR:                'KDXAIR';
KDXBIN:                'KDXBIN';
KDXBNE:                'KDXBNE';
KDXBPU:                'KDXBPU';
KDXDUMPCOMPDO:         'KDXDUMPCOMPDO';
KDXIMA:                'KDXIMA';
KDXLCL:                'KDXLCL';
KDXLDE:                'KDXLDE';
KDXLEM:                'KDXLEM';
KDXLENXT:              'KDXLENXT';
KDXLEPRV:              'KDXLEPRV';
KDXLIN:                'KDXLIN';
KDXLKFLG:              'KDXLKFLG';
KDXLNE:                'KDXLNE';
KDXLNITL:              'KDXLNITL';
KDXLNNCO:              'KDXLNNCO';
KDXLNDSZ:              'KDXLNDSZ';
KDXLNCOL:              'KDXLNCOL';
KDXLNFLG:              'KDXLNFLG';
KDXLNNXT:              'KDXLNNXT';
KDXLNPRV:              'KDXLNPRV';
KDXLOK:                'KDXLOK';
KDXLPR:                'KDXLPR';
KDXLPU:                'KDXLPU';
KDXLRE:                'KDXLRE';
KDXLUP:                'KDXLUP';
KDXULO:                'KDXULO';
KDO:                   'KDO';
KDO_KDOM2:             'KDO_KDOM2';
KGL:                   'KGL';
KQR:                   'KQR';
HRID:                  'HRID';
KTB:                   'KTB';
KTFBHREDO:             'KTFBHREDO';
KTFBHUNDO:             'KTFBHUNDO';
KTFBBREDO:             'KTFBBREDO';
KTFBN:                 'KTFBN';
KTSBIFM:               'KTSBIFM';
KTSBI:                 'KTSBI';
KTSL:                  'KTSL';
KTSPHFREDO:            'KTSPHFREDO';
KTSPFFREDO:            'KTSPFFREDO';
KTECUSH:               'KTECUSH';
KTELK:                 'KTELK';
KTEOPU:                'KTEOPU';
KTEOP:                 'KTEOP';
KTSFRGRP:              'KTSFRGRP';
KTSFRBLNK:             'KTSFRBLNK (BLOCK LINK MODIFY)';
KTSFRBFMT:             'KTSFRBFMT (BLOCK FORMAT)';
KTSPBFREDO:            'KTSPBFREDO';
KTSPSFREDO:            'KTSPSFREDO';
KTUBL:                 'KTUBL';
KTUBU:                 'KTUBU';
KTUDBR:                'KTUDBR';
KTUDBU:                'KTUDBU';
KTUCF:                 'KTUCF';
KTUCM:                 'KTUCM';
KTUDB:                 'KTUDB';
KTUDH:                 'KTUDH';
KTUST:                 'KTUST';
KTUXVFLG:              'KTUXVFLG';
KTUXVOFF:              'KTUXVOFF';
KTSFM:                 'KTSFM';
LAYER:                 'LAYER';
LAST:                  'LAST';
LASTMAP:               'LASTMAP';
LB:                    'LB';
LEAF:                  'LEAF';
LEN:                   'LEN';
LENGTH:                'LENGTH';
LEVEL:                 'LEVEL';
LEV:                   'LEV';
LIST:                  'LIST';
LKC:                   'LKC';
LKR:                   'LKR';
LMC:                   'LMC';
LOB:                   'LOB';
LOCK:                  'LOCK';
LOCKING:               'LOCKING';
LOGON:                 'LOGON';
LWN:                   'LWN';
LOW:                   'LOW';
LWRT:                  'LWRT (LOCK WRITE)';
LSET:                  'LSET (LOCK SET)';
LCLR:                  'LCLR (LOCK CLEAR)';
LCK:                   'LCK';
LFDBA:                 'LFDBA';
LINK:                  'LINK';
LUPD_LLIST:            'LUPD_LLIST';
LUPD_UNLIST:           'LUPD_UNLIST';
LUPD_UNLBLK:           'LUPD_UNLBLK';
LVEC:                  'LVEC';
UNLINK:                'UNLINK';
MAKE:                  'MAKE';
MAP:                   'MAP';
MAPBLK:                'MAPBLK';
MAPCNT:                'MAPCNT';
MARK:                  'MARK';
MARKER:                'MARKER';
MAXFR:                 'MAXFR';
MAX:                   'MAX';
MEDIA:                 'MEDIA';
METADATA:              'METADATA';
MODIFY:                'MODIFY';
MOVE:                  'MOVE';
NBITS:                 'NBITS';
NBKS:                  'NBKS';
NBK:                   'NBK';
NBLKS:                 'NBLKS';
NCOL:                  'NCOL';
NCO:                   'NCO';
NEW:                   'NEW';
NEWLY:                 'NEWLY';
NEXT:                  'NEXT';
NMRK:                  'NMRK';
NNEW:                  'NNEW';
NFL:                   'NFL';
NO:                    'NO';
NONBFT:               'NON-BFT';
NRID:                  'NRID';
NROW:                  'NROW';
POUND_BLOCKS:          '#BLOCKS';
YES:                   'YES';
NCMT:                  'NCMT';
NEWSTATE:              'NEWSTATE';
NK:                    'NK';
NST:                   'NST';
NULL_COLUMN_VALUE:      '*NULL*';
NULL:                  'NULL';
NUMBER:                'NUMBER';
OBJD:                  'OBJD';
OBJECT:                'OBJECT';
OBJN:                  'OBJN';
OBJ:                   'OBJ';
OF:                    'OF';
OFF:                   'OFF';
OFFSET:                'OFFSET';
OLD:                   'OLD';
ON:                    'ON';
ONLY:                  'ONLY';
OP:                    'OP';
OPC:                   'OPC';
OPCODE:                'OPCODE';
OPERATION:             'OPERATION';
OPERATIONS:            'OPERATIONS';
OPT:                   'OPT';
ORP:                   'ORP';
OR:                    'OR';
PADDING:               'PADDING';
PAGETABLE:             'PAGETABLE';
PARENT:                'PARENT';
PDBUID:                'PDBUID';
PDB:                   'PDB';
PENDING:               'PENDING';
PERSISTENT:            'PERSISTENT';
PK:                    'PK';
POFF:                  'POFF';
POST:                  'POST';
PRE:                   'PRE';
PREFIX:                'PREFIX';
PREVIOUS:              'PREVIOUS';
PREV:                  'PREV';
PROPERTY:              'PROPERTY';
PSIZ:                  'PSIZ';
PUA:                   'PUA';
PUB:                   'PUB';
PURGE:                 'PURGE';
PXID:                  'PXID';
QMD:                   'QMD';
QMI:                   'QMI';
RANGE:                 'RANGE';
RBA:                   'RBA';
RBL:                   'RBL';
RBR:                   'RBR';
RC:                    'RC';
RCI:                   'RCI';
RDBA:                  'RDBA';
RECO:                  'RECO';
RECORD:                'RECORD';
RECOVERY:              'RECOVERY';
REC:                   'REC';
REDO:                  'REDO';
REGULAR:               'REGULAR';
REJECTION:             'REJECTION';
RESETTOK:                 'RESET';
RESIZE:                'RESIZE';
RESTORE:               'RESTORE';
RESTORED:              'RESTORED';
REUSE:                 'REUSE';
ROLLBACK:              'ROLLBACK';
ROLLED:                'ROLLED';
ROW:                   'ROW';
ROWS:                  'ROWS';
SAVE:                  'SAVE';
SCLS:                  'SCLS';
SCN:                   'SCN';
SDC:                   'SDC';
SEQ:                   'SEQ';
SEG:                   'SEG';
SEGHDR:                'SEGHDR';
SEGMENT:               'SEGMENT';
SEGOBJD:               'SEGOBJD';
SELFLOCK:              'SELFLOCK';
SET:                   'SET';
SETSTAT:               'SETSTAT';
SHDR:                  'SHDR';
SHIFT:                 'SHIFT';
SINGLE:                'SINGLE';
SIZE:                  'SIZE';
SIZES:                 'SIZES';
SIZ:                   'SIZ';
SKL:                   'SKL';
SLOT:                  'SLOT';
SLOTS:                 'SLOTS';
SLT:                   'SLT';
SNO:                   'SNO';
SPACE:                 'SPACE';
SPARE:                 'SPARE';
SPC:                   'SPC';
SPLITTING:             'SPLITTING';
SPLIT:                 'SPLIT';
SQN:                   'SQN';
SRT:                   'SRT';
STA:                   'STA';
STATE:                 'STATE';
STAT:                  'STAT';
START:                 'START';
STANDBY:               'STANDBY';
SUBSCN:                'SUBSCN';
TABLESPACE:            'TABLESPACE';
TABN:                  'TABN';
TEMP:                  'TEMP';
TAIL:                  'TAIL';
THE:                   'THE';
THREAD:                'THREAD';
TL:                    'TL';
TO:                    'TO';
TRANS:                 'TRANS';
TRANSACTION:           'TRANSACTION';
TREE:                  'TREE';
TRUE:                  'TRUE';
TRY:                   'TRY';
TSN:                   'TSN';
TX:                    'TX';
TXN:                   'TXN';
TYP:                   'TYP';
TYPE:                  'TYPE';
UBA:                   'UBA';
UNDO:                  'UNDO';
UNLOCK:                'UNLOCK';
UPDATE:                'UPDATE';
UPDXNT:                'UPDXNT';
USE:                   'USE';
USER:                  'USER';
USING:                 'USING';
UTIME:                 'UTIME';
URP:                   'URP';
VLD:                   'VLD';
VECT:                  'VECT';
VECTOR:                'VECTOR';
VER:                   'VER';
WHR:                   'WHR';
WRITTEN:               'WRITTEN';
WRP:                   'WRP';
XA:                    'XA';
XID:                   'XID';
XIDSLOT:               'XIDSLOT';
XR:                    'XR';
XTYPE:                 'XTYPE';
XAT:                   'XAT';
XAXTYPE:               'XAXTYPE';
ZEROED:                'ZEROED';
Y:                     'Y';
N:                     'N';
STARDATE:              '*** '[2][0-1][0-9][0-9]'-'[0-9][0-9]'-'[0-9][0-9]'T'[0-2][0-9]':'[0-5][0-9]':'[0-5][0-9]'.'[0-9]+'-'[0-2][0-9]':'[0][0] -> skip;
AT_SIGN:               '@';
QUESTION:              '?';
COLON:                 ':';
SEMICOLON:             ';';
POUND:                 '#';
MINUS:                 '-';
DOT:                   '.';
COMMA:                 ',';
HEXBYTE:              ' [0-9A-F][0-9A-F';
HEX:                   [0]?[X]?[0-9A-F]+;
LPAREN:                '(';
RPAREN:                ')';
LSQUARE:               '[';
RSQUARE:               ']';
FSLASH:                '/';
EQUAL:                 '=';
SPACES: [ \t\r\n]+ -> skip;


mode MEMORY_DUMP;
REPEAT_X_TIMES:    'REPEAT '[0-9]+ ' TIMES' -> skip; 
DUMPING_ROWS2:     'DUMPING ROWS' -> type(DUMPING_ROWS)  ;
DUMP2:             'DUMP' -> type(DUMP);
FROM2:              'FROM';
MEMORY:            'MEMORY';
MINUS2:            '-' -> type(MINUS);
OF2:               'OF' -> type(OF);
TO2:               'TO' -> type(TO);
HEX2:              '0X'?[0-9A-F]+ -> type(HEX);
MEMORY_DISPLAY:     '[' .? .? .? .? .? .? .? .? .? .? .? .? .? .? .? .?  ']';
AUTO2:              'AUTO' -> type(AUTO), popMode;
REDO2:              'REDO' -> type(REDO), popMode;
CHANGE2:            'CHANGE #' -> type(CHANGE), popMode;
STARDATE2:              '*** '[2][0-1][0-9][0-9]'-'[0-9][0-9]'-'[0-9][0-9]'T'[0-2][0-9]':'[0-5][0-9]':'[0-5][0-9]'.'[0-9]+'-'[0-2][0-9]':'[0][0] -> skip;
LPAREN2:            '(' -> type (LPAREN), popMode;
SPACES2: [ \t\r\n]+ -> skip;
