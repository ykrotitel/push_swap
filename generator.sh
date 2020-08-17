#!/bin/zsh
# variables

PUSH_SWAP=push_swap
CHECKER=checker
TEMPFILE=resulttempfile.txt;
RECOMPILE=0;
ERRORS=errorstempfile.txt

# unchanging variables
YESNO=0;
A=;
RED='\033[0;31m';
WHITE='\033[1m';
CLN='\033[0m';
RM=/bin/rm;
# RANGENUM=10
RANGENUM=10000
NUMMAX=5000
WRONGCOUNT=0;
OKCOUNT=0;
SORTCOUNTEROK=0;
SORTCOUNTERKO=0;
MAXNUMBER=0;
MINNUMBER=10000;
MEDIUM=0;
TESTNUM=1;
NUMBERS=500;

    while [ ${YESNO} -lt ${NUMBERS} ]; do
        TEMP=$((RANDOM%${RANGENUM}+0))" ";
        if [[ ${A} == *${TEMP}* ]]; then
            continue;
        else
            A+=${TEMP};
            ((YESNO++));
        fi
    done
​
 # A="1 3 7 2 4 9 8 6 5 0 "
    echo ${A}
  # ./push_swap ${A} | ../visualizer ${A} # | wc -l #./checker ${A}
  ./push_swap ${A} | wc -l
 #./push_swap ${A}
#   valgrind ./push_swap ${A} | valgrind ./checker ${A}