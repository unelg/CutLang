#!/bin/bash
export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system
EVENTS=0
INIFILE=CLA.ini
VERBOSE=5000
STRT=0
PRLL=1
datafile=$1
datatype=$2
numcpu=1

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
    -v|--verbose)
    VERBOSE="$4"
    shift # past argument
    shift # past value
    ;;
    -j|--parallel)
    PRLL="$4"
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

#echo INIFILE  = "${INIFILE}"
#echo EVENTS   = "${EVENTS}"
#echo VERBOSE  = "${VERBOSE}"


cat ${INIFILE} | grep -v '#' | grep "region " > pippo
cat ${INIFILE} | grep -v '#' | grep "algo " >> pippo
Nalgo=`cat pippo | wc -l`
rm pippo

# number of logical processors is determined
if [ ${PRLL} -ne 1 ]; then
  OS="`uname`"
  case $OS in
    'Linux')
      numcpu=$(nproc)
      ;;
    'FreeBSD')
      numcpu=$(sysctl -n hw.ncpu)
      ;;
    'Windows')
      numcpu=$(echo %NumberOfCores%)
      ;;
    'Darwin') 
      numcpu=$(sysctl -n hw.ncpu)
      ;;
     *) 
      echo Unknown system, use CutLang with only 1 cpu
      ;;
  esac
  # echo Number of available cpus : $numcpu
fi

if [ ${PRLL} -ne 1 ]; then
  # taking skip histos and skip efficiencies values for final eff table
  sh=$(cat ${INIFILE} | grep -v "#" | grep -i "SkipHistos" | sed 's/[^0-9]//g')
  se=$(cat ${INIFILE} | grep -v "#" | grep -i "SkipEffs" | sed 's/[^0-9]//g')
  if [ -z "${sh}" ]; then
    sh=0
  fi
  if [ -z "${se}" ]; then
    se=0
  fi
  cp ${INIFILE} tempor.adl  # temporary adl to supress eff tables from parallel processes
  if [[ -n $(grep -i "SkipEffs" ${INIFILE}) ]]; then 
    sed -i '/SkipEffs/Id' ./tempor.adl
  fi
  ex -sc '1i|SkipEffs = 1' -cx tempor.adl
else
  if [ $Nalgo -gt 1 ]; then
    echo Analysis with Multiple Regions
    ../scripts/separate_algos.sh ${INIFILE}
  else
    echo Simple Analysis
    cp ${INIFILE} BP_1-card.ini
    Nalgo=1
  fi
  for ialgo in `seq $Nalgo`; do
   ../scripts/ini2txt.sh  BP_$ialgo
  done
fi

if [ `echo $LD_LIBRARY_PATH | grep CLA > /dev/null ; echo $?` -ne 0 ]; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../CLA/
fi

if ! [[ "${PRLL}" =~ ^[0-9]+$ ]] || [ ${PRLL} -gt $numcpu ] || [ ${PRLL} -lt 0 ]; then
  echo "Please write an integer between 1 and $((numcpu - 1 )) after -j or use 0 for optimum performance"
elif [ ${PRLL} -ne 1 ]; then
  if [ ${PRLL} -eq 0 ]; then # automatically divides jobs to numcpu-1
    PRLL=$((numcpu - 1 ))
    echo Using $((numcpu - 1 )) cores
  fi
  if [ $EVENTS -eq 0 ]; then # gets entries to divide events into intervals
    dt=$(grep "\"$datatype\"" ../CLA/CLA.C | cut -d '{' -f 2 | head -c -9 | cut -c 2-)
    chn=$(grep -A2 "if ($dt)" ../CLA/CLA.C | grep "TChain(" | cut -d '"' -f 2)
    TotalEvents="$(root -l -q '../analysis_core/getentries.cxx("'${datafile}'" ,"'${chn}'")')"
    EVENTS="$(echo $TotalEvents | awk '{print $NF}')"
    # echo Total number of events: $EVENTS
  fi
  echo "**********************************************************************************************"
  echo ../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -PLL ${PRLL}
  for ((i = 0 ; i < ${PRLL} ; i++)); do # temp folders created
      cp -a ../runs/. ../temp_runs${i}
      rm -f ../temp_runs${i}/histoOut-BP_*.root
      echo temp_runs${i} copied from runs
  done
  multitask(){
    lp=$1
    cd ../temp_runs${lp}
    if [ $lp -eq $((PRLL-1)) ]; then # calls CLA.sh from temp folders
      echo ./CLA.sh $datafile $datatype -i ${INIFILE} -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE
      ./CLA_multicore.sh $datafile $datatype -i tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE
    else
      echo ./CLA.sh $datafile $datatype -i ${INIFILE} -s $((STRT+lp*intrvl)) -e $((intrvl)) -v $VERBOSE
      ./CLA_multicore.sh $datafile $datatype -i tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl)) -v $VERBOSE
    fi
  }
  intrvl=$(( (EVENTS-STRT)/PRLL)) # workload division
  if [ $? -eq 0 ]; then # multithreading
    for ((i = 0 ; i < ${PRLL} ; i++)); do
      multitask "$i" &
    done
    wait
  fi
  if [ $? -eq 0 ]; then
    rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
    rm -f ../runs/histoOut-${rbase}.root
    for ((i = 0 ; i < ${PRLL} ; i++)); do
      hadd -a ../runs/histoOut-${rbase}.root \
      ../temp_runs${i}/histoOut-tempor.root # merging all root files
    done
    wait
    # prints efficiencies of combined files
    if [ $? -eq 0 ]; then
      root -l -q \
      '../analysis_core/FinalEff.C("../runs/histoOut-'${rbase}'.root", '$sh', '$se')'
      rm -r ../temp*  # removes temp folders
      rm -f ../runs/tempor.adl # removes temporary adl
    fi
  fi

else
  rm -f histoOut-BP_*.root
  echo ../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT
  ../CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT
  if [ $? -eq 0 ]; then
    rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev | cut -f1 -d'.'`
    rm -f histoOut-${rbase}.root
    if [[ -z $(pwd | grep "temp_runs") ]]; then
      hadd histoOut-${rbase}.root histoOut-BP_*.root
    else
      hadd histoOut-${rbase}.root histoOut-BP_*.root > /dev/null # supress output of parallel processes
    fi
  fi
fi
