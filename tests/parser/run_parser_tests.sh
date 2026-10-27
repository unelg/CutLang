#!/bin/bash
# CutLang parser tests: grammar conflict counts, plus every case in cases.txt.
# Usage:   tests/parser/run_parser_tests.sh [output directory]
# Input:   tests/data/mc_361106.Zee.2lep.2000evt.root (ATLASODR2); INPUT=<file or URL> FORMAT=<format> to change.
# Exit:    0 if everything passes, 1 otherwise. Outputs stay in the output directory (default
#          tests/parser/out_<date>), one subdirectory per case with out.txt and err.txt.

HERE=$(cd "$(dirname "$0")" && pwd)
CL=$(cd "$HERE/../.." && pwd)
IN=${INPUT:-$CL/tests/data/mc_361106.Zee.2lep.2000evt.root}
FMT=${FORMAT:-ATLASODR2}
EVTS=20
OUT=${1:-$HERE/out_$(date +%Y%m%d_%H%M%S)}
# CLA.sh adds CutLang/CLA to the library path itself, CLA.py does not (needed on Linux)
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH:+$LD_LIBRARY_PATH:}$CL/CLA

# expected grammar conflicts (see the notes on the remaining conflicts); update together with parse.y
EXPECT_SR=23
EXPECT_RR=25

# GNU timeout on Linux, perl alarm on macOS
run_limited() {
  if command -v timeout > /dev/null 2>&1; then timeout -k 10 120 "$@"; else perl -e 'alarm shift; exec @ARGV' 120 "$@"; fi
}

trim() { printf '%s' "$1" | sed -e 's/^[[:blank:]]*//' -e 's/[[:blank:]]*$//'; }   # [ \t] is not a tab in BSD sed

# number of events left at the end of region $1 (from the cutflow in out.txt)
region_count() {
  awk -v r="$1" '/Based on/ { cur = $1 } / evt: / && cur == r { n = $NF } END { print n }' out.txt
}

# 1 if every cut of region $1 keeps all events (efficiency 1), else 0
region_allpass() {
  awk -v r="$1" '/Based on/ { cur = $1 } / evt: / && cur == r { seen = 1; if ($(NF-4) != 1) bad = 1 }
                 END { print (seen && !bad) ? 1 : 0 }' out.txt
}

# values printed by the first event, one line per print statement ("5 , -3 ,  . " -> "5 -3")
printed_values() {
  grep -E '^-?[0-9][0-9.e+-]* ,' out.txt | sed -e 's/ *, *\. *$//' -e 's/ *, */ /g' | head -n "$1"
}

mkdir -p "$OUT" || exit 1
OUT=$(cd "$OUT" && pwd)   # absolute: each case runs in its own directory
echo "CutLang: $CL"
echo "input:   $IN ($FMT, $EVTS events)"
echo "output:  $OUT"
npass=0; nfail=0
result() {  # name driver PASS/FAIL detail
  if [ "$3" = PASS ]; then npass=$((npass+1)); else nfail=$((nfail+1)); fi
  printf '%-30s %-3s %s  %s\n' "$1" "$2" "$3" "$4"
}

# ---- grammar: conflict counts, no useless rules, no flex warnings
bison -d -o "$OUT/b.cpp" "$CL/CLA/parse.y" > "$OUT/bison.txt" 2>&1
flex -s -o "$OUT/l.cpp" "$CL/CLA/parse.l" > "$OUT/flex.txt" 2>&1
sr=$(sed -n 's/.* \([0-9]*\) shift\/reduce conflicts.*/\1/p' "$OUT/bison.txt"); sr=${sr:-0}
rr=$(sed -n 's/.* \([0-9]*\) reduce\/reduce conflicts.*/\1/p' "$OUT/bison.txt"); rr=${rr:-0}
if [ "$sr" -eq $EXPECT_SR ] && [ "$rr" -eq $EXPECT_RR ] && ! grep -q useless "$OUT/bison.txt" && [ ! -s "$OUT/flex.txt" ]; then
  result grammar - PASS "$sr shift/reduce, $rr reduce/reduce"
else
  result grammar - FAIL "$sr shift/reduce, $rr reduce/reduce (expected $EXPECT_SR/$EXPECT_RR); see $OUT/bison.txt, flex.txt"
fi

# ---- cases
while IFS='|' read -r name driver want checks <&3; do
  name=$(trim "$name"); driver=$(trim "$driver"); want=$(trim "$want"); checks=$(trim "$checks")
  case "$name" in ''|'#'*) continue ;; esac
  dir="$OUT/${name}_$driver"
  mkdir -p "$dir" && cd "$dir" || continue
  case $driver in
    sh) run_limited "$CL/runs/CLA.sh" "$IN" "$FMT" -i "$HERE/adl/$name.adl" -e $EVTS ;;
    j2) run_limited "$CL/runs/CLA.sh" "$IN" "$FMT" -i "$HERE/adl/$name.adl" -e $EVTS -j 2 ;;
    py) run_limited python3 "$CL/runs/CLA.py" "$IN" "$FMT" -i "$HERE/adl/$name.adl" -e $EVTS ;;
  esac > out.txt 2> err.txt < /dev/null
  rc=$?
  why=""
  if [ "$want" = ok ] && [ $rc -ne 0 ]; then why="exit $rc, expected 0"; fi
  if [ "$want" = fail ] && [ $rc -eq 0 ]; then why="exit 0, expected an error"; fi
  if [ "$want" = fail ] && [ $rc -ge 124 ]; then why="exit $rc: crash or timeout"; fi
  # crashes also count when a driver hides them behind its own exit code (e.g. a -j child)
  if grep -qE "scanner jammed|Segmentation fault|Aborted|double free|There was a crash|core dumped" out.txt err.txt; then
    why="crash or flex failure in the output"
  fi
  rest="$checks"
  while [ -z "$why" ] && [ -n "$rest" ]; do
    case "$rest" in
      msg:*)  text=${rest#msg:}; rest=""
              grep -qF -- "$text" out.txt err.txt || why="message not found: $text" ;;
      *)      check=${rest%% *}; rest=$(echo "${rest#$check}" | sed 's/^ *//')
              case "$check" in
                print:*)   exp="$HERE/expected/${check#print:}"
                           printed_values "$(wc -l < "$exp")" > printed.txt
                           diff -q printed.txt "$exp" > /dev/null || why="printed values differ from ${check#print:} (see printed.txt)" ;;
                same:*)    pair=${check#same:}; a=${pair%%=*}; b=${pair#*=}
                           na=$(region_count "$a"); nb=$(region_count "$b")
                           [ -n "$na" ] && [ "$na" = "$nb" ] || why="region $a ends with '$na' events, $b with '$nb'" ;;
                allpass:*) [ "$(region_allpass "${check#allpass:}")" = 1 ] || why="region ${check#allpass:}: not all events pass" ;;
                *)         why="unknown check: $check" ;;
              esac ;;
    esac
  done
  if [ -z "$why" ]; then
    result "$name" "$driver" PASS "exit=$rc $(grep -h -m1 '^ERROR' err.txt out.txt | head -1 | cut -c1-80)"
  else
    result "$name" "$driver" FAIL "exit=$rc $why"
  fi
done 3< "$HERE/cases.txt"

echo "passed $npass, failed $nfail   (details in $OUT/<case>_<driver>/)"
[ $nfail -eq 0 ]
