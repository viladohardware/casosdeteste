#include "../lib/stack.h"

st* create_stack()
{
	st *temp = (st*) malloc(sizeof(st));
	temp->top = NULL;
	temp->size = 0;
	return temp;
}

void push(st *stack, int item)
{
  node *temp = malloc(sizeof(node));
  temp->item = item;
	temp->next = stack->top;
	stack->top = temp;
	stack->size++;
}

void pop(st *stack)
{
  if(stack->size == 0)
  {
    printf("Stack Underflow!\n");
  }
  node* previous = stack->top;
  stack->top = previous->next;
  //free(previous);
  //stack->size--;
}

int peek(st* stack)
{
  if(stack->top != NULL) return ((*(*stack).top).item);
  else return -9999;
}
