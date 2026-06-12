python
import sys, os
qt_lib = os.path.expanduser("~/Qt/6.11.0/gcc_64/lib")
if qt_lib not in sys.path:
    sys.path.insert(0, qt_lib)
try:
    from qt import register_qt_printers
    register_qt_printers(None)
except Exception:
    pass
end

set print pretty on
set print object on
set print static-members on
