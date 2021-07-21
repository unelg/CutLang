## Syntax Highlighting 
vim plugin for highlighting .adl syntax for CutLang [cutlang.vim]

## Installation 
The plugin is installed by copying the .vim file to filepath ~/.vim/syntax 
```bash
 cp CutLang/scripts/cutlang.vim ~/.vim/syntax/
```

## Usage
Syntax Highlighting is triggered by entering
```bash
 :set syntax=cutlang
```
on the vim terminal window 

# addntuple

Script for adding (or deleting) new ntuples into CutLang - CutLang/scripts/addntuple.py

```bash
    python3 addntuple.py --<create | delete | find | recreate | save> --[name | file | branch]
```

To create an ntuple template, run:
```bash
    python3 addntuple.py --create --name <ntuplename> --file <rootfile> [--branch <branchname>]
```
To delete an already added ntuple, run:
```bash
    python3 addntuple.py --delete --name <ntuplename>
```
To find an already added ntuple, run:
```bash
    python3 addntuple.py --find --file <rootfile> [--branch <branchname>]
```
To recreate an already added ntuple, run:
```bash
    python3 addntuple.py --recreate --name <ntuplename> --file <rootfile> [--branch <branchname>]
```
To save an already added ntuple into CLA and analysis_core, run:
```bash
    python3 addntuple.py --save --name <ntuplename>
```

To edit template, change CutLang/scripts/templates/\<ntuplename\>

!Old templates are backed up to CutLang/scripts/templates/\<ntuplename\>/history