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
    if((p->rear +1) % p->size == p->front)
        cout<< "Queue is Full" <<endl;
    else
    {
        p->rear = (p->rear +1) % p->size;
        p -> q [p->rear] = x;
    }
}

int Dequeue(struct Queue *p)
{
    int x = -1;
    if(p->front == p->rear)
        cout<< "Queue is Empty" <<endl;
    else
    {
        p->front = (p->front +1) % p->size;
        x = p -> q [p->front];
    }
    return x;
}

void Display(struct Queue p)
{
    int i = (p.front + 1) % p.size;
    do                                        ///do-while loop
    {
        cout<< p.q[i] << " ";
        i = (i+1) % p.size;
    }
    while(i != (p.rear+1) % p.size);
}

int main()
{
    struct Queue ob;
    ob.size = 5;
    ob.front = ob.rear = 0;         ///Initially, front and rear will point at 0
    ob.q = new int[ob.size];

    Enqueue(&ob,3);
    Enqueue(&ob,7);
    Enqueue(&ob,11);
    Display(ob);
    cout<<endl;
    cout<< Dequeue(&ob);

    delete[] ob.q;               //Free dynamically allocated memory
}
