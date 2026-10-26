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

#-------comment lines become empty lines (not removed), and the #@line markers of the CLA
#-------drivers are kept, so that each card can point back to the lines of the ADL file
LC_ALL=C awk '/^[ \t]*#@line / { print; next } /^[ \t]*#/ { print ""; next } { print }' $INIFILE > $PWD/_inifile
INIFILE=$PWD/_inifile

# replace all region keyword with algo
sed 's/region /algo /g'  $INIFILE > $PWD/pippo
mv  $PWD/pippo $PWD/_inifile

inihead=`cat ${INIFILE} | grep -n -m 1 algo | cut -f1 -d":"`
initot=`wc -l ${INIFILE} |  awk '{ print $1 }'`

# line i of _linemap is the line number in the ADL file of line i of _inifile
LC_ALL=C awk '/^#@line [0-9]+/ { print n; n = $2 - 1; next } { n++; print n }' $INIFILE > $PWD/_linemap
adlline() { sed -n "$(( inihead + $1 - 1 ))p" $PWD/_linemap; }   # ADL line of line $1 of _algos.ini

head -n $(( inihead - 1 )) ${INIFILE} > $PWD/_head.ini
tail -n $(( initot - $inihead +1 )) ${INIFILE} > $PWD/_algos.ini
rm -rf $PWD/out1

algo_list=`cat $PWD/_algos.ini | grep -n algo | cut -f1 -d":"`

iregion=0
for an_algo in $algo_list ; do
 iregion=$(( iregion + 1 ))
 algo1p=$(( an_algo + 1  ))
 thisline=`head -n $an_algo $PWD/_algos.ini| tail -n 1`
 # first non-empty line after the region header (empty lines and comments are skipped)
 depline=`awk -v s=$an_algo 'NR > s && NF { print NR; exit }' $PWD/_algos.ini`
 if [ -z "$depline" ]; then depline=$algo1p; fi
 nextline=`head -n $depline  $PWD/_algos.ini| tail -n 1`
 depalgo=-1
 mainalgo=-1

### echo $an_algo  $thisline $nextline

 this_region_name=`echo $thisline | cut -f2 -d ' '`
 next_rline=`cat $PWD/_algos.ini | grep -n -m $(( 1 + iregion )) algo | tail -1| cut -f1 -d":"`
 if [ $next_rline == $an_algo ]; then
   next_rline=`wc -l $PWD/_algos.ini |  awk '{ print $1+1 }'`
 fi
 printf 'A region, ID:%3s named:%20s \t is defined in lines from %d to %d\n' "$((iregion -1 ))" "[$this_region_name]" "$an_algo" "$next_rline"

 # a region depends on another one if its first line is just the name of an earlier region
 # (the lines of every region were written to a file with the name of the region)
 set -- $nextline
 if [ $depline -lt $next_rline ] && [ $# -eq 1 ] && [ -f "$1" ]; then
  echo "   this region depends on:"  $nextline
  cat $nextline > $this_region_name
  echo "#@line $(adlline $(( depline + 1 )))" >> $this_region_name
  awk -v lstart=$depline -v lfinish=$next_rline  'NR > lstart && NR < lfinish' $PWD/_algos.ini >> $this_region_name
  depalgo=$((iregion -1 ))
 else
  echo "#@line $(adlline $algo1p)" > $this_region_name
  awk -v lstart=$an_algo -v lfinish=$next_rline  'NR > lstart && NR < lfinish' $PWD/_algos.ini >> $this_region_name
  mainalgo=$((iregion -1 ))
 fi
 cat $PWD/_head.ini > $PWD/BP_${iregion}-card.ini
 echo "#@line $(adlline $an_algo)" >> $PWD/BP_${iregion}-card.ini
 echo $thisline >> $PWD/BP_${iregion}-card.ini
 cat $this_region_name >> $PWD/BP_${iregion}-card.ini
 
# echo  $mainalgo ":" $depalgo
 if [[ $mainalgo -gt -1 ]] && [[ $depalgo -eq -1 ]]; then
   echo -n "@"${mainalgo}":">> $PWD/out1
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
