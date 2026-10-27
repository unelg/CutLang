# Regression tests

Runs the nine analyses of the ATLAS Open Data ADL Benchmark Suite
([ADL4ATLASOpenData](https://github.com/ahmetcansansar/ADL4ATLASOpenData)) on small skims and compares
the results with `reference/`, so that a change of CutLang that changes an analysis result is noticed.

```
SUITE=<ADL4ATLASOpenData checkout> tests/regression/run_regression_tests.sh [--update] [output directory]
```
Needs a built CutLang (`CLA/CLA.exe`), ROOT and python3. The suite must be at the commit in
`suite_commit.txt`: the ADLs are taken from `analyses/`, the inputs from `tests/skims/` (the first 5000
events of one MC sample per analysis, checked against `skims.sha256`). The whole run takes less than a
minute. Exit status 0 means everything passed.

## What is compared
For each case in `cases.txt` the runner copies the suite ADL and adds one region per region,
```
region ref_<region>
  <region>
  save ref_<region> csv RunNo EventNo
```
which writes the run and event numbers of the events of that region. The analysis regions are not
changed. Then, against `reference/<analysis>/` (`compare.py`):
- `ref_<region>.csv`: exactly the same events, in the same order;
- `histos.txt`, every histogram of every region including the weighted cutflow (`dump_histos.C`): the
  same names, binning and numbers of entries; bin contents and errors within a relative 1e-6 (weighted
  sums can differ in the last digits, e.g. after merging the jobs of a parallel run).

The ZBoson analysis also runs with `CLA.sh -j 2` and must give the same results as the serial run.
A crash or a non-zero exit fails the case.

## After an intended change
If a change of CutLang is meant to change results, run with `--update` to rewrite `reference/` and commit
it with the change: the diff of `reference/` shows which events and histograms changed. If the suite gets
new skims or ADLs, update `suite_commit.txt` and `skims.sha256` (a copy of the suite's
`tests/skims/skims.sha256`) and the references together.
