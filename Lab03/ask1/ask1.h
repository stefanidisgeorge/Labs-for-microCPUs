// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff

  #include <stdint.h>
  
  extern "C" void read8(void);
  extern "C" void ledon(void);
  extern "C" void ledoff(void);

#endif
