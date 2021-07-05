NAME=$2
if [ $1 = "install" ]; then
    mkdir -p ~/CutLang_repo
    #git clone https://github.com/shenburak/CutLang ~/CutLang_repo
    #conda env create -f https://raw.githubusercontent.com/shenburak/CutLang/master/environment.yml --name $NAME
    #source activate $NAME && cd ~/CutLang_repo/CLA && make
    source ~/CutLang_repo/setup.sh
    echo "source ~/CutLang_repo/setup.sh" >> ~/.bashrc
    echo "~~~~~~~~ Now you can use CutLang with CLA command ~~~~~~~~"
elif [ $1 = "remove" ]; then
    echo "remove"
else
  echo "Only install and remove are valid"
fi
