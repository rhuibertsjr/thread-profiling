#pragma comment(lib, "user32")

global Arena *w32_permanent_storage = 0;
global Arena *w32_entity_free = 0;

//= rhjr: windows-specific

internal W32Entity *
w32_entity_allocate(W32EntityKind kind)
{
  W32Entity *result = w32_entity_free;

  if (result != 0)
  {
    w32_entity_free = w32_entity_free->next;
    memory_zero_struct(result);
  }
  
  else
  {
    result = arena_push(w32_permanent_storage, W32Entity); 
  }

  return result;
}

internal void
w32_entity_release(W32Entity *entity)
{
  entity->kind = W32_ENTITY_KIND_NULL;
  entity->next = w32_entity_free;
  w32_entity_free = entity;
}

//= rhjr: generic functions

internal void
platform_initialize()
{
}

internal void
platform_thread_open (thread_function_t *function, void *parameters)
{
  W32Entity *entity = w32_entity_allocate(W32_ENTITY_KIND_THREAD);
  entity->thread.function = function;
  entity->thread.parameters = parameters;

  entity->thread.handle =
    CreateThread(0, 0, platform_thread__base, entity, 0, &entity->thread.tid);
}

internal void *
platform_thread__base (void *thread_entity)
{
  W32Entity *entity = (W32Entity*) thread_entity;
  thread_function_t *thread_function = entity->thread.function;
  void *thread_parameters = entity->thread.function;

  thread_function(thread_parameters);

  return 0;
}
