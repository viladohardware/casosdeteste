#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node
{
 	int item;
  struct node* next;
}node;

typedef struct stack
{
	node* top;
	int size;
}st;

/*
	Cria uma pilha vazia.
*/
st* create_stack();

/*
	Adiciona um elemento no topo da pilha.
*/
void push(st *stack, int item);

/*
	Retira o elemento no topo da pilha.
*/
void pop(st *stack);

/*
  Olha o primeiro elemento da pilha.
*/
int peek(st* stack);

#endif
