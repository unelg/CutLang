set -ex
#set -o pipefail

conda info
conda env list
conda list

anaconda -h

go_to_build_dir() {
    if [ ! -z $SUBDIR ]; then
        cd ../../$SUBDIR
    fi
}

if [ -z "$PACKAGE_USERNAME" ]; then
    PACKAGE_USERNAME="cutlang"
fi

check_if_meta_yaml_file_exists() {
    if [ ! -f meta.yaml ]; then
        echo "meta.yaml must exist in the directory that is being packaged and published."
        exit 1
    fi
}

build_package(){
    conda build -c conda-forge --output-folder . .
    #conda build -c conda-forge -c bioconda --output-folder . .
    #conda convert -p osx-64 linux-64/*.tar.bz2
}

upload_package(){
    export ANACONDA_API_TOKEN=$ANACONDA_TOKEN
    PACKAGE_FILE=$(find . \( -path "*/linux-64/*.conda" -o -path "*/linux-64/*.tar.bz2" \) -print | head -n 1)
    if [ -z "$PACKAGE_FILE" ]; then
        echo "No linux-64 package artifact was produced."
        exit 1
    fi
    anaconda upload -u "$PACKAGE_USERNAME" --label main "$PACKAGE_FILE"
    #anaconda upload -u cutlang --label main osx-64/*.tar.bz2
}

go_to_build_dir
check_if_meta_yaml_file_exists
build_package
upload_package
