#ifndef PLATFORM_CORE_H
#define PLATFORM_CORE_H

#include <Windows.h>
#include <processthreadsapi.h>

typedef void thread_function_t(void *ptr);

typedef enum
{
  W32_ENTITY_KIND_NULL,
  W32_ENTITY_KIND_THREAD
}
W32EntityKind;

typedef struct W32Entity W32Entity;
struct W32Entity
{
  W32Entity *next;
  W32EntityKind kind;

  struct
  {
    uint32_t tid;
    HANDLE handle;
    thread_function_t *function;
    void *parameters;
  } thread;
};

//= rhjr: windows-specific

internal W32Entity * w32_entity_allocate(W32EntityKind kind);

internal void w32_entity_release(W32Entity *entity);

//= rhjr: generic functions

internal void platform_initialize();

internal void platform_thread_open(thread_function_t *function);

internal void * platform_thread__base(void *thread_parameters);

#endif //PLATFORM_CORE_H
