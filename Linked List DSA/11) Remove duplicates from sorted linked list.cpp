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

///Here, We can only remove duplicate elements if the Linked List is SORTED.
void RemoveDuplicate()
{
    struct Node *p, *q;
    p = first;
    q = first->next;

    while(q!=NULL)
    {
        if(p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void Display()       //Display function to show the change after duplicate removal
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
    int A[7] = {3,3,5,7,7,10,14};
    create(A,7);

    Display();
    RemoveDuplicate();
    printf("\n");
    Display();
}
