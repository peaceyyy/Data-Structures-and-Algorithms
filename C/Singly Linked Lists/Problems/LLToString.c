//10:29

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {

    char* word;
    struct Node* next;
} node_t;

node_t* createNode(char* word)
{
    node_t* newNode = malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        printf("Memory allocation for Node failed");
        exit(1);
    }

    newNode->next = NULL;
    newNode->word = strdup(word); 

    return newNode;
}

void insertNodeAtEnd (node_t** head, char* word)
{
    node_t* newNode = createNode(word);

    if(*head == NULL)
    {
        *head = newNode;
   
    }

    else {
    node_t* trav = *head;

    while (trav -> next != NULL)
    {
        trav = trav-> next;
    }

    trav->next = newNode;
}
}

void insertNodeAtBeginning (node_t** head, char* word)
{
    node_t* newNode = createNode(word);

    if(*head == NULL)
    {
        *head = newNode;
        return;    
    }

    newNode->next = *head;
    *head = newNode;

}

void insertAtMiddle (node_t** head, int n, char*  word)
{
    node_t* newNode = createNode(word);

    if(n == 1)
    {
        *head = newNode;
        return;    
    }

    int i = 0;
    node_t* trav = *head;

    while (i < n && trav -> next != NULL)
    {
        trav = trav -> next;
        i++;
    }

    newNode->next = trav->next;
    trav->next = newNode;

}


void deleteNode (node_t** head, int n, char* word)
{
    
    if(n == 1 && (*head)->next != NULL)
    {
        *head = (*head)->next;
    }

    int i = 0;
    node_t* trav = *head;

    while (i < n && trav -> next != NULL)
    {
        trav = trav -> next;
        i++;
    }   
    
    node_t* aux = trav -> next;
    trav -> next = trav -> next -> next;

    free(aux);

}



char* LLToString (node_t* head)
{
    char* str = (char*) malloc(sizeof(char) * 20);
    str[0] = '\0';


    node_t* trav = head;

    while (trav != NULL)
    {   

        strcat(str, trav->word);
        trav = trav->next;
    }


    return str; 
}







int main()
{
    node_t* head = NULL;
    int numOfNodes;

    printf("Input the number of nodes: ");
    scanf("%d", &numOfNodes);
    char data[100];

    for (int i = 0 ; i < numOfNodes; i++)
    {   
        printf("Input data for Node %d: ", i + 1);
        scanf(" %[^\n]", data);
        insertNodeAtEnd(&head, data);
    }

    char* LLString = LLToString(head);
    printf(" %s", LLString);

    return 0;
}

