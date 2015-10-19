// global register vars
#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff

  #include <stdint.h>

  extern "C" void make_add(void);
  extern uint16_t n1;
  extern uint16_t n2;
  extern uint16_t res;

#endif
