// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
    
  char s1='A';

  extern "C" void stack_add(void);

#endif
