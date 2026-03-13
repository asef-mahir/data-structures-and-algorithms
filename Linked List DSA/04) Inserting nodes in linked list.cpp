#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;
void create(int A[], int n)
{
    first=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p, *last;
    first->data = A[0];
    first ->next = NULL;
    last = first;
    int i;
    for(int i=1; i<n; i++)
    {
        p = (struct Node*) malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

/// Inserting Node in a given position in the linked list
void Insert(int pos, int x)
{
    struct Node *t, *p ;
    if(pos==0)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos>0)
    {
        p = first;
        for(int i=0; i<pos-1 && p ;i++)
        {
            p = p->next;
        }
        if(p)
        {
            t = (struct Node*) malloc(sizeof(struct Node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

/*When the for loop ends, there's no guarantee that p is still valid (non-NULL).
The loop could have stopped because p became NULL, so we also need to check after
the loop by using if(p) condition whether p is valid or not.*/

// Using Display function to show change before and after node insertion
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
    int A[5]= {7,9,11,64,5};
    create(A,5);

    Display(first);
    Insert(3,17);
    printf("\n");
    Display(first);
}
