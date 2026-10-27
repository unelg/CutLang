#!/usr/bin/env python3
"""Compare a regression test output directory with its reference directory.

Usage: compare.py <reference dir> <output dir>
- ref_<region>.csv (events of each region): the same files, with exactly the same lines.
- histos.txt (from dump_histos.C): the same histograms, binning and entries exactly; bin contents
  and errors within a relative tolerance (weighted sums can differ in the last digits, e.g. after
  merging -j jobs).
Prints at most MAX_REPORT problems; exit status 0 if there are none.
"""
import math
import sys
from pathlib import Path

REL_TOL = 1e-6
MAX_REPORT = 10


def csv_events(path):
    # "284500 , 353 , " -> "284500,353"
    return [",".join(x.strip() for x in line.split(",") if x.strip())
            for line in path.read_text().splitlines()]


def compare_csv(ref, out, problems):
    ref_files = {p.name for p in ref.glob("ref_*.csv")}
    out_files = {p.name for p in out.glob("ref_*.csv")}
    for name in sorted(ref_files - out_files):
        problems.append(f"{name}: missing")
    for name in sorted(out_files - ref_files):
        problems.append(f"{name}: not in the reference")
    for name in sorted(ref_files & out_files):
        a, b = csv_events(ref / name), csv_events(out / name)
        if a == b:
            continue
        only_ref = sorted(set(a) - set(b))
        only_out = sorted(set(b) - set(a))
        msg = f"{name}: {len(a)} events in the reference, {len(b)} now"
        if only_ref:
            msg += f"; lost {len(only_ref)} (first: run,event {only_ref[0]})"
        if only_out:
            msg += f"; new {len(only_out)} (first: run,event {only_out[0]})"
        if not only_ref and not only_out:
            msg += "; same events in a different order"
        problems.append(msg)


def read_histos(path):
    """{region/name: (header lines, [bin values])}"""
    histos, key = {}, None
    for line in path.read_text().splitlines():
        word, _, rest = line.partition(" ")
        if word == "histo":
            key = rest.split()[0]
            histos[key] = ([line], [])
        elif word == "axis":
            histos[key][0].append(line)
        elif word == "bins":
            histos[key] = (histos[key][0], [float(x) for x in rest.split()])
    return histos


def same_axes(a, b):
    """axis lines: the same number of bins, and bin edges equal up to rounding (an edge at 0 comes
    out as about +-1e-16, different on each platform)"""
    if len(a) != len(b):
        return False
    for la, lb in zip(a, b):
        ea, eb = [float(x) for x in la.split()[1:]], [float(x) for x in lb.split()[1:]]
        if len(ea) != len(eb) or ea[0] != eb[0]:   # ea[0] is the number of bins
            return False
        width = abs(ea[-1] - ea[1]) or 1.0         # axis range
        if any(abs(x - y) > 1e-9 * width for x, y in zip(ea[1:], eb[1:])):
            return False
    return True


def compare_histos(ref, out, problems):
    if not (out / "histos.txt").exists():
        problems.append("histos.txt: missing (no output file?)")
        return
    a, b = read_histos(ref / "histos.txt"), read_histos(out / "histos.txt")
    for key in sorted(a.keys() - b.keys()):
        problems.append(f"{key}: missing")
    for key in sorted(b.keys() - a.keys()):
        problems.append(f"{key}: not in the reference")
    for key in sorted(a.keys() & b.keys()):
        (ha, va), (hb, vb) = a[key], b[key]
        if ha[0] != hb[0]:
            problems.append(f"{key}: header differs: {ha[0]!r} vs {hb[0]!r}")
            continue
        if not same_axes(ha[1:], hb[1:]):
            problems.append(f"{key}: binning differs: {ha[1:]!r} vs {hb[1:]!r}")
            continue
        for i, (x, y) in enumerate(zip(va, vb)):
            if not math.isclose(x, y, rel_tol=REL_TOL, abs_tol=0.0):
                what = "content" if i % 2 == 0 else "error"
                problems.append(f"{key}: bin {i // 2} {what} {x!r} vs {y!r}")
                break


def main():
    ref, out = Path(sys.argv[1]), Path(sys.argv[2])
    problems = []
    compare_csv(ref, out, problems)
    compare_histos(ref, out, problems)
    for p in problems[:MAX_REPORT]:
        print("   " + p)
    if len(problems) > MAX_REPORT:
        print(f"   ... and {len(problems) - MAX_REPORT} more")
    return 1 if problems else 0


if __name__ == "__main__":
    sys.exit(main())
