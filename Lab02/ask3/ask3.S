#include <avr/io.h>
#include "ask3.h"

.section .data

.global p
p: .space 10, 0x00

.section .text

.global table_init
table_init: clr  r18
            ldi r30, lo8(p)
            ldi r31, hi8(p) ;Z reg
mloopa:     inc r18
            st Z+, r18
            cpi r18,10
            brge done
            jmp mloopa
done:

ret

.end
