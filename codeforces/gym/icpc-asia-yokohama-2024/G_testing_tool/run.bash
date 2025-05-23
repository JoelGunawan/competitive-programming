#!/bin/env bash

DIR=`dirname ${0}`

PROBNAME="Beyond the Former Explorer"
INPUTSPEC="The first line of the input file should contain an integer n.
After that, (2n + 1) lines must follow, each containing a string of (2n + 1) characters, representing an arrangement of the grid."

if (( $# < 1 ))
then
  echo "Local testing tool for ${PROBNAME}"
  echo ""
  echo "Usage:"
  echo "  $ bash ${0} [--silent] input-file exec-command ..."
  echo ""
  echo "By default, the outputs from an interactor and an author's program are written to the standard error."
  echo "Adding --silent option will suppress the output."
  echo ""
  echo "Sample input files are available under \"${DIR}\"."
  echo ""
  echo "Example commands for executing the tool:"
  echo "  $ bash ${0} ${DIR}/1.in ./main.out"
  echo "  $ bash ${0} ${DIR}/1.in runjava Main"
  echo "  $ bash ${0} ${DIR}/1.in runpython3 main.py"
  echo ""
  echo "${INPUTSPEC}"
  echo ""
  echo "Disclaimer: While the helper tool tries to yield the same"
  echo "results as the real judging system, this *is not* guaranteed and the result"
  echo "may differ if the tested program does not use the correct formatting or"
  echo "exhibits other incorrect behavior. It also does not apply the time and"
  echo "memory limits that are applied to submitted solutions."
  echo "Executing this tool with two or more processes simultaneously is not recommended."
  echo ""
  exit 1
fi

if [[ $1 == "--silent" ]]
then
  ENV_PARAM='-u INTERACTOR_VERBOSE USING_HELPER=1'
  shift
else
  ENV_PARAM='INTERACTOR_VERBOSE=1 USING_HELPER=1'
fi

INP=$1
shift

ANS=$INP

COMMAND=$@
FEEDBACK=`mktemp -d /tmp/__feedback_XXXXXXXXXX`
FIFO="${FEEDBACK}/__fifo"
LOG=/tmp/interactor.log
INTERACTOR=${DIR}/interactor.out

mkfifo ${FIFO}

cat <<EOF >> $LOG
{"time":"$(date +"%Y-%m-%d %H:%M:%S")", "state":"start", "dir": "${FEEDBACK}"}
EOF

$COMMAND < ${FIFO} | env ${ENV_PARAM} ${INTERACTOR} ${INP} ${ANS} ${FEEDBACK} > ${FIFO}
RET=$?

JUDGEMES_FILE=${FEEDBACK}/judgemessage.txt
JUDGEERR_FILE=${FEEDBACK}/judgeerror.txt

if [[ -f ${JUDGEMES_FILE} ]]
then
  JUDGEMES=`cat $JUDGEMES_FILE`
fi
if [[ -f ${JUDGEERR_FILE} ]]
then
  JUDGEERR=`cat $JUDGEERR_FILE`
fi

if [[ "$RET" = 42 ]]
then
  VERDICT="CORRECT"
elif [[ "$RET" = 43 ]]
then
  VERDICT="WRONG ANSWER"
else
  VERDICT="RUN ERROR (EXIT CODE = $RET)"
fi

echo "VERDICT: ${VERDICT}"

cat <<EOF >> $LOG
{"time":"$(date +"%Y-%m-%d %H:%M:%S")", "state":"end", "dir": "${FEEDBACK}", "exit_code":$RET, "judge_message":"${JUDGEMES}", "judge_error":"${JUDGEERR}", "verdict":"$VERDICT"}
EOF

rm -rf "${FEEDBACK}"

exit $RET
