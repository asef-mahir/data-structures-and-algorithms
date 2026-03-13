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

int Length()
{
    int len=0;
    Node *p = first;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

int Delete(int pos)
{
    Node *p;
    int x;

    if(pos<=0 || pos>Length())
        return -1;
    if(pos==1)
    {
        p = first;
        x = p->data;
        first = first->next;
        delete p;
        if(first)
        {
            first->prev = NULL;
        }
    }
    else
    {
        p = first;
        for(int i=0; i<pos-1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
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
    cout<<endl;
    cout<<Delete(4) <<endl;
    Display();
}
