#!/bin/bash
export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system

realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

_RUNS_PATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
_SCRIPT=`realpath -s $0`
SCRIPT=`realpath $0`            # /home/.../CutLang/runs/CLA.sh
RUNS_PATH=`dirname $SCRIPT`    # /home/.../CutLang/runs
WORK_PATH=`dirname $RUNS_PATH`  # /home/.../CutLang

echo $SCRIPT
echo $RUNS_PATH
echo $WORK_PATH

EVENTS=0
INIFILE=$RUNS_PATH/CLA.ini
VERBOSE=5000
STRT=0
DEPS=" "
HLTLIST=" "
datafile=$1
datatype=$2

if [ $# -lt 2 ]; then
 echo ERROR: not enough arguments
 echo $0  ROOTfile_name  ROOTfile_type [-h]
 cat $0 | grep '|-'|grep -v grep| cut -f1 -d')'
 echo "ROOT file type can be:"; grep "inptype ==" $WORK_PATH/CLA/CLA.C | cut -f3 -d'=' | cut -f1 -d')'
 exit 1
fi





POSITIONAL=()
while [[ $# -gt 2 ]]
do
key="$3"

case $key in
    -i|--inifile)
    INIFILE="$4"
    if [ ! -f "$INIFILE" ]; then
      echo "$INIFILE does NOT exist!"
      exit 1
    fi

    cat ${INIFILE} | grep -v '#' | grep "region " > pippo
    cat ${INIFILE} | grep -v '#' | grep "algo " >> pippo
    Nalgo=`cat pippo | wc -l`
    rm pippo
    
    # for HistoList command
    if grep -q "histoList" "$INIFILE"; then
     cp ${INIFILE} ${INIFILE}.tmp
     INIFILE=${INIFILE}.tmp
    fi
    
    while grep -q "histoList" "$INIFILE"; do #while there is a histoList command in the .ini file, loop continues
     a=($(awk '/histoList/{ print NR; }' "$INIFILE")) #get the line numbers where histoList command written
     b=${a[0]} #always work on zeroth variable. Since they will disappear one-by-one, working on the zeroth variable won't cause any harm.
     histListName=$(awk -v b="$b" 'FNR == b {print $2}' ${INIFILE})
     echo "************", $histListName
     c=$(awk -v histListName="${histListName}" '$2 == histListName {print NR}' "$INIFILE")
     let c++
     whereToInsert=$( awk -v histListName="${histListName}" '$1 == histListName {print NR;}' ${INIFILE}) #get line number to insert
     while grep -w -A1 "histoList ${histListName}" ${INIFILE} |  grep -q -w 'histo'; do
      awk -v c="$c" -v d="${whereToInsert}" 'NR==c{store=$0;next}1;NR==d{print store}' ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
     done
     sed "/${histListName}/d" ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
    done

    # for select HLT command
    hltInFile=$(grep -E "select HLT" ${INIFILE} | sed 's/select HLT//g')
    hltList=""
    for i in $(echo $hltInFile | tr "||" " " | tr "\"" " " | tr "'" " ")
    do
      hltList+=$i,
    done
    HLTLIST=$hltList
    
    if [ $Nalgo -gt 1 ]; then
     echo Analysis with Multiple Regions
     $WORK_PATH/scripts/separate_algos.sh ${INIFILE}
    else
     echo Single Analysis
     cp ${INIFILE} $PWD/BP_1-card.ini
     Nalgo=1
    fi
    shift # past argument
    shift # past value
    ;;
    -e|--events)
    EVENTS="$4"
    shift # past argument
    shift # past value
    ;;
    -s|--start)
    STRT="$4"
    shift # past argument
    shift # past value
    ;;
    -h|--help)
    echo command line arguments:
    cat $0 | grep '|-'|grep -v grep| cut -f1 -d')'
    echo "ROOT file type can be:"; grep "inptype ==" $WORK_PATH/CLA/CLA.C | cut -f3 -d'=' | cut -f1 -d')'
    exit 1
    ;;
    -d|--deps)
    if [ -f "algdeps.cmd" ]; then
     DEPS=`cat algdeps.cmd`
     rm -f algdeps.cmd
    fi
    shift # past argument
    ;;
    -v|--verbose)
    VERBOSE="$4"
    shift # past argument
    shift # past value
    ;;
    --default)
    DEFAULT=YES
    shift # past argument
    ;;
    *)    # unknown option
    POSITIONAL+=("$1") # save it in an array for later
    shift # past argument
    ;;
esac
done
set -- "${POSITIONAL[@]}" # restore positional parameters

if [ -n ${datafile+x} ] && [ ! -f "$datafile" ]; then
  tput setaf 1; echo "${datafile} does not exist."
  tput sgr0
fi


# for ialgo in `seq $Nalgo`; do
#  ../scripts/ini2txt.sh  BP_$ialgo
# done

if [ `echo $LD_LIBRARY_PATH | grep $WORK_PATH/CLA > /dev/null ; echo $?` -ne 0 ]; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORK_PATH/CLA/
fi

rm $PWD/histoOut-BP_*.root 2>/dev/null 
echo $WORK_PATH/CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -HLT ${HLTLIST} ${DEPS}
$WORK_PATH/CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -HLT ${HLTLIST} ${DEPS}
if [ $? -eq 0 ]; then
  echo "CutLang finished successfully, now adding histograms"
  rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
  if [ -f "$PWD/histoOut-${rbase}.root" ]; then
    rm -f  $PWD/histoOut-${rbase}.root
  fi
  hadd $PWD/histoOut-${rbase}.root $PWD/histoOut-BP_*.root
  #if histoList command is given, the ${INIFILE}.tmp is produced, and now it gets deleted.
  if grep -q "histoList" `echo ${INIFILE} | sed 's/.tmp//g'`; then
    rm -f ${INIFILE}
  fi
  if [ $? -eq 0 ]; then
   echo "hadd finished successfully, now removing auxiliary files"
   rm -f $PWD/histoOut-BP_*.root
   rm -f $PWD/_head.ini $PWD/_algos.ini $PWD/_inifile
   rm -f $PWD/BP_*-card.ini 
   rm -f $PWD/out1 
   rm -f $PWD/algdeps.cmd
  fi
fi


