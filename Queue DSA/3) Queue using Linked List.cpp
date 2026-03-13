#include<iostream>
using namespace std;

struct Linked
{
    int data;
    struct Linked *next;
};
typedef struct Linked Node;
Node *front = NULL, *rear = NULL;

void Enqueue(int x)
{
    Node *t = new Node;
    if(t==NULL)                         //heap is full, so new node can't be created
        cout<< "Queue is Full" <<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front==NULL)               //If it's the first node in the linked list
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Dequeue()
{
    int x = -1;
    if(front==NULL)
        cout<< "Queue is Empty" <<endl;
    else
    {
        Node *p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Display()
{
    Node *p = front;
    while(p!=NULL)
    {
        cout<< p->data << " ";
        p = p->next;
    }
}

int main()
{
    Enqueue(12);
    Enqueue(7);
    Enqueue(17);
    Display();
    cout<<endl;
    cout<< Dequeue();
}
