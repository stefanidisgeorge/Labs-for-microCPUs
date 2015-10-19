// global register vars
#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
  
  extern uint8_t adval;
  
  extern "C" void aetherphone(void);

#endif
