#include<stdio.h>
#include<stdlib.h>
#define DATA_TYPE char	// define which data you want to use

struct Node {
	DATA_TYPE value;
	struct Node *next;
};

//typedef
typedef struct Node Node;

// function prototypes
void insertNode (Node **head,DATA_TYPE value);
void deleteNode (Node **head, DATA_TYPE value);
Node* searchNode (Node *head, DATA_TYPE value);	// returns pointer to first node that contains the value
void printList(Node *head); // it works only for char. 
//If different DATA_TYPE is used printf placeholder must be changed.

int main () 
{
	// create first node of singly-linked list
	Node *headNode = calloc(1, sizeof(Node));
	Node *searchResult = calloc(1, sizeof(Node));
	printf("\nCreate singly-linked list with values 'a,b,c,d,e'");
	headNode->value = 'a';
	insertNode(&headNode, 'b');
	insertNode(&headNode, 'c');
	insertNode(&headNode, 'd');
	insertNode(&headNode, 'e');
	printList(headNode);
	printf("\nSearch for node with value c");
	searchResult = searchNode(headNode, 'c');
	printf("\n%c", searchResult->value);
	deleteNode(&headNode, 'c');
	printf("\nValue c was deleted.");
	printList(headNode);
	printf("\nDelete head of the list which is letter e");
	deleteNode(&headNode, 'e');
	printList(headNode);
	return 0;
}

void insertNode (Node **head, DATA_TYPE value) {
	Node *ptrNewNode = calloc(1,sizeof(Node));
	if (ptrNewNode == NULL) {
		printf("\nNot enough memory.");
		return;
	}
	ptrNewNode->value = value;
	ptrNewNode->next = *head;
	*head = ptrNewNode;
}

void deleteNode (Node **dptr, DATA_TYPE value) {
	Node *delNode;
	while (*dptr != NULL && (*dptr)->value != value) {
		dptr = &(*dptr)->next;
	}
	if (*dptr != NULL) {
		delNode = *dptr;
		*dptr = delNode->next;
		free(delNode);
	}
}

Node* searchNode (Node *n, DATA_TYPE value) {
	if (n == NULL) return NULL;
	if (n->value == value) return n;
	return searchNode (n->next, value);
}

void printList(Node *head) {
	Node *nodePtr = head;
	while (nodePtr != NULL) {
		printf("\n%c", nodePtr->value);
		nodePtr = nodePtr->next;
	}
	printf("\n");
}
