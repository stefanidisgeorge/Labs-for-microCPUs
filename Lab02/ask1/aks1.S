#include <avr/io.h>
#include "ask1.h"

.section .data

.global n1
n1: .byte 28

.global n2
n2: .byte 0b00001100

.global n3
n3: .byte 0x3F

.global n4
n4: .byte 'A'

.global msg
msg: .asciz "my string\0"; 

.global msg1
msg1: .asciz "Another string"; 

.global msg2
msg2: .string "Last string\0"; 

.section .text


.end
