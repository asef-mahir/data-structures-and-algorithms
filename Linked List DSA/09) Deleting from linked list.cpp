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

void Display(struct Node *p)     //Using this func. just to show the change after deletion, otherwise, not needed
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int Delete(int pos)
{
    struct Node *p, *q;
    int i, value;
    if(pos==1)                // If we have to delete first node
    {
        p = first;
        value = first->data;
        first = first->next;
        delete p;
    }
    if(pos>1)              // If we have to delete node in any other given position
    {
        p = first;
        q = NULL;
        for(i=0; i<pos-1 && p ;i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            value = p->data;
            delete p;
        }
    }
    return value;
}
int main()
{
    int A[5] = {3,5,7,10,11};

    create(A,5);

    Display(first);
    printf("\n");
    int x = Delete(3);
    printf("Data of the deleted node: %d\n",x);
    Display(first);
}
