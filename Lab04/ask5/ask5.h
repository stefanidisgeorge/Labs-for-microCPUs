// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
    
  extern uint8_t args[];
  extern uint16_t res;

  extern "C" void f_compute(void);

#endif
