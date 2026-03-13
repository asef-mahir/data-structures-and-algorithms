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

int isSorted(struct Node *p)
{
    while(p!=NULL && p->next!=NULL)
    {
        if(p->next->data < p->data)
        {
            return false;
        }
        else
            p = p->next;
    }
    return true;
}
int main()
{
    int A[5] = {3,5,7,10,11};
    create(A,5);

    int result = isSorted(first);

    if (result)
        printf("List is sorted");
    else
        printf("List is not sorted");
}
