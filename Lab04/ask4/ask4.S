#define __SFR_OFFSET 0  // automatically subtract 0x20 from I/O addresses

#include <avr/io.h>
#include "ask4.h"

.section .data

.global args
args: .space 3,0x00

.global res
res: .space 2,0x00


.section .text


.global f_compute
f_compute:
push r0
push r1
push r16
push r17
push r20

lds r16, args   // a
lds r17, args+1 // x
lds r20, args+2 // b

// make the mul
MUL  r16, r17 // a * X 
MOVW r16, r0  // get the LSB in order to make the add
// and then the add
ADD  r16, r20 // (a*x) + b -> to +b edw
CLR  r20 // make add with carry in the next step
ADC  r17, r20

sts res,   r16
sts res+1, r17

pop r20
pop r17
pop r16
pop r1
pop r0

ret

.end
