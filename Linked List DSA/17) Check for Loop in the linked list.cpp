#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next ;
};
struct Node *first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first= (struct Node*) malloc(sizeof(struct Node));
    first->data= A[0];
    first->next= NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t= (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

/// Checking if the linked list has a Loop or not ^_-
int isLoop()
{
    struct Node *p, *q;
    p=q= first;
    while(p && q && q->next)
    {
        p = p->next;
        q = q->next->next;

        if(p==q)      //If p & q meet, loop exists
            return 1;
    }
        return 0;
}

int main()
{
    int A[4] = {3,5,7,10};
    create(A,4);

    if(isLoop())
        printf("LInked list has loop");
    else
        printf("Linked list is linear");
}
