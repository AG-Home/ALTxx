import subprocess
import os
import pathlib
import shutil

src_folder = r"html/"
dst_folder = r"../../Documentation/"
dstDir = pathlib.Path(dst_folder)

if dstDir.exists():
    pass
else:
    os.mkdir(dst_folder)

file_name = ('main_8c.html', 'Agh__Driver_8c.html', 'Agh__Driver_8h.html',
             'Clock__User_8c.html')

retVal = subprocess.check_call("doxygen config-doxygen.conf", shell = True)

