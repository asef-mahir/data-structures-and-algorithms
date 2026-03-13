#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;
void create(int A[], int n)
{
    first=(struct Node*) malloc(sizeof(struct Node));
    struct Node *p, *last;
    first->data = A[0];
    first ->next = NULL;
    last = first;
    int i;
    for(int i=1; i<n; i++)
    {
        p = (struct Node*) malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

///Finding Maximum element in the linked list
int m = -32768;              //-32768 is the lowest integer in int data type
int max(struct Node *p)
{
    while(p!=NULL)
    {
        if(p->data > m)
        {
            m = p->data;
        }
        p= p->next;
    }
    return m;
}

/// Searching in a linked list   (Binary Search is performed in linkedlist)
struct Node* searchFunc(struct Node *p, int val)     //return type struct Node pointer
{
    while(p!=NULL)
    {
        if(val == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int main()
{
    int A[5]= {7,9,11,64,5};
    create(A,5);

    int maximum = max(first);
    printf("%d\n",maximum);

    struct Node *ptr = searchFunc(first, 64);
    printf("%d\n",ptr);      ///prints the address of allocated memory which data is 64

}
