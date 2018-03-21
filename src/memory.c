/**
 * @file memory.c
 * @brief Memory source implementing header functions
 *
 * Various implementations of memory manipulation functions.
 * Moves memory, copies memory, sets memory values, reverses
 * bytes, reserves heap space, and frees space.
 *
 * @author Zachary Asmussen
 * @date January 30th, 2018
 *
 */
#include "memory.h"
#include <stdint.h>
#include <stdlib.h>
#define WORD_SIZE_IN_BYTES 4

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  if(src == NULL || length <= 0 || dst == NULL)
  {
    return NULL;
  }

  uint32_t i;
  uint8_t * tmp = (uint8_t*) malloc(length);
  for(i=0;i<length;i++)
  {
    *(tmp+i) = *(src+i);
  }
  for(i=0;i<length;i++)
  {
    *(dst+i) = *(tmp+i);
  }
  free(tmp);
  return dst;
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
  if(src == NULL || length <= 0)
  {
    return NULL;
  }

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(dst+i) = *(src+i);
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  if(src == NULL || length <= 0)
  {
    return NULL;
  }

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(src+i) = value;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
  if(src == NULL || length <= 0)
  {
    return NULL;
  }

  uint32_t i;
  for(i=0;i<length;i++)
  {
    *(src+i) = 0;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
  if(src == NULL || length <= 0)
  {
    return NULL;
  }

  uint32_t i;
  for(i=0;i<(length/2);i++)
  {
    uint8_t tmp = *(src+i);
    *(src+i) = *(src+length-1-i);
    *(src+length-1-i) = tmp;
  }
  return src;
}

void * reserve_words(size_t length)
{
  if(length > 0)
  {
    return (void *) malloc(length*WORD_SIZE_IN_BYTES);
  }
  else
  {
    return NULL;
  }
}

uint8_t free_words(void * src)
{
  if(src == NULL)
  {
    return 1;
  }
  free(src);
  return 0;
}
