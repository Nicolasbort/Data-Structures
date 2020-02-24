#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void){
	List* Ref = createList(5);

	insertEnd(2, Ref);
	insertEnd(9, Ref);
	insertEnd(7, Ref);
	insertEnd(-18, Ref);
	insertBegin(1, Ref);
	insertBegin(9, Ref);
	insertBegin(101, Ref);
	insertBegin(82, Ref);
	insertEnd(75, Ref);

	printList(Ref);

	printf("\nHighest value: %d\n", higherValue(Ref));

	printf("\nLowest value: %d\n", lowestValue(Ref));

	free(Ref);
}