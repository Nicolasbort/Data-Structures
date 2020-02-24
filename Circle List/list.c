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
	Node* tempNode = createNode(value);

	List* list = (List *)malloc(sizeof(List));

	list->first = tempNode;
	list->last = tempNode;
	list->higher = value;
	list->lowest = value;
	
	return list;
}

// Insert the value at the end of the list
void insertEnd(int value, List* list)
{
	Node* tempNode = createNode(value);
	list->last->next = tempNode;

	tempNode->previous = list->last;
	tempNode->next = list->first;
	
	list->last = tempNode;
	list->first->previous = list->last;
	
	if ( value > list->higher )
		list->higher = value;

	else if ( value < list->lowest )
		list->lowest = value;
}

// Insert the value at the beginning of the list
void insertBegin(int value, List* list)
{
	Node* tempNode = createNode(value);

	tempNode->next = list->first;
	tempNode->previous = list->last;
	
	list->first->previous = tempNode;
	list->last->next = tempNode;
	list->first = tempNode;

	if ( value > list->higher )
		list->higher = value;
	
	else if ( value < list->lowest )
			list->lowest = value;
}

// Prints the list
void printList(List* list)
{
	Node* auxNode = list->first;
	int cont = 0;

	printf("Nodo (%d) : %d\n", cont+1, auxNode->value);
	
	do
	{
		cont++;
		auxNode = auxNode->next;
		printf("Nodo (%d) : %d\n", cont+1, auxNode->value);
	}while (auxNode != list->last);
}

// Returns the higher value of the list
int higherValue(List* list){ return list->higher; }

// Returns the lowest value of the list
int lowestValue(List* list){ return list->lowest; }
