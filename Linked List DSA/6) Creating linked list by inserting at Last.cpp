/*In this way, we can just add a new node at the end of the linked list in just
constant time. We don't have to traverse the list every time. Because last pointer
will be pointing at the last node, we don't have to start traversing from first node.*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *first, *last = NULL;

void InsertLast(int x)
{
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first==NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
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
    InsertLast(2);     //position is always at the last, we'll just pass the value
    InsertLast(5);
    InsertLast(7);

    Display(first);
}
