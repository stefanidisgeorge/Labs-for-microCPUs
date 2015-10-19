// global register vars

#ifdef __ASSEMBLER__
    // asembler only stuf

#else
    // C-only stuff
    #include <stdint.h>
    extern "C" void mul_calculate(void);
    extern uint16_t res;
    extern uint8_t  n1,n2;

#endif
