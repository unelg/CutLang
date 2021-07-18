# Source this script to set up the ROOT build that this script is part of.
#
# Conveniently an alias like this can be defined in .bashrc:
#   alias thisroot=". bin/thisroot.sh"
#
# This script if for the bash like shells, see thisroot.csh for csh like shells.
#
# Author: Fons Rademakers, 18/8/2006
#
# Edited for CutLang

set_environment()
{
   #if [ -z "${PATH}" ]; then
   #   PATH=$_ROOTSYS/bin; export PATH
   #else
      PATH=$_ROOTSYS/bin:$PATH; export PATH
      PATH=$PATH:$_ROOTSYS/bin; export PATH
   #fi

   #if [ -z "${LD_LIBRARY_PATH}" ]; then
   #   LD_LIBRARY_PATH=$_ROOTSYS/lib
   #   export LD_LIBRARY_PATH       # Linux, ELF HP-UX
   #else
      LD_LIBRARY_PATH=$_ROOTSYS/lib:$LD_LIBRARY_PATH
      export LD_LIBRARY_PATH
      LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$_ROOTSYS/lib
      export LD_LIBRARY_PATH
   #fi

   #if [ -z "${DYLD_LIBRARY_PATH}" ]; then
   #   DYLD_LIBRARY_PATH=$_ROOTSYS/lib
   #   export DYLD_LIBRARY_PATH       # Linux, ELF HP-UX
   #else
      DYLD_LIBRARY_PATH=$_ROOTSYS/lib:$DYLD_LIBRARY_PATH
      export DYLD_LIBRARY_PATH
      DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$_ROOTSYS/lib
      export DYLD_LIBRARY_PATH
   #fi

   #if [ -z "${SHLIB_PATH}" ]; then
   #   SHLIB_PATH=$_ROOTSYS/lib
   #   export SHLIB_PATH       # Linux, ELF HP-UX
   #else
      SHLIB_PATH=$_ROOTSYS/lib:$SHLIB_PATH
      export SHLIB_PATH
      SHLIB_PATH=$SHLIB_PATH:$_ROOTSYS/lib
      export SHLIB_PATH
   #fi

   #if [ -z "${LIBPATH}" ]; then
   #   LIBPATH=$_ROOTSYS/lib
   #   export LIBPATH       # Linux, ELF HP-UX
   #else
      LIBPATH=$_ROOTSYS/lib:$LIBPATH
      export LIBPATH
      LIBPATH=$LIBPATH:$_ROOTSYS/lib
      export LIBPATH
   #fi

   #if [ -z "${PYTHONPATH}" ]; then
   #   PYTHONPATH=$_ROOTSYS/lib
   #   export PYTHONPATH       # Linux, ELF HP-UX
   #else
      PYTHONPATH=$_ROOTSYS/lib:$PYTHONPATH
      export PYTHONPATH
      PYTHONPATH=$PYTHONPATH:$_ROOTSYS/lib
      export PYTHONPATH
   #fi

   #if [ -z "${MANPATH}" ]; then
   #   MANPATH=$_ROOTSYS/man:${default_manpath}; export MANPATH
   #else
      MANPATH=$_ROOTSYS/man:$MANPATH; export MANPATH
      MANPATH=$MANPATH:$_ROOTSYS/man; export MANPATH
   #fi

   #if [ -z "${CMAKE_PREFIX_PATH}" ]; then
   #   CMAKE_PREFIX_PATH=$_ROOTSYS; export CMAKE_PREFIX_PATH       # Linux, ELF HP-UX
   #else
      CMAKE_PREFIX_PATH=$_ROOTSYS:$CMAKE_PREFIX_PATH; export CMAKE_PREFIX_PATH
      CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:$_ROOTSYS; export CMAKE_PREFIX_PATH
   #fi

   #if [ -z "${JUPYTER_PATH}" ]; then
   #   JUPYTER_PATH=$_ROOTSYS/etc/notebook; export JUPYTER_PATH       # Linux, ELF HP-UX
   #else
      JUPYTER_PATH=$_ROOTSYS/etc/notebook:$JUPYTER_PATH; export JUPYTER_PATH
      JUPYTER_PATH=$JUPYTER_PATH:$_ROOTSYS/etc/notebook; export JUPYTER_PATH
   #fi

   #if [ -z "${JUPYTER_CONFIG_DIR}" ]; then
   #   JUPYTER_CONFIG_DIR=$_ROOTSYS/etc/notebook; export JUPYTER_CONFIG_DIR # Linux, ELF HP-UX
   #else
      JUPYTER_CONFIG_DIR=$_ROOTSYS/etc/notebook:$JUPYTER_CONFIG_DIR; export JUPYTER_CONFIG_DIR
      JUPYTER_CONFIG_DIR=$JUPYTER_CONFIG_DIR:$_ROOTSYS/etc/notebook; export JUPYTER_CONFIG_DIR
   #fi
}

set_environment

if [ "x`root-config --arch | grep -v win32gcc | grep -i win32`" != "x" ]; then
   _ROOTSYS="`cygpath -w $_ROOTSYS`"
fi

unset thisroot
unset -f drop_from_path
unset -f clean_environment
unset -f set_environment
