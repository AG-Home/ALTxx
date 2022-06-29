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

retVal = subprocess.check_call("doxygen config-doxygen.conf", shell = True)

