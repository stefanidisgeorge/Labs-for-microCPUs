#include <avr/io.h>
#include "ask1.h"

.section .data

.global counter
counter: .space 2,0x00

.section .text

.global cup
cup:
push r28
push r29

clr r28
clr r29

lds r28, counter
lds r29, counter+1

ADIW r28, 1

sts counter,   r28
sts counter+1, r29

pop r29
pop r28

ret

.global cdown
cdown:
push r28
push r29

clr r28
clr r29

lds r28, counter
lds r29, counter+1

SBIW r28, 1

sts counter,   r28
sts counter+1, r29

pop r29
pop r28

ret

.end
