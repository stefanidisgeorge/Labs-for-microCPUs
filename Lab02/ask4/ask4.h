// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff

  #include <stdint.h>
  extern "C" void my_delay(void);
  
  extern uint16_t start_time;
  extern uint16_t end_time;
  

#endif
