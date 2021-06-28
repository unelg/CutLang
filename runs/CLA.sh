#!/bin/bash
export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system

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
echo $WORK_PATH/CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT ${DEPS}
$WORK_PATH/CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT ${DEPS}
if [ $? -eq 0 ]; then
  echo "CutLang finished successfully, now adding histograms"
  rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
  if [ -f "$PWD/histoOut-${rbase}.root" ]; then
    rm -f  $PWD/histoOut-${rbase}.root
  fi
  hadd $PWD/histoOut-${rbase}.root $PWD/histoOut-BP_*.root
  if [ $? -eq 0 ]; then
   echo "hadd finished successfully, now removing auxiliary files"
   rm -f $PWD/histoOut-BP_*.root
   rm -f $PWD/_head.ini $PWD/_algos.ini $PWD/_inifile
   rm -f $PWD/BP_*-card.ini 
   rm -f $PWD/out1 
   rm -f $PWD/algdeps.cmd 
  fi
fi


