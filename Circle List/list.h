
typedef struct node
{
	int value;
	struct node *next;
	struct node *previous;
}Node;


typedef struct list
{
	Node *first;
	Node *last;
	int higher, lowest;
}List;

Node* createNode(int value);

List* createList(int value);

void insertEnd(int value, List* list);

void insertBegin(int value, List* list);

void printList(List* list);

int higherValue(List* list);

int lowestValue(List* list);