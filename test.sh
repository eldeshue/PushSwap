#!/bin/zsh

# Get from arguments
if [ -z $1 ]; then
	SEQ_START=1
else
	SEQ_START=$1
fi
if [ -z $2 ]; then
	SEQ_END=100
else
	SEQ_END=$2
fi
if [ -z $3 ]; then
	ITER_COUNT=5
else
	ITER_COUNT=$3
fi
MEM_CHECK=0

# Print Constants
RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

# Check argument parser
echo "[INFO] Checking Argument Parser"
for VAR in "1 3 5" "-2 -6 -5" "-1 0 4" "2147483647 1" "-2147483648 -2" ; do
	MEMCHECK=$(./push_swap $VAR)
	if [ $? -ne 0 ]; then
		echo
		echo "${RED}[PARSER ERROR]${ENDCOLOR} should have no error - \`./push_swap \"$VAR\"\`" >&2
		exit
	fi
done
for VAR in "1 1 3" "2147483648 1" "9223372036854775807 1" "-2147483649 -2" "-9223372036854775808 0"; do
	MEMCHECK=$(./push_swap $VAR)
	if [ $? -eq 0 ] || [ $? -eq 255 ]; then
		echo
		echo "${RED}[PARSER ERROR]${ENDCOLOR} should have error - \`./push_swap \"$VAR\"\`" >&2
		exit
	fi
done
echo "${GREEN}[SUCCESS]${ENDCOLOR}Parser test success!"

# Test constants
ERROR_COUNT=0
ERROR_MAX=5
ERRORS=""
# Test begin...
for N in $(seq $SEQ_START $SEQ_END); do 
	MAX_OP=-1
	TOTAL_OP=0
	echo -n "[INFO] Randomized sequence of $N variables: "

	for RUN in $(seq 1 $ITER_COUNT); do
		# RUN THE TEST!!!
		VAR=$(seq $N | sort -R | tr '\n' ' ');
		CHECKER=$(./push_swap $VAR | ./checker $VAR);

		# exit status is not 0 when (1) timeout occured or (2) push_swap output contains illegal characters
		# terminate condition: timeout or illegal output
		if [ "$?" != "0" ]; then
			echo
			echo "${RED}[TIMEOUT/Illegal Output]${ENDCOLOR} - \`./push_swap \"$VAR\"\`" > 2
			exit
		fi
		
		# checker should print "OK" when result is sorted, and "KO" when not sorted
		# if "KO"...
		if [ $CHECKER != "OK" ]; then
			echo -n "${RED}.${ENDCOLOR}"
			# terminate condition: more "KO"s then $ERROR_MAX
			ERROR_COUNT=$(($ERROR_COUNT + 1))
			ERRORS="${ERRORS}[$N]\"$VAR\"\n"
			if [ $ERROR_COUNT -ge $ERROR_MAX ]; then
				echo
				echo "${RED}ERROR LIMIT EXCEEDED${ENDCOLOR}"
				break 2
			fi
		# else...
		else
			echo -n "${GREEN}.${ENDCOLOR}";

			# check for leaks if $MEM_CHECK is set
			# terminate condition: leak or illegal memory read/write
			if [ $MEM_CHECK -ne 0 ]; then
				MEMCHECK=$(valgrind -q --leak-check=full --error-exitcode=1 ./push_swap $VAR);
				if [ "$?" != "0" ]; then
					echo
					echo "${RED}[MEMORY ERROR]${ENDCOLOR} - \`./push_swap \"$VAR\"\`" >&2
					exit
				fi
			fi
		fi

		# GET NUMBER OF OPERATIONS!!!
		COUNT=$((`./push_swap $VAR | wc -l`));
		if [ $MAX_OP -eq -1 ] || [ $MAX_OP -le $COUNT ]; then 
			MAX_OP=$COUNT
		fi
		TOTAL_OP=$(($TOTAL_OP + $COUNT))
	done
	echo
	echo "${GREEN}[SUCCESS]$N variables ${ENDCOLOR} average $(($TOTAL_OP / $ITER_COUNT)) max $MAX_OP"
done

# print arguments resulting WA
if [ $ERROR_COUNT -gt 0 ]; then
	echo
	echo "${RED}Wrong Answers${ENDCOLOR} $ERROR_COUNT errors occured..."
	echo $ERRORS
	exit 1
fi

echo "Test success!! $SEQ_START ~ $SEQ_END -> $ITER_COUNT iterations each. MEMCHECK=$MEM_CHECK"
exit 0
