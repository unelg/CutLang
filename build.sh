mkdir -p $PREFIX/bin

cd $RECIPE_DIR/CLA
make clean
cp -R $RECIPE_DIR $PREFIX/bin/cutlang

rm -rf $PREFIX/bin/cutlang/.github
rm -rf $PREFIX/bin/cutlang/.git

cd $PREFIX/bin/cutlang/CLA
make clean
make

echo "build.sh done"

for CHANGE in "activate" "deactivate"
do
    mkdir -p "${PREFIX}/etc/conda/${CHANGE}.d"
    cp "${PREFIX}/bin/cutlang/conda_${CHANGE}.sh" "${PREFIX}/etc/conda/${CHANGE}.d/${PKG_NAME}_${CHANGE}.sh"
done