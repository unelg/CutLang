#!/bin/bash
# CutLang regression tests: the analyses of the ATLAS Open Data ADL Benchmark Suite on small skims.
# Usage:   SUITE=<ADL4ATLASOpenData checkout> tests/regression/run_regression_tests.sh [--update] [output directory]
#          The suite must be at the commit in suite_commit.txt; its skims must match skims.sha256.
# Checks:  per case in cases.txt, against reference/<analysis>/ (see compare.py):
#          the events of every region exactly, histograms and weighted cutflows within 1e-6.
# Update:  --update writes the new results of the sh cases into reference/ (after an intended change;
#          the diff of reference/ then shows what changed).
# Exit:    0 if everything passes, 1 otherwise. Outputs stay in the output directory (default
#          tests/regression/out_<date>), one subdirectory per case.

HERE=$(cd "$(dirname "$0")" && pwd)
CL=$(cd "$HERE/../.." && pwd)
UPDATE=0
if [ "$1" = --update ]; then UPDATE=1; shift; fi
OUT=${1:-$HERE/out_$(date +%Y%m%d_%H%M%S)}
FMT=ATLASODR2
if [ -z "$SUITE" ]; then echo "set SUITE to a checkout of ADL4ATLASOpenData"; exit 1; fi
SUITE=$(cd "$SUITE" && pwd)

# GNU timeout on Linux, perl alarm on macOS
run_limited() {
  if command -v timeout > /dev/null 2>&1; then timeout -k 10 600 "$@"; else perl -e 'alarm shift; exec @ARGV' 600 "$@"; fi
}
sha256() { if command -v sha256sum > /dev/null 2>&1; then sha256sum "$@"; else shasum -a 256 "$@"; fi; }

trim() { printf '%s' "$1" | sed -e 's/^[[:blank:]]*//' -e 's/[[:blank:]]*$//'; }

mkdir -p "$OUT" || exit 1
echo "CutLang: $CL"
echo "suite:   $SUITE"
echo "output:  $OUT"

# ---- the inputs must be the ones the references were made with
want=$(cat "$HERE/suite_commit.txt")
have=$(git -C "$SUITE" rev-parse HEAD 2>/dev/null)
if [ "$have" != "$want" ]; then
  echo "suite is at commit '$have', the references need $want"; exit 1
fi
if ! (cd "$SUITE/tests/skims" && sha256 -c "$HERE/skims.sha256" > "$OUT/skims_check.txt" 2>&1); then
  echo "skims differ from skims.sha256:"; cat "$OUT/skims_check.txt"; exit 1
fi

npass=0; nfail=0
result() {  # name driver PASS/FAIL detail
  if [ "$3" = PASS ]; then npass=$((npass+1)); else nfail=$((nfail+1)); fi
  printf '%-24s %-3s %s  %s\n' "$1" "$2" "$3" "$4"
}

while IFS='|' read -r name skim driver <&3; do
  name=$(trim "$name"); skim=$(trim "$skim"); driver=$(trim "$driver")
  case "$name" in ''|'#'*) continue ;; esac
  if [ $UPDATE -eq 1 ] && [ "$driver" != sh ]; then continue; fi
  dir="$OUT/${name}_$driver"
  mkdir -p "$dir" && cd "$dir" || continue
  # the suite ADL, plus one region per region that saves its events: region ref_X / X / save ...
  cp "$SUITE/analyses/$name/$name.adl" "$name.adl"
  for r in $(awk '$1 == "region" { print $2 }' "$name.adl"); do
    printf '\nregion ref_%s\n  %s\n  save ref_%s csv RunNo EventNo\n' "$r" "$r" "$r" >> "$name.adl"
  done
  case $driver in
    sh) run_limited "$CL/runs/CLA.sh" "$SUITE/tests/skims/$skim.5000evt.root" $FMT -i "$name.adl" ;;
    j2) run_limited "$CL/runs/CLA.sh" "$SUITE/tests/skims/$skim.5000evt.root" $FMT -i "$name.adl" -j 2 ;;
  esac > out.txt 2> err.txt < /dev/null
  rc=$?
  why=""
  if [ $rc -ne 0 ]; then why="exit $rc"; fi
  if grep -qE "scanner jammed|Segmentation fault|Aborted|double free|There was a crash|core dumped" out.txt err.txt; then
    why="crash in the output"
  fi
  if [ -z "$why" ]; then
    root -l -b -q "$HERE/dump_histos.C(\"histoOut-$name.root\", \"histos.txt\")" > dump.txt 2>&1 || why="dump_histos.C failed (see dump.txt)"
  fi
  if [ -z "$why" ] && [ $UPDATE -eq 1 ]; then
    ref="$HERE/reference/$name"
    mkdir -p "$ref" && cp histos.txt ref_*.csv "$ref/" && result "$name" "$driver" PASS "reference written" || result "$name" "$driver" FAIL "cannot write $ref"
    continue
  fi
  if [ -z "$why" ]; then
    python3 "$HERE/compare.py" "$HERE/reference/$name" . > compare.txt 2>&1 || why="differs from the reference:"
  fi
  if [ -z "$why" ]; then
    result "$name" "$driver" PASS "$(cat ref_*.csv | wc -l | tr -d ' ') region events, $(grep -c '^histo' histos.txt) histograms"
  else
    result "$name" "$driver" FAIL "$why"
    [ -s compare.txt ] && cat compare.txt
  fi
done 3< "$HERE/cases.txt"

echo "passed $npass, failed $nfail   (details in $OUT/<analysis>_<driver>/)"
[ $nfail -eq 0 ]
