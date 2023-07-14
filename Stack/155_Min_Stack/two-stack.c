#include <stdlib.h>

typedef struct {
  int *stack;
  int *curMin;
  int top;
} MinStack;

#define MAX_OP 3e4

MinStack *minStackCreate() {
  MinStack *s = malloc(sizeof(MinStack));
  s->stack = malloc(sizeof(int) * MAX_OP);
  s->curMin = malloc(sizeof(int) * MAX_OP);
  s->top = 0;
  return s;
}

void minStackPush(MinStack *obj, int val) {
  obj->stack[obj->top] = val;
  if (obj->top - 1 >= 0 && obj->curMin[obj->top - 1] < val)
    obj->curMin[obj->top] = obj->curMin[obj->top - 1];
  else
    obj->curMin[obj->top] = val;

  obj->top++;
}

void minStackPop(MinStack *obj) { obj->top--; }

int minStackTop(MinStack *obj) { return obj->stack[obj->top - 1]; }

int minStackGetMin(MinStack *obj) { return obj->curMin[obj->top - 1]; }

void minStackFree(MinStack *obj) {
  free(obj->stack);
  free(obj->curMin);
  free(obj);
}
