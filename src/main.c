#include "base.h"

#include "arena.h"
#include "arena.c"

#include "platform/w32_core.h"
#include "platform/w32_core.c"

#include <stdio.h>

void
func(void *ptr)
{
  printf("Hello world\n");
  fflush(stdout);
  return NULL;
}

int main(void) {

  platform_initialize();

  platform_thread_open(func, 0);
  platform_thread_open(func, 0);
  platform_thread_open(func, 0);
  platform_thread_open(func, 0);

  while(1);

  return 0;
}
