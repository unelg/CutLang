# Parser tests

Checks that CutLang reads valid ADL the intended way and reports invalid ADL clearly.

```
tests/parser/run_parser_tests.sh [output directory]
```
Needs a built CutLang (`CLA/CLA.exe`), ROOT, bison and flex. Exit status 0 means everything
passed. The input is `tests/data/mc_361106.Zee.2lep.2000evt.root`; `INPUT=<file or URL>` and
`FORMAT=<format>` choose another one. Each case runs on 20 events, and the whole suite takes a
few minutes.

## What is tested
- **Grammar:** bison must report exactly 23 shift/reduce and 25 reduce/reduce conflicts, with
  no useless rules and no flex warnings. If `parse.y` changes these numbers on purpose, update
  `EXPECT_SR`/`EXPECT_RR` in the runner.
- **Accepted ADL, read the intended way:**
  - operator precedence (`print` values compared with `expected/`);
  - `NOT` precedence (regions with and without brackets compared);
  - lists without commas;
  - names of variables, particles and objects;
  - the three `histo` forms;
  - the top-level structure;
  - CRLF line endings, a comment at the end of the file, `\` line continuation;
  - combined conditions in object blocks, compared with the same cuts written one per line.
- **Malformed ADL:** the reported line is the line in the user's ADL file (across comments,
  regions, region dependencies and continuations), and the message names the problem
  (characters copied from PDF/Word, `;`, `=` instead of `==`, reserved words, a region without a name).
- **Drivers:** errors and successful runs through `CLA.sh`, `CLA.sh -j 2` and `CLA.py`.

## Cases
One line per case in `cases.txt`: `name | driver | result | checks` (format at the top of the file).
A failure must be a clean exit with an error code: a crash, a timeout or "scanner jammed" in the
output always fails the case, even when a driver turns it into a normal error code.

To add a case, put the ADL in `adl/<name>.adl` and add a line to `cases.txt`. For `print:`
checks, put the expected values of the first event in `expected/`, one line per `print`
statement with the values separated by spaces.
