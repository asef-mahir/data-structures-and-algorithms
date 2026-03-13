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

void Sort(int x)
{
    struct Node *t;
    struct Node *p = first, *q = NULL ;
    if(x < first->data)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else
    {
        while(p && p->data < x)
        {
            q = p;            //q=p must be written before p=p->next
            p = p->next ;     //Otherwise, if x is greater than all node's data, it won't be added as the last node, because then both p and q will be NULL
        }
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->next =  q->next;
        q->next = t;
    }
}
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
int main()
{
    int A[5] = {3,5,7,10,11};

    create(A,5);
    Display(first);
    Sort(2);
    printf("\n");
    Display(first);
}
