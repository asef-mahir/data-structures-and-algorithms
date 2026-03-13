#include<iostream>
using namespace std;
struct Stack
{
    char data;
    struct Stack *next;
};
typedef struct Stack Node;
Node *top = NULL;

void push(char x)
{
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    Node *t;
    char x= -1;
    if(top==NULL)
        return x;

    t = top;
    top = top->next;
    x = t->data;
    delete t;
    return x;
}

int isBalanced(char *p)
{
    for(int i=0; p[i]!='\0'; i++)
    {
        if(p[i]=='(')
        {
            push(p[i]);
        }
        else if(p[i]==')')
        {
            if(top==NULL)        //means the stack is empty
                return 0;
            pop();           //this indicates else part when if part doesn't return
        }
    }
    if(top==NULL)
        return 1;               //return true if balanced, false otherwise
    else
        return 0;
}
int main()
{
    char str[] = "(((a+b)*(c+d)))";
    char *p = str;
    cout<< isBalanced(p);
}
