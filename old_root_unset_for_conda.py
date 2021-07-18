import os

PATH=os.environ.get("PATH", "").replace("\n", "").split(os.pathsep)
ROOTSYS=os.environ.get("ROOTSYS", "").replace("\n", "")

old_root_path=""

for i, key in enumerate(PATH):
    filenames=[]
    if key.split("/")[-1]=="bin":
        filenames = [f for f in os.listdir(key) if os.path.isfile(os.path.join(key, f))]
    for filename in filenames:
        if "thisroot.sh" == filename.lower() and (ROOTSYS not in key):
            old_root_path=os.path.abspath(os.path.join(os.path.dirname( key )))
            #PATH=os.pathsep.join(PATH).replace(key+os.pathsep, "").split(os.pathsep)

print(old_root_path)
