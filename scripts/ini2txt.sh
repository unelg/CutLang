#!/bin/bash

inpf=${1}-card.ini
outf=${1}-card.txt

sep="    "

cat $inpf | grep -v "algo " | grep -v "cmd "| grep -v "obj "| grep -v "__"| grep -v "def " | grep -v "histo " > $outf
echo >> $outf
cat $inpf | grep "^obj " | awk 'BEGIN{i=1} { print "obj", sep, substr($0, index($0,$2)) }' >> $outf
echo >> $outf
cat $inpf | grep "^def " | awk 'BEGIN{i=1} { print "def", sep, substr($0, index($0,$2)) }' >> $outf
echo >> $outf

# start algo
cat  $inpf | grep "^algo " >> $outf
cat $inpf |grep --max-count 999999 --after-context 999999  'ALL ' | grep "^cmd " | awk 'BEGIN{i=1} { print "cmd", sep, substr($0, index($0,$2)) }' >> $outf
echo >> $outf
echo >> $outf

ocnum=`grep -o obj  $inpf | wc -l|awk '{print $1}' `
cat $inpf| grep --max-count 1 --before-context 999999  'ALL '| grep -v 'ALL ' | grep -v "^#"| awk  -F'["]' 'BEGIN{i=1} /obj/ {flag++; i=1; next};  { if (flag>=1) { 
if ($1 ~ /^cmd/) 
   print "cmd" flag "-", sep, "\" " substr($2, index($1,$5)), "\" "
}
}' >> $outf

# we define histos directly in .ini now
#outf=${1}-histos.txt

# no need for FillHistos either
#ocnum=`grep -o FillHistos  $inpf | wc -l|awk '{print $1}' `

#grep "histo " $inpf| awk "/FillHistos/ {flag++; next}; {print}; " | awk 'BEGIN{i=1} { print "histo" i++,"=", substr($0, index($0,$2)) }' 
#grep "histo " $inpf| awk 'BEGIN{i=1} /FillHistos/ {flag++; next}; { print "histo" i++,"=", substr($0, index($0,$2)) }' 


#cat $inpf| grep -v "^#"| awk  -F'[,]' 'BEGIN{i=1} /FillHistos/ {flag++; next};  { if (flag>=1) { 
#if ($5 != "" && $1 ~ /histo/)
#   print "histo" ,"    ", $1 "," $2 "," $3 "," $4 "," $5,"," flag "," substr($0, index($0,$6))
#else if ($1 ~ /Basics/ ) print "histo" ,  "histo    \"Basics,",flag,"," ,flag,"\""
#}
#}' > pippo.tmp
#cat pippo.tmp | awk '{print $1,$2,substr($0, index($0,$4)) }' > $outf
#rm -f  pippo.tmp

# copy the histos lines directly
cat $inpf | grep "^histo" | awk '{print $0}' >> $outf
