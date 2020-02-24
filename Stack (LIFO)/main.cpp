#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "stack.hpp"

int main() {
	Stack* stack = createStack();

	push(10, stack);
	push(20, stack);
	push(30, stack);
	push(40, stack);
	push(50, stack);
	push(60, stack);

	printf("\nBefore pop:\n");
	print(stack); 

	pop(stack);
	pop(stack);
	pop(stack);

	printf("\nAfter pop:\n");
	print(stack); 
	
	free(stack);
}