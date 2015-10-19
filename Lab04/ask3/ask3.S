#define __SFR_OFFSET 0  // automatically subtract 0x20 from I/O addresses

#include <avr/io.h>
#include "ask3.h"

.section .data

message:
.extern s1

.section .text

.global stack_add
stack_add:
lds r16, s1
push r0
push r16

call m_stack_add

pop r0
pop r18

sts s1,r18

ret

m_stack_add:
IN R31, SPH // SPH=0x3E
IN R30, SPL // SPL=0x3D
LDD r18, Z+3
LDD r19, Z+4
INC r18
STD Z+4, r18
OUT 0x3E, R31
OUT 0x3D, R30
ret

.end
