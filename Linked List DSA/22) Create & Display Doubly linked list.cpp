#include<iostream>
using namespace std;
#define size 5

struct Cristiano
{
    struct Cristiano *prev;
    int data;
    struct Cristiano *next;
} *first = NULL;
typedef struct Cristiano Node;

void create(int A[],int n)            ///Creating a Doubly linked list
{
    Node *t,*last;
    int i;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display()
{
    Node *p = first;
    while(p!=NULL)
    {
        cout<< p->data << " ";
        p = p->next;
    }
}
int main()
{
    int A[size] = {11,22,33,44,55};
    create(A,size);
    Display();
}
