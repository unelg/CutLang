import os

c = get_config()

if 'ROOTSYS' in os.environ:
    # Prefer using JSROOT from ROOTSYS if defined
    # Configuration file for jupyter-notebook.
    _rootbin = os.environ['ROOTSYS'] + '/bin'
    _rootlib = os.environ['ROOTSYS'] + '/lib'
    _rootetc = os.environ['ROOTSYS'] + '/etc'
    _rootdata = os.environ['ROOTSYS']

    _rootnbpath = os.environ['HOME'] + "/.rootnb"
    
    os.environ['PATH']            = '%s:%s/bin' % (_rootbin,_rootbin) + ':' + os.getenv('PATH', '')
    os.environ['LD_LIBRARY_PATH'] = '%s' % _rootlib + ':' + os.getenv('LD_LIBRARY_PATH', '')
    os.environ['DYLD_LIBRARY_PATH'] = '%s' % _rootlib + ':' + os.getenv('DYLD_LIBRARY_PATH', '')
    os.environ['SHLIB_PATH'] = '%s' % _rootlib + ':' + os.getenv('SHLIB_PATH', '')
    os.environ['LIB_PATH'] = '%s' % _rootlib + ':' + os.getenv('LIB_PATH', '')
    os.environ['PYTHONPATH']      = '%s' % _rootlib + ':' + os.getenv('PYTHONPATH', '')
    os.environ['CMAKE_PREFIX_PATH']      = '%s' % _rootdata + ':' + os.getenv('CMAKE_PREFIX_PATH', '')
    os.environ['JUPYTER_PATH']      = '%s' % _rootnbpath + ':' + os.getenv('JUPYTER_PATH', '')
    os.environ['JUPYTER_CONFIG_DIR']      = '%s' % _rootnbpath + ':' + os.getenv('JUPYTER_CONFIG_DIR', '')
    c.NotebookApp.extra_static_paths.append(os.path.join(os.environ['ROOTSYS'], 'js/'))
    c.ServerApp.extra_static_paths.append(os.path.join(os.environ['ROOTSYS'], 'js/'))
    c.NotebookApp.extra_static_paths.append(os.path.join(os.environ['CUTLANG_PATH'], 'scripts/JsRoot620/'))
    c.ServerApp.extra_static_paths.append(os.path.join(os.environ['CUTLANG_PATH'], 'scripts/JsRoot620/'))

    print("All config", c)
else:
    print("ROOTSYS not found!")