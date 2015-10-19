#include <avr/io.h>
#include "ask2.h"

.section .data

.global n1
n1: .byte 0x00
.global n2
n2: .byte 0x00
.global res
res: .byte 0x00

.section .text

.global mcalculate
mcalculate:
push r16
push r17
lds r16, n1
lds r17, n2
add r16, r17
sts res, r16
pop r17
pop r16
ret

.end
