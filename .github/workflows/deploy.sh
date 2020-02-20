#!/bin/bash 
set -x

cp /root.conf /etc/ld.so.conf.d/
ldconfig

wget http://www.hepforge.org/archive/cutlang/cms_opendata_ttbar.root

cd CLA
make
cd ../runs/

for i in $(ls |grep .adl); do
	./CLA.sh ../cms_opendata_ttbar.root CMSOD -i $i -e 10000
done


