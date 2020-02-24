#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// List constructor
List* createList()
{
	List *list = (List *) malloc (sizeof(List));

	list->length = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
}


Node* createNode(){
	Node *node = (Node *) malloc (sizeof(Node));
	return node;
}


// Insert a value at the end of the list
void insert(int value, List *list){

	Node *node = createNode();
	
	node->value = value;

	list->length++;

	// Check if the pointer first is empty
	if ( list->first == NULL )
	{
		node->next = NULL;
		list->first = node;
		list->last = node;

	}
	else
	{
		list->last->next = node;
		list->last = node;
	}
}

// Prints the list
void printList(List *list)
{
	Node* tempNode = list->first;
	int cont = 0;
	
	// Prints the value while the pointer next isn't null
	while (tempNode != NULL)
	{
		cont++;
		printf("Node |%d| : %d\n", cont, tempNode->value);
		tempNode = tempNode->next;
	}
	free(tempNode);
}

// Returns the length of the list
int len(List *list)
{
	return list->length;
}

// compares to the equality of the lists
int compareLists(List *fstList, List *secList)
{
	Node *nodeFstList = fstList->first, *nodeSecList = secList->first;

	// Check if the length is equal
	if (len(fstList) != len(secList))
	{
		free(nodeFstList);
		free(nodeSecList);
		return 0;
	// Check if the values are equal
	}
	else
	{
		do
		{
			if (nodeFstList->value != nodeSecList->value)
			{
				free(nodeFstList);
				free(nodeSecList);
				return 0;
			}
			nodeFstList = nodeFstList->next;
			nodeSecList = nodeSecList->next;	
		} while ( nodeFstList != NULL );
	}
	free(nodeFstList);
	free(nodeSecList);
	return 1;
}

void printInverse(List *list)
{
	Node *tempNode = list->first;
	
	// Auxiliary vector that will contain inverted values 
	int *vecValues = (int *) malloc( len(list) * sizeof(int) );
	int i, cont = 0;
	int len = list->length;

	// Goes through the list
	while(tempNode != NULL)
	{
		vecValues[cont] = tempNode->value;
		tempNode = tempNode->next;
		cont++;
	}
	cont = 0;
	
	// Goes through the list from the beginning to the end
	for (i = len-1; i >= 0; i--)
	{
		cont++;
		printf("Node (%d) : %d\n", cont, vecValues[i]);
	}
	free(vecValues);
	free(tempNode);
}