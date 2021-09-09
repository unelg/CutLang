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

SHELL_ID=$$

echo $SCRIPT
echo $RUNS_PATH
echo $WORK_PATH

EVENTS=0
INIFILE=$RUNS_PATH/CLA.ini
VERBOSE=5000
STRT=0
PRLL=1
DEPS=" "
HLTLIST=" "
datafile=$1
datatype=$2
numcpu=1

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

    cat ${INIFILE} | grep -v '^#' | grep "region " > pippo
    cat ${INIFILE} | grep -v '^#' | grep "algo " >> pippo
    Nalgo=`cat pippo | wc -l`
    rm pippo
    
    # for histoList command
    if grep -q "histoList" "$INIFILE"; then
     cat ${INIFILE} | grep -v '^#' > ${INIFILE}.tmp
     INIFILE=${INIFILE}.tmp
    fi
    
    while grep -q "histoList" "$INIFILE"; do #while there is a histoList command in the .ini file, loop continues
     a=($(awk '/histoList/{ print NR; }' "$INIFILE")) #get the line numbers where histoList command written
     b=${a[0]} #always work on zeroth variable. Since they will disappear one-by-one, working on the zeroth variable won't cause any harm.
     histListName=$(awk -v b="$b" 'FNR == b {print $2}' ${INIFILE}) #get the name given by the user
#     echo "************", $histListName
     count=$(awk -v histListName="${histListName}" '$1 == histListName {print NR}' "$INIFILE" | wc -l) #how many times user prefers to fill same set of histos

     if [ $count -gt 1 ]; then
       countMinor=$(awk -v histListName="${histListName}" '$1 == histListName {print NR}' "$INIFILE" | wc -l) #get the same count again, but now it will be always modified
        c=$(awk -v histListName="${histListName}" '$2 == histListName {print NR}' "$INIFILE")
        d=${c[0]}
        let d++
        whereToInsert=$( awk -v histListName="${histListName}" '$1 == histListName {print NR;}' ${INIFILE}) #get line number to insert
        while grep -w -A1 "histoList ${histListName}" ${INIFILE} |  grep -q -w 'histo'; do
          counttmp=0
          for k in ${whereToInsert}; do
#            echo $k
            awk -v d="$d" -v e="${k}" 'NR==d{store=$0}1;NR==e{print store}' ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
            let f=k+1
            awk -v e="$f" -v counttmp=${counttmp} -F" " -vOFS=" " 'NR==e{$2=$2counttmp}1' ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
            let counttmp+=1
#            echo $counttmp
          done
          awk -v d="$d" 'NR==d{next}1' ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
        done
        grep -v -w ${histListName} ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
     fi
     
     c=$(awk -v histListName="${histListName}" '$2 == histListName {print NR}' "$INIFILE")
     let c++
     whereToInsert=$( awk -v histListName="${histListName}" '$1 == histListName {print NR;}' ${INIFILE}) #get line number to insert
     while grep -w -A1 "histoList ${histListName}" ${INIFILE} |  grep -q -w 'histo'; do
      awk -v c="$c" -v d="${whereToInsert}" 'NR==c{store=$0;next}1;NR==d{print store}' ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
     done
     grep -v -w ${histListName} ${INIFILE} > ${INIFILE}.tmp && cp ${INIFILE}.tmp ${INIFILE} && rm -f ${INIFILE}.tmp
    done

    # for select HLT command
    hltInFile=$(grep -E "select HLT" ${INIFILE} | sed 's/select HLT//g')
    hltList=""
    for i in $(echo $hltInFile | tr "||" " " | tr "\"" " " | tr "'" " ")
    do
      hltList+=$i,
    done
    HLTLIST=$hltList

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

if [ -n ${datafile+x} ] && [ ! -f "$datafile" ]; then
  tput setaf 1; echo "${datafile} does not exist."
  tput sgr0
fi


# for ialgo in `seq $Nalgo`; do
#  ../scripts/ini2txt.sh  BP_$ialgo
# done

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
  mkdir -p $WORK_PATH/temp_adl_$SHELL_ID
  cp ${INIFILE} $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl  # temporary adl to supress eff tables from parallel processes
  if [[ -n $(grep -i "SkipEffs" ${INIFILE}) ]]; then 
    sed -i '/SkipEffs/Id' $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl
  fi
  echo 'SkipEffs = 1' | cat - $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl | tee $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl
else
  if [ $Nalgo -gt 1 ]; then
  echo Analysis with Multiple Regions
  $WORK_PATH/scripts/separate_algos.sh ${INIFILE}
  else
  echo Single Analysis
  cp ${INIFILE} $PWD/BP_1-card.ini
  Nalgo=1
  fi
fi

if [ `echo $LD_LIBRARY_PATH | grep $WORK_PATH/CLA > /dev/null ; echo $?` -ne 0 ]; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORK_PATH/CLA/
fi


if ! [[ "${PRLL}" =~ ^[0-9]+$ ]] || [ ${PRLL} -gt $numcpu ] || [ ${PRLL} -lt 0 ]; then
  echo "Please write an integer between 1 and $((numcpu - 1 )) after -j or use 0 for optimum performance"
elif [ ${PRLL} -ne 1 ]; then
  if [ ${PRLL} -eq 0 ]; then # automatically divides jobs to numcpu-1
    PRLL=$((numcpu - 1 ))
    echo Using $((numcpu - 1 )) cores
  fi
  if [ $EVENTS -eq 0 ]; then # gets entries to divide events into intervals
    dt=$(grep "\"$datatype\"" $WORK_PATH/CLA/CLA.C | cut -d '{' -f 2 | head -c -9 | cut -c 2-)
    chn=$(grep -A2 "if ($dt)" $WORK_PATH/CLA/CLA.C | grep "TChain(" | cut -d '"' -f 2)
    TotalEvents="$(root -l -q ''$WORK_PATH'/analysis_core/getentries.cxx("'${datafile}'" ,"'${chn}'")')"
    EVENTS="$(echo $TotalEvents | awk '{print $NF}')"
    intrvl=$(( (EVENTS-STRT)/PRLL)) # workload division
    echo Total number of events: $EVENTS
  else
    intrvl=$(( EVENTS/PRLL)) # workload division
  fi
  echo "**********************************************************************************************"
  echo $WORK_PATH/CLA/CLA.exe $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -PLL ${PRLL} -HLT ${HLTLIST} ${DEPS}
  for ((i = 0 ; i < ${PRLL} ; i++)); do # temp folders created
      cp -a $WORK_PATH/runs/. $WORK_PATH/temp_runs_${SHELL_ID}_${i}
      rm -f $WORK_PATH/temp_runs_${SHELL_ID}_${i}/histoOut-BP_*.root
      echo $WORK_PATH/temp_runs_${SHELL_ID}_${i} copied from runs
  done
  multitask(){
    lp=$1
    _dataf=$(realpath $datafile)
    cd $WORK_PATH/temp_runs_${SHELL_ID}_${lp}
    if [ $lp -eq $((PRLL-1)) ]; then # calls CLA.sh from temp folders
      echo CLA $_dataf $datatype -i ${INIFILE} -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE
      ./CLA.sh $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE
    else
      echo CLA $_dataf $datatype -i ${INIFILE} -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE
      ./CLA.sh $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl)) -v $VERBOSE
    fi
  }
  if [ $? -eq 0 ]; then # multithreading
    for ((i = 0 ; i < ${PRLL} ; i++)); do
      multitask "$i" &
    done
    wait
  fi
  if [ $? -eq 0 ]; then
    rbase=`echo ${INIFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
    rm -f $PWD/histoOut-${rbase}.root
    allHistos=""
    for ((i = 0 ; i < ${PRLL} ; i++)); do
      allHistos+=$WORK_PATH/temp_runs_${SHELL_ID}_${i}/histoOut-tempor.root
      allHistos+=" "
    done
    echo "hadd -f $PWD/histoOut-${rbase}.root $allHistos ------- merging all root files"
    hadd -f $PWD/histoOut-${rbase}.root $allHistos # merging all root files
    wait
    # prints efficiencies of combined files
    if [ $? -eq 0 ]; then
      root -l -q \
      ''${WORK_PATH}'/analysis_core/FinalEff.C("'${PWD}'/histoOut-'${rbase}'.root", '$sh', '$se')'
      rm -r $WORK_PATH/temp*  # removes temp folders

      echo "hadd (merging all root files) finished successfully, now removing auxiliary files"
      rm -f $PWD/histoOut-BP_*.root
      rm -f $PWD/_head.ini $PWD/_algos.ini $PWD/_inifile
      rm -f $PWD/BP_*-card.ini 
      rm -f $PWD/out1 
      rm -f $PWD/algdeps.cmd
    fi
  fi

  echo end CLA_multicore

else

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

  echo end CLA single

fi

