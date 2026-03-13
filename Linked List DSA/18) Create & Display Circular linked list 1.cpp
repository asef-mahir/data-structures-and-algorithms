#include<stdio.h>
#include<stdlib.h>
#define size 5
struct LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList Node;
Node *head = NULL;

///Creating circular linked list
void create(int A[],int n)
{
    Node *t, *last;
    head = (Node*) malloc(sizeof(Node));
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1; i<n; i++)
    {
        t = (Node*) malloc(sizeof(Node));
        t->data = A[i];
        t->next = last->next;
        last->next =t;
        last = t;
    }
}

///First method of displaying circular linked list
void Display(Node *p)
{
    do                          //Using do-while loop is must here, cz if we used
    {                              // while loop, the condition would be false at
        printf("%d ",p->data);        //very first time & nothing will be printed
        p = p->next;
    } while(p!=head);
}

int main()
{
    int A[size] = {2,4,6,8,10};
    create(A,5);
    Display(head);
}
