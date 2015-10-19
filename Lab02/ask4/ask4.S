#include <avr/io.h>
#include "ask4.h"

.section .data

.global start_time
start_time: .space 2,0x00
.global end_time
end_time: .space 2,0x00

.section .text

.global my_delay
my_delay:
  ldi r18, 162
  jmp delay_2s

delay_12ms:
  dec r8
  brne delay_12ms
  dec r9
  brne delay_12ms

delay_2s:
  dec r18
  brne delay_12ms

ret

.end
