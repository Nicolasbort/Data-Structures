typedef struct node{
	int value;
	struct node *next;
	struct node *previous;
}Node;

typedef struct list{
	Node *first;
	Node *last;
	int length;
}List;

Node* createNode(int value);

List* createList(int value);

void insertEnd(int value, List *list);

void insertBegin(int value, List *list);

int len(List *list);

void print(List *list);