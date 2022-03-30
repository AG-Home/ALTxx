#!/bin/bash
mkdir build
cd src
msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 Gpio_User.c -v 2> ../build.log
mv Gpio_User.o ../build
cd ..
msp430-gcc-4.6.3 -c -I/home/marco/Projects/AG-Home/ALTxx/MSP430/ALT01/include -mmcu=msp430g2553 main.c -v 2> build.log
mv main.o build
cd build 
msp430-gcc-4.6.3 -mmcu=msp430g2553 Gpio_User.o main.o -o APPL.out -v 2> ../build.log
rm Gpio_User.o main.o
