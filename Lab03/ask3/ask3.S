#include <avr/io.h>
#include "ask3.h"

.section .data

.global n1
n1: .byte 0x00
.global n2
n2: .byte 0x00
.global res
res: .space 2,0x00

.section .text

.global mul_calculate
mul_calculate:
push r17
push r16
push r1
push r0
lds r16, n1
lds r17, n2
MUL r16, r17
MOVW r16, r0

sts res,   r16
sts res+1, r17

pop r0
pop r1
pop r16
pop r17
ret

.end
