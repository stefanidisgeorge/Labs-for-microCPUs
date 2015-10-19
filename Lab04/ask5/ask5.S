#define __SFR_OFFSET 0  // automatically subtract 0x20 from I/O addresses

#include <avr/io.h>
#include "ask5.h"

.section .data

.global args
args: .space 3,0x00

.global res
res: .space 2,0x00


.section .text


.global f_compute
f_compute:
// keep the values of the registers
push r0
push r1

push r20
push r21
push r22

// load the args
lds r20, args   // a
lds r21, args+1 // x & result
lds r22, args+2 // b & result

// pass it through stack
push r20
push r21
push r22

call sub_f_compute

pop r22 // LSB
pop r21 // MSB
pop r20 // dont mind

sts res,   r22
sts res+1, r21

// retrieve old values of the registers
pop r22
pop r21
pop r20

pop r1
pop r0

ret


sub_f_compute:
// load stack pointer
IN R31, SPH
IN R30, SPL

// load values
LDD r16, Z+5 // a
LDD r17, Z+4 // x
LDD r18, Z+3 // b

// make the mul
MUL  r16, r17 // a * X 
MOVW r16, r0  // get the LSB in order to make the add
// and then the add
ADD  r16, r18 // (a*x) + b -> to +b edw
CLR  r18 // make add with carry in the next step
ADC  r17, r18

STD Z+3, r16 // LSB
STD Z+4, r17 // MSB

ret



.end
