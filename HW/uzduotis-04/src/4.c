#include <functions.h>

int main() 
{
    LinkedList* head = NULL;

    push(&head, 6);
    push(&head, 7);
    push(&head, 1);
    push(&head, 54);
    push(&head, 8);
    push(&head, 23);
    push(&head, 2);
    push(&head, 9);

    printf("\nCreated Linked list is:\n\t");
    printList(head);
    printf("\n");

    if(search(head, 23)) 
    {
        insertBefore(&head, 23, 81);
    }
    else 
    {
        printf("Element deosn't exist\n");
    }
    
    printf("\nEdited Linked list is:\n\t");
    printList(head);

    destroy(&head);
    printf("\nLinked list after destroying:\n\t");
    printList(head);

    return 0;
}