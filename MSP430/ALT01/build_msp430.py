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

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Gpio_User.c -o build/Gpio_User.o", shell = True)
if(retVal == 0):
    print('Gpio_User.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Gpio_Service.c -o build/Gpio_Service.o", shell = True)
if(retVal == 0):
    print('Gpio_Service.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Mcu_User.c -o build/Mcu_User.o", shell = True)
if(retVal == 0):
    print('Mcu_User.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Clock_User.c -o build/Clock_User.o", shell = True)
if(retVal == 0):
    print('Clock_User.o')
    
retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Agh_Driver.c -o build/Agh_Driver.o", shell = True)
if(retVal == 0):
    print('Agh_Driver.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Icu_User.c -o build/Icu_User.o", shell = True)
if(retVal == 0):
    print('Icu_User.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Icu_Service.c -o build/Icu_Service.o", shell = True)
if(retVal == 0):
    print('Icu_Service.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Interrupt_User.c -o build/Interrupt_User.o", shell = True)
if(retVal == 0):
    print('Interrupt_User.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 src/Sar.c -o build/Sar.o", shell = True)
if(retVal == 0):
    print('Sar.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -c -Iinclude/ -mmcu=msp430g2553 main.c -o build/main.o", shell = True)
if(retVal == 0):
    print('Main.o')

retVal = subprocess.check_call("msp430-gcc-4.6.3 -mmcu=msp430g2553 \
                                build/Gpio_User.o \
                                build/Gpio_Service.o \
                                build/Icu_User.o \
                                build/Icu_Service.o \
                                build/Agh_Driver.o \
                                build/Mcu_User.o \
                                build/Clock_User.o \
                                build/Interrupt_User.o \
                                build/Sar.o \
                                build/main.o \
                                -o build/APPL.out", shell = True)
if(retVal == 0):
    print('APPL.out')


os.remove('build/Agh_Driver.o')
os.remove('build/Gpio_User.o')
os.remove('build/Gpio_Service.o')
os.remove('build/Mcu_User.o')
os.remove('build/Clock_User.o')
os.remove('build/Interrupt_User.o')
os.remove('build/Icu_User.o')
os.remove('build/Icu_Service.o')
os.remove('build/Sar.o')
os.remove('build/main.o')

