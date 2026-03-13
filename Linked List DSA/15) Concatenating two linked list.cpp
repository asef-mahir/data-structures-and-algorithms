#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next ;
};
struct Node *first = NULL, *second = NULL;

void create_first_list(int A[],int n)          //first linked list
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

void create_second_list(int B[],int n)           //second linked list
{
    struct Node *t, *last;
    second = (struct Node*) malloc(sizeof(struct Node));
    second->data = B[0];
    second->next = NULL;
    last = second;
    for(int i=1; i<n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

/// Concatenating two linked list
void concat()
{
    struct Node *p = first;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL;
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
    int A[5] = {3,5,7,10,14};
    create_first_list(A,5);

    int B[4] = {2,4,6,8};
    create_second_list(B,4);

    Display(first);
    printf("\n");
    Display(second);
    printf("\n");

    concat();
    Display(first);
}
