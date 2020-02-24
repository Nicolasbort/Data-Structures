#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){

	// List constructor
	List *firstList = createList();
	List *secondList = createList();

	// First list
	insert(19, firstList);
	insert(5, firstList);
	insert(8, firstList);
	insert(6, firstList);
	insert(10,firstList);

	// Second list
	insert(3, secondList);
	insert(22, secondList);
	insert(8, secondList);
	insert(5, secondList);

	// Length list
	printf("\nLength first list: (%d)\n", len(firstList));
	printf("\nLength second list: (%d)\n", len(secondList));
	
	// Print first list
	printf("\nFirst List:\n");
	printList(firstList);
	
	// Print first list inverse
	printf("\nSecond List:\n");
	printList(secondList);

	// Print second list inverse
	printf("\nFirst list inverse:\n");
	printInverse(firstList);

	if ( compareLists(firstList, secondList) )
	{
		printf("\nEqual!\n");
	}
	else
	{
		printf("\nNot equal\n");
	}

	// Deallocate memory
	free(firstList);
	free(secondList);
}