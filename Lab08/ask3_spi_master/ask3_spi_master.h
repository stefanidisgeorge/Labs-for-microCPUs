// global register vars

#ifdef __ASSEMBLER__
  // asembler only stuf

#else
  // C-only stuff
  #include <stdint.h>
  #include <WString.h>
  
  extern "C" void spi_send(void);
  extern "C" void spi_init(void);

#endif
