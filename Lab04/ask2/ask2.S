#include <avr/io.h>
#include "ask2.h"


.section .data

.global in_char
in_char: .ascii "A"

.global out_char
out_char: .ascii "A"


.section .text

.global next_char
next_char:

push r16
clr r16
lds r16, in_char
inc r16
sts out_char, r16
pop r16
ret



.end
