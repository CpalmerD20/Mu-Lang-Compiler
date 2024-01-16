// Chunks of Bytecode
#ifndef mu_chunk_h
#define mu_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
// Types of Values literal-ops
  OP_NIL,
  OP_TRUE,
  OP_FALSE,
// Global Variables pop-op
  OP_POP,
// Local Variable operations
  OP_GET_LOCAL,
  OP_SET_LOCAL,
// Global Variables get-global-op
  OP_GET_GLOBAL,
  OP_DEFINE_GLOBAL,
  OP_SET_GLOBAL,
// Closures operations
  OP_GET_UPVALUE,
  OP_SET_UPVALUE,
// Classes and Instances property-ops
  OP_GET_PROPERTY,
  OP_SET_PROPERTY,
// Superclasses get-super-op
  OP_GET_SUPER,
// Types of Values comparison-ops
  OP_EQUAL,
  OP_GREATER,
  OP_LESS,
// START A Virtual Machine binary-ops
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
// Types of Values unary-ops
  OP_NOT,
  OP_NEGATE,
// Global Variables op-print
  OP_PRINT,
// Jumping Back and Forth operations
  OP_JUMP,
  OP_JUMP_IF_FALSE,
  OP_JUMP_IF_TRUE,
  OP_LOOP,
// Calls and Functions op-call
  OP_CALL,
  OP_INVOKE,
  OP_SUPER_INVOKE,
  OP_CLOSURE,
  OP_CLOSE_UPVALUE,
  OP_RETURN,
// Classes and Instances class-op
  OP_CLASS,
  OP_INHERIT,
  OP_METHOD
} OpCode;

typedef struct {
  int count;
  int capacity;
  uint8_t* code;
  int* lines;
  ValueArray constants; // constant pool
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);

#endif
