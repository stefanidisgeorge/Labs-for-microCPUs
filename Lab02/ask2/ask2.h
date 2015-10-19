// global register vars

#ifdef __ASSEMBLER__
    // asembler only stuf

#else
    // C-only stuff
    #include <stdint.h>
    extern "C" void mcalculate(void);
    extern uint8_t res;
    extern uint8_t n1,n2;
#endif
