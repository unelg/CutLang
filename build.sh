mkdir -p $PREFIX/bin
cp -R $RECIPE_DIR $PREFIX/bin/cutlang
rm -rf $PREFIX/bin/cutlang/.github

cd $PREFIX/bin/cutlang/CLA
make clean
make

echo "build.sh done"

# Copy the [de]activate scripts to $PREFIX/etc/conda/[de]activate.d.
# This will allow them to be run on environment activation.
for CHANGE in "activate" #"deactivate"
do
    #echo "source $PREFIX/bin/cutlang/setup.sh" >> ~/.bashrc
    mkdir -p "${PREFIX}/etc/conda/${CHANGE}.d"
    #echo "export PATH=${PREFIX}/bin/cutlang/runs:${PATH}" >> ${PREFIX}/etc/conda/${CHANGE}.d/${PKG_NAME}_${CHANGE}.sh
    #echo "alias CLA='CLA.sh'" >> ${PREFIX}/etc/conda/${CHANGE}.d/${PKG_NAME}_${CHANGE}.sh
    cp "${PREFIX}/bin/cutlang/conda_activate.sh" "${PREFIX}/etc/conda/${CHANGE}.d/${PKG_NAME}_${CHANGE}.sh"
    #source $PREFIX/bin/cutlang/setup.sh
done