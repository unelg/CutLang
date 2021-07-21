#!/bin/bash

realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}

_SCRIPTS_PATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
_SCRIPT=`realpath -s $0`
SCRIPT=`realpath $0`            # /home/.../CutLang/scripts/seperate_algos.sh
SCRIPTS_PATH=`dirname $SCRIPT`    # /home/.../CutLang/scripts
WORK_PATH=`dirname $SCRIPTS_PATH`  # /home/.../CutLang
RUNS_PATH=$WORK_PATH/runs  # /home/.../CutLang/runs

INIFILE=$RUNS_PATH/CLA.ini

if [ $# == 1 ]; then
 INIFILE=$1
fi

cat $INIFILE | grep -v '^ *#' > $PWD/_inifile
#-------remove all lines starting with a #
INIFILE=$PWD/_inifile

# replace all region keyword with algo
sed 's/region /algo /g'  $INIFILE > $PWD/pippo
mv  $PWD/pippo $PWD/_inifile 

inihead=`cat ${INIFILE} | grep -n -m 1 algo | cut -f1 -d":"`
initot=`wc -l ${INIFILE} |  awk '{ print $1 }'` 

head -n $inihead ${INIFILE} | grep -v algo > $PWD/_head.ini
tail -n $(( initot - $inihead +1 )) ${INIFILE} > $PWD/_algos.ini
rm -rf $PWD/out1

algo_list=`cat $PWD/_algos.ini | grep -n algo | cut -f1 -d":"`

iregion=0
for an_algo in $algo_list ; do
 iregion=$(( iregion + 1 ))
 algo1p=$(( an_algo + 1  ))
 thisline=`head -n $an_algo $PWD/_algos.ini| tail -n 1`
 nextline=`head -n $algo1p  $PWD/_algos.ini| tail -n 1`
 depalgo=-1
 mainalgo=-1

### echo $an_algo  $thisline $nextline

 this_region_name=`echo $thisline | cut -f2 -d ' '`
 next_rline=`cat $PWD/_algos.ini | grep -n -m $(( 1 + iregion )) algo | tail -1| cut -f1 -d":"`
 if [ $next_rline == $an_algo ]; then
   next_rline=`wc -l $PWD/_algos.ini |  awk '{ print $1+1 }'`
 fi
 printf 'A region, ID:%3s named:%20s \t is defined in lines from %d to %d\n' "$((iregion -1 ))" "[$this_region_name]" "$an_algo" "$next_rline"

 if [[ $nextline != *"cmd "* ]] && [[ $nextline != *"select "* ]] && [[ $nextline != *"histo "* ]] && [[ $nextline != *"weight "* ]]; then
  echo "   this region depends on:"  $nextline
  cat $nextline > $this_region_name
  awk -v lstart=$an_algo -v lfinish=$next_rline  'NR > lstart+1 && NR < lfinish' $PWD/_algos.ini >> $this_region_name 
  depalgo=$((iregion -1 ))
 else
  awk -v lstart=$an_algo -v lfinish=$next_rline  'NR > lstart && NR < lfinish' $PWD/_algos.ini > $this_region_name 
  mainalgo=$((iregion -1 ))
 fi
 cat $PWD/_head.ini > $PWD/BP_${iregion}-card.ini
 echo $thisline >> $PWD/BP_${iregion}-card.ini
 cat $this_region_name >> $PWD/BP_${iregion}-card.ini
 
# echo  $mainalgo ":" $depalgo
 if [[ $mainalgo -gt -1 ]] && [[ $depalgo -eq -1 ]]; then
   echo -n ${mainalgo}":">> $PWD/out1
 fi
 if [[ $mainalgo -eq -1 ]] && [[ $depalgo -gt -1 ]]; then
   echo -n  $depalgo",">> $PWD/out1
 fi

done
echo >> $PWD/out1
depregs=`cat $PWD/out1 | grep ','| sed 's/.$//'`
if [ ${#depregs} -gt 0 ]; then
 echo "-P ${depregs}" >$PWD/algdeps.cmd
fi

# CLEAN the region names
for an_algo in $algo_list ; do
 thisline=`head -n $an_algo _algos.ini| tail -n 1`
 this_region_name=`echo $thisline | cut -f2 -d ' '`
 rm -f $this_region_name
done
