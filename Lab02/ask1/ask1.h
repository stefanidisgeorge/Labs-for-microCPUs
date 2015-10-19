// global register vars
#ifdef __ASSEMBLER__
    // asembler only stuf

#else
    // C-only stuff

    #include <stdint.h>
    #include <WString.h> // for string
    extern "C" void mcalculate(void);
    extern uint8_t n1;
    extern uint8_t n2;
    extern uint8_t n3;
    extern uint8_t n4;
    extern char msg[];
    extern char msg1[];
    extern char msg2[];

#endif
