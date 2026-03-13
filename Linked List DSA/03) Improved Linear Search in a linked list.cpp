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

/// Improved Linear Search in a linked list
/*Move to Front/Head:
In this method, if the key element is found then it is directly swapped with the
first pointer, so that the next consecutive time, search operation for the same key
element is of O(1), i.e., constant time.*/

struct Node* searchFunc(struct Node *p, int val)     //return type struct Node pointer
{
    struct Node* q = NULL;
    while(p!=NULL)
    {
        if(val == p->data)
        {
            q->next = p->next ;
            p->next = first;
            first = p;
            return p;
        }
        q = p;                    //this is else part by deafult
        p = p->next;
    }
    return NULL;           //if 1st return works, this one won't
}

int main()
{
    int A[5]= {7,9,11,64,5};
    create(A,5);

    struct Node *ptr = searchFunc(first, 5);
    printf("%d",ptr);      ///prints the address of allocated memory which data is 64

}
