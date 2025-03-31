void insertSorted(Node **head, int value)
{

    if (*head == NULL || value >= (**head).value)
    {
        insertAtBeginning(head, value);
        return;
    }

    Node *traverser = *head;

    while (traverser->next != NULL && value >= traverser->next->value) traverser = traverser->next;
    
    insertAfterANode(traverser, value);
}