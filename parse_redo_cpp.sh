export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/lib64 
./parse_redo_cpp $1
exit $?
