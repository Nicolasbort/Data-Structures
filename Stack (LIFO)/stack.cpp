#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stack.hpp"

Node* createNode(int value)
{
	Node *node = (Node *)malloc (sizeof(Node));

	node->value = value;
	node->next = NULL;
	node->previous = NULL;

	return node; 
}


Stack* createStack()
{
	Stack *newStack = (Stack *)malloc (sizeof(Stack));

	newStack->started = false;
	newStack->base = NULL;
	newStack->top = NULL;

	return newStack;
}


void push(int value, Stack *stack)
{
	Node *newNode = createNode(value);
	
	if ( stack->started )
	{
		stack->top->next = newNode;
		newNode->previous = stack->top;
		stack->top = newNode;
	}
	else
	{
		stack->started = true;
		stack->base = newNode;
		stack->top = newNode;
	}
}


void pop(Stack *stack)
{
	if ( stack->top == NULL || stack->started == false)
	{
		printf("\nEmpty stack!\n");
		return;
	}
	else if ( stack->top == stack->base )
	{
		free(stack->top);

		stack->top = NULL;
		stack->base = NULL;
		stack->started = false;
	}
	else
	{
		Node *auxNode = stack->top;

		stack->top = stack->top->previous;
		stack->top->next = NULL;

		free(auxNode);
	}
}



void print(Stack *stack)
{
	Node *aux = stack->top;

	while (aux != NULL)
	{
		printf("%d\n", aux->value);
		aux = aux->previous;
	}
	free(aux);
}

