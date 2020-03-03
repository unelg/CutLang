cd $HOME/work/CutLang/CutLang/runs

for i in $(ls |grep .adl); do
        echo "Testing $i:"
        echo "With CMSOD"
        ./CLA.sh ../../cms_opendata_ttbar.root CMSOD -i $i -e 10000
        echo "With ATLASOD"
        ./CLA.sh ../../atla_opendata_had_ttbar.root -i $i -e 10000
done
