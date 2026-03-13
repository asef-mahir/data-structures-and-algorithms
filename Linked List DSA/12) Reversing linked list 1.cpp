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

///Reversing a linked list - Reversing Elements Method
void Reverse_1(int B[])
{
    struct Node *p = first;
    int i=0;
    while(p!=NULL)
    {
        B[i] = p->data;
        p = p->next;
        i++;                   //i=0 theke loop 5 bar cholle i er value 4 na hoye 5 hobe, cz p=NULL howar poreo i++ ekbar hobe
    }

    p = first, i--;              // i= i-1 = 5-1=4
    while(p!=NULL)
    {
        p->data = B[i];
        p = p->next;
        i-- ;
    }
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

    int B[5];
    Display();
    printf("\n");
    Reverse_1(B);
    Display();

}
