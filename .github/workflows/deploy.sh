cd $HOME/work/CutLang/CutLang/runs
wget http://www.hepforge.org/archive/cutlang/cms_opendata_ttbar.root
wget http://www.hepforge.org/archive/cutlang/atla_opendata_had_ttbar.root

for i in $(ls |grep .adl); do
        echo "Testing $i:"
        echo "With CMSOD"
        ./CLA.sh ./cms_opendata_ttbar.root CMSOD -i $i -e 10000
        echo "With ATLASOD"
        ./CLA.sh ./atla_opendata_had_ttbar.root ATLASOD -i $i -e 10000
done
