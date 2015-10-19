#define __SFR_OFFSET 0


#include <avr/io.h>
#include <avr/interrupt.h>
#include "ask3_spi_master.h"

#define SPI_PORT PORTB
#define SPI_DDR  DDRB
#define SPI_CS   PINB2


.section .data
.section .text

.global spi_init
spi_init:
; MASTER SPI
; DECLARE MASTER SPI
LDI R16, (1<<DDB2) | (1<<DDB3) | (1<<DDB5)
OUT DDRB, R16
LDI R17, (1<<SPE) | (1<<MSTR) ;| (1<<DORD)
OUT SPCR, R17
LDI R18, (1<<SPI2X)
OUT SPSR, R18
ret

.global spi_send
spi_send:
send: cbi PORTB, SPI_CS
ldi r19, 0x04
out SPDR, r19
nop
nop
nop

;;;; SOS GIA EKSETASEIS

ldi r20, 0x00
wait: inc r20
cpi r20, 0xFF
breq mend
rjmp wait
mend: sbi PORTB, 2
ret

.end
