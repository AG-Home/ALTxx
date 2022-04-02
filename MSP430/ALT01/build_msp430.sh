#!/bin/bash
if [ -d "build" ] 
then
    echo "Directory build exists." 
else
    mkdir build
fi
cd src
msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 Gpio_User.c -v 2> ../build/build.log
mv Gpio_User.o ../build
msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 Agh_Driver.c -v >> ../build/build.log
mv Agh_Driver.o ../build
cd ..
msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 main.c -v >> build/build.log
mv main.o build
cd build 
msp430-gcc-4.6.3 -mmcu=msp430g2553 Gpio_User.o Agh_Driver.o main.o -o APPL.out -v >> build.log
rm Gpio_User.o Agh_Driver.o main.o
