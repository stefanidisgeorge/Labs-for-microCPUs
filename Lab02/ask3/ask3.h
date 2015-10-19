// global register vars
#ifdef __ASSEMBLER__
    // asembler only stuf

#else
    // C-only stuff

    #include <stdint.h>
    extern "C" void table_init(void);
    extern uint8_t p[];

#endif
