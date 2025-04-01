#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* string;
    struct Node* next;
} node_t;

node_t* createNode (char* str)
{
    node_t* newNode = malloc(sizeof(node_t));
    
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation for node failed");
    }

    newNode->next = NULL;
    newNode -> string = (char*) malloc((sizeof(char) * strlen(str)) + 1);
    strcpy((*newNode).string, str);

    return newNode;
}

void insertAtBeginning (node_t** head, char* str)
{   
    node_t* newNode = createNode(str);

    if((*head) == NULL) 
    {
        *head = newNode;
        return; 
    }

    newNode->next = *head;
    *head = newNode;
}


void insertSorted (node_t** head, char* str)
{   
    if ((*head) == NULL || strcmp(str, (*head)->string) <= 0){
        insertAtBeginning(&(*head), str);
        return; 
    }
    node_t* trav;
    node_t* newNode = createNode(str);

    for (trav = *head; trav -> next != NULL && strcmp(str, trav -> next -> string) > 0; trav = trav -> next);

    newNode -> next = trav -> next;
    trav -> next = newNode;
    
    
}

void show(node_t* head){
	node_t* trav;
	for (trav = head; trav!=NULL; trav = trav->next){
		printf("%s ", trav->string);
		if (trav->next != NULL){
			printf("--> ");
		}
	}
}


void main(){
	
    
    node_t* head = createNode("Test");
	insertSorted(&head, "Joenell");
	insertSorted(&head, "Migo");
	insertSorted(&head, "Louie");
	insertSorted(&head, "Margot");
	insertSorted(&head, "Cindy");
	insertSorted(&head, "Chris Michael");
	insertSorted(&head, "Chris Evans");
	insertSorted(&head, "Asdf");
	show(head);

	
}

