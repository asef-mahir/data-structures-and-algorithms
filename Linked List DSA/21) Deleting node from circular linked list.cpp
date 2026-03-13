#include<iostream>
using namespace std;
#define size 5
struct LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList Node;
Node *head = NULL;

void create(int A[],int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next =t;
        last = t;
    }
}

int Length()
{
    Node *p = head;
    int len=0;
    do
    {
        len++;
        p = p->next;
    }
    while(p!=head);
    return len;
}

int Delete(int pos)            ///Deleting a node
{
    Node *p, *q;
    int x;
    if(pos <=0 || pos>Length())
        return -1;
    if(pos==1)                     //deleting head node
    {
        p=head;
        while(p->next != head)
        {
            p = p->next;
        }

        x = head->data;

        if(p==head)          //It means there is only one node which is head node
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }
    else
    {
        p = head, q = NULL;
        for(int i=0; i<pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Display(Node *p)
{
    do
    {
        cout<< p->data << " ";
        p = p->next;
    }
    while(p!=head);
}

int main()
{
    int A[size] = {2,4,6,8,10};
    create(A,5);
    Display(head);
    cout<<endl;
    cout<< Delete(4) <<endl;
    Display(head);
}
