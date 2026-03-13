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

int Length()             //we'll use Length() function inside Insert() function,
{                        //that's why we're declaring it before Insert() function
    int len=0;
    Node *p = first;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}

void Insert(int pos, int x)             ///Inserting
{
    Node *t;

    if(pos<0 || pos>Length())          //it means functions won't return anything
        return;                                  //and it'll just stop

    if(pos==0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        Node *p = first;
        t = new Node;
        t->data = x;
        for(int i=0; i<pos-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if(p->next)                     //it means if(p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
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
    cout<<endl;
    Insert(1,69);
    Display();
}
