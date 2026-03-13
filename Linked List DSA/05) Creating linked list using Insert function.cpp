#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;

// Inserting the first node in the linked list
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
    Insert(0,17);
    Insert (1,5);
    Insert (2,7);
    Display(first);
}
