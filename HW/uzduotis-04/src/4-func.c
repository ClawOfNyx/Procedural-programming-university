#include <functions.h>

/* Checks whether the value x is present in linked list */
bool search(LinkedList* head, int x) {
    LinkedList* current = head;
    while(current != NULL) 
    {
        if(current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

void printList(struct LinkedList *node) 
{
    if(node == NULL) 
    {
        printf("List does not exist.");
    }
    while(node != NULL) 
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

/* Given an element, insert a new given value before it*/
void insertBefore(LinkedList** node, int element, int value) 
{
    LinkedList* new = (LinkedList*) malloc(sizeof(LinkedList));
    LinkedList* prevNode;

    new->data = value;
    prevNode = *node;

    if(prevNode->data == element) 
    {
        new->next = (*node);
        (*node) = new;
    }
    else 
    {
        while(prevNode != NULL) 
        {
            if((prevNode->next)->data == element) 
            {
                new->next = prevNode->next;
                break;
            }
            prevNode = prevNode->next;
    }
    prevNode->next = new;
    }
}

void push(LinkedList** header, int nValue) 
{
    LinkedList* newNode = (LinkedList*) malloc(sizeof(LinkedList));
    newNode->data  = nValue;
    newNode->next = (*header);
    (*header) = newNode;
}

void destroy(LinkedList** head) 
{
    LinkedList *current = *head;
    LinkedList *next;

    while(current != NULL)
    {
       next = current->next;
       free(current);
       current = next;
    }

    *head = NULL;
}