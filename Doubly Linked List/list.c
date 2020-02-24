#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Node constructor
Node* createNode(int value)
{
	Node* node = (Node *)malloc(sizeof(Node));

	node->value = value;
	node->next = NULL;
	node->previous = NULL;

	return node;
}

// List constructor 
List* createList(int value)
{
	Node* node = createNode(value);
	List* list = (List *)malloc(sizeof(List));
	
	list->first = node;
	list->last = node;
	list->length = 0;

	return list;
}

// Insert the value at the end of the list
void insertEnd(int value, List* list)
{
	Node* node = createNode(value);

	list->last->next = node;
	node->previous = list->last;
	list->last = node;

	list->length++;
}

// Insert the value at the beginning of the list
void insertBegin(int value, List* list)
{
	Node* node = createNode(value);
	node->next = list->first;

	list->first->previous = node;
	list->first = node;

	list->length++;
}

// Returns the length of the list
int len(List *list)
{
	return list->length;
}

// Prints the list
void print(List* list)
{
	Node* auxNode = list->first;
	int cont = 0;

	while (auxNode != NULL){
		printf("Node (%d) : %d\n", cont+1, auxNode->value);
		cont++;
		auxNode = auxNode->next;
	}
}
