//#define __SFR_OFFSET 0
//#define _SFR_ASM_COMPAT 1

#include <avr/io.h>
#include "ask2.h"

.section .data

.global n1
n1: .space 2,0x00
.global n2
n2: .space 2,0x00
.global res
res: .space 2,0x00


.section .text

.global make_add
make_add:
push r25
push r24
push r23
push r22

clr r25
clr r24
clr r23
clr r22

lds r22, n1
lds r23, n1+1

lds r24, n2
lds r25, n2+1

add r22, r24
adc r23, r25

sts res,   r22
sts res+1, r23

pop r22
pop r23
pop r24
pop r25

ret


.end
