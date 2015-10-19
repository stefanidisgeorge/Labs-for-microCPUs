#include <avr/io.h>
#include "ask1.h"

.section .data

.section .text

.EQU MDDRB  , 0x04
.EQU MPORTB , 0x05
.EQU MPORTC , 0x08
.EQU PORTBI , 0x03
.EQU PORTCI , 0x06

.global read8
read8:
sbis PORTBI, 4
rcall ledon

sbic PORTBI, 4
rcall ledoff
ret

.global ledon
ledon:
sbi 0x08, 7
ldi r16,40
rcall delay
ret

.global ledoff
ledoff:
cbi 0x08, 7
ldi r16,40
rcall delay
ret

delay:
dec r8
brne delay
dec r9
brne delay
dec r16
brne delay
ret

.end
