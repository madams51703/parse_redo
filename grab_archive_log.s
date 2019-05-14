#!/bin/bash
START_DATE_TIME=""
START_TIME=0
END_DATE_TIME=""
END_TIME=0
usage()
{
	echo "Usage:"
	exit 1
}


while getopts "e:s:i:a:o:x:" o; do
	case "${o}" in
 		i)
			TRACEFILEID=${OPTARG}
		;;	

		o)
			LOGFILEOPTIONS="${LOGFILEOPTIONS}  OBJNO ${OPTARG} " 
		;;

		x)
			LOGFILEOPTIONS="${LOGFILEOPTIONS}  XID ${OPTARG} " 
		;;

        	s)
            		START_DATE_TIME=${OPTARG}
			START_DAY=`date -d "${START_DATE_TIME}" +%d`
			START_MONTH=`date -d "${START_DATE_TIME}" +%m`
			START_YEAR=`date -d "${START_DATE_TIME}" +%Y`
			START_HOUR=`date -d "${START_DATE_TIME}" +%H`
			START_MINUTE=`date -d "${START_DATE_TIME}" +%M`
			START_SECONDS=`date -d "${START_DATE_TIME}" +%S`
			START_TIME=$(( (((((${START_YEAR} - 1988 )*12) + ( ${START_MONTH}-1))*31  +  ( ${START_DAY} - 1) ) *24   +  ${START_HOUR} ) *60  + ( ${START_MINUTE} * 60 ) + ( ${START_SECONDS} )    ))
			LOGFILEOPTIONS="${LOGFILEOPTIONS} MIN TIME ${START_TIME} " 
			
		;;

        	e)
            		END_DATE_TIME=${OPTARG}
			END_DAY=`date -d "${END_DATE_TIME}" +%d`
			END_MONTH=`date -d "${END_DATE_TIME}" +%m`
			END_YEAR=`date -d "${END_DATE_TIME}" +%Y`
			END_HOUR=`date -d "${END_DATE_TIME}" +%H`
			END_MINUTE=`date -d "${END_DATE_TIME}" +%M`
			END_SECONDS=`date -d "${END_DATE_TIME}" +%S`
			END_TIME=$(( (((((${END_YEAR} - 1988 )*12) + ( ${END_MONTH}-1))*31  +  ( ${END_DAY} - 1) ) *24   +  ${END_HOUR} ) *60  + ( ${END_MINUTE} * 60 ) + ( ${END_SECONDS} )    ))
			
			
			LOGFILEOPTIONS="${LOGFILEOPTIONS} MAX TIME ${END_TIME} " 
		;; 

		a)
			ARCHIVEDLOGNUM="${OPTARG}"
		;;	

    esac
done
if [ "${TRACEFILEID}" = "" ] ; then echo "Requires a tracefile identifier"
	exit 1 
fi

rm /opt/oracle/diag/rdbms/xe/XE/trace/*${TRACEFILEID}*.trc
L=`sqlplus -s / as sysdba @archived_log.sql | tail -1`
echo "alter session set tracefile_identifier='${TRACEFILEID}'  ; " > trace.sql
if [ "${ARCHIVEDLOGNUM}" = "" ] ; then
	echo "alter system dump logfile '$L' ${LOGFILEOPTIONS} ;"  >> trace.sql
else
B=`dirname ${L}` 
C=`ls -1 ${B}/*${ARCHIVEDLOGNUM}*`
	echo "alter system dump logfile '${C}' ${LOGFILEOPTIONS}  ;" >> trace.sql
fi
echo "quit "  >> trace.sql
sqlplus -s / as sysdba @trace.sql
set -x
#egrep "REDO RECORD|CHANGE|^SCN|^col|redo:|^Block cleanout record|      xid" /opt/oracle/diag/rdbms/xe/XE/trace/*${TRACEFILEID}*.trc  > ${TRACEFILEID}.input
egrep "REDO RECORD|CHANGE|^SCN|redo:|^Block cleanout record|      xid" /opt/oracle/diag/rdbms/xe/XE/trace/*${TRACEFILEID}*.trc  > ${TRACEFILEID}.input
./parse_redo.sh ${TRACEFILEID}.input >${TRACEFILEID}.output
