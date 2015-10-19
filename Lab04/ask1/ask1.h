// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
    
  extern uint16_t counter;
  
  extern "C" void cup(void);
  extern "C" void cdown(void);

#endif
