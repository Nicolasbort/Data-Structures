#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	List* Ref = createList(5);

	insertEnd(2, Ref);
	insertEnd(9, Ref);
	insertEnd(7, Ref);
	insertEnd(1, Ref);
	insertEnd(99, Ref);
	insertBegin(1, Ref);
	insertBegin(9, Ref);
	insertEnd(41, Ref);

	print(Ref);

	printf("\nLength: %i\n", len(Ref));

	free(Ref);
}