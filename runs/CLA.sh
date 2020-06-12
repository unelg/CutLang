#!/bin/bash
export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system
EVENTS=0
INIFILE=CLA.ini
VERBOSE=5000
STRT=0
DEPS=" "
datafile=$1
datatype=$2

if [ $# -lt 2 ]; then
 echo ERROR: not enough arguments
 echo $0  ROOTfile_name  ROOTfile_type [-h]
 cat $0 | grep '|-'|grep -v grep| cut -f1 -d')'
 echo "ROOT file type can be:"; grep "inptype ==" ../CLA/CLA.C | cut -f3 -d'=' | cut -f1 -d')'
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
     ../scripts/separate_algos.sh ${INIFILE}
    else
     echo Single Analysis
     cp ${INIFILE} BP_1-card.ini
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
    echo "ROOT file type can be:"; grep "inptype ==" ../CLA/CLA.C | cut -f3 -d'=' | cut -f1 -d')'
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

if [ `echo $LD_LIBRARY_PATH | grep CLA > /dev/null ; echo $?` -ne 0 ]; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../CLA/
fi

rm histoOut-BP_*.root 2>/dev/null 
echo ../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT ${DEPS}
../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT ${DEPS}
if [ $? -eq 0 ]; then
  echo "CutLang finished successfully, now adding histograms"
  rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
  if [ -f "histoOut-${rbase}.root" ]; then
    rm -f  histoOut-${rbase}.root
  fi
  hadd histoOut-${rbase}.root histoOut-BP_*.root
  if [ $? -eq 120 ]; then
   echo "hadd finished successfully, now removing auxiliary files"
   rm -f histoOut-BP_*.root
   rm -f _head.ini _algos.ini _inifile
   rm -f BP_*-card.ini 
  fi
fi


