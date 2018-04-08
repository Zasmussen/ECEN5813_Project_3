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
  profiling();
  while(1)
  {

  }
}

void spi_test()
{
  SPI_init();
  uint8_t config;
  uint32_t i;
  while(1)
  {
    config = nrf_read_config();
    nrf_write_config(config|NRF_CONFIG_PWR_UP_MASK);
    config = nrf_read_config();
    for(i=0;i<10000;i++);
    nrf_write_config(config&~(NRF_CONFIG_PWR_UP_MASK));
    config = nrf_read_config();
    for(i=0;i<10000;i++);
  }
}

void profiling()
{
  #ifdef KL25Z
    GPIO_Configure();
    UART_configure();
    uint8_t digits;
    uint8_t * send = (uint8_t *)reserve_words(10);
  #endif
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk|SysTick_CTRL_CLKSOURCE_Msk;
  SysTick->LOAD = 0xFFFFFFFF;
  uint32_t i;
  uint8_t * src = (uint8_t *)malloc(5100);
  uint8_t * dst = (uint8_t *)malloc(5100);
  reset_memory(src,dst);

  uint32_t length,start,end;

/* Standard memmove */
  // 10 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove(dst,src,10);
  end = SysTick->VAL;
  length = start-end;
#ifdef HOST
  PRINTF("*****PROFILING*****\n");
  PRINTF("**memmove**\n");
  PRINTF("Standard Memmove took %d clock cycles");
#endif
#ifdef KL25Z
  UART_send_n((uint8_t *)"*****PROFILING*****\r\n",21);
  UART_send_n((uint8_t *)"**memmove**\r\n",13);
  UART_send_n((uint8_t *)"Standard 10 Byte Memmove took ",30);
  digits = my_itoa(length,send,10);
  UART_send_n(send,digits-1);
  UART_send_n((uint8_t *)" clock cycles\n\r",15);
#endif
  reset_memory(src,dst);


  // 100 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove(dst,src,100);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
#ifdef KL25Z
  UART_send_n((uint8_t *)"Standard 100 Byte Memmove took ",31);
  digits = my_itoa(length,send,10);
  UART_send_n(send,digits-1);
  UART_send_n((uint8_t *)" clock cycles\n\r",15);
#endif
  reset_memory(src,dst);

  // 1000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove(dst,src,1000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
#ifdef KL25Z
  UART_send_n((uint8_t *)"Standard 1000 Byte Memmove took ",32);
  digits = my_itoa(length,send,10);
  UART_send_n(send,digits-1);
  UART_send_n((uint8_t *)" clock cycles\n\r",15);
#endif
  reset_memory(src,dst);

  // 5000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove(dst,src,5000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
#ifdef KL25Z
  UART_send_n((uint8_t *)"Standard 5000 Byte Memmove took ",32);
  digits = my_itoa(length,send,10);
  UART_send_n(send,digits-1);
  UART_send_n((uint8_t *)" clock cycles\n\r",15);
#endif
  reset_memory(src,dst);



/* My memmove */
  // 10 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memmove(src,dst,10);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 10 Byte Memmove took ",24);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memmove(src,dst,100);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 100 Byte Memmove took ",25);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memmove(src,dst,1000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 1000 Byte Memmove took ",26);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memmove(src,dst,5000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 5000 Byte Memmove took ",26);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);


#ifdef KL25Z
/* DMA memmove */
  // 10 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,10,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 1 Byte Burst Memmove took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 10 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,10,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 2 Byte Burst Memmove took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 10 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,10,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 4 Byte Burst Memmove took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,100,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 1 Byte Burst Memmove took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,100,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 2 Byte Burst Memmove took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,100,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 4 Byte Burst Memmove took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,1000,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 1 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,1000,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 2 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,1000,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 4 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,5000,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 1 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,5000,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 2 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memmove_dma(src,dst,5000,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 4 Byte Burst Memmove took ",40);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
    UART_send_n((uint8_t *)"\n\r",2);
  #endif
  reset_memory(src,dst);
#endif


/* Standard memset */
  // 10 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset(src,0xFF,10);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"**memset**\r\n",12);
    UART_send_n((uint8_t *)"Standard 10 Byte Memset took ",29);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset(src,0xFF,100);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"Standard 100 Byte Memset took ",30);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset(src,0xFF,1000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"Standard 1000 Byte Memset took ",31);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset(src,0xFF,5000);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"Standard 5000 Byte Memset took ",31);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);


/* My memset */
  // 10 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memset(src,10,0xFF);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 10 Byte Memset took ",23);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memset(src,100,0xFF);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 100 Byte Memset took ",24);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memset(src,1000,0xFF);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 1000 Byte Memset took ",25);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes
  SysTick->VAL = 0;
  start = SysTick->VAL;
  my_memset(src,5000,0xFF);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"My 5000 Byte Memset took ",25);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

#ifdef KL25Z
/* DMA memset */
  // 10 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,10,0xFF,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 1 Byte Burst Memset took ",37);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 10 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,10,0xFF,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 2 Byte Burst Memset took ",37);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 10 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,10,0xFF,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 10 Byte 4 Byte Burst Memset took ",37);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,100,0xFF,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 1 Byte Burst Memset took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,100,0xFF,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 2 Byte Burst Memset took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 100 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,100,0xFF,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 100 Byte 4 Byte Burst Memset took ",38);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,1000,0xFF,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 1 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,1000,0xFF,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 2 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 1000 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,1000,0xFF,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 1000 Byte 4 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 1 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,5000,0xFF,1);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 1 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 2 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,5000,0xFF,2);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 2 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);

  // 5000 bytes 4 byte burst
  SysTick->VAL = 0;
  start = SysTick->VAL;
  memset_dma(src,5000,0xFF,4);
  end = SysTick->VAL;
  length = start-end;
  PRINTF("%d\n",length);
  #ifdef KL25Z
    UART_send_n((uint8_t *)"DMA 5000 Byte 4 Byte Burst Memset took ",39);
    digits = my_itoa(length,send,10);
    UART_send_n(send,digits-1);
    UART_send_n((uint8_t *)" clock cycles\n\r",15);
  #endif
  reset_memory(src,dst);
#endif
}

void reset_memory(uint8_t * src, uint8_t * dst)
{
  uint32_t i;
  for(i=0;i<5100;i++)
  {
    *(src+i) = 0xDE;
    *(dst+i) = 0xAD;
  }
}
