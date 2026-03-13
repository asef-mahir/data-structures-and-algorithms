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

///Reversing a linked list - Reversing Links Method (better & easy version)
void Reverse_2()
{
    struct Node *p, *q, *r;
    p = first; q = NULL; r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Display()
{
    struct Node *p = first;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
int main()
{
    int A[5] = {3,5,7,10,14};
    create(A,5);

    Display();
    printf("\n");
    Reverse_2();
    Display();

}
