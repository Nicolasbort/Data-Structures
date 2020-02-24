
using namespace std;

typedef struct node{
	int value;
	struct node *next;
	struct node *previous;
}Node;


typedef struct stack{
	Node *base;
	Node *top;
	bool started;
}Stack;


Node* createNode(int value);

Stack* createStack();

void push(int value, Stack *stack);

void pop(Stack *stack);

void print(Stack *stack);