export version_cutlang=$(echo cat ../../VERSION)

sed -i "/version = /c{% set version = '$version_cutlang' %}" meta.yaml
sed -i "/cout << \"CLA v/c cout << \"CLA v$version_cutlang\\\t\";" ../../CLA/CLA.Q
meta=$(cat ../../scripts/conda/meta.yaml)

sed -i "/cutlang ==/c  - cutlang ==$version_cutlang" ../../binder/environment.yml

export check_version_cutlang=$(conda search -c ${{secrets.PACKAGE_USERNAME}} -f cutlang | grep $version_cutlang)

export unelgRepo=$(git remote -v | grep -e 'origin.*unelg')