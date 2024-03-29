

lexer grammar RedoLexer;




AFN:                   'AFN';
BEGIN:                 'BEGIN';
BCL:                   'BCL';
BDDBA:                 'BDDBA';
BIGSCN:                'BIGSCN';
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
CLEAR:                 'CLEAR';
CLS:                   'CLS';
CMT:                   'CMT';
CODE:                  'CODE';
COL:                   'COL';
COMPACT:               'COMPACT';
COMPAT:                'COMPAT';
CONTROL:               'CONTROL';
CON_ID:                'CON_ID';
CON_UID:               'CON_UID';
CSCN:                  'CSCN';
CTL:                   'CTL';
DATE:                  [0-1][0-9][/][0-3][0-9][/][1-2][0-9][0-9][0-9][ ][0-2][0-9][:][0-5][0-9][:][0-5][0-9];
DBA:                   'DBA';
DEPENDENCIES:          'DEPENDENCIES';
DISABLED:              'DISABLED';
ENC:                   'ENC';
ENTRIES:               'ENTRIES';
EXT:                   'EXT';
EXTENT:                'EXTENT';
FBI:                   'FBI';
FLAG:                  'FLAG';
FLG:                   'FLG';
FLG2:                  'FLG2';
FGB:                   'FGB';
FREELIST:              'FREELIST';
FOLLOW:                'FOLLOW';
HDBA:                  'HDBA';
INFO:                  'INFO'; 
INVALIDATION:          'INVALIDATION';
INVLD:                 'INVLD';
ISPAC:                 'ISPAC';
ITLI:                  'ITLI';
ITLS:                  'ITLS';
ITL:                   'ITL';
KDO:                   'KDO';
KGL:                   'KGL';
KQR:                   'KQR';
KTB:                   'KTB';
KTECUSH:               'KTECUSH';
KTELK:                 'KTELK';
KTSFRGRP:              'KTSFRGRP';
KTSFRBLNK:             'KTSFRBLNK (BLOCK LINK MODIFY)';
KTSFRBFMT:             'KTSFRBFMT (BLOCK FORMAT)';
KTUBL:                 'KTUBL';
KTUBU:                 'KTUBU';
KTUDBU:                'KTUDBU';
KTUCF:                 'KTUCF';
KTUCM:                 'KTUCM';
KTUDB:                 'KTUDB';
KTUDH:                 'KTUDH';
KTSFM:                 'KTSFM';
LAST:                  'LAST';
LEN:                   'LEN';
LOCK:                  'LOCK';
LOGON:                 'LOGON';
LWN:                   'LWN';
LWRT:                  'LWRT (LOCK WRITE)';
LSET:                  'LSET (LOCK SET)';
LCLR:                  'LCLR (LOCK CLEAR)';
LFDBA:                 'LFDBA';
MARKER:                'MARKER';
MAXFR:                 'MAXFR';
MAX:                   'MAX';
MEDIA:                 'MEDIA';
METADATA:              'METADATA';
MODIFY:                'MODIFY';
NCOL:                  'NCOL';
NFL:                   'NFL';
NNEW:                  'NNEW';
NST:                   'NST';
NULL_COLUMN_VALUE:      '*NULL*';
OBJD:                  'OBJD';
OBJECT:                'OBJECT';
OBJN:                  'OBJN';
OBJ:                   'OBJ';
OP:                    'OP';
OPC:                   'OPC';
OPCODE:                'OPCODE';
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
SEGOBJD:               'SEGOBJD';
SHDR:                  'SHDR';
SIZE:                  'SIZE';
SIZ:                   'SIZ';
SLOT:                  'SLOT';
SLT:                   'SLT';
SPARE:                 'SPARE';
SPC:                   'SPC';
SPLIT:                 'SPLIT';
SQN:                   'SQN';
SRT:                   'SRT';
STA:                   'STA';
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
TYPE:                  'TYPE';
UBA:                   'UBA';
UNDO:                  'UNDO';
USER:                  'USER';
VLD:                   'VLD';
VER:                   'VER';
XA:                    'XA';
XID:                   'XID';
XTYPE:                 'XTYPE';
Y:                     'Y';
N:                     'N';
COLON:                 ':';
POUND:                 '#';
MINUS:                 '-';
DOT:                   '.';
COMMA:                 ',';
HEX:                   '0X'?[0-9A-F]+;
LPAREN:                '(';
RPAREN:                ')';
LSQUARE:               '[';
RSQUARE:               ']';
FSLASH:                '/';

SPACES: [ \t\r\n]+ -> skip;
