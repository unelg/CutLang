#!/bin/bash

INIFILE=CLA.ini

if [ $# == 1 ]; then
 INIFILE=$1
fi

cat $INIFILE | grep -v '^ *#' > _inifile
#-------remove all lines starting with a #
INIFILE=_inifile

# replace all region keyword with algo
sed 's/region /algo /g'  $INIFILE > pippo
mv  pippo _inifile 

inihead=`cat ${INIFILE} | grep -n -m 1 algo | cut -f1 -d":"`
initot=`wc -l ${INIFILE} |  awk '{ print $1 }'` 

head -n $inihead ${INIFILE} | grep -v algo > _head.ini
tail -n $(( initot - $inihead +1 )) ${INIFILE} > _algos.ini
rm -rf out1

algo_list=`cat _algos.ini | grep -n algo | cut -f1 -d":"`

iregion=0
for an_algo in $algo_list ; do
 iregion=$(( iregion + 1 ))
 algo1p=$(( an_algo + 1  ))
 thisline=`head -n $an_algo _algos.ini| tail -n 1`
 nextline=`head -n $algo1p  _algos.ini| tail -n 1`
 depalgo=-1
 mainalgo=-1

### echo $an_algo  $thisline $nextline

 this_region_name=`echo $thisline | cut -f2 -d ' '`
 next_rline=`cat _algos.ini | grep -n -m $(( 1 + iregion )) algo | tail -1| cut -f1 -d":"`
 if [ $next_rline == $an_algo ]; then
   next_rline=`wc -l _algos.ini |  awk '{ print $1+1 }'`
 fi
 printf 'A region, ID:%3s named:%20s \t is defined in lines from %d to %d\n' "$((iregion -1 ))" "[$this_region_name]" "$an_algo" "$next_rline"

 if [[ $nextline != *"cmd "* ]] && [[ $nextline != *"select "* ]] && [[ $nextline != *"histo "* ]] && [[ $nextline != *"weight "* ]]; then
  echo "   this region depends on:"  $nextline
  cat $nextline > $this_region_name
  awk -v lstart=$an_algo -v lfinish=$next_rline  'NR > lstart+1 && NR < lfinish' _algos.ini >> $this_region_name 
  depalgo=$((iregion -1 ))
 else
  awk -v lstart=$an_algo -v lfinish=$next_rline  'NR > lstart && NR < lfinish' _algos.ini > $this_region_name 
  mainalgo=$((iregion -1 ))
 fi
 cat _head.ini > BP_${iregion}-card.ini
 echo $thisline >> BP_${iregion}-card.ini
 cat $this_region_name >> BP_${iregion}-card.ini
 
# echo  $mainalgo ":" $depalgo
 if [[ $mainalgo -gt -1 ]] && [[ $depalgo -eq -1 ]]; then
   echo -n ${mainalgo}":">> out1
 fi
 if [[ $mainalgo -eq -1 ]] && [[ $depalgo -gt -1 ]]; then
   echo -n  $depalgo",">> out1
 fi

done
echo >> out1
depregs=`cat out1 | grep ','| sed 's/.$//'`
if [ ${#depregs} -gt 0 ]; then
 echo "-P ${depregs}" >algdeps.cmd
fi

# CLEAN the region names
for an_algo in $algo_list ; do
 thisline=`head -n $an_algo _algos.ini| tail -n 1`
 this_region_name=`echo $thisline | cut -f2 -d ' '`
 rm -f $this_region_name
done
