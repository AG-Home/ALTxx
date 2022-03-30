#!/bin/bash
msp430-gcc-4.6.3 -mmcu=msp430g2553 main.c -o APPL.out -v 2> build.log
mv APPL.out ../../Deliverables