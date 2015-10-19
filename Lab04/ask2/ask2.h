// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
    
  extern char in_char;
  extern char out_char;
  
  extern "C" void next_char(void);

#endif
