

lexer grammar RedoLexer;




AFN:                   'AFN';
BEGIN:                 'BEGIN';
BCL:                   'BCL';
BDDBA:                 'BDDBA';
BIT:                   'BIT';
BLKS:                  'BLKS';
BLOCK:                 'BLOCK';
BUEXT:                 'BUEXT';
BUFFER:                'BUFFER';
BRB:                   'BRB';
CACHE:                 'CACHE';
CHANGE:                'CHANGE #';
CKIX:                  'CKIX';
CLEANOUT:              'CLEANOUT';
CLS:                   'CLS';
CMT:                   'CMT';
CODE:                  'CODE';
COL:                   'COL';
COMPAT:                'COMPAT';
CTL:                   'CTL';
DATE:                  [0-1][0-2][/][0-3][0-9][/][1-2][0-9][0-9][0-9][ ][1-2][0-9][:][0-5][0-9][:][0-5][0-9];
DBA:                   'DBA';
DEPENDENCIES:          'DEPENDENCIES';
DISABLED:              'DISABLED';
ENC:                   'ENC';
ENTRIES:               'ENTRIES';
EXT:                   'EXT';
FBI:                   'FBI';
FLAG:                  'FLAG';
FLG:                   'FLG';
FLG2:                  'FLG2';
FOLLOW:                'FOLLOW';
HDBA:                  'HDBA';
INFO:                  'INFO'; 
INVALIDATION:          'INVALIDATION';
INVLD:                 'INVLD';
ISPAC:                 'ISPAC';
ITLI:                  'ITLI';
ITL:                   'ITL';
KDO:                   'KDO';
KGL:                   'KGL';
KQR:                   'KQR';
KTB:                   'KTB';
KTUBL:                 'KTUBL';
KTUCF:                 'KTUCF';
KTUCM:                 'KTUCM';
KTUDB:                 'KTDB';
KTUDH:                 'KTUDH';
LAST:                  'LAST';
LEN:                   'LEN';
LOCK:                  'LOCK';
LOGON:                 'LOGON';
LWN:                   'LWN';
MARKER:                'MARKER';
MAXFR:                 'MAXFR';
MAX:                   'MAX';
MEDIA:                 'MEDIA';
METADATA:              'METADATA';
NCOL:                  'NCOL';
NNEW:                  'NNEW';
NST:                   'NST';
OBJD:                  'OBJD';
OBJECT:                'OBJECT';
OBJN:                  'OBJN';
OBJ:                   'OBJ';
OP:                    'OP';
OPT:                   'OPT';
PADDING:               'PADDING';
POST:                  'POST';
PREV:                  'PREV';
PXID:                  'PXID';
RBA:                   'RBA';
RBL:                   'RBL';
RCI:                   'RCI';
RECORD:                'RECORD';
RECOVERY:              'RECOVERY';
REC:                   'REC';
REDO:                  'REDO';
REGULAR:               'REGULAR';
ROW:                   'ROW';
SCN:                   'SCN';
SEQ:                   'SEQ';
SIZE:                  'SIZE';
SIZ:                   'SIZ';
SLOT:                  'SLOT';
SLT:                   'SLT';
SPC:                   'SPC';
SPLIT:                 'SPLIT';
SQN:                   'SQN';
STANDBY:               'STANDBY';
SUBSCN:                'SUBSCN';
TABLESPACE:            'TABLESPACE';
TABN:                  'TABN';
TEMP:                  'TEMP';
THREAD:                'THREAD';
TRANS:                 'TRANS';
TSN:                   'TSN';
TX:                    'TX';
TXN:                   'TXN';
TYP:                   'TYP';
UNDO:                  'UNDO';
USER:                  'USER';
VLD:                   'VLD';
VER:                   'VER';
XA:                    'XA';
XID:                   'XID';
XTYPE:                 'XTYPE';
COLON:                 ':';
POUND:                 '#';
MINUS:                 '-';
DOT:                   '.';
HEX:                   '0X'?[0-9A-F]+;

SPACES: [ \t\r\n]+ -> skip;
