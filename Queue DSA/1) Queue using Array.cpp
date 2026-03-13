#include<iostream>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};

void Enqueue(struct Queue *p, int x)
{
    if(p->rear == p->size - 1)
        cout<< "Queue is full" <<endl;
    else
    {
        p->rear ++ ;
        p -> q [p->rear] = x;
    }
}

int Dequeue(struct Queue *p)
{
    int x = -1;
    if(p->rear == p->front)
        cout<< "Queue is Empty" <<endl;
    else
    {
        p->front ++ ;
        x = p -> q [p->front];
    }
    return x;
}

void Display(struct Queue p)
{
    int i;
    for(i= p.front +1; i<= p.rear; i++)          //slightly different *_^
    {
        cout<< p.q[i] <<" " ;
    }
}

int main()
{
    struct Queue ob;
    ob.size = 5;
    ob.front = ob.rear = -1;       ///Initially, front and rear will point at -1
    ob.q = new int[ob.size];

    Enqueue(&ob,2);
    Enqueue(&ob,5);
    Enqueue(&ob,7);
    Display(ob);
    cout<<endl;
    cout<< Dequeue(&ob);

    delete[] ob.q;               //Free dynamically allocated memory
}
