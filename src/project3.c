#include "project3.h"


void project3()
{
  #ifdef DMA
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;
  set = (uint8_t *) reserve_words(8);
  ptra = &set[0];
  ptrb = &set[16];
  uint32_t i;
  for(i=0;i<32;i++)
  {
    set[i] = i;
  }

  memmove_dma(ptrb,ptra,16,4);
  #endif

  SPI_init();
  // SPI_write_byte(0b00000111);
  //SPI_write_byte((uint8_t)0x00);
  uint8_t byte;
  //SPI_read_byte(&byte);
  //SPI_read_byte(&byte);
  GPIOC->PDOR |= (1<<4);

  //byte++;
  uint32_t i = 0;
  while(1)
  {
	// GPIOC->PDOR &= ~(1<<4);
	// SPI_write_byte((uint8_t)0x00);
	// SPI_read_byte(&byte);
	// SPI_write_byte((uint8_t)0x00);
	// SPI_read_byte(&byte);
	// //SPI_read_byte(&byte);
	// GPIOC->PDOR |= (1<<4);
	// //for(i=0;i<10000;i++);
	// //GPIOC->PDOR |= (1<<4);
    byte = nrf_read_register(NRF_CONFIG_REG);
	  for(i=0;i<10000;i++);
    i++;
  }
}
