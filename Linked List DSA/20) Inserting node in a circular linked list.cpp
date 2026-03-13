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

int length()
{
    Node *p = head;
    int len=0;
    do                     //Have to use do-while here
    {
        len++ ;
        p = p->next;
    }
    while(p!=head);
    return len;
}

void Insert(int pos, int x)            ///Inserting node
{
    Node *t;
    Node *p = head;

    int len = length();
    if(pos<0 || pos>len)            //for invalid given position
        return;

    if(pos==0)               //In circular linked list, inserting a node before the
    {
        t = new Node;        //head is same as inserting after last node
        t->data = x;
        if(head==NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
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
    Insert(4,69);
    Display(head);
}
