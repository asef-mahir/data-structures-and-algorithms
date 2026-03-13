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

///Second method of displaying circular linked list using recursion

int flag=0;                         //this is to mark head pointer
void Display(Node *p)
{
    if(p!=head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        Display(p->next);
    }
}

int main()
{
    int A[size] = {2,4,6,8,10};
    create(A,5);
    Display(head);
}
