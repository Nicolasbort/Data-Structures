typedef struct node{
	int value;
	struct node *next;
}Node;

typedef struct list{
	Node *first;
	Node *last;
	int length;
}List;

List* createList();

Node* createNode();

void insert(int value, List *List);

void printList(List *List);

int len(List *List);

int compareLists(List *fstList, List *secList);

void printInverse(List *List);