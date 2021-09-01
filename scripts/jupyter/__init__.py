from JupyROOT.helpers import cppcompleter, utils, cutlang_utils

# Check if we are in the IPython shell
try:
    import builtins
except ImportError:
    import __builtin__ as builtins # Py2
_is_ipython = hasattr(builtins, '__IPYTHON__')

if _is_ipython:
    from IPython import get_ipython
    cppcompleter.load_ipython_extension(get_ipython())
    utils.iPythonize()
    
    # CutLang
    cutlang_utils.iPythonize()
