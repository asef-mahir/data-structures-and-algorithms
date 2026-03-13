#include<iostream>
using namespace std;
struct name
{
    int data;
    struct name *next;
};
typedef struct name Node;
Node *top = NULL;

void push(int x)                    ///PUSH FUNCTION
{
    Node *t = new Node;
    if(t==NULL)
        cout<< "Stack Overflow";
    else        //this is like inserting a new node before first node in linked list
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()                             ///POP FUNCTION
{
    Node *t;           //this is like deleting the first node
    int x= -1;
    if(top==NULL)
    {
        cout<< "Stack is empty";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int peek(int pos)                         ///PEEK FUNCTION
{
    Node *p = top;
    for(int i=0; p && i<pos-1; i++)
    {
        p = p->next;
    }
    if(p)
        return p->data;
    else
        return -1;
}

int stackTop()                            ///STACKTOP FUNCTION
{
    if(top)
        return top->data;
    else
        return -1;
}

int isEmpty()                            ///ISEMPTY FUNCTION
{
    return top==NULL? 1:0 ;
}

int isFull()                            ///ISFULL FUNCTION
{
    Node *t = new Node;         //stack will only be full when heap memory is full
    int r = (t==NULL)? 1:0 ;
    delete t;
    return r;
}

void Display()
{
    Node *p = top;
    while(p!=NULL)
    {
        cout<<p->data<< " ";
        p=p->next;
    }
}

int main()
{
    push(3);
    push(5);
    push(8);
    Display();
    cout<<endl;
    cout<<peek(3) <<endl;
    cout<<stackTop() <<endl;
    cout<<isEmpty() <<endl;
    cout<<isFull() <<endl;
    cout<<pop();
}
