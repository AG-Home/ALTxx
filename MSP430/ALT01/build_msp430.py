import subprocess
import os
import pathlib

buildPath = 'build/'
srcPath = 'src/'
buildDir = pathlib.Path(buildPath)
if buildDir.exists():
    pass
else:
    os.mkdir(buildPath)
# os.chdir('src')
retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 src/Gpio_User.c -o build/Gpio_User.o", shell = True)
if(retVal == 0):
    print('Gpio_User.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 src/Agh_Driver.c -o build/Agh_Driver.o", shell = True)

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 main.c -o build/main.o", shell = True)

retVal = subprocess.check_call("msp430-gcc-4.6.3 -mmcu=msp430g2553 build/Gpio_User.o build/Agh_Driver.o build/main.o -o build/APPL.out", shell = True)

os.remove('build/Agh_Driver.o')
os.remove('build/Gpio_User.o')
os.remove('build/main.o')

