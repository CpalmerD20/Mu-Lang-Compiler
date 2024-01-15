#include <stdlib.h>

#include "compiler.h"
#include "memory.h"
#include "vm.h"
#include "object.h"

#ifdef DEBUG_LOG_GC
#include <stdio.h>
#include "debug.h"
#endif

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
  // vm.bytesAllocated += newSize - oldSize;
  if (newSize == 0) {
    free(pointer);
    return NULL;
  }

  void* result = realloc(pointer, newSize);
  if (result == NULL) exit(1);

  return result;
}

static void freeObject(Object* iObject) {
  switch (iObject->type) {
    case STRING_TYPE : {
      StringObject* string_ = (StringObject*)iObject;
      FREE_ARRAY(char, string_->runes_, string_->length + 1);
      FREE(StringObject, iObject);
      break;
    }
    case BOUND_METHOD_TYPE :
      break;
    case CLASS_TYPE :
      break;
    case CLOSURE_TYPE :
      break;
    case FUNCTION_TYPE : {
      FunctionObject* oFunction = (FunctionObject*)iObject;
      freeChunk(&oFunction->chunk);
      FREE(FunctionObject, iObject);
      break;
    }
      break;
    case INSTANCE_TYPE :
      break;
    case NATIVE_TYPE :
      printf("<native function>");
      break;
    case UPVALUE_TYPE :
      break;
  }
}

void freeObjects() {
  Object* iObject = vm.objects_pointer;
  while (iObject != NULL) {
    Object* next = iObject->next_pointer;
    freeObject(iObject);
    iObject = next;
  }
}