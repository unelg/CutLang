#!/bin/bash
export PATH=$PATH:$ROOTSYS/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:.:/usr/lib:/usr/lib/system:/usr/local/lib

realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

_RUNS_PATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
_SCRIPT=`realpath -s $0`
SCRIPT=`realpath $0`            # /home/.../CutLang/runs/CLA.sh
RUNS_PATH=`dirname $SCRIPT`    # /home/.../CutLang/runs
WORK_PATH=`dirname $RUNS_PATH`  # /home/.../CutLang
tempdir=$(mktemp -d /tmp/CLAdir.XXXXXX)
execmd=$WORK_PATH/CLA/CLA.exe

SHELL_ID=$$

##echo $SCRIPT
##echo $RUNS_PATH
##echo $WORK_PATH

EVENTS=0
ADLFILE=$RUNS_PATH/CLA.ini
VERBOSE=5000
SYST=0
EXARGS=" "
STRT=0
PRLL=1
DEPS="w"
DEPP=" "
HLTLIST=" "
datadir=$(realpath $1)
dataurl=$1
datatype=$2
numcpu=1
addRootName=0

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
    ADLFILE="$4"
    if [ ! -f "$ADLFILE" ]; then
      echo "$ADLFILE does NOT exist!"
      exit 1
    fi
    origdir=$PWD
    # error messages of CLA.exe point to this file (a parallel sub-run keeps the user's file)
    if [ -z "$CLA_ADLFILE" ]; then
      case "$ADLFILE" in
        /*) CLA_ADLFILE=$ADLFILE ;;
        *)  CLA_ADLFILE=$origdir/$ADLFILE ;;
      esac
      export CLA_ADLFILE
    fi
    pushd . > /dev/null
    cp $ADLFILE $tempdir;
    cd $tempdir;
    ADLFILE=`echo $ADLFILE | rev | cut -d'/' -f 1|rev`
    INIFILE=_lastrun.adl
# convert the \ signs back to same line; an empty line is added for each joined line
# so that the line numbers stay the same as in the ADL file
    LC_ALL=C awk '{ if (sub(/\\$/, "")) { buf = buf $0; n++; next }
           print buf $0; for (i = 0; i < n; i++) print ""; buf = ""; n = 0 }
         END { if (n) { print buf; for (i = 1; i < n; i++) print "" } }' ${ADLFILE} > ${INIFILE}
    cat ${INIFILE} | grep -v '^#' | grep "region " > pippo
    cat ${INIFILE} | grep -v '^#' | grep "algo " >> pippo
    Nalgo=`cat pippo | wc -l`
    rm pippo
    
    # for select HLT command
    hltInFile=$(grep -E "select HLT" ${INIFILE} | sed 's/select HLT//g')
    hltList=""
    for i in $(echo $hltInFile | tr "||" " " | tr "\"" " " | tr "'" " ")
    do
      hltList+=$i,
    done
    if [ ${#hltlist} -gt 1 ]; then 
     HLTLIST=" -HLT " $hltList
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
    -n|--rootname)
    addRootName=1
    shift # past value
    ;;
    -h|--help)
    echo command line arguments:
    cat $0 | grep '|-'|grep -v grep| cut -f1 -d')'
    echo "ROOT file type can be:"; grep "inptype ==" $WORK_PATH/CLA/CLA.C | cut -f3 -d'=' | cut -f1 -d')'
    exit 1
    ;;
    -d|--deps)
# speedup
    echo "Running " $DEPS " dependencies"
    DEPS="XXX"
    DEPP=" -d "
    shift # past argument
    ;;
    -S|--systematics)
    echo "******************" Systematics Run "******************"
    SYST=1
    shift # past argument
    ;;
    -r|--runsummary)
# Run Summary
    echo "~~~~~~~~~~~~~" Run Summary "~~~~~~~~~~~~"
    EXARG="${EXARG} -RS "
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

inputfilelist="${datadir}"

if [ -d ${datadir} ]; then
   echo "====> working with a directory !"
   addRootName=1
   inputfilelist=`ls ${datadir}/*.root`
   echo $inputfilelist
   echo '-----------------------------'
else if [ -n ${datadir+x} ] && [ ! -f "$datadir" ]; then
  	tput setaf 1; echo "${datadir} does not exist."
  	tput sgr0
     fi
fi

if [[ $datadir == *"://"* ]]; then
  inputfilelist=$dataurl
fi

if [ $ADLFILE == "$RUNS_PATH/CLA.ini" ]; then
  Nalgo=1
  INIFILE=$ADLFILE
  echo "ATTENTION ! XXXXXXXXX running with default ADL file CLA.ini XXXXXXXX"
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
  echo Number of available cpus : $numcpu
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
  # temporary adl to supress eff tables from parallel processes: an existing SkipEffs line is
  # emptied (not deleted) and "#@line 1" after the added line keeps the ADL line numbers
  LC_ALL=C awk 'tolower($0) ~ /skipeffs/ { print ""; next } { print }' ${INIFILE} > _tempor.adl
#  echo 'SkipEffs = 1' | cat - $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl | tee $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl
  printf 'SkipEffs = 1\n#@line 1\n' | cat - _tempor.adl > $WORK_PATH/temp_adl_$SHELL_ID/tempor.adl; rm -f _tempor.adl
else
  if [ $Nalgo -gt 1 ]; then
  echo Analysis with Multiple Regions $tempdir
  $WORK_PATH/scripts/separate_algos.sh ${INIFILE}
   if [ $DEPS == "XXX" ]; then
    
    if [ -f "algdeps.cmd" ]; then
     DEPS=`cat algdeps.cmd`
     cat algdeps.cmd
     ## echo "******************" $DEPS "***"
     rm -f algdeps.cmd
    fi
   fi

  else
   echo Single Analysis $tempdir
   cp ${INIFILE} $PWD/BP_1-card.ini
   Nalgo=1
  fi
fi

if [ `echo $LD_LIBRARY_PATH | grep $WORK_PATH/CLA > /dev/null ; echo $?` -ne 0 ]; then
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WORK_PATH/CLA/
fi

for bpfile in `ls -1 BP_*-card.ini`; do
#   echo "AAAAAAAAAAAAAAAAAAAAAAAAA" $abpfile
    HISTOLISTVAR=0
    # for histoList command
    if grep -q "histoList" "$bpfile"; then
     # comments become empty lines and #@line markers are kept, so that line numbers before
     # the histoList expansion stay correct (lines after an expanded histoList can shift)
     LC_ALL=C awk '/^#@line / { print; next } /^#/ { print ""; next } { print }' ${bpfile} > ${bpfile}.tmp
     abpfile=${bpfile}.tmp
     HISTOLISTVAR=1
    fi
    
    if [ $HISTOLISTVAR -eq 0 ]; then
     continue
    fi


    while grep -q "histoList" "$abpfile"; do #while there is a histoList command in the .ini file, loop continues
     a=($(awk '/histoList/{ print NR; }' "$abpfile")) #get the line numbers where histoList command written
     b=${a[0]} #always work on zeroth variable. Since they will disappear one-by-one, working on the zeroth variable won't cause any harm.
     histListName=$(awk -v b="$b" 'FNR == b {print $2}' ${abpfile}) #get the name given by the user
#    echo "************", $histListName
     count=$(awk -v histListName="${histListName}" '$1 == histListName {print NR}' "$abpfile" | wc -l) #how many times user prefers to fill same set of histos

     if [ $count -gt 1 ]; then
       countMinor=$(awk -v histListName="${histListName}" '$1 == histListName {print NR}' "$abpfile" | wc -l) #get the same count again, but now it will be always modified
        c=$(awk -v histListName="${histListName}" '$2 == histListName {print NR}' "$abpfile")
        d=${c[0]}
        let d++
        whereToInsert=$( awk -v histListName="${histListName}" '$1 == histListName {print NR;}' ${abpfile}) #get line number to insert
        while grep -w -A1 "histoList ${histListName}" ${abpfile} |  grep -q -w 'histo'; do
          counttmp=0
          for k in ${whereToInsert}; do
#            echo $k
            awk -v d="$d" -v e="${k}" 'NR==d{store=$0}1;NR==e{print store}' ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
            let f=k+1
            awk -v e="$f" -v counttmp=${counttmp} -F" " -vOFS=" " 'NR==e{$2=$2counttmp}1' ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
            let counttmp+=1
#           echo $counttmp
          done
          awk -v d="$d" 'NR==d{next}1' ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
        done
        grep -v -w ${histListName} ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
     fi
     
     c=$(awk -v histListName="${histListName}" '$2 == histListName {print NR}' "$abpfile")
     let c++
     whereToInsert=$( awk -v histListName="${histListName}" '$1 == histListName {print NR;}' ${abpfile}) #get line number to insert
     while grep -w -A1 "histoList ${histListName}" ${abpfile} |  grep -q -w 'histo'; do
      awk -v c="$c" -v d="${whereToInsert}" 'NR==c{store=$0;next}1;NR==d{print store}' ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
     done
     grep -v -w ${histListName} ${abpfile} > ${abpfile}.tmp && cp ${abpfile}.tmp ${abpfile} && rm -f ${abpfile}.tmp
    done
    echo 'finished................... for ' ${bpfile}
    mv ${abpfile} ${bpfile}
done

######### finished HistoList
clastatus=0   # exit code of this script: not 0 if CutLang stopped (for example on an ADL error)
for datafile in $inputfilelist; do

if ! [[ "${PRLL}" =~ ^[0-9]+$ ]] || [ ${PRLL} -gt $numcpu ] || [ ${PRLL} -lt 0 ]; then
  echo "Please write an integer between 1 and $((numcpu - 1 )) after -j or use 0 to use all cores"
elif [ ${PRLL} -ne 1 ]; then
  if [ ${PRLL} -eq 0 ]; then # automatically divides jobs to numcpu-1
    PRLL=$((numcpu - 1 ))
    echo Using $((numcpu - 1 )) cores
  fi
  if [ $EVENTS -eq 0 ]; then # gets entries to divide events into intervals
#    dt=$(grep "\"$datatype\"" $WORK_PATH/CLA/CLA.C | cut -d '{' -f 2 | head -c -9 | cut -c 2-)
    dt=$(grep "\"$datatype\"" $WORK_PATH/CLA/CLA.C | cut -d '{' -f2 |cut -f1 -d'=' )
    chn=`grep -A2  $dt  $WORK_PATH/CLA/CLA.C | grep leafname | cut -d '"' -f 2`
    echo $datatype data: $dt tree: ${chn}
    TotalEvents="$(root -l -q ''$WORK_PATH'/analysis_core/getentries.cxx("'${datafile}'" ,"'${chn}'")')"
    EVENTS="$(echo $TotalEvents | awk '{print $NF}')"
    intrvl=$(( (EVENTS-STRT)/PRLL)) # workload division
    echo Total number of events: $EVENTS
  else
    intrvl=$(( EVENTS/PRLL)) # workload division
  fi
# echo "**********************************************************************************************"
  echo $execmd $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -S ${SYST} -PLL ${PRLL} ${HLTLIST} ${DEPS}
  for ((i = 0 ; i < ${PRLL} ; i++)); do # temp folders created
      mkdir $WORK_PATH/temp_runs_${SHELL_ID}_${i}
      cp -a $WORK_PATH/runs/*.sh $WORK_PATH/temp_runs_${SHELL_ID}_${i}
      rm -f $WORK_PATH/temp_runs_${SHELL_ID}_${i}/histoOut-BP_*.root
#     echo $WORK_PATH/temp_runs_${SHELL_ID}_${i} copied from runs
  done

####################################
  multitask(){ #####################
####################################
    lp=$1
    if [[ $datafile == *"://"* ]]; then
      _dataf=$datafile
    else
      _dataf=$(realpath $datafile)
    fi

    cd $WORK_PATH/temp_runs_${SHELL_ID}_${lp}
    if [ $lp -eq $((PRLL-1)) ]; then # calls CLA.sh from temp folders
      echo CLA $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE $DEPP
      ./CLA.sh $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE $DEPP 2>../temp_adl_$SHELL_ID/err_${lp}.txt > ../temp_adl_$SHELL_ID/out_${lp}.txt
    else
      echo CLA $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl+EVENTS%PRLL)) -v $VERBOSE $DEPP
      ./CLA.sh $_dataf $datatype -i ../temp_adl_$SHELL_ID/tempor.adl -s $((STRT+lp*intrvl)) -e $((intrvl)) -v $VERBOSE  $DEPP 2>../temp_adl_$SHELL_ID/err_${lp}.txt > ../temp_adl_$SHELL_ID/out_${lp}.txt
    fi
  }
#####################################

  prc=0
  pids=()
  for ((i = 0 ; i < ${PRLL} ; i++)); do # multithreading
    multitask "$i" &
    pids+=($!)
  done
  for p in "${pids[@]}"; do
    wait $p || prc=1
  done
  if [ $prc -ne 0 ]; then
    # every process parses the same ADL, so the messages of the first one are enough
    cat $WORK_PATH/temp_adl_$SHELL_ID/err_0.txt >&2
    rm -rf $WORK_PATH/temp_runs_${SHELL_ID}_* $WORK_PATH/temp_adl_$SHELL_ID  # temp folders of this run
    clastatus=99
  else
    rbase=`echo ${ADLFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
    rm -f $PWD/histoOut-${rbase}.root
    allHistos=""
    for ((i = 0 ; i < ${PRLL} ; i++)); do
      allHistos+=$WORK_PATH/temp_runs_${SHELL_ID}_${i}/histoOut-tempor.root
      allHistos+=" "
    done
#   echo "hadd -f $PWD/histoOut-${rbase}.root $allHistos ------- merging all root files"
    echo "----> merging all root files"
    hadd -f $PWD/histoOut-${rbase}.root $allHistos >> /dev/null # merging all root files
    wait
    # prints efficiencies of combined files
    if [ $? -eq 0 ]; then
      root -l -b -q \
      ''${WORK_PATH}'/analysis_core/FinalEff.C("'${PWD}'/histoOut-'${rbase}'.root", '$sh', '$se')'
      rm -r $WORK_PATH/temp*  # removes temp folders

      echo "hadd (merging all root files) finished successfully, now removing auxiliary files"
      rm -f $PWD/histoOut-BP_*.root
      rm -f $PWD/_head.ini $PWD/_algos.ini $PWD/_inifile
      rm -f $PWD/BP_*-card.ini 
      rm -f $PWD/out1
      rm -f $PWD/algdeps.cmd
    fi
    if [ $addRootName -eq 0 ]; then
       outfilename=histoOut-${rbase}.root
    else
       outfilename=histoOut-${rbase}-${database}.root
    fi
    echo "end CLA_multicore. Output file:  " ${outfilename}
    mv histoOut-${rbase}.root ${origdir}/$outfilename
  fi
else
########################################## SINGLE CORE
  rm $PWD/histoOut-BP_*.root 2>/dev/null 
  echo $execmd $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -S ${SYST} ${HLTLIST} ${EXARG} ${DEPS} 
  $execmd $datafile -inp $datatype -BP $Nalgo -EVT $EVENTS -V ${VERBOSE} -ST $STRT -S ${SYST} ${HLTLIST} ${EXARG} ${DEPS}
  rc=$?
  database=`echo ${datafile} | rev | cut -d'/' -f 1 | cut -f2- -d'.'|rev`
  if [ $rc -eq 0 ]; then
    rbase=`echo ${ADLFILE} | rev | cut -d'/' -f 1 | rev|cut -f1 -d'.'`
    if [ -f "$PWD/histoOut-${rbase}.root" ]; then
      rm -f  $PWD/histoOut-${rbase}.root
    fi
    hadd $PWD/histoOut-${rbase}.root $PWD/histoOut-BP_*.root >> /dev/null
    #if histoList command is given, the ${INIFILE}.tmp is produced, and now it gets deleted.
    if grep -q "histoList" `echo ${INIFILE} | sed 's/.tmp//g'`; then
      rm -f ${INIFILE}
    fi
    if [ $? -ne 0 ]; then
     echo "hadd failed. Check auxiliary files in $tempdir ."
    fi
    if [ $addRootName -eq 0 ]; then
       outfilename=histoOut-${rbase}.root
    else
       outfilename=histoOut-${rbase}-${database}.root
    fi
    echo "end CLA single. Output file: " $outfilename
    mv histoOut-${rbase}.root ${origdir}/$outfilename
  else
    clastatus=$rc   # CLA.exe has printed the reason; no output file is written
  fi

fi
done
popd > /dev/null
#rm -r "$tempdir"
exit $clastatus
