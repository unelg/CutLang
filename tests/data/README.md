# Test samples

`mc_361106.Zee.2lep.2000evt.root` (460 kB): the first 2000 events (tree `mini`) of the ATLAS Open
Data 13 TeV sample `2lep/MC/mc_361106.Zee.2lep.root`, from
https://opendata.cern.ch/eos/opendata/atlas/OutreachDatasets/2020-01-22/ (CC0 licence).
Input format `ATLASODR2`. Made with:

```
root -l -b -q 'skim.C("https://opendata.cern.ch/eos/opendata/atlas/OutreachDatasets/2020-01-22/2lep/MC/mc_361106.Zee.2lep.root", "mc_361106.Zee.2lep.2000evt.root", 2000)'
```
where `skim.C` copies the first N entries: `TFile::Open(in)->Get("mini")` and then `CopyTree("", "", N)`
written to a new file.

It is stored in the repository so that the tests run without network access and always use the
same events.
