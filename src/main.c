#include "base.h"

#include "arena.h"
#include "arena.c"

#include "platform/w32_core.h"
#include "platform/w32_core.c"

#include <stdio.h>

void
func(void *ptr)
{
  uint64_t *n = ptr;

  printf("Number: %u\n", *n);
  fflush(stdout);

  return NULL;
}

int main(void) {

  platform_initialize();

  platform_thread_open(func, 1);
  platform_thread_open(func, 2);
  platform_thread_open(func, 3);
  platform_thread_open(func, 4);

  while(1);

  return 0;
}
