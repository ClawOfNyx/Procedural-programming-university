#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkedList 
{
    int data;
    struct LinkedList *next;
} LinkedList;

bool search(LinkedList* head, int x);
void printList(struct LinkedList *node);
void insertBefore(LinkedList** node, int element, int value);
void push(LinkedList** header, int nValue);
void destroy(LinkedList** head);